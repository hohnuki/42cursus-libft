/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:08:12 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/18 18:59:23 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	setStr_to_catDest(char *dest, const char *src)
{
	int	i;
	int	dest_len;
	int	first_dest_len;

	i = 0;
	dest_len = (int)ft_strlen(dest);
	first_dest_len = (int)ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[dest_len++] = src[i++];
	}
	dest[dest_len] = '\0';
	return (first_dest_len + (int)ft_strlen(src));
}

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	int	i;
	int	ans;
	int	dest_len;
	int	src_len;
	int	first_dest_len;

	i = 0;
	ans = 0;
	dest_len = (int)ft_strlen(dest);
	src_len = (int)ft_strlen(src);
	first_dest_len = dest_len;
	if ((int)destsize < 0)
		return ((size_t)setStr_to_catDest(dest, src));
	else if (dest_len >= (int)destsize || !destsize)
		ans = src_len + (int)destsize;
	else
		ans = dest_len + src_len;
	while (src[i] != '\0' && i < (int)destsize - first_dest_len - 1)
	{
		dest[dest_len++] = src[i++];
	}
	dest[dest_len] = '\0';
	return ((size_t)ans);
}
