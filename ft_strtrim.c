/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:56:18 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/08 16:51:46 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	int		s1_i;
	int		set_i;
	int		str_i;

	str = (char *)malloc(sizeof(char) * ft_strlen(s1));
	if (str == NULL)
		return (0);
	s1_i = 0;
	str_i = 0;
	while (s1[s1_i] != '\0')
	{
		set_i = 0;
		while (set[set_i] != '\0')
		{
			if (set[set_i] == s1[s1_i])
				break ;
			set_i++;
		}
		if (set[set_i] == '\0')
			str[str_i++] = s1[s1_i];
		s1_i++;
	}
	return (str);
}
