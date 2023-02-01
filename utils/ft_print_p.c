/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:37:55 by bhielsch          #+#    #+#             */
/*   Updated: 2022/10/20 13:55:59 by bhielsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	ft_putchar(char c);

static int	ft_print_hexlowp(unsigned long nb, int count);

int	ft_print_p(void *ptr)
{
	unsigned long	size;
	unsigned long	i;

	i = (unsigned long) ptr;
	if (i == 0)
		return (write (1, "(nil)", 5));
	write (1, "0x", 2);
	size = ft_print_hexlowp(i, 1);
	return (size + 2);
}

int	ft_print_hexlowp(unsigned long nb, int count)
{
	int	i;

	i = count;
	if (nb >= 16)
	{
		i++;
		i = ft_print_hexlowp(nb / 16, i);
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
// 	int nb = -1;
// 	void *ptr = &nb;
// 	ft_print_p(ptr);
// }
