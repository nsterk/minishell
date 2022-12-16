/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 12:18:59 by abeznik       #+#    #+#                 */
/*   Updated: 2022/12/11 21:50:59 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
simple_command	:	cmd_prefix	cmd_word	cmd_suffix
				|	cmd_prefix	cmd_	 
  
 */

t_table	*parser(t_token *token)
{
	t_table	*table = NULL;
	// printf("parser works!\n");
	return (table);
}
