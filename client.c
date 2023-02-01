/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:12:28 by bhielsch          #+#    #+#             */
/*   Updated: 2022/11/29 17:14:10 by bhielsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_receive;

void	handshake(int signal)
{
	if (signal == SIGUSR1)
		g_receive = 1;
	else
	{
		ft_printf("R: %d\n", g_receive);
		exit(0);
	}
}

void	send_text(char *str, int pid)
{
	static int	i = 0;

	while (str[i])
		char_to_bin(str[i++], pid);
	exit(0);
}

void	char_to_bin(char c, int pid)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (g_receive == 1)
		{
			if (c >> bit & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit--;
			g_receive = 0;
		}
	}
}

int	main(int argc, char **argv)
{
	g_receive = 1;
	if (ft_atoi(argv[1]) < 0)
		error_mess("Pid < 0");
	if (argc != 3)
		error_mess(": WRONG AMOUNT OF ARGUMENTS!");
	signal(SIGUSR1, handshake);
	send_text(argv[2], ft_atoi(argv[1]));
	return (0);
}

void	error_mess(char *str)
{
	ft_printf("\nERROR: %s\n", str);
	exit(EXIT_FAILURE);
}
