/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnukihiroki <ohnukihiroki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:56:18 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/17 00:40:39 by ohnukihirok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	int		s1_i;
	int		set_i;
	int		str_i;
	int		start;
	int		end;
	int		s1_max;

	s1_i = 0;
	set_i = 0;
	str_i = 0;
	start = 0;
	end = 0;
	s1_max = (int)ft_strlen(s1);
	while (s1[s1_i] != '\0')
	{
		set_i = 0;
		while (set[set_i] != '\0')
		{
			if (s1[s1_i] == set[set_i] || s1[s1_i] == ' ')
				break ;
			set_i++;
		}
		if ((set_i + 1) != (int)ft_strlen(set) && ft_isalnum(s1[s1_i]) == 1)
		{
			start = s1_i;
			break;
		}
		else
			s1_i++;
	}
	s1_i = 0;
	while (s1_max > 0)
	{
		set_i = 0;
		while (set[set_i] != '\0')
		{
			if (s1[s1_max - 1] == set[set_i] || s1[s1_max - 1] == ' ')
				break ;
			set_i++;
		}
		if ((set_i + 1) != (int)ft_strlen(set) && ft_isalnum(s1[s1_max - 1]) == 1)
		{
			end = s1_max;
			break;
		}
		else
			s1_max--;
	}

	str = (char  *)malloc(sizeof(char) * (end - start));
	while (((end + 1) - start) >= 0)
	{
		str[str_i] = s1[start];
		str_i++;
		start++;
	}
	str[str_i + 1] = '\0';
	return (str);
}

//test4
#define TRIM_SET_PLACEHOLDER " \n\t"
#include <string.h>
#include <stdio.h>

int main(void)
{
	char	*s1 = "  \t \t \n   \n\n\n\t";
	char	*s2 = "";
	char	*ret = ft_strtrim(s1, TRIM_SET_PLACEHOLDER);
	
	printf("ret = %s\ns2 = %s\n", ret, s2);
	printf("ret = %d\ns2 = %d\n", (int)ft_strlen(ret), (int)ft_strlen(s2));
	if (!strcmp(s2, ret))
		printf("fail\n");
}

//test2
// #define TRIM_SET_PLACEHOLDER " \n\t"
// #include <string.h>

// int main(void)
// {
// 	char	*s1 = "  \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !";
// 	char	*s2 = "Hello \t  Please\n Trim me !";
// 	char	*ret = ft_strtrim(s1, TRIM_SET_PLACEHOLDER);
	
// 	printf("ret = %s\ns2 = %s\n", ret, s2);
// 	printf("ret = %d\ns2 = %d\n", (int)ft_strlen(ret), (int)ft_strlen(s2));
// 	if (!strcmp(s2, ret))
// 		printf("fail\n");
// }

// test1
// #define TRIM_SET_PLACEHOLDER " \n\t"
// int main(void)
// {
// 	char	*s1 = "\t   \n\n\n  \n\n\t    Hello \t  Please\n Trim me !\t\t\t\n  \t\t\t\t  ";
// 	char	*s2 = "Hello \t  Please\n Trim me !";
// 	char	*ret = ft_strtrim(s1, TRIM_SET_PLACEHOLDER);
	
// 	printf("ret = %s\ns2 = %s\n", ret, s2);
// }