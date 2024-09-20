/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 21:28:44 by barjimen          #+#    #+#             */
/*   Updated: 2024/09/20 22:02:50 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void reset_moves(t_stack **stack)
{
	t_stack *head;

	head = *stack;
	while (*stack)
	{
		(*stack)->cost = 0;
		(*stack)->moves.ra = 0;
		(*stack)->moves.rb = 0;
		(*stack)->moves.rr = 0;
		(*stack)->moves.rra = 0;
		(*stack)->moves.rrb = 0;
		(*stack)->moves.rrr = 0;
		(*stack)->moves.pb = 0;
		(*stack) = (*stack)->next;
	}
	*stack = head;
}

void	push_cheap(t_stack **stack_a, t_stack **stack_b)
{
	calcular_movimientos_a(stack_a);
	calcular_movimientos_b(stack_b);
	calcular_costes_parejas(stack_a, stack_b);
	mover_nb(stack_a, stack_b, encontrar_el_mas_barato(*stack_a));
	reset_moves(stack_a);
	reset_moves(stack_b);
}

void	order_more(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	push(stack_a, stack_b, 'b');
	push(stack_a, stack_b, 'b');
	size = stack_size(*stack_a);
	while (size-- > 3)
		push_cheap(stack_a, stack_b);
	order_three(*stack_a);
	//return_to_a(stack_a, stack_b);
	//while (!is_it_ordered(stack_a))
	//	spin_stack();
}
