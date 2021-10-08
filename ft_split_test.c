/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:21:04 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/08 17:38:54 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	isDelimiter(char p, char delim)
{
	return (p == delim);
}

int	ft_split(char *dst[], char *src, char delim)
{
	int	count;

	count = 0;
	while (1)
	{
		while (isDelimiter(*src, delim))
		{
			src++;
		}
		if (*src == '\0')
			break;
		dst[count++] = src;
		while (*src && !isDelimiter(*src, delim))
		{
		src++;
		}
		if (*src == '\0')
			break;
		*src++ = '\0';
	}
	return (count);
}

int	main(void)
{
	char *ptr[100];
	int count;

	count = ft_split(ptr, "AAbBBbCC", 'b');

	for(int i = 0; i < count; i++)
	{
		printf("%s\n", ptr[i]);
	}
}
