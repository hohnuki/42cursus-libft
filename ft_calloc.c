/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:45:28 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/07 19:16:15 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*ptr;
	int		i;

	ptr = (char *)malloc(size * n);
	i = 0;
	while (i < (int)(size * n))
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}
