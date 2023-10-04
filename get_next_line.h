/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegpark <yegpark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:44:58 by yegpark           #+#    #+#             */
/*   Updated: 2023/10/04 18:45:46 by yegpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h> // free(), malloc()
# include <unistd.h> // read()
# include <sys/types.h> // size_t

// 안쪽에 적용하는 이유는, 헤더파일이 읽힐 때마다 다시 버퍼사이즈가 셋업되는 것을 막기 위해서
// 안쪽에 있으니 해당 헤더파일이 한 번 정의되었으면 다시 정의가 되지 않으니 계속 셋업되지 않는다.
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, size_t start, size_t len);
char	*ft_substr_line(char const *s, size_t start, size_t len);
char	*ft_strchr(const char *string, int c);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *s);

#endif