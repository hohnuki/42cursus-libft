/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnukihiroki <ohnukihiroki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:45:17 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/20 18:15:11 by ohnukihirok      ###   ########.fr       */
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

char	*reverse_str(char *str, int max)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = max;
	if (str[0] != '-')
	{
		while (i < (j / 2))
		{
			tmp = str[i];
			str[i] = str[max - 1];
			str[max - 1] = tmp;
			i++;
			max--;
		}
	}
	else
	{
		while (i < (j / 2))
		{
			tmp = str[i + 1];
			str[i + 1] = str[max];
			str[max] = tmp;
			i++;
			max--;
		}
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		max;
	int		i;

	len = int_len(n);
	max = int_len(n);
	i = 0;
	if (n == -0 || n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[i++] = '-';
		n *= -1;
	}
	while (len > 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	str[i] = '\0';
	return (reverse_str(str, max));
}
