/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:30:37 by barjimen          #+#    #+#             */
/*   Updated: 2024/09/16 22:34:34 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*  calcular_movimientos(a);
	calcular_movimientos(b);
	Calcular_costes_parejas(a y b);
	encontrar_el_mas_barato(a);
	hacer_los_movimientos(a y b);*/

void	calcular_movimientos(t_stack **stack)
{
	t_stack	*head;
	int		size;
	int		pos;

	head = *stack;
	size = stack_size(*stack);
	pos = 0;
	while (*stack)
	{
		if ((size / 2) <= pos)
		{
			(*stack)->moves.ra = pos;
			(*stack)->moves.rra = 0;
		}
		else
		{
			//los movimientos que son de mitad para abajo son el tamaño - la posicion (ver dibu ipad :) )
			(*stack)->moves.rra = (size - pos);
			(*stack)->moves.ra = 0;
		}
		*stack = (*stack)->next;
		pos++;
	}
	*stack = head;
}

int	calcular_pareja(int a, int b_now, int b_before)
{
	if (a > b_before && a < b_now)
		return (b_before);
	else
	{
		if (b_before > b_now)
			return (b_before);
		else
			return (b_now);
	}
	return (b_before);
}

int	calcular_coste_hasta_pareja(t_stack	**stack_a, t_stack *stack_b, int num)
{
	int	cost;

	cost = 1;
	if ((*stack_a)->moves.ra > 0 || (*stack_a)->moves.rra > 0)
		cost += (*stack_a)->moves.ra + (*stack_a)->moves.rra;
	while (stack_b)
	{
		if (num == stack_b->content)
		{
			if (stack_b->moves.rb > 0 || stack_b->moves.rrb > 0)
			{
				cost += stack_b->moves.rb + stack_b->moves.rrb;
				(*stack_a)->moves.rb = stack_b->moves.rb;
				(*stack_a)->moves.rrb = stack_b->moves.rrb;
			}
		}
		stack_b = stack_b->next;
	}
	(*stack_a)->moves.pb = 1;
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
		while (*stack_b)
		{
			num = calcular_pareja((*stack_a)->content, (*stack_b)->content, num);
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
