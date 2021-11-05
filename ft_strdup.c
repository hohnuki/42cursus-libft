/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:50:13 by hohnuki           #+#    #+#             */
/*   Updated: 2021/11/05 16:36:56 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *s1, const char *s2)
{
	int	count;

	count = 0;
	while (s2[count] != '\0')
	{
		s1[count] = s2[count];
		count++;
	}
	s1[count] = '\0';
	return (s1);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		num;

	num = 0;
	while (s1[num] != '\0')
		num++;
	str = (char *)malloc(sizeof(char) * (num + 1));
	if (!str)
		return (NULL);
	ft_strcpy(str, s1);
	return (str);
}
