/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:30:37 by barjimen          #+#    #+#             */
/*   Updated: 2024/10/13 20:50:28 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	calcular_movimientos_a(t_stack **stack)
{
	t_stack	*head;
	int		size;
	int		pos;

	head = *stack;
	size = stack_size(*stack);
	pos = 0;
	while (*stack)
	{
		if ((size / 2) >= pos)
		{
			(*stack)->moves.ra = pos;
			(*stack)->moves.rra = 0;
		}
		else
		{
			(*stack)->moves.rra = (size - pos);
			(*stack)->moves.ra = 0;
		}
		*stack = (*stack)->next;
		pos++;
	}
	*stack = head;
}

void	calcular_movimientos_b(t_stack **stack)
{
	t_stack	*head;
	int		size;
	int		pos;

	head = *stack;
	size = stack_size(*stack);
	pos = 0;
	while (*stack)
	{
		if ((size / 2) >= pos)
		{
			(*stack)->moves.rb = pos;
			(*stack)->moves.rrb = 0;
		}
		else
		{
			(*stack)->moves.rrb = (size - pos);
			(*stack)->moves.rb = 0;
		}
		*stack = (*stack)->next;
		pos++;
	}
	*stack = head;
}

int	calcular_pareja(int a, int b_now, int b_before)
{
	if (b_before > b_now)
	{
		if (a < b_before && a > b_now)
			return (b_now);
		else
			return (b_before);
	}
	else
	{
		if (a > b_before && a < b_now)
			return (b_before);
		else
			return (b_now);
	}
}

int	calcular_pareja_ba(int a, int b_now, int b_before)
{
	if (b_before < b_now)
	{
		if (a > b_before && a < b_now)
			return (b_now);
		else
			return (b_before);
	}
	else
	{
		if (a < b_before && a > b_now)
			return (b_before);
		else
			return (b_now);
	}
}

void	join_moves(t_stack **stack_a)
{
	while ((*stack_a)->moves.ra > 0 && (*stack_a)->moves.rb > 0)
	{
		(*stack_a)->moves.rr++;
		(*stack_a)->moves.ra--;
		(*stack_a)->moves.rb--;
	}
	while ((*stack_a)->moves.rra > 0 && (*stack_a)->moves.rrb > 0)
	{
		(*stack_a)->moves.rrr++;
		(*stack_a)->moves.rra--;
		(*stack_a)->moves.rrb--;
	}
}
