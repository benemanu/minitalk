/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:33:34 by bhielsch          #+#    #+#             */
/*   Updated: 2022/10/20 10:35:53 by bhielsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_print_percentage(char c);

static int	ft_type(va_list args, const char type);

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_type(args, str[i]);
		}
		else
			len += ft_print_c(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

int	ft_type(va_list args, const char type)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += ft_print_c(va_arg(args, int));
	else if (type == '%')
		len += ft_print_percentage('%');
	else if (type == 'x')
		len += ft_print_hexlow(va_arg(args, unsigned int), 1);
	else if (type == 'X')
		len += ft_print_hexup(va_arg(args, unsigned int), 1);
	else if (type == 'i' || type == 'd')
		len += ft_print_int(va_arg(args, int), 1);
	else if (type == 'p')
		len += ft_print_p(va_arg(args, void *));
	else if (type == 'u')
		len += ft_print_u(va_arg(args, unsigned int));
	else if (type == 's')
		len += ft_print_str(va_arg(args, char *));
	return (len);
}

int	ft_print_percentage(char c)
{
	write(1, &c, 1);
	return (1);
}
// int main()
// {
//     int nb = 4294967294;
// 	void *ptr = &nb;
// 	ft_printf("Mine:%p", ptr);
//     printf("\nOG:  %p", ptr);
// }