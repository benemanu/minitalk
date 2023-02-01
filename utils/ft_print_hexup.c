/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:32:07 by bhielsch          #+#    #+#             */
/*   Updated: 2022/10/20 10:33:13 by bhielsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	ft_putchar(char c);

int	ft_print_hexup(unsigned int nb, int count)
{
	int	i;

	i = count;
	if (nb >= 16)
	{
		i++;
		i = ft_print_hexup(nb / 16, i);
		nb = nb % 16;
	}
	if (nb < 10)
	{
		ft_putchar(nb + 48);
	}
	else
	{
		ft_putchar(nb + 55);
	}
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// int main()
// {
//     int i = 1;
//     int nb = 4294967295;
//     printf("\nLen:%d\n", ft_print_hexup(nb, i));
// }
