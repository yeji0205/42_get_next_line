/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegipark <yegipark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:44:58 by yegpark           #+#    #+#             */
/*   Updated: 2023/10/04 02:27:45 by yegipark         ###   ########.fr       */
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
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, size_t start, size_t len);
char	*ft_substr_line(char const *s, size_t start, size_t len);
char	*ft_strchr(const char *string, int c);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t num_block, size_t size_block);

#endif