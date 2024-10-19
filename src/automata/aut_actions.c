/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aut_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:37:51 by barjimen          #+#    #+#             */
/*   Updated: 2024/10/19 22:12:49 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	print_state(t_automata *a, void *data)
{
	(void)data;
	printf("state: %d\n", a->state);
}

void	save_numbers(t_automata *a, void *data)
{
	t_stack	**list;
	int		numb;

	numb = ft_atoi_ps(a->str + a->j);
	list = (t_stack **)data;
	add_last_wagon(list, new_wagon(numb));
	a->j = a->i;
}
