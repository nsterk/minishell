/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testing_init.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/22 11:39:24 by arthurbezni   #+#    #+#                 */
/*   Updated: 2023/01/22 11:40:53 by arthurbezni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/**
 * ? testing function
*/
void	init_lexer_data(t_lexer *lexer, t_cmd **cmd, \
			t_data_exe **data_exe, t_exec **exec)
{
	t_data_exe 	*tmp_data;
	t_cmd 		*cmd0;
	t_cmd 		*cmd1;
	t_cmd 		*cmd2;
	t_cmd 		*cmd3;
	// t_exec 		*tmp_exec;
	// t_red		*tmp_in;
	// t_red		*tmp_out;

	tmp_data = (t_data_exe *)malloc(sizeof(t_data_exe));
	// tmp_exec = (t_exec *)malloc(sizeof(t_exec));
	// tmp_in = (t_red *)malloc(sizeof(t_red));
	// tmp_out = (t_red *)malloc(sizeof(t_red));

	cmd0 = (t_cmd *)malloc(sizeof(t_cmd));
	cmd0->exec = (t_exec *)malloc(sizeof(t_exec));
	cmd0->exec->args = (char **)malloc(sizeof(char *) * 2);
	cmd0->exec->args[0] = (char *)malloc(sizeof(char *) * 1024);
	cmd0->exec->args[1] = (char *)malloc(sizeof(char *) * 1024);
	cmd0->in = (t_red *)malloc(sizeof(t_red));
	cmd0->out = (t_red *)malloc(sizeof(t_red));

	cmd1 = (t_cmd *)malloc(sizeof(t_cmd));
	cmd1->exec = (t_exec *)malloc(sizeof(t_exec));
	cmd1->in = (t_red *)malloc(sizeof(t_red));
	cmd1->out = (t_red *)malloc(sizeof(t_red));

	cmd2 = (t_cmd *)malloc(sizeof(t_cmd));
	cmd2->exec = (t_exec *)malloc(sizeof(t_exec));
	cmd2->in = (t_red *)malloc(sizeof(t_red));
	cmd2->out = (t_red *)malloc(sizeof(t_red));

	cmd3 = (t_cmd *)malloc(sizeof(t_cmd));
	cmd3->exec = (t_exec *)malloc(sizeof(t_exec));
	cmd3->in = (t_red *)malloc(sizeof(t_red));
	cmd3->out = (t_red *)malloc(sizeof(t_red));

	/**
	 * ? here_doc
	 * 	<< Arthur cat -e > output0 << naomi ls > output1
	*/
	// cmd0->in->filename = "Arthur";
	// cmd1->in->filename = "Naomi";
	// cmd2->in->filename = "test_out";

	// cmd0->in->type = HERE_DOC;
	// cmd1->in->type = HERE_DOC;
	// cmd2->in->type = RED_OPUT;
	// // cmd3->in->type = RED_OPUT;

	// cmd0->in->next = cmd1->in;
	// cmd1->in->next = cmd2->in;
	// cmd2->in->next = NULL;
	// // cmd3->in->next = NULL;


	/**
	 * ? pipe
	 * 	cat | ls
	*/
	// cmd0->next = cmd1;
	// cmd1->next = cmd2;

	// cmd0->exec->cmd = "cat";
	// cmd0->next = NULL;
	// cmd0->out = NULL;

	/**
	 * ? testing exit
	*/
	cmd0->exec->argc = 1;
	cmd0->exec->cmd = "exit";
	// cmd0->exec->cmd = "echo";
	cmd0->exec->args[0] = "exit";
	cmd0->exec->args[1] = '\0';
	cmd0->in = NULL;
	cmd0->out = NULL;
	cmd0->next = NULL;

	tmp_data->envp = lexer->envp;
	*data_exe = tmp_data;

	*cmd = cmd0;
}
