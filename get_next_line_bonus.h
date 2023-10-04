/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegipark <yegipark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 01:50:23 by yegipark          #+#    #+#             */
/*   Updated: 2023/10/04 02:27:26 by yegipark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h> // free(), malloc()
# include <unistd.h> // read()
# include <sys/types.h> // size_t

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, size_t start, size_t len);
char	*ft_substr_line(char const *s, size_t start, size_t len);
char	*ft_strchr(const char *string, int c);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t num_block, size_t size_block);

#endif