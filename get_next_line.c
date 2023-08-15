/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegpark <yegpark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:46:27 by yegpark           #+#    #+#             */
/*   Updated: 2023/08/15 18:02:32 by yegpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <unistd.h>
#include <fcntl.h> // for the flag parameter of open()
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char	*ft_stradd(char const *s1, char const *s2, size_t init_size)
{
	//size_t	len;
	size_t	i;

	// len = ft_strlen(s1) + ft_strlen(s2);
	i = init_size;
	if (s1)
	{
		// while (i < ft_strlen(s1))
		// {
		// 	joined[i] = s1[i];
		// 	i++;
		// }
		while (i < len)
		{
			s1[i] = s2[i - ft_strlen(s1)];
			i++;
		}
		s1[i] = 0;
		return (s1);
	}
	return (0);

}

char	*get_next_line(int fd)
{
	size_t	temp_size = 6;
	size_t	init_len_buf;
	size_t	total_len;
	
	// 파일을 read 할 임시 버퍼.
	char temp[temp_size];
	// 
	static char *buf;

	read(fd, temp, temp_size);

	// now add the temp char behind of the existing char in buf 
	init_len_buf = ft_stradd(buf);
	total_len = temp_size + ft_strlen(buf);
	buf = (char *)malloc(sizeof(char) * (total_len + 1));

	// buffer has already enough memory allocation
	ft_stradd(buf, temp, init_len_buf);
	
}





extern int errno;

int	main(void)
{
	char	*line = "the file is open without error\n";
	//int	i;
	int	fd1;

	//  It allows you to refer to and 
	// interact with the opened file throughout your program.
	// 프로세스 내에서 열려 있는 파일을 고유하게 식별하는 음수가 아닌 작은 정수를 반환
	// 실패하면 -1 
	fd1 = open("text/test2.txt", O_RDONLY);

	get_next_line(fd1);

	return 0;
}