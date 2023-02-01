/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:24:03 by bhielsch          #+#    #+#             */
/*   Updated: 2022/10/20 10:26:28 by bhielsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	ft_inputcheck(unsigned int nb, unsigned int size);

static int	ft_count(unsigned int nb);

int	ft_print_u(unsigned int nb)
{
	unsigned int	size;

	size = ft_count(nb);
	ft_inputcheck(nb, size);
	return (ft_count(nb));
}

int	ft_count(unsigned int nb)
{
	unsigned int	temp;
	unsigned int	count;

	temp = nb;
	count = 0;
	while (temp != 0)
	{
		temp = temp / 10;
		count++;
	}
	if (nb == 0)
		return (1);
	return (count);
}

void	ft_inputcheck(unsigned int nb, unsigned int size)
{
	unsigned int	x;
	char			arr[10];

	x = 0;
	while (x < size)
	{
		arr[x] = nb % 10 + '0';
		nb = nb / 10;
		x++;
	}
	while (x > 0)
	{
		write (1, &arr[x - 1], 1);
		x--;
	}
}

// int main()
// {
//     unsigned int i = 0;
//     i = ft_print_int(i);
//     printf("\n%d", i);
// }
