/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:05:07 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/07 20:27:29 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	if (start >= ft_strlen(s))
		return (str);
	str = (char *)malloc(sizeof(char) * (len - (size_t)start));
	if (!(str))
		return (0);
	while (len-- && len >= 0)
	{
		str[i] = s[start - 1];
		i++;
		start++;
	}
	return (str);
}
