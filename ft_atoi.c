/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:51:33 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/19 21:49:20 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	n_count;
	int	p_count;
	int	ans;

	i = 0;
	n_count = 0;
	p_count = 0;
	ans = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n_count++;
		if (str[i] == '+')
			p_count++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		ans = (ans * 10) + ((str[i++] - '0'));
	if (p_count > 1 || n_count > 1 || (p_count + n_count) > 1)
		ans = 0;
	else if (n_count % 2 == 1)
		ans *= -1;
	return (ans);
}
