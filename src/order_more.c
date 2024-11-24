/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 21:28:44 by barjimen          #+#    #+#             */
/*   Updated: 2024/11/24 18:57:52 by barjimen         ###   ########.fr       */
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
	calculate_movements_a(stack_a);
	calculate_movements_b(stack_b);
	calculate_cost_partners(stack_a, stack_b);
	move_nb(stack_a, stack_b, find_the_cheapest(*stack_a));
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
		num = calculate_couple_ba((*stack_b)->content, (*stack_a)->content,
				num);
		*stack_a = (*stack_a)->next;
	}
	*stack_a = head_a;
	calculate_movements_a(stack_a);
	move_nb_ba(stack_a, stack_b, num);
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
