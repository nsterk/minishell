/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prompt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 17:08:36 by nsterk        #+#    #+#                 */
/*   Updated: 2023/01/07 17:03:20 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

// # include "utils.h"
# include "lexer.h"
# include <stdio.h>

int		prompt(t_lexer *lexer);
char	*grab_input(char *prompt);

#endif