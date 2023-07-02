/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 14:51:12 by abeznik       #+#    #+#                 */
/*   Updated: 2023/07/02 12:14:33 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "lexer.h"

typedef struct s_expander
{
	t_expansion	*exp;
	size_t		pos;
	char		**envp;
	pid_t		*status;
}	t_expander;

bool		expander(t_expander *expander, t_lexer *lexer);
bool		do_expanding(t_expander *expr, t_token *token);
void		get_param(t_expander *expr, t_token *token);
bool		is_parameter(int c);
t_token		*split_words(t_token **token);
bool		contains_space(char *str);
void		rm_tokenspace(t_lexer *lexer);

#endif
