/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnukihiroki <ohnukihiroki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:56:18 by hohnuki           #+#    #+#             */
/*   Updated: 2021/10/18 00:46:39 by ohnukihirok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_start_number (const char *str, const char *set)
{
	int	str_i;
	int	set_i;
	int	start;

	str_i = 0;
	set_i = 0;
	start = 0;
	while (str[str_i] != '\0')
	{
		set_i = 0;
		while (set[set_i] != '\0')
		{
			if (str[str_i] == set[set_i] || str[str_i] == ' ')
				break ;
			set_i++;
		}
		if ((set_i + 1) != (int)ft_strlen(set) && ft_isalnum(str[str_i]) == 1)
		{
			start = str_i;
			break;
		}
		else
			str_i++;
	}
	return (start);
}

int	find_end_number (const char *str, const char *set)
{
	int		set_i;
	int		end;
	int		str_max;

	set_i = 0;
	end = 0;
	str_max = (int)ft_strlen(str);
	
	while (str_max > 0)
	{
		set_i = 0;
		while (set[set_i] != '\0')
		{
			if (str[str_max - 1] == set[set_i] || str[str_max - 1] == ' ')
				break ;
			set_i++;
		}
		if ((set_i + 1) != (int)ft_strlen(set) && ft_isalnum(str[str_max - 1]) == 1)
		{
			end = str_max;
			break;
		}
		else
			str_max--;
	}
	return (end);
}
#include <stdio.h>
char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	if (!s1)
		return (NULL);
	start = find_start_number(s1, set);
	end = find_end_number(s1, set);
	// printf("start = %d\nend = %d\n", start, end);
	i = 0;
	if (!set || (end == 0 && start == 0))
	{
		str = (char *)malloc(sizeof(char) * 1);
		str[0] = '\0';
		return (str);
	}
	str = (char  *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	while (((end + 1) - start) >= 0)
	{
		str[i] = s1[start];
		// printf("str[%d] = %c\n", i,  str[i]);
		i++;
		start++;
	}
	str[i + 1] = '\0';
	// printf("str[%d] = %c\n", i, str[i]);
	return (str);
}

//test4
// #define TRIM_SET_PLACEHOLDER " \n\t"
// #include <string.h>
// #include <stdio.h>

// int main(void)
// {
// 	char	*s1 = "  \t \t \n   \n\n\n\t";
// 	char	*s2 = "";
// 	char	*ret = ft_strtrim(s1, TRIM_SET_PLACEHOLDER);
	
// 	printf("ret = %s\ns2 = %s\n", ret, s2);
// 	printf("ret = %d\ns2 = %d\n", (int)ft_strlen(ret), (int)ft_strlen(s2));
// 	if (!strcmp(s2, ret))
// 		printf("fail\n");
// }

//test2
// #define TRIM_SET_PLACEHOLDER " \n\t"
// #include <string.h>
// #include <stdio.h>

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

//test1
// #include <string.h>
// #include <stdio.h>
// #define TRIM_SET_PLACEHOLDER " \n\t"

// int main(void)
// {
// 	char	*s1 = "\t   \n\n\n  \n\n\t    Hello \t  Please\n Trim me !\t\t\t\n  \t\t\t\t  ";
// 	char	*s2 = "Hello \t  Please\n Trim me !";
// 	char	*ret = ft_strtrim(s1, TRIM_SET_PLACEHOLDER);
	
// 	printf("ret = %s\ns2 = %s\n", ret, s2);
// 	printf("ret_size = %d\n", (int)ft_strlen(ret));
// 	printf("s2_size = %d\n", (int)ft_strlen(s2));
// }