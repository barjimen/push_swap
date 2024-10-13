/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 21:28:44 by barjimen          #+#    #+#             */
/*   Updated: 2024/10/13 01:21:07 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	reset_moves(t_stack **stack)
{
	t_stack	*head;

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

void	return_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int		num;
	t_stack	*head_a;

	head_a = *stack_a;
	num = (*stack_a)->content;
	*stack_a = (*stack_a)->next;
	while (*stack_a)
	{
		num = calcular_pareja_ba((*stack_b)->content, (*stack_a)->content, num);
		*stack_a = (*stack_a)->next;
	}
	*stack_a = head_a;
	calcular_movimientos_a(stack_a);
	mover_nb_ba(stack_a, stack_b, num);
}

void spin_number(t_stack **stack_a, int pos)
{
	t_stack	*head;
	t_moves moves;

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

void	order_more(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	push(stack_a, stack_b, 'b');
	push(stack_a, stack_b, 'b');
	size = stack_size(*stack_a);
	while (size-- > 3)
		push_cheap(stack_a, stack_b);
	if (!is_it_ordered(stack_a))
		order_three(*stack_a);
	size = stack_size(*stack_b);
	while (size-- > 0)
		return_to_a(stack_a, stack_b);
	while (!is_it_ordered(stack_a))
		spin_stack(stack_a);
}
