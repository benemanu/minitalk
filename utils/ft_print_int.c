/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:36:18 by bhielsch          #+#    #+#             */
/*   Updated: 2022/10/20 11:56:20 by bhielsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	ft_putchar(char c);

int	ft_print_int(long long int nb, int count)
{
	int	i;

	i = count;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
		i++;
	}
	if (nb >= 10)
	{
		i++;
		i = ft_print_int(nb / 10, i);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48);
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// int main()
// {
//     int i = 0;
//     i = ft_print_int(-2147483647, 1);
//     write (1, "\n", 1);
//     printf("%d", i);
// }
