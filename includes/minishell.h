/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 15:05:45 by arthurbezni   #+#    #+#                 */
/*   Updated: 2022/09/13 20:01:25 by arthurbezni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/**
 * Needed libs.
 */
# include <unistd.h>

/**
 * Minishell libs.
 */
# include <lexer.h>
# include <parser.h>
# include <utils.h>

int				main(void);

#endif