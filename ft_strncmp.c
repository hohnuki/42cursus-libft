/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:38:34 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/07 19:04:54 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && i < (int)n)
	{
		i++;
	}
	if (i == (int)n)
		return (0);
	else
		return (s1[i] - s2[i]);
}
