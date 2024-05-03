/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:13:43 by lde-taey          #+#    #+#             */
/*   Updated: 2024/04/28 17:36:54 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	checkargs(char *argv1, char *argv2)
{
	int	i;

	i = 0;
	while (argv1[i] != '\0')
	{
		if (!ft_isdigit(argv1[i]))
		{
			ft_printf("Error. No valid PID.\n");
			return (0);
		}
		i++;
	}
	if (argv1[0] == 0)
	{
		ft_printf("Error. No valid PID.\n");
		return (0);
	}
	if (argv2[0] == 0)
	{
		ft_printf("Error. You forgot to enter a message.\n");
		return (0);
	}
	return (1);
}

void	ft_encrypt(int serverid, char *message)
{
	int	i;
	int	j;

	i = 0;
	while (message[i] != '\0')
	{
		j = 0;
		while (j < 8)
		{
			if (((unsigned char)(message[i] >> (7 - j)) & 1) == 0)
				kill(serverid, SIGUSR1);
			else if (((unsigned char)(message[i] >> (7 - j)) & 1) == 1)
				kill(serverid, SIGUSR2);
			usleep(200);
			j++;
		}
		i++;
	}
	j = 8;
	while (j > 0)
	{
		kill(serverid, SIGUSR1);
		usleep(50);
		j--;
	}
}

int	main(int argc, char **argv)
{
	int		serverid;

	if (argc == 3)
	{
		if (!checkargs(argv[1], argv[2]))
			exit(-1);
		serverid = ft_atoi(argv[1]);
		ft_encrypt(serverid, argv[2]);
	}
	else
		ft_printf("Error. Not enough or too many arguments.\n");
	return (0);
}
