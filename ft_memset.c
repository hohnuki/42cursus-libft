/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:47:57 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/07 18:23:49 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t size)
{
	int				i;
	unsigned char	*ptr;
	unsigned char	value;

	i = 0;
	ptr = (unsigned char *)str;
	value = (unsigned char)c;
	while (i < (int)size)
	{
		ptr[i] = value;
		i++;
	}
	return (str);
}
