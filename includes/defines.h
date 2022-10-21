/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   defines.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 19:40:39 by nsterk        #+#    #+#                 */
/*   Updated: 2022/10/19 21:37:32 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

typedef enum e_ttoktype
{
	TOK_EERROR,
	TOK_CCMD,
	TOK_AARG,
	TOK_PIPE,
	TOK_MAX
}			t_ttoktype;

typedef enum e_chr_class
{
	CHR_ERROR,
	CHR_WORD,
	CHR_DIGIT,
	CHR_SPACE,
	CHR_DASH,
	CHR_AND,
	CHR_MAX
}			t_chr_class;

#endif
