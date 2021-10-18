/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:56:18 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/18 15:06:02 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_start_number(const char *str, const char *set)
{
	int	str_i;
	int	set_i;
	int	start;

	str_i = 0;
	set_i = 0;
	start = 0;
	while (str[str_i] != '\0')
	{
		set_i = 0;
		while (set[set_i] != '\0')
		{
			if (str[str_i] == set[set_i] || str[str_i] == ' ')
				break ;
			set_i++;
		}
		if ((set_i + 1) != (int)ft_strlen(set) && ft_isalnum(str[str_i]) == 1)
		{
			start = str_i;
			break ;
		}
		else
			str_i++;
	}
	return (start);
}

int	find_end_number(const char *str, const char *set)
{
	int		i;
	int		end;
	int		max;

	i = 0;
	end = 0;
	max = (int)ft_strlen(str);
	while (max > 0)
	{
		i = 0;
		while (set[i] != '\0')
		{
			if (str[max - 1] == set[i] || str[max - 1] == ' ')
				break ;
			i++;
		}
		if ((i + 1) != (int)ft_strlen(set) && ft_isalnum(str[max - 1]) == 1)
		{
			end = max;
			break ;
		}
		else
			max--;
	}
	return (end);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	if (!s1)
		return (NULL);
	start = find_start_number(s1, set);
	end = find_end_number(s1, set);
	i = 0;
	if (!set || (end == 0 && start == 0))
		return (ft_strdup("\0"));
	str = (char *)malloc(sizeof(char) * (end - start + 3));
	if (!str)
		return (NULL);
	while (((end + 1) - start) >= 0)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
