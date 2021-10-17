/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnukihiroki <ohnukihiroki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:45:17 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/18 00:36:06 by ohnukihirok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *set_int_min(char *str)
{
	str = (char *)malloc(sizeof(char) * 13);
	str= "-2147483648\0";
	return (str);
}

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
	tmp[i] = '\0';
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
	if (n == -0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	else if (n == -2147483648)
	{
		return (set_int_min(str));
	}
	else if (n < 0)
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

//test4
// #include <stdio.h>
// int main(void)
// {
// 	char	*i1 = ft_itoa(-2147483648);
	
// 	printf("%s\n", i1);
// }

//test1
// #include <stdio.h>
// int main(void)
// {
// 	char	*i1 = ft_itoa(-623);
// 	char	*i2 = ft_itoa(156);
// 	char	*i3 = ft_itoa(-0);

// 	printf("%s\n", i1);
// 	printf("%s\n", i2);
// 	printf("%s\n", i3);
// }