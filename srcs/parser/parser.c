/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 12:18:59 by abeznik       #+#    #+#                 */
/*   Updated: 2023/01/07 14:14:27 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_table	*parser(t_token *token)
{
	t_table	*table = NULL;

	printf("%s\n", token->word);
	return (table);
}
