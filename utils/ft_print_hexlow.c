/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexlow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:30:29 by bhielsch          #+#    #+#             */
/*   Updated: 2022/10/20 10:31:51 by bhielsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	ft_putchar(char c);

int	ft_print_hexlow(unsigned int nb, int count)
{
	int	i;

	i = count;
	if (nb >= 16)
	{
		i++;
		i = ft_print_hexlow(nb / 16, i);
		nb = nb % 16;
	}
	if (nb < 10)
	{
		ft_putchar(nb + 48);
	}
	else
	{
		ft_putchar(nb + 87);
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
//     printf("\nLen:%d\n", ft_print_hexlow(nb, i));
// }
