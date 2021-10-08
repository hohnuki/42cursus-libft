/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:46:13 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/08 17:42:29 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**ft_split(const char *s, char c)
{
	int i;
	int ptr_i;
	int count;
	char *ptr;
	char *p;

	i = 0;
	ptr_i = 0;
	count = 0;
	ptr = NULL;
	p = NULL;

	ptr = (char *)malloc(sizeof(char ) * 10);
	p = (char *)s;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			p[i] = '\0';
			printf("%s\n", p);
			ptr[ptr_i] = p;
			printf("ptr[%d] == %c, s[count] == %c\n", ptr_i, ptr[ptr_i], s[count]);
			ptr_i++;
		}
		i++;
	}
	return ((char **)ptr);
}
