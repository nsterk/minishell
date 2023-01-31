/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_parser.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 22:23:22 by nsterk        #+#    #+#                 */
/*   Updated: 2023/01/31 22:24:35 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_table	*init_parser(t_token *token)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	return (table);
}
