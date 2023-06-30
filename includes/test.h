
#ifndef TEST_H
# define TEST_H

# include "lexer.h"
# include "parser.h"
# include "utils.h"

/* Print tokens head to tail */
void	token_printHtT(t_token *lst);

/* Print tokens tail to head */
void	token_printTtH(t_token *lst);

void	print_tbl(t_cmd *cmd);  

#endif
