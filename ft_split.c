/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:46:13 by hohnuki           #+#    #+#             */
/*   Updated: 2021/11/04 17:01:34 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*str_cutter(const char	*s, int start, int end)
{
	char	*ptr;
	int		i;
	int		len;

	i = 0;
	len = end - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static int	str_separate_count(const char *s, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] == c)
			flag = 0;
		else if (s[i] != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		i++;
	}
	return (count);
}

void	free_splitStr(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	split_loop(char **split, const char *s, char c)
{
	int	start;
	int	i;
	int	j;
	int	len;

	start = -1;
	i = 0;
	j = 0;
	len = (int)ft_strlen(s);
	while (i <= len)
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == len) && start >= 0)
		{
			split[j] = str_cutter(s, start, i);
			if (!split[j])
				return (-1);
			start = -1;
			j++;
		}
		i++;
	}
	split[j] = (char *) '\0';
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (str_separate_count(s, c) + 1));
	if (!split)
		return (NULL);
	if (split_loop(split, s, c) == -1)
		free_splitStr(split);
	return (split);
}
