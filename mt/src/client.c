/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalara-s <dalara-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:38:19 by dalara-s          #+#    #+#             */
/*   Updated: 2025/01/31 13:38:51 by dalara-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	c_kill(pid_t pid, int sig)
{
	if (kill(pid, sig) < 0)
	{
		perror("kill error");
		exit(EXIT_FAILURE);
	}
}

void	finish(int pid)
{
	static int	i = 0;

	if (i <= 8)
		c_kill(pid, SIGUSR1);
	i++;
}

void	send_msg(int pid, char *msg)
{
	static int	bit = 0;
	static char	*msg_copy = 0;

	if (msg)
		msg_copy = msg;
	if (*msg_copy)
	{
		if ((((unsigned char)*msg_copy >> bit) % 2) == 0)
			c_kill(pid, SIGUSR1);
		if ((((unsigned char)*msg_copy >> bit) % 2) == 1)
			c_kill(pid, SIGUSR2);
		bit++;
		if (bit == 8)
		{
			msg_copy++;
			bit = 0;
		}
	}
	if (!(*msg_copy))
		finish(pid);
}

void	ack_handler(int sig, siginfo_t *info, void *more_info)
{
	static int	id;

	if (info->si_pid != 0)
		id = info->si_pid;
	(void)more_info;
	if (sig == SIGUSR1)
		send_msg(id, NULL);
	usleep(42);
	if (sig == SIGUSR2)
	{
		ft_printf("ok\n");
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = ack_handler;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	if (argc != 3)
	{
		ft_printf("Input error.'./cliente PID MSG'");
		exit(EXIT_FAILURE);
	}
	send_msg(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
