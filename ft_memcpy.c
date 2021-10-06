/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:43:10 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/06 16:37:32 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *buf1, const void *buf2, int n)
{
	int				i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	ptr1 = (unsigned char *)buf1;
	ptr2 = (unsigned char *)buf2;
	while (i < n)
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	return (buf1);
}
