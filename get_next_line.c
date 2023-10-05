/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegipark <yegipark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:46:27 by yegpark           #+#    #+#             */
/*   Updated: 2023/10/05 12:59:33 by yegipark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_update_remain(char *remain_str)
{
	size_t	i;
	size_t	len;
	char	*renew_str;

	if (!remain_str)
		return (NULL);
	i = 0;
	while (remain_str[i] && remain_str[i] != '\n')
		i++;
	len = ft_strlen(remain_str) - (++i);
	renew_str = ft_substr(remain_str, i, len);
	free(remain_str);
	if (!renew_str)
		return (NULL);
	return (renew_str);
}

char	*ft_get_output(char *remain_str)
{
	size_t	i;
	char	*output_str;

	if (!remain_str)
		return (NULL);
	i = 0;
	while (remain_str[i] && remain_str[i] != '\n')
		i++;
	output_str = ft_substr_line(remain_str, 0, i);
	if (!output_str)
		return (NULL);
	return (output_str);
}

char	*ft_strjoin(char *remain_str, char *read_str)
{
	size_t	i;
	size_t	j;
	char	*joined;

	if (!read_str || !remain_str)
		return (NULL);
	joined = (char *)malloc(sizeof(char) * (ft_strlen(remain_str) + ft_strlen(read_str) + 1));
	if (!joined)
		return (NULL);
	i = 0;
	while (remain_str[i] != '\0')
	{
		joined[i] = remain_str[i];
		i++;
	}
	j = 0;
	while (read_str[j] != '\0')
		joined[i++] = read_str[j++];
	joined[i] = '\0';
	free(remain_str);
	return (joined);
}

char	*ft_check_read(char *remain_str, int fd)
{
	char	*read_str;
	int	read_byte_num;

	read_str = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!read_str)
		return (NULL);
	read_byte_num = 1;
	while (!ft_strchr(remain_str, '\n') && read_byte_num != 0)
	{
		read_byte_num = read(fd, read_str, BUFFER_SIZE);
		if (read_byte_num == -1)
		{
			free(remain_str);
			free(read_str);
			read_str = NULL;
			return (NULL);
		}
		read_str[read_byte_num] = '\0';
		remain_str = ft_strjoin(remain_str, read_str);
	}
	free(read_str);
	read_str = NULL;
	return (remain_str);
}

char	*get_next_line(int fd)
{
	char	*output_str;
	static char	*remain_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!remain_str)
	{
		remain_str = (char *)malloc(sizeof(char) * 1);
		if (!remain_str)
			return (NULL);
		remain_str[0] = '\0';
	}
	remain_str = ft_check_read(remain_str, fd);
	if (!remain_str)
		return (NULL);
	output_str = ft_get_output(remain_str);
	if (!output_str || ft_strlen(output_str) == 0)
	{
		free(remain_str);
		free(output_str);
		remain_str = NULL;
		return (NULL);
	}
	remain_str = ft_update_remain(remain_str);
	return (output_str);
}

// #include <fcntl.h> // for the flag parameter of open()
// #include <stdio.h>

// int	main(void)
// {
// 	int	fd1;
// 	char	*line;

// 	// It allows you to refer to and
// 	// interact with the opened file throughout your program.
// 	// 프로세스 내에서 열려 있는 파일을 고유하게 식별하는 음수가 아닌 작은 정수를 반환
// 	// lowest positive number not currently opened by the calling process
// 	// 실패하면 -1

// 	// 3 LINES TEXT
// 	fd1 = open("test.txt", O_RDONLY);

// 	for (int i = 0; i < 4; i++)
// 	{
// 		line = get_next_line(fd1);
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd1);

// 	return (0);
// }