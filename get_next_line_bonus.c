/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegipark <yegipark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 01:50:29 by yegipark          #+#    #+#             */
/*   Updated: 2023/10/04 02:38:06 by yegipark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**************************************************************************
 * get_next_line() using only one static variable.
 * can manage multiple file descriptors at the same time.
 *	e.g It means that you should be able to call get_next_line()
 	to read from fd 3, then fd 4, then 5, then once again 3, once again 4, and so forth.
 *
***************************************************************************/

#include "get_next_line_bonus.h"

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
		read_str[read_byte_num] = '\0';
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
	remain_str = ft_check_read(remain_str, fd);
	if (!remain_str)
		return (NULL);
	output_str = ft_get_output(remain_str);
	remain_str = ft_update_remain(remain_str);
	return (output_str);
}



#include <fcntl.h> // for the flag parameter of open()
#include <stdio.h>

int	main(void)
{
	char	*line;
	int	fd1;
	int	fd2;
	int	fd3;

	fd1 = open("text/3lines.txt", O_RDONLY);
	fd2 = open("text/4lines_1empty.txt", O_RDONLY);
	fd3 = open("text/empty.txt", O_RDONLY);

	for (int i = 0; i < 4; i++)
	{
		line = get_next_line(fd1);
		printf("%d -> %s", i, line);
		free(line);

		line = get_next_line(fd2);
		printf("%d -> %s", i, line);
		free(line);

		line = get_next_line(fd3);
		printf("%d -> %s", i, line);
		free(line);
	}
	close(fd1);
	close(fd2);
	close(fd3);

	return (0);
}