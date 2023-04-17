/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/22 11:32:28 by nsterk        #+#    #+#                 */
/*   Updated: 2023/02/13 16:55:48 by nsterk        ########   odam.nl         */
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