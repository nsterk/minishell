/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chr_class.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 20:09:52 by nsterk        #+#    #+#                 */
/*   Updated: 2022/10/26 14:08:35 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_toktype	get_type(int c)
{
	if (ft_isspace(c))
		return (TOK_SPACE);
	if (c == '<' || c == '>' || c == '|')
		return (TOK_OP);
	if (c == '\0')
		return (TOK_EOF);
	return (TOK_CMD);
}
