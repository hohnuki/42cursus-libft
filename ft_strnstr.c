/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:41:54 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/07 19:14:42 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t size)
{
	const char	*p1 = s1;
	const char	*p2 = s2;

	while (*p1 && *p2 && size >= (size_t)0)
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
