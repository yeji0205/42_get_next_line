/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegipark <yegipark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:51:49 by yegpark           #+#    #+#             */
/*   Updated: 2023/10/03 17:45:22 by yegipark         ###   ########.fr       */
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

static void	ft_bzero(void *dest, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)dest)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t num_block, size_t size_block)
{
	void	*ptr;

	ptr = malloc(num_block * size_block);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, num_block * size_block);
	return (ptr);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	char	*joined;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	joined = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (joined)
	{
		while (i < ft_strlen(s1))
		{
			joined[i] = s1[i];
			i++;
		}
		while (i < len)
		{
			joined[i] = s2[i - ft_strlen(s1)];
			i++;
		}
		joined[i] = '\0';
		return (joined);
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
		return (0);
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
		return (0);
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
		return (0);
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




// static size_t	ft_cnt_wrd(const char *s, char c)
// {
// 	size_t	count;

// 	count = 0;
// 	while (*s)
// 	{
// 		if (*s != c)
// 		{
// 			count++;   // 1
// 			while (*s && *s != c)  // if its not c
// 			s++;             // go next memory
// 		}       // looping getting out when c found in the string
// 		else
// 			s++;
// 	}
// 	return (count);
// }

// static char	*ft_extract_word(char const *s, char c)
// {
// 	size_t	word_len;
// 	char	*ptr;

// 	word_len = 0;
// 	while (s[word_len] && s[word_len] != c)
// 			word_len++;
// 	ptr = ft_substr(s, 0, word_len);
// 	return (ptr);
// }

// // Free the memory if array memory allocation fails
// char	**ft_free(char **arr)
// {
// 	size_t	i;

// 	i = 0;
// 	while (arr[i])
// 	{
// 		free(arr[i]);
// 		i++;
// 	}
// 	free(arr);
// 	return (NULL);
// }


// /*******************************************
// * split the sentence to "output" & "remain"
// *******************************************/

// char	**ft_split(char const *s, char c)
// {
// 	size_t	res_i;
// 	char	**res;

// 	if (!s)
// 		return (0);
// 	res = (char **)malloc(sizeof(char *) * (ft_cnt_wrd(s, c) + 1));
// 	if (!res)
// 		return (0);
// 	res_i = 0;
// 	while (*s)
// 	{
// 		if (*s != c)
// 		{
// 			res[res_i] = ft_extract_word(s, c);
// 			if(!res[res_i])
// 				return (ft_free(res));
// 			res_i++;
// 			while (*s && *s != c)
// 				s++;
// 		}
// 		else
// 			s++;
// 	}
// 	res[res_i] = 0;
// 	return (res);
// }