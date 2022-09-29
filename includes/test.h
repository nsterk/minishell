/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/22 11:32:28 by nsterk        #+#    #+#                 */
/*   Updated: 2022/09/22 14:59:37 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "lexer.h"
# include "utils.h"

/* Print tokens head to tail */
void	token_printHtT(t_token *lst);

/* Print tokens tail to head */
void	token_printTtH(t_token *lst);

/* Print token addresses */
void	token_printaddress(t_token *lst);

/* Insrt an element after the first element, so don't test with lst < 2 */
void	test_insert(t_token **lst);

/* This function tests whether insert works correctly if spot is tail of list */
void	test_insert_end(t_token **lst);

#endif