/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegpark <yegpark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:46:27 by yegpark           #+#    #+#             */
/*   Updated: 2023/08/16 17:34:11 by yegpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <unistd.h>
#include <fcntl.h> // for the flag parameter of open()
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

/*******************************************
* add the readed sentence into static buffer
*******************************************/
char	*ft_stradd(char *buf, char *temp, size_t init_size)
{
	size_t	init_len_buf;
	size_t	i;

	init_len_buf = init_size;
	i = 0;
	while (temp[i])
	{
		buf[init_len_buf] = temp[i];
		i++;
		init_len_buf++;
	}
	buf[init_len_buf] = '\0';
	return (buf);
}

/*******************************************
* copy of only the part to return
*******************************************/
char	*ft_substr(char *buf, size_t len)
{
	char	*sub;
	size_t	i;

	if (!buf)
		return (NULL);
	sub = (char *)malloc(sizeof(char) * (len + 1)); 
	i = 0;
	if (sub)
	{
		while (i < len)
		{
			sub[i] = buf[i];
			i++;
		}
		sub[len] = '\0';
		return (sub);
	}
	free(sub);
	return (NULL);
}

char	*get_next_line(int fd)
{
	size_t	read_size = 6;
	size_t	init_len_buf;
	size_t	total_len;
	int	err_check;

	// 파일을 read 할 임시 버퍼. +1 to add '\0'
	char temp[read_size + 1];
	//static buffer that will store all the characters
	//and not get empty after leaving this function
	static char *buf;
	//to print out
	char *output;

	//reading from fd(txt file) amount of temp_size
	//'\0'는 버퍼에 수용할 충분한 공간이 있는 경우 read() 함수에 의해 추가됩니다
	err_check = read(fd, temp, read_size);
	// checking if there is an error
	if (err_check == -1)
		return (NULL);
	temp[read_size] = '\0';
	/************************************************
	 * put the read part from .txt into static buf
	 * we should put from behind of the buf
	************************************************/
	// length of static buf before getting added from temp 
	init_len_buf = ft_strlen(temp);
	// allocate memory adding the temp into static buf
	total_len = read_size + ft_strlen(buf);
	buf = (char *)malloc(sizeof(char) * (total_len + 1));
	if (buf)
		buf = ft_stradd(buf, temp, init_len_buf);
	
	int	len_output;
	len_output = 0;
	while (buf[len_output])
	{
		if (buf[len_output] == '\n')
		{
			output = ft_substr(buf, len_output);
			return (output);
		}
		else
		{
			get_next_line(fd);
		}
		len_output++;
	}
	free(buf);
	return (NULL);
}


extern int errno;

int	main(void)
{
	char	*test_input = "the file is open without error\n";
	int	fd1;
	char	buffer[12];

	// It allows you to refer to and 
	// interact with the opened file throughout your program.
	// 프로세스 내에서 열려 있는 파일을 고유하게 식별하는 음수가 아닌 작은 정수를 반환
	// lowest positive number not currently opened by the calling process
	// 실패하면 -1 
	fd1 = open("text/test2.txt", O_RDONLY);
	// read(fd1, buffer, 10);
	// read(fd1, buffer, 10);
	// printf("%s\n", buffer);
	printf(get_next_line(fd1));
	close(fd1);

	return (NULL);
}