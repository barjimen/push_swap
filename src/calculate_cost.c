/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:30:37 by barjimen          #+#    #+#             */
/*   Updated: 2024/09/30 19:16:57 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*  calcular_movimientos(a);
	calcular_movimientos(b);
	Calcular_costes_parejas(a y b);
	encontrar_el_mas_barato(a);
	hacer_los_movimientos(a y b);*/

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
			// los movimientos que son de mitad para abajo son el tamaño
				// la posicion (ver dibu ipad :) )
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
			// los movimientos que son de mitad para abajo son el tamaño
				// la posicion (ver dibu ipad :) )
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
			printf("%d ----> %d\n", (*stack_a)->content, num);
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

void	mover_nb(t_stack **stack_a, t_stack **stack_b, int nb)
{
	t_stack	*head;

	head = *stack_a;
	while (*stack_a)
	{
		if ((*stack_a)->content == nb)
		{
			while ((*stack_a)->moves.ra && (*stack_a)->moves.ra--)
				rotate(stack_a, 'a', 1);
			while ((*stack_a)->moves.rb && (*stack_a)->moves.rb--)
				rotate(stack_b, 'b', 1);
			while ((*stack_a)->moves.rr && (*stack_a)->moves.rr--)
				rotate_both(stack_a, stack_b);
			while ((*stack_a)->moves.rra && (*stack_a)->moves.rra--)
				rotate_reverse(stack_a, 'a', 1);
			while ((*stack_a)->moves.rrb && (*stack_a)->moves.rrb--)
				rotate_reverse(stack_b, 'b', 1);
			while ((*stack_a)->moves.rrr && (*stack_a)->moves.rrr--)
				rotate_reverse_both(stack_a, stack_b);
			// push(stack_a, stack_b, 'b');
		}
		(*stack_a) = (*stack_a)->next;
	}
	*stack_a = head;
	push(stack_a, stack_b, 'b');
}
