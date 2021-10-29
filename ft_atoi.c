/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:51:33 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/29 15:48:24 by hohnuki          ###   ########.fr       */
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

static long	convert_to_negative(long ans, int n_i, int p_i)
{
	if (p_i > 1 || n_i > 1 || (p_i + n_i) > 1)
		ans = 0;
	else if (n_i % 2 == 1)
		ans *= -1;
	return (ans);
}

static int	check_longMaxMin(long ans, char c, int n_i)
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
	int		p_i;
	long	ans;

	i = 0;
	n_i = 0;
	p_i = 0;
	ans = 0;
	while (check_isspace(str[i]) == 1)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n_i++;
		if (str[i] == '+')
			p_i++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (check_longMaxMin(ans, str[i], n_i) == -1)
			return ((int)LONG_MAX);
		else if (check_longMaxMin(ans, str[i], n_i) == 0)
			return ((int)LONG_MIN);
		ans = (ans * 10) + ((str[i++] - '0'));
	}
	ans = convert_to_negative(ans, n_i, p_i);
	return ((int)ans);
}
