/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:45:17 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/18 15:49:24 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*set_int_min(void)
{
	return (ft_strdup("-2147483648"));
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
			tmp[i++] = str[len--];
	}
	else
	{
		while (i < max)
			tmp[i++] = str[(len--) - 1];
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		max;
	int		i;

	str = NULL;
	len = int_len(n);
	max = int_len(n);
	i = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == -0 || n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (set_int_min());
	else if (n < 0)
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

//test7
// #include <stdio.h>
// int main(void)
// {
// 	char	*i1 = ft_itoa(0);

// 	printf("%s\n", i1);
//	printf("i1_size = %d, idol_size = 2\n", (int)ft_strlen(i1));
// }

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
