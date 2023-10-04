/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegpark <yegpark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:51:49 by yegpark           #+#    #+#             */
/*   Updated: 2023/10/04 18:46:06 by yegpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
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

char	*ft_strdup(const char *str)
{
	char	*copy_str;
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	copy_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy_str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		copy_str[i] = str[i];
		i++;
	}
	copy_str[i] = '\0';
	return (copy_str);
}

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (sub)
	{
		while (s[start + i] && (i < len))
		{
			sub[i] = s[start + i];
			i++;
		}
		sub[i] = '\0';
		return (sub);
	}
	return (NULL);
}

char	*ft_substr_line(char const *s, size_t start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc(sizeof(char) * (len + 2));
	i = 0;
	if (sub)
	{
		while (s[start + i] && (i < len))
		{
			sub[i] = s[start + i];
			i++;
		}
		sub[i] = '\n';
		sub[++i] = '\0';
		return (sub);
	}
	return (NULL);
}

