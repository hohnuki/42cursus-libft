/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:45:28 by hohnuki           #+#    #+#             */
/*   Updated: 2021/11/08 14:37:05 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*ptr;
	size_t	i;

	if (!n || !size)
		return (malloc(0));
	ptr = (char *)malloc(size * n);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (size * n))
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}
