/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:00:07 by bhielsch          #+#    #+#             */
/*   Updated: 2022/10/07 16:10:30 by bhielsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		min;
	size_t	j;

	j = 0;
	i = 0;
	min = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 43 || str[i] == 45)
		if (str[i++] == 45)
			min = -1;
	while (str[i] >= 48 && str[i] <= 57)
	{
		j = j * 10 + str[i] - '0';
		i++;
	}
	return ((int)j * min);
}	

// int main()
// {
//     char str[] = "1b9101112130";
//     printf("Mine: %d\n", ft_atoi(str));
//     printf("OG:   %d\n", atoi(str));
// }
