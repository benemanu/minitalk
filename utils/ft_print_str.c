/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:41:20 by bhielsch          #+#    #+#             */
/*   Updated: 2022/10/20 10:41:45 by bhielsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_print_str(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

// int main()
// {
//     char str[] = "-1241234123";
//     int i = ft_print_str(str);
//     write (1, "\n", 1);
//     printf("Mine :%d\n", i);
//     printf("\nOG:   %d", printf("%s", str));
// }
