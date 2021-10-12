/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:46:13 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/12 20:31:14 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_word_cut(char *s, int start, int i)
{
	char	*ptr;
	ptr = (char *)malloc(sizeof(char) * (i - start));
	while (i < start)
	{
		ptr[i] = s[i];
		printf("%c\n", s[i]);
		i++;
	}
	return (ptr);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	char	*tmp;
	int		i;
	int		start;

	split = (char **)malloc(sizeof(char *) * (ft_strlen(s) + 1));
	if (!split)
		return (NULL);
	i = 0;
	start = -1;
	while (i <= (int)ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if (s[i] == c)
		{
			tmp = (char *)malloc(sizeof(char) * i);
			if(!tmp)
				return (NULL);
			tmp = ft_word_cut((char *)s, start, i);
		}
		i++;
	}
	split = &tmp;
	return (split);
}

#include <stdio.h>
int main(void)
{
    char *ptr = (char *)ft_split("AAbbBBbCC", 'b');
    printf("%s\n", ptr);
}
