/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:51:33 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/15 19:36:23 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nagative_count;
	int	ans;

	i = 0;
	nagative_count = 0;
	ans = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			nagative_count++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		ans = (ans * 10) + ((str[i++] - '0'));
	if (nagative_count % 2 == 1)
		ans *= -1;
	return (ans);
}
