/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   defines.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 19:40:39 by nsterk        #+#    #+#                 */
/*   Updated: 2022/12/06 19:48:30 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define CH_SQUOTE		'\''
# define CH_DQUOTE 		'"'
# define CH_PIPE		'|'
# define CH_REDIR_IN	'<'
# define CH_REDIR_OUT	'>'

/**
 * Token flags. Flags are set in one int, with different bits corresponding
 * to different flags.
 */

# define F_SQUOTE	1
# define F_DQUOTE	2
# define F_EXPAND	4

#endif
