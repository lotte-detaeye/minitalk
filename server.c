/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:13:47 by lde-taey          #+#    #+#             */
/*   Updated: 2024/04/28 17:31:56 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	powoftwo(int counter)
{
	int	result;

	result = 1;
	if (counter == 0)
		return (1);
	while (counter != 0)
	{
		result = result * 2;
		counter--;
	}
	return (result);
}

void	signal_handler(int signbr)
{
	static int	counter = 0;
	static int	c = 0;

	if (signbr == SIGUSR1)
		c = c + 0;
	else if (signbr == SIGUSR2)
		c = c + powoftwo(7 - counter);
	counter++;
	if (counter == 8)
	{
		if (c == 0)
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(c, 1);
		counter = 0;
		c = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	signal_act;

	pid = getpid();
	ft_printf("Server has started running.\n", 1);
	ft_printf("This is the server's PID: %d\n", pid);
	sigemptyset(&signal_act.sa_mask);
	signal_act.sa_handler = signal_handler;
	signal_act.sa_flags = 0;
	while (1)
	{
		sigaction(SIGUSR1, &signal_act, NULL);
		sigaction(SIGUSR2, &signal_act, NULL);
	}
	return (0);
}
