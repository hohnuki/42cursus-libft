/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:42:53 by hohnuki           #+#    #+#             */
/*   Updated: 2021/11/05 16:25:30 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	split_loop_check(const char *s, char c, int i)
{
	while (s[i] == c && i != (int)ft_strlen(s))
		i++;
	return (i);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
