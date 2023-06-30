/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   defines.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 14:47:52 by abeznik       #+#    #+#                 */
/*   Updated: 2023/06/30 14:48:31 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define CH_SQUOTE	'\''
# define CH_DQUOTE 	'"'
# define CH_PIPE	'|'
# define CH_LESS	'<'
# define CH_GREAT	'>'
# define CH_EXPAND	'$'

/**
 * Token flags. Flags are set in one int, with different bits corresponding
 * to different flags. The following flags are set if:
 * 
 * F_SQUOTE		token is in single quoted state
 * F_DQUOTE		token is in double quoted state
 * F_OPERATOR	token is redirect or pipe
 * F_SPACE		token is space
 * F_WORD		token is word
 * F_EXPAND		token contains expansion
 * F_APPEND		token is special redirect (heredoc for redir_in, 
 * 					append for redir_out)
 * F_FILENAME	token is a filename
 */
# define F_SQUOTE	1
# define F_DQUOTE	2
# define F_OPERATOR	16
# define F_SPACE	32
# define F_WORD		128
# define F_EXPAND	256
# define F_APPEND	512
# define F_FILENAME	1024

#endif
