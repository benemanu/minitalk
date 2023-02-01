/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:13:11 by bhielsch          #+#    #+#             */
/*   Updated: 2022/11/30 10:57:21 by bhielsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_to_char(int signum, siginfo_t *siginfo, void *unused)
{
	static unsigned char	c = 0xFF;
	static int				bit = 0;
	static int				pid;

	(void)unused;
	pid = siginfo->si_pid;
	if (signum == SIGUSR2)
		c ^= 0x80 >> bit;
	else if (signum == SIGUSR1)
		c |= 0x80 >> bit;
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0xFF;
	}
	usleep(300);
	if (pid == 0)
		error_mess("Pid = 0");
	if (kill(pid, SIGUSR1) == -1)
		error_mess("Signal couldt not be send");
}

int	main(void)
{
	struct sigaction	sigac;

	ft_printf("PID: %d\n", getpid());
	sigac.sa_handler = 0;
	sigac.sa_flags = SA_SIGINFO;
	sigac.sa_sigaction = bit_to_char;
	sigaction(SIGUSR2, &sigac, NULL);
	sigaction(SIGUSR1, &sigac, NULL);
	while (1)
		pause();
	return (0);
}

void	error_mess(char *str)
{
	ft_printf("\nERROR: %s\n", str);
	exit(EXIT_FAILURE);
}
