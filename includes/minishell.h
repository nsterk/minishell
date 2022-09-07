/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: arthurbeznik <arthurbeznik@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 15:05:45 by arthurbezni   #+#    #+#                 */
/*   Updated: 2022/09/07 15:07:17 by arthurbezni   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h> // EXIT_
# include <stddef.h> // size_t
# include <stdio.h> // printf


// Main functions.
int				main(int argc, char **argv);

// Utils.
int				error_msg(char *msg);
int				success_msg(char *msg);
void			error_exit(void);
int				ft_atoi(const char *str);
long long		ft_atoll(const char *str);
int				ft_isdigit(int c);
int				ft_isspace(int c);
char			**ft_split(char const *s, char c);
size_t			ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);

#endif