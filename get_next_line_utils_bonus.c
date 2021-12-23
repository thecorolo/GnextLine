/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinbi- <azinbi-@sudent.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:48:37 by azinbi-           #+#    #+#             */
/*   Updated: 2021/12/23 21:36:48 by azinbi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *str)
{
	if (str)
		free(str);
	str = NULL;
	return (str);
}

size_t ft_strlen( const char *s1)
{
	int i;

	i = 0;
	while(s1[i])
	{
		i++;
	}
	return (i);
}

int ft_strchr(const char *s1, char c)
{
	int i;
	i = 0;

	if(!s1)
	return (-1);

	if(s1[i] == '\0' || (char)c == '\0')
	return (-1);
	while(s1[i])
	{

		if (s1[i] == (char)c)
		{
			return i;
		}
		i++;
	}
	return (-1);
}

int	count_char(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	str_len;
	int		diff;

	size = 0;
	str_len = ft_strlen(s);
	if (start > str_len)
		return (1);
	diff = len - start;
	while (s[start] && size < len)
	{
		size++;
		start++;
	}
	return (size + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	str = malloc(sizeof(char) * count_char(s, start, len));
	if (str == NULL)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

char *ft_strdup(const char *s1)
{
	char *copy;
	int i;

	i = 0;

	copy = malloc(sizeof(char) * ft_strlen(s1) + 1);
	while(s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

char *ft_strjoin(const char *s1, const char *s2)
{
	int i;
	int j;

	char *str;

	i = 0;
	j = 0;

	if(!s1)
		return ft_strdup((char *)s2);

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));

	while(s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while(s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
} 
