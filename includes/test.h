/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 14:53:15 by abeznik       #+#    #+#                 */
/*   Updated: 2023/06/30 14:53:29 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
