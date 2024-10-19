/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aut_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:36:59 by barjimen          #+#    #+#             */
/*   Updated: 2024/10/19 22:29:14 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	init_alphabet(t_automata *a)
{
	a->alphabet = malloc(4 * sizeof(char *));
	a->alphabet[0] = ft_strdup(" ");
	a->alphabet[1] = ft_strdup("+-");
	a->alphabet[2] = ft_strdup("0123456789");
	a->alphabet[3] = NULL;
}

void	init_errors(t_automata *a)
{
	a->errorlen = 2;
}

void	init_simple_actions(t_automata *a)
{
	(void)a;
}

void	init_transition_actions(t_automata *a)
{
	a->fta[NUMBER][SPACE] = save_numbers;
}

void	automata_init(t_automata *a, void *data)
{
	ft_bzero(a, sizeof(t_automata));
	a->data = data;
	init_alphabet(a);
	init_errors(a);
	init_simple_actions(a);
	init_transition_actions(a);
	a->get_state = get_state;
}
