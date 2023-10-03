/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegipark <yegipark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:46:27 by yegpark           #+#    #+#             */
/*   Updated: 2023/10/03 23:56:55 by yegipark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**************************************************************************
 * * One line at a time
 * * if there is nothing to read or error occurred => NULL
 * * working reading a file & reading from a standard input
 * * returned line should have \n + \0
 *
 * - ft_check_case():
 * 	check if remain_str has already \n -> then no need to read -> ft_get_output()
 * 	check if remain_str + read_str has \n -> if not, keep reading(while loop)
 * 	check if there is nothing to read -> keep current remain_str -> ft_get_output()
 * - ft_get_output(): extract the output string (finding \n)
 * - ft_update_remain(): update remain_str (deleting output string)
 *
***************************************************************************/

char	*ft_get_output(char *remain_str)
{
	size_t	i;
	char	*output_str;

	if (!remain_str)
		return (NULL);
	i = 0;
	// looping until we find '\n' and increase index
	while (remain_str[i] && remain_str[i] != '\n')
		i++;
	output_str = ft_substr_line(remain_str, 0, i);
	if (!output_str)
		return (NULL);
	return (output_str);
}

char	*ft_update_remain(char *remain_str)
{
	size_t	i;
	size_t	len;
	char	*renew_str;

	if (!remain_str)
		return (NULL);
	i = 0;
	// looping until we find '\n' and increase index
	while (remain_str[i] && remain_str[i] != '\n')
		i++;
	len = ft_strlen(remain_str) - (++i);
	renew_str = ft_substr(remain_str, i, len);
	if (!renew_str)
		return (NULL);
	return (renew_str);
}

char	*ft_check_read(char *remain_str, int fd)
{
	char	*read_str;
	int	read_byte_num;

	read_str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	// if there is error to create memory, return Null
	if (!read_str)
		return (NULL);
	// case check and keep reading if there is no \n in current remain_str
	// to keep read the txt, read() should be inside of loop
	// and to start the loop, we set up the variable 1
	if (!remain_str)
		remain_str = ft_calloc(1, 1);
	read_byte_num = 1;
	while (!ft_strchr(remain_str, '\n') && read_byte_num != 0)
	{
		read_byte_num = read(fd, read_str, BUFFER_SIZE);
		if (read_byte_num == -1)
		{
			free(read_str);
			return (NULL);
		}
		read_str[read_byte_num] = '\0';  // have to add at the end so that we can treat it as string, otherwise functions that process strings might continue reading past the intended end of the string.
		remain_str = ft_strjoin(remain_str, read_str);
	}
	free(read_str);
	return (remain_str);
}

char	*get_next_line(int fd)
{

	char	*output_str;
	static char	*remain_str;

	// if its fail to open file fd = -1
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// if there is nothing to read more, then it will come here directly
	// or if there is already \n inside of remain_str
	remain_str = ft_check_read(remain_str, fd);
	if (!remain_str)
		return (NULL);
	// finding a line will get return
	output_str = ft_get_output(remain_str);
	// deleting the ouput line from remain_str
	remain_str = ft_update_remain(remain_str);
	return (output_str);
}



#include <fcntl.h> // for the flag parameter of open()
#include <stdio.h>

int	main(void)
{
	int	fd1;
	char	*line;

	// It allows you to refer to and
	// interact with the opened file throughout your program.
	// 프로세스 내에서 열려 있는 파일을 고유하게 식별하는 음수가 아닌 작은 정수를 반환
	// lowest positive number not currently opened by the calling process
	// 실패하면 -1

	// 3 LINES TEXT
	fd1 = open("text/test_3lines.txt", O_RDONLY);

	for (int i = 0; i < 4; i++)
	{
		line = get_next_line(fd1);
		printf("%d -> %s", i, line);
		free(line);
	}
	close(fd1);

	// // 3 LINES + 1 EMPTY LINE
	// // fd1 = open("text/test_3lines_1empty.txt", O_RDONLY);

	// // for (int i = 0; i < 4; i++)
	// // {
	// // 	line = get_next_line(fd1);
	// // 	printf("%d, %s", i, line);
	// // 	free(line);
	// // }
	// // close(fd1);

	// // EMPTY TEXT
	// fd1 = 0;

	// line = get_next_line(fd1);
	// printf("%s", line);
	// free(line);

	// close(fd1);

	return (0);
}