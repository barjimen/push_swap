/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 22:05:27 by barjimen          #+#    #+#             */
/*   Updated: 2024/10/19 22:06:20 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	exit_msg(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit(EXIT_SUCCESS);
}

int	ft_atoi_ps(const char *str)
{
	int			x;
	long int	nb;
	int			sym;

	x = 0;
	nb = 0;
	sym = 1;
	while ((str[x] >= 9 && str[x] <= 13) || (str[x] == 32))
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			sym *= -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		nb = (str[x++] - '0') + (nb * 10);
		if ((nb > 2147483647 && sym == 1) || (nb > 2147483648 && sym == -1))
			exit_msg(NULL);
	}
	nb *= sym;
	return (nb);
}
