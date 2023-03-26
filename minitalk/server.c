/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyolasig <student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:39:33 by hyolasig          #+#    #+#             */
/*   Updated: 2022/10/09 23:39:34 by hyolasig         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

void	signalcatcher(int signal)
{
	static unsigned char	total;
	static int				mi = 128;

	if (signal == SIGUSR2)
		total += mi;
	mi /= 2;
	if (mi == 0)
	{
		write (1, &total, 1);
		mi = 128;
		total = 0;
	}
}

void	ft_printnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_printnbr(n / 10);
	c = n % 10 + 48;
	write(1, &c, 1);
}

int	main(void)
{
	ft_printnbr(getpid());
	write(1, "\n", 1);
	signal (SIGUSR1, signalcatcher);
	signal (SIGUSR2, signalcatcher);
	while (1)
		pause();
	return (0);
}
