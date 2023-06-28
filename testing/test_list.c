
#include "lexer.h"
#include "utils.h"
#include "colours.h"

void	token_printHtT(t_token *lst)
{
	t_token	*tmp;

	tmp = lst;
	while (tmp)
	{
		// if (tmp->flags & F_SPACE)
		// 	printf(GRN"");
		if (tmp->word)
			printf("%s", tmp->word);
		printf(" (state: %d)", tmp->state);
		// printf(" expansions: %zu", tmp->exp_count);
		if (tmp->next)
			printf(RED" - "RST);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
	printf("\n");
}

void	token_printTtH(t_token *lst)
{
	t_token	*tmp;

	tmp = token_last(lst);
	while (tmp)
	{
		printf("%s", tmp->word);
		if (tmp->prev)
			printf(" - ");
		tmp = tmp->prev;
	}
	printf("\n");
}

void	token_printaddress(t_token *lst)
{
	t_token	*tmp;

	tmp = lst;
	while (tmp)
	{
		printf("\033[34m	%s\033[0m\n", tmp->word);
		printf("prev: %p	current: %p		next: %p\n", tmp->prev, tmp, tmp->next);
		tmp = tmp->next;
	}
}

// int	token_size(t_token *token)
// {
// 	int		i;

// 	i = 0;
// 	while (token)
// 	{
// 		token = token->next;
// 		i++;
// 	}
// 	return (i);
// }

// void	test_insert(t_token **lst)
// {
// 	t_token	*tmp;

// 	tmp = (*lst)->next;
// 	printf("\033[32mToken list before insertion:\033[0m ");
// 	token_printHtT(*lst);
// 	if (token_addafter(&tmp, token_new("momo")))
// 	{
// 		printf("failed to insert token\n");
// 		exit(0);
// 	}
// 	printf("\033[32mToken list after insertion: \033[0m");
// 	token_printHtT(*lst);
// }

// void	test_insert_end(t_token **lst)
// {
// 	t_token	*tmp;

// 	tmp = token_last(*lst);
// 	printf("\033[32mToken list before insertion:\033[0m ");
// 	token_printHtT(*lst);
// 	if (token_addafter(&tmp, token_new("momo")))
// 	{
// 		printf("failed to insert token\n");
// 		exit(0);
// 	}
// 	printf("\033[32mToken list after insertion: \033[0m");
// 	token_printHtT(*lst);
// }

// void	test_append(t_token **lst)
// {
// 	printf("\033[32mToken list before append:\033[0m ");
// 	token_printHtT(*lst);
// 	if (token_append(lst, token_new("momo_append", TOK_CMD)))
// 	{
// 		printf("failed to insert token\n");
// 		exit(0);
// 	}
// 	printf("\033[32mToken list after insertion: \033[0m");
// 	token_printHtT(*lst);
// }

// void	test_remove(t_token **head, t_token *token)
// {
// 	if (token_size(*head) < 3)
// 	{
// 		printf("Token list needs to have at least 3 elements for test_remove\n");
// 		return ;
// 	}
// 	printf("\033[32mToken list before remove head:\033[0m ");
// 	token_printHtT(*head);
// 	*head = token_remove(head, token);
// 	printf("\033[32mToken list after remove head:\033[0m ");
// 	token_printHtT(*head);
// 	printf("\033[33mToken list before remove mid:\033[0m ");
// 	token_printHtT(*head);
// 	*head = token_remove(head, (*head)->next);
// 	printf("\033[33mToken list after remove mid:\033[0m ");
// 	token_printHtT(*head);
// 	printf("\033[35mToken list before remove last:\033[0m ");
// 	token_printHtT(*head);
// 	*head = token_remove(head, token_last(*head));
// 	printf("\033[35mToken list after remove last:\033[0m ");
// 	token_printHtT(*head);
// }
