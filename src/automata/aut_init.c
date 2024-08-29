/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aut_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:36:59 by barjimen          #+#    #+#             */
/*   Updated: 2024/08/30 00:52:14 by barjimen         ###   ########.fr       */
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
	a->errors = malloc(4 * sizeof(char *));
	a->errors[0] = ft_strdup("Empty argument!");
	a->errors[1] = ft_strdup("sign found at the end!");
	a->errors[2] = ft_strdup("Invalid character!");
	a->errors[3] = NULL;
	a->errorlen = 2;
}

void	init_simple_actions(t_automata *a)
{
	(void)a;
	/*a->fsa[EMPTY] = print_state;
	a->fsa[NUMBER] = print_state;
	a->fsa[INVALID] = print_state;
	a->fsa[SPACE] = print_state;
	a->fsa[SIGN] = print_state;*/
}

void	init_transition_actions(t_automata *a)
{
	a->fta[NUMBER][SPACE] = test;
	//(void)a;
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