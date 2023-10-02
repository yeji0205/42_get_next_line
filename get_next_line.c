/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegpark <yegpark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:46:27 by yegpark           #+#    #+#             */
/*   Updated: 2023/10/02 18:05:00 by yegpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**************************************************************************
 * 1. 파일에서 입력된 버퍼 사이즈 만큼 믄장을 읽는다
 * 2. 읽은 문장은 backup 배열에 저장.
 * 3. backup 배열에 \n 이 존재하면, 그 전까지 리턴
 *    backup 배열에 \n 이 존재하지 않으면, 1번부터 다시
 * 다시 함수가 콜되면 프로그램은 이 전에 읽었던 문장 뒤부터 읽어야 한다.
***************************************************************************/

char	*get_next_line(int fd)
{
	char	*buf_read;
	char	**splited;
	char	*line;
	static char	*remain_str;
	int	cnt_read_byte;
	int	test_buf_size = 10;

	// // if nothing is remained, malloc size with 1 to have EOF
	// if (!remain_str)
	// 	remain_str = ft_calloc(1, sizeof(char));
	// set up the buffer array to put the characters read
	// if its fail to open file fd = -1
	if (fd < 0 || test_buf_size <= 0)
		return (NULL);
	buf_read = ft_calloc(test_buf_size + 1, sizeof(char));
	// if there is error to create memory, return Null
	if (!buf_read)
		return (NULL);

	cnt_read_byte = 1;
	// if there is still chars to read
	// and there is no \n in the remain string
	// if there is nothing to read => its end of the text
	// if there is \n in remain string, doesn't have to join new string
	//    since it will print out first 
	while (cnt_read_byte != 0 && !ft_strchr(remain_str, '\n'))
	{
		cnt_read_byte = read(fd, buf_read, test_buf_size);
		if (cnt_read_byte == -1)
		{
			free(buf_read);
			return (NULL);
		}
		buf_read[cnt_read_byte] = '\0';
		remain_str = ft_strjoin(remain_str, buf_read);
	}
	free(buf_read);
	
	// if there is nothing to read more, then it will come here directly
	// or if there is already \n inside of remain_str 
	if (!remain_str)
		return (NULL);
	// find if \n exists in the joined sentence
	int	i = 0;
	int	len_line;
	int	len_remain;
	while (remain_str[i])
	{
		if (remain_str[i] == '\n')
		{
			splited = ft_split(remain_str, '\n');
			if (!splited)
				return (NULL);
			line = ft_strdup(splited[0]);
			if (!line)
				return (NULL);
			ft_free(splited);
			len_line = ft_strlen(line);
			len_remain = ft_strlen(remain_str);
			remain_str = ft_substr(remain_str, len_line + 1, len_remain - len_line);
		}
		i++;
	}
	return (line);
}


extern int errno;

#include <fcntl.h> // for the flag parameter of open()
#include <stdio.h>


int	main(void)
{
	int	fd1;
	char	*line;
	char	*buffer;

	// It allows you to refer to and
	// interact with the opened file throughout your program.
	// 프로세스 내에서 열려 있는 파일을 고유하게 식별하는 음수가 아닌 작은 정수를 반환
	// lowest positive number not currently opened by the calling process
	// 실패하면 -1
	fd1 = open("text/test2.txt", O_RDONLY);
	read(fd1, buffer, 10);
	printf("%s\n", buffer);

	for (int i = 0; i < 3; i++)
	{
		line = get_next_line(fd1);
		printf("%d -> %s\n", i, line);
		free(line);
	}
	close(fd1);

	// FILE	*file;
	// char buffer[100];

	// file = fopen("text/test2.txt", "r");

	// if (file == NULL){
	// 	perror("Error opening file");
	// 	return (-1);
	// }	while (fgets(buffer, sizeof(buffer), file) != NULL){
	// 	printf("%s", buffer);
	// }
	// fclose(file);

	// char *test_str = "hello, \nnice to meet you. \nI am yeji";
	// char **for_line = ft_split(test_str, '\n');
	
	// int len_line = ft_strlen(for_line[0]);
	// int len_org = ft_strlen(test_str);
	// printf("%d \n", len_line);
	// printf("%d \n", len_org);
	// test_str = ft_substr(test_str, len_line + 1, len_org - len_line);
	// printf("%s", test_str);
	// // for(int i = 0; i < 3; i++){
	// // 	printf("%d: %s \n", i, return_str[i]);
		
	// // }

	return (0);
}