/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:51:33 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/29 16:32:02 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static long	check_negative(int n_i, int ope_i)
{
	long	i;

	i = 0;
	if (ope_i > 1 || n_i > 1)
		i = 0;
	else if (n_i % 2 == 1)
		i = -1;
	else
		i = 1;
	return (i);
}

static int	check_l(long ans, char c, int n_i)
{
	if ((ans * 10) + (c - '0') - LONG_MAX >= 0 && n_i % 2 != 1)
		return (-1);
	else if ((ans * 10) + (c - '0') + LONG_MIN >= 0 && n_i % 2 == 1)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		n_i;
	int		ope_i;
	long	ans;

	i = 0;
	n_i = 0;
	ope_i = 0;
	ans = 0;
	while (check_isspace(str[i]) == 1)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n_i++;
		ope_i++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (check_l(ans, str[i], n_i) == -1 || check_l(ans, str[i], n_i) == 0)
			return (check_l(ans, str[i], n_i));
		ans = (ans * 10) + ((str[i++] - '0'));
	}
	return ((int)(ans * check_negative(n_i, ope_i)));
}

//#include <stdio.h>
//#include <stdlib.h>
//int main(void)
//{
//	char c1[40] = "9223372036854775810";
//	char c2[40] = "9999999999999999999";
//	char c3[40] = "9223372036854775808";
//	printf("atoi = %d, ft_atoi = %d\n", atoi(c1), ft_atoi(c1));
//	printf("atoi = %d, ft_atoi = %d\n", atoi(c2), ft_atoi(c2));
//	printf("atoi = %d, ft_atoi = %d\n", atoi(c3), ft_atoi(c3));
//}
