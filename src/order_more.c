/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 21:28:44 by barjimen          #+#    #+#             */
/*   Updated: 2024/09/14 18:05:41 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_cheap(t_stack **stack_a, t_stack **stack_b)
{
	calcular_movimientos(a);
	calcular_movimientos(b);
	Calcular_costes_parejas(a y b);
	encontrar_el_mas_barato(a);
	hacer_los_movimientos(a y b);
}

void	order_more(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	push(stack_a, stack_b, 'b');
	push(stack_a, stack_b, 'b');
	while (size-- > 3)
		push_cheap();
	order_three(*stack_a);
	return_to_a(stack_a, stack_b);
	while (!is_it_ordered(stack_a))
		spin_stack();
}
