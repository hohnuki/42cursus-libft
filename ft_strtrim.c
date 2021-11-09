/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:56:18 by hohnuki           #+#    #+#             */
/*   Updated: 2021/11/09 19:36:10 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_start_number(const char *str, const char *set)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(str))
	{
		if (!ft_strchr(set, str[i]))
			break ;
		i++;
	}
	return (i);
}

static int	find_end_number(const char *str, const char *set)
{
	int	str_len;

	str_len = (int)ft_strlen(str);
	while (str_len >= 0)
	{
		if (!ft_strrchr(set, str[str_len]))
			break ;
		str_len--;
	}
	return (str_len + 1);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = find_start_number(s1, set);
	end = find_end_number(s1, set);
	i = 0;
	if (end == 0 && start == ft_strlen(s1))
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	while (start < end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
