/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalara-s <dalara-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:37:58 by dalara-s          #+#    #+#             */
/*   Updated: 2025/01/31 13:38:05 by dalara-s         ###   ########.fr       */
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

void	print_char(int *bit, unsigned char *c, int pid)
{
	*bit = 1;
	if (*c == 0)
	{
		c_kill(pid, SIGUSR2);
		ft_printf("\nok.\n");
		*c = 0;
		return ;
	}
	write(1, c, 1);
	*c = 0;
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				bit = 1;
	static int				pid = 0;

	if (info->si_pid != 0 && info->si_pid != pid)
	{
		c = 0;
		bit = 1;
		pid = info->si_pid;
	}
	(void)context;
	if (sig == SIGUSR2)
		c += bit;
	bit *= 2;
	if (bit == 256)
		print_char(&bit, &c, pid);
	c_kill(pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid_server;
	struct sigaction	action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handler;
	sigemptyset(&action.sa_mask);
	pid_server = getpid();
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	ft_printf("Server PID: %d\n", pid_server);
	while (1)
		pause();
	return (0);
}
