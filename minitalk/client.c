/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyolasig <student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:39:06 by hyolasig          #+#    #+#             */
/*   Updated: 2022/10/09 23:39:15 by hyolasig         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	total;
	int	i;
	int	n;

	i = 0;
	n = 1;
	total = 0;
	while (str[i] <= 32)
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
		if (str[i++] == '-')
			n = -1;
	while (str[i] <= '9' && str[i] >= '0')
		total = (total * 10) + (str[i++] - 48);
	if (str[i] != '\0')
		return (write(1, "pid error!\n", 11));
	return (total * n);
}

int	main(int argc, char **argv)
{
	int	len;
	int	size;
	int	pidd;

	if (argc != 3)
		return (write(2, "Argument error!!", 16));
	pidd = ft_atoi(argv[1]);
	len = -1;
	while (++len < ft_strlen(argv[2]))
	{
		size = 8;
		while (size--)
		{
			if (((argv[2][len] >> size) % 2) == 0)
				kill(pidd, SIGUSR1);
			else
				kill(pidd, SIGUSR2);
			usleep(70);
		}
	}
	return (0);
}
