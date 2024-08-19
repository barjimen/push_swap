/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:16:49 by barjimen          #+#    #+#             */
/*   Updated: 2024/08/19 18:57:42 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	arg_handler(t_automata *a, int argc, char **argv)
{
	int	state;
	int	i;

	i = 0;
	if (argc < 2)
		return ;
	while (argv[i])
	{
		automata_init(a, NULL);
		a->str = argv[i++];
		state = evaluate(a);
		if (state == NUMBER)
			test(a, a->data);
		print_out_error(a, state);
		free_aut(a);
	}
}

int	main(int argc, char **argv)
{
    t_automata	a;

	arg_handler(&a, argc, argv);
}
