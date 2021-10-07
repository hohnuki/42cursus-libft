/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:41:23 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/07 18:51:12 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < (int)(size - 1) && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
		count++;
	}
	while (i < (int)size)
	{
		dest[i] = '\0';
		i++;
	}
	return ((size_t)count);
}
