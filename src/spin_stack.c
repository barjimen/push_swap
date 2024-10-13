/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spin_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:55:25 by barjimen          #+#    #+#             */
/*   Updated: 2024/10/13 20:55:36 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	spin_number(t_stack **stack_a, int pos)
{
	t_stack	*head;
	t_moves	moves;

	head = *stack_a;
	while (pos--)
		head = head->next;
	moves = head->moves;
	while (moves.ra--)
		rotate(stack_a, 'a', 1);
	while (moves.rra--)
		rotate_reverse(stack_a, 'a', 1);
}

void	spin_stack(t_stack **stack_a)
{
	calcular_movimientos_a(stack_a);
	spin_number(stack_a, search_small(stack_a));
}
