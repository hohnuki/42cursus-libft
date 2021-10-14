/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:20:32 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/14 17:34:56 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t size)
{
	int				i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (i < (int)size)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>

int main(void)
{
    char s1[] = "abc\0de";
    char s2[] = "ab\0c";
    char s3[] = "abcdef";

    printf( "%d\n", ft_memcmp(s1, s1, sizeof(s1)) );
    printf( "%d\n", ft_memcmp(s1, s2, sizeof(s1)) );
    printf( "%d\n", ft_memcmp(s1, s3, sizeof(s1)) );

    return 0;
}
