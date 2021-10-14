/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnukihiroki <ohnukihiroki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:41:54 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/15 00:22:26 by ohnukihirok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t size)
{
	const char	*p1;
	const char	*p2;

	p1 = s1;
	p2 = s2;
	
	while (*p1 && *p2 && size >= 0)
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

#include <stdio.h>
#include <string.h>
int main(void)
{
    char* p1 = ft_strnstr( "abcdcba", "cd" , 3);
    if( p1 == NULL ){
        puts( "見つからない。" );
    }
    else{
        puts( p1 );
    }
		char* p2 = strnstr( "abcdcba", "cd" , 3);
    if( p2 == NULL ){
        puts( "見つからない。" );
    }
    else{
        puts( p2 );
    }
    return 0;
}