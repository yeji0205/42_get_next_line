/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegpark <yegpark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:44:58 by yegpark           #+#    #+#             */
/*   Updated: 2023/10/02 17:49:50 by yegpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, size_t start, size_t len);
char	**ft_free(char **arr);
char	*ft_strchr(const char *string, int c);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t num_block, size_t size_block);
void	*ft_memmove(void *dest, const void *src, size_t len);

#endif