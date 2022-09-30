/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prompt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 17:08:36 by nsterk        #+#    #+#                 */
/*   Updated: 2022/09/30 21:00:41 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# include "utils.h"
# include "lexer.h"
# include <stdio.h>

int		prompt(t_lexer *lexer);
char	*grab_input(t_lexer *lexer, char *prompt);

#endif