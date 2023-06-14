
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
 * to different flags.
 * 
 * F_SQUOTE		set if token is in single quoted state
 * F_DQUOTE		set if token is in double quoted state
 * F_EXPAND		set if token contains expansion
 * F_APPEND		special redirection (heredoc for redir_in, append for redir_out)
 */

# define F_SQUOTE	1
# define F_DQUOTE	2
# define F_OPERATOR	16
# define F_SPACE	32
# define F_WORD		128
# define F_EXPAND	256
# define F_APPEND	512

#endif
