/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:46:13 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/21 16:50:34 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str_separate_count(const char *s, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (s[i] == c)
		{
			flag = 0;
		}
		i++;
	}
	return (count);
}

char	*str_cutter(const char	*s, int start, int end)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * (end - start + 1));
	while (start < end)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	split_loop(char **split, const char *s, char c)
{
	int	start;
	int	i;
	int	j;

	start = -1;
	i = 0;
	j = 0;
	while (i <= (int)ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == (int)ft_strlen(s)) && start >= 0)
		{
			split[j] = str_cutter(s, start, i);
			start = -1;
			j++;
		}
		i++;
	}
	split[j] = (char *) '\0';
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	start = -1;
	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (str_separate_count(s, c) + 1));
	if (!split)
		return (NULL);
	split_loop(split, s, c);
	return (split);
}
