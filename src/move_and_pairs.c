/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_and_pairs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:48:30 by barjimen          #+#    #+#             */
/*   Updated: 2024/10/13 20:57:48 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	calcular_coste_hasta_pareja(t_stack **stack_a, t_stack *stack_b, int num)
{
	int	cost;

	cost = 1;
	while (stack_b)
	{
		if (num == stack_b->content)
		{
			if (stack_b->moves.rb > 0 || stack_b->moves.rrb > 0)
			{
				(*stack_a)->moves.rb = stack_b->moves.rb;
				(*stack_a)->moves.rrb = stack_b->moves.rrb;
			}
		}
		stack_b = stack_b->next;
	}
	join_moves(stack_a);
	(*stack_a)->moves.pb = 1;
	cost = ((*stack_a)->moves.pb + (*stack_a)->moves.ra + (*stack_a)->moves.rra
			+ (*stack_a)->moves.rb + (*stack_a)->moves.rrb
			+ (*stack_a)->moves.rr + (*stack_a)->moves.rrr
			+ (*stack_a)->moves.sa + (*stack_a)->moves.sb);
	return (cost);
}

void	calcular_costes_parejas(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	t_stack	*head_b;
	int		pos;
	int		num;

	head_a = *stack_a;
	head_b = *stack_b;
	pos = 0;
	while (*stack_a)
	{
		num = (*stack_b)->content;
		*stack_b = (*stack_b)->next;
		while (*stack_b)
		{
			num = calcular_pareja((*stack_a)->content, (*stack_b)->content,
					num);
			*stack_b = (*stack_b)->next;
		}
		(*stack_a)->cost = calcular_coste_hasta_pareja(stack_a, head_b, num);
		*stack_b = head_b;
		*stack_a = (*stack_a)->next;
		pos++;
	}
	*stack_a = head_a;
	*stack_b = head_b;
}

int	encontrar_el_mas_barato(t_stack *stack_a)
{
	int	before_cost;
	int	nb;

	before_cost = stack_a->cost;
	nb = stack_a->content;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (before_cost > stack_a->cost)
		{
			before_cost = stack_a->cost;
			nb = stack_a->content;
		}
		stack_a = stack_a->next;
	}
	return (nb);
}

void	mover_nb_ba(t_stack **stack_a, t_stack **stack_b, int nb)
{
	t_stack	*head;
	t_moves	moves;

	head = *stack_a;
	while (head)
	{
		if (head->content == nb)
		{
			moves = head->moves;
			break ;
		}
		head = head->next;
	}
	while (moves.ra--)
		rotate(stack_a, 'a', 1);
	while (moves.rra--)
		rotate_reverse(stack_a, 'a', 1);
	push(stack_b, stack_a, 'a');
}

void	mover_nb(t_stack **stack_a, t_stack **stack_b, int nb)
{
	t_stack	*head;
	t_moves	moves;

	head = *stack_a;
	while (head)
	{
		if (head->content == nb)
			moves = head->moves;
		head = head->next;
	}
	while (moves.ra--)
		rotate(stack_a, 'a', 1);
	while (moves.rb--)
		rotate(stack_b, 'b', 1);
	while (moves.rr--)
		rotate_both(stack_a, stack_b);
	while (moves.rrb--)
		rotate_reverse(stack_b, 'b', 1);
	while (moves.rra--)
		rotate_reverse(stack_a, 'a', 1);
	while (moves.rrr--)
		rotate_reverse_both(stack_a, stack_b);
	push(stack_a, stack_b, 'b');
}
