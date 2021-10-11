/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:45:17 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/11 14:26:16 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	int_len(int n)
{
	int	i;
	int	len_count;

	i = 0;
	len_count = 0;
	while (n)
	{
		n /= 10;
		len_count++;
	}
	return (len_count);
}

char	*reverse_str(char *str, int len)
{
	int		i;
	int		max;
	char	*tmp;

	i = 0;
	max = len;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (str[i] == '-')
	{
		tmp[i] = str[i];
		i++;
		while (i < max + 1)
		{
			tmp[i++] = str[len--];
		}
	}
	else
	{
		while (i < max)
		{
			tmp[i++] = str[len - 1];
			len--;
		}
	}
	return (tmp);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		len;
	int		max;

	str = NULL;
	i = 0;
	len = int_len(n);
	max = int_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (n < 0)
	{
		str[i] = '-';
		n *= -1;
		i++;
	}
	while (len > 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i++;
		len--;
	}
	return (reverse_str(str, max));
}
