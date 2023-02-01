/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:12:40 by bhielsch          #+#    #+#             */
/*   Updated: 2022/11/29 17:14:53 by bhielsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "utils/utils.h"
# include <bits/unistd_ext.h>
# include <signal.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>

void	error_mess(char *str);
void	char_to_bin(char c, int pid);
void	send_text(char *str, int pid);
void	handshake(int signal);

#endif
