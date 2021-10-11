/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:46:13 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/11 20:54:00 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(const char *s, char c)
{
	int	start;
	char	**split;
	char	*tmp;
	unsigned int	i;
	unsigned int	j;

	split = ft_calloc(sizeof(char *), ft_strlen(s) + 1);
	if (!split)
		return (NULL);
	start = -1;
	i = 0;
	j = 0;
	while (i++ <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			tmp = ft_word_cut(s, start, i);
			if (!tmp)
				return (ft_freeall(split));
			split[j++] = tmp;
			start = -1;
		}
	}
	return (split);
}
