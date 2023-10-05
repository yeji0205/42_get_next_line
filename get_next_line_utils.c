/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegipark <yegipark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:51:49 by yegpark           #+#    #+#             */
/*   Updated: 2023/10/05 12:55:58 by yegipark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *string, int c)
{
	while (*string)
	{
		if (*string == (char)c)
		{
			return ((char *)string);
		}
		string++;
	}
	if ((char)c == '\0')
	{
		return ((char *)string);
	}
	return (NULL);
}

char	*ft_substr(char *remain_str, size_t start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!remain_str)
		return (NULL);
	if (start >= ft_strlen(remain_str))
		return (NULL);
	if (len > ft_strlen(remain_str) - start)
		len = ft_strlen(remain_str) - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (sub)
	{
		while (remain_str[start + i] && (i < len))
		{
			sub[i] = remain_str[start + i];
			i++;
		}
		sub[i] = '\0';
		return (sub);
	}
	return (NULL);
}

char	*ft_substr_line(char *remain_str, size_t start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!remain_str)
		return (NULL);
	if (start >= ft_strlen(remain_str))
		return (NULL);
	if (len > ft_strlen(remain_str) - start)
		len = ft_strlen(remain_str) - start;
	sub = (char *)malloc(sizeof(char) * (len + 2));
	i = 0;
	if (sub)
	{
		while (remain_str[start + i] && (i < len))
		{
			sub[i] = remain_str[start + i];
			i++;
		}
		sub[i++] = remain_str[len];
		sub[i] = '\0';
		return (sub);
	}
	return (NULL);
}
