/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:30:37 by barjimen          #+#    #+#             */
/*   Updated: 2024/09/14 18:44:07 by barjimen         ###   ########.fr       */
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

void	calcular_costes_parejas(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	t_stack	*head_b;
	int		pos;

	head_a = *stack_a;
	head_b = *stack_b;
	pos = 0;
	while (*stack_a)
	{
		*stack_a = (*stack_a)->next;
		pos++;
	}
	while (*stack_b)
	{
		pos = 0;
		*stack_b = (*stack_b)->next;
		pos++;
	}
	*stack_a = head_a;
	*stack_b = head_b;
}
