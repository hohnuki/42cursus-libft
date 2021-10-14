/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:08:12 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/14 20:05:05 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (n == 0)
		return (ft_strlen(src) + ft_strlen(dst));
	while (dst[i] != '\0')
	{
		i++;
	}
	while (j < (int)(n  - (int)ft_strlen(dst) - 1) && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ft_strlen(src) + ft_strlen(dst));
}

//#include <stdio.h>

//int main(void)
//{
//	printf("%d\n", (int)ft_strlcat("abcdef", "abcdef", 10));
//}
