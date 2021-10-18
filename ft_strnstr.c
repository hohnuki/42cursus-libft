/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:41:54 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/18 19:09:23 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t size)
{
	const char	*p1;
	const char	*p2;

	p1 = s1;
	p2 = s2;
	while (*p1 && *p2 && size >= 1)
	{
		if (*p1 == *p2)
		{
			p1++;
			p2++;
		}
		else
		{
			p1 -= p2 - s2 - 1;
			p2 = s2;
		}
		size--;
	}
	if (*p2)
		return (0);
	else
		return ((char *)(p1 - (p2 - s2)));
}

//test10
//#include <stdio.h>

//int main(void)
//{
//	char haystack[30] = "aaabcabcd";

//	printf("ft_strnstr = %s\n", ft_strnstr(haystack, "abcd", 9));
//	printf("%s\n", haystack + 5);
//}

//test2
//#include <stdio.h>

//int main(void)
//{
//	char haystack[30] = "aaabcabcd";
//	char needle[10] = "aabc";
//	//char * empty = (char*)"";

//	printf("ft_strnstr = %s\n", ft_strnstr(haystack, needle, -1));
//	printf("%s\n", haystack + 1);
//}
