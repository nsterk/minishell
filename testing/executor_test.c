/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor_test.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 14:05:30 by abeznik       #+#    #+#                 */
/*   Updated: 2022/11/23 13:09:40 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "testing.h"

t_token 	*tokens;
t_token 	*i;
t_data		*data;
int			g_ret_expected;
int			g_ret_actual;
bool		skip_check;

static void	init_test(char *line)
{
	tokens = grab_input(&data->lexer, line);
	TEST_ASSERT_NOT_NULL(tokens);
	i = tokens;
    g_ret_actual = parse_quotes_and_expand(i, data->env, data);
}

static void		assert_token(t_toktype type, char *text)
{
	long	len;

	TEST_ASSERT_NOT_NULL(i);
	TEST_ASSERT_EQUAL_INT16(type, i->type);
	if (!text)
	{
		TEST_ASSERT_NULL(i->word);
		i->end = 0;
	}
	else
	{
		len = strlen(text);
		TEST_ASSERT_EQUAL_STRING(text, i->word);
		TEST_ASSERT_EQUAL_UINT64(len, i->end);
	}
	i = i->next;
}

void	setUp(void) {
    g_ret_expected = 0;
	// data->last_pid = 42;
	skip_check = false;
}

void	tearDown(void) {
	if (!skip_check)
    	assert_token(TOK_EOF, NULL);
	ft_free_array(&tokens);
	tokens = NULL;
	i = NULL;
	TEST_ASSERT_EQUAL_UINT8(g_ret_expected, g_ret_actual);
}

static void	trial_1()
{
	init_test("  test  ");
	assert_token(TOK_CMD, "test");
}

static void	trial_2()
{
	init_test("  test  test test  test test test       test     test    test ");
	assert_token(TOK_CMD, "test");
	assert_token(TOK_CMD, "test");
	assert_token(TOK_CMD, "test");
	assert_token(TOK_CMD, "test");
	assert_token(TOK_CMD, "test");
	assert_token(TOK_CMD, "test");
	assert_token(TOK_CMD, "test");
	assert_token(TOK_CMD, "test");
	assert_token(TOK_CMD, "test");
}

static void	trial_3()
{
	init_test("      ");
}

static void	trial_4()
{
	init_test("");
}

static void	trial_5()
{
	init_test(" ls -l");
	assert_token(TOK_CMD, "ls");
	assert_token(TOK_CMD, "-l");
}

static void	trial_6()
{
	init_test("echo \"string\" hi");
	assert_token(TOK_CMD, "echo");
	assert_token(TOK_CMD, "string");
	assert_token(TOK_CMD, "hi");
}

static void	trial_7()
{
	init_test("echo hi\"string\"hi");
	assert_token(TOK_CMD, "echo");
	assert_token(TOK_CMD, "histringhi");
}

static void	trial_8()
{
	init_test("echo hi\"\'string\'\"hi");
	assert_token(TOK_CMD, "echo");
	assert_token(TOK_CMD, "hi\'string\'hi");
}

static void	trial_9()
{
	init_test("echo hi\"\"\'string\'\"\"hi");
	assert_token(TOK_CMD, "echo");
	assert_token(TOK_CMD, "histringhi");
}

static void	trial_10()
{
	init_test("echo hi\"\"\'string\'\"\"hi");
	assert_token(TOK_CMD, "echo");
	assert_token(TOK_CMD, "histringhi");
}

static void	trial_11()
{
	init_test("\'\"\' ");
	assert_token(TOK_CMD, "\"");
}

static void	trial_12()
{
	init_test("\"\'\" ");
	assert_token(TOK_CMD, "\'");
}

static void	trial_13()
{
	init_test("echo hi\"hi ");
	skip_check = true;
	g_ret_expected = 1;
}

static void	trial_14()
{
	init_test("echo hi\'hi ");
	skip_check = true;
	g_ret_expected = 1;
}

static void	trial_15()
{
	init_test("echo hi\'hi\'\" ");
	skip_check = true;
	g_ret_expected = 1;
}

static void	trial_16()
{
	init_test("echo hi\"hi\"\' ");
	skip_check = true;
	g_ret_expected = 1;
}

static void	trial_17()
{
	init_test("\'");
	skip_check = true;
	g_ret_expected = 1;
}

static void	trial_18()
{
	init_test("\"");
	skip_check = true;
	g_ret_expected = 1;
}

static void	trial_19()
{
	init_test("$env_var");
	assert_token(TOK_CMD, "blabla");
}

static void	trial_20()
{
	init_test("\"$env_var\"");
	assert_token(TOK_CMD, "blabla");
}

static void	trial_21()
{
	init_test("\'$env_var\'");
	assert_token(TOK_CMD, "$env_var");
}

static void	trial_22()
{
	init_test("\"\'$env_var\'\"");
	assert_token(TOK_CMD, "\'blabla\'");
}

static void	trial_23()
{
	init_test("\"  $env_var  \"");
	assert_token(TOK_CMD, "  blabla  ");
}

static void	trial_24()
{
	init_test("\"  $?  \"");
	assert_token(TOK_CMD, "  42  ");
}

static void	trial_25()
{
	init_test("\"  $$  \"");
	assert_token(TOK_CMD, "    ");
}

static void	trial_26()
{
	init_test("\"  $  \"");
	assert_token(TOK_CMD, "  $  ");
}

static void	trial_27()
{
	init_test("\"     $\"");
	assert_token(TOK_CMD, "     $");
}

static void	trial_28()
{
	init_test("echo hi\"$env_var\"$env_var");
	assert_token(TOK_CMD, "echo");
	assert_token(TOK_CMD, "hiblablablabla");
}

static void	trial_29()
{
	init_test("\"123$double_var123\"");
	assert_token(TOK_CMD, "123");
}

static void	trial_30()
{
	init_test("\"  $doesnt_exist  \"");
	assert_token(TOK_CMD, "    ");
}

static void	trial_31()
{
	init_test("\"123$double_var 123\"");
	assert_token(TOK_CMD, "123blabla 123");
}

static void	trial_32()
{
	init_test("echo$?echo");
	assert_token(TOK_CMD,"echo42echo");
}

static void	trial_33()
{
	init_test("echo$?echo");
	assert_token(TOK_CMD,"echo42echo");
}

static void trial_34()
{
	init_test("echo \'\"$USER\"\'");
	assert_token(TOK_CMD, "echo");
	assert_token(TOK_CMD, "\"$USER\"");
}

static void trial_35()
{
	init_test("echo $9a");
	assert_token(TOK_CMD, "echo");
	assert_token(TOK_CMD, "a");
}

static void trial_36()
{
	init_test("echo $a9");
	assert_token(TOK_CMD, "echo");
	assert_token(TOK_CMD, "jup");
}

static void trial_37()
{
	init_test("echo $*");
	assert_token(TOK_CMD, "echo");
	assert_token(TOK_CMD, NULL);
}

static void trial_38()
{
	init_test("echo $$");
	assert_token(TOK_CMD, "echo");
	assert_token(TOK_CMD, NULL);
}

int main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		exit(-1);
	data->env = envp;
    UNITY_BEGIN();
	RUN_TEST(trial_1);
    RUN_TEST(trial_2);
    RUN_TEST(trial_3);
    RUN_TEST(trial_4);
    RUN_TEST(trial_5);
	RUN_TEST(trial_6);
	RUN_TEST(trial_7);
	RUN_TEST(trial_8);
	RUN_TEST(trial_9);
	RUN_TEST(trial_10);
	RUN_TEST(trial_11);
	RUN_TEST(trial_12);
	RUN_TEST(trial_13);
	RUN_TEST(trial_14);
	RUN_TEST(trial_15);
	RUN_TEST(trial_16);
	RUN_TEST(trial_17);
	RUN_TEST(trial_18);
	RUN_TEST(trial_19);
	RUN_TEST(trial_20);
	RUN_TEST(trial_21);
	RUN_TEST(trial_22);
	RUN_TEST(trial_23);
	RUN_TEST(trial_24);
	RUN_TEST(trial_25);
	RUN_TEST(trial_26);
	RUN_TEST(trial_27);
	RUN_TEST(trial_28);
	RUN_TEST(trial_29);
	RUN_TEST(trial_30);
	RUN_TEST(trial_31);
	RUN_TEST(trial_32);
	RUN_TEST(trial_33);
	RUN_TEST(trial_34);
	RUN_TEST(trial_35);
	RUN_TEST(trial_36);
	RUN_TEST(trial_37);
	RUN_TEST(trial_38);
    return (UNITY_END());
}
