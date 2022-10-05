/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 19:02:58 by abeznik       #+#    #+#                 */
/*   Updated: 2022/10/05 19:41:48 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "parser.h"
# include "executor.h"
# include "utils.h"

int	read_builtin(char *cmd);

int	exec_pwd(void);

#endif