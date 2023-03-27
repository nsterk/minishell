/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   defines.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 19:40:39 by nsterk        #+#    #+#                 */
/*   Updated: 2023/02/16 14:43:34 by nsterk        ########   odam.nl         */
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
 * 
 * F_SQUOTE		set if token is in single quoted state
 * F_DQUOTE		set if token is in double quoted state
 * F_EXPAND		set if token contains expansion
 * F_APPEND		special redirection (heredoc for redir_in, append for redir_out)
 */

# define SQUOTE		0
# define DQUOTE		2
# define LESS		4
# define DLESS		8
# define GREAT		16
# define DGREAT		32

#endif
