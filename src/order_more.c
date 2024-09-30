/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 21:28:44 by barjimen          #+#    #+#             */
/*   Updated: 2024/09/30 20:40:46 by barjimen         ###   ########.fr       */
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

void return_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int num;
	
	num = (*stack_a)->content;
	*stack_a = (*stack_a)->next;
	while (*stack_a)
	{
		num = calcular_pareja((*stack_b)->content, (*stack_a)->content,
				num);//AQUI ESTAMOS :D
		printf("%d ----> %d\n", (*stack_b)->content, num);
		*stack_a = (*stack_a)->next;
	}
	(*stack_a)->cost = calcular_coste_hasta_pareja(stack_a, head_b, num);
	*stack_b = head_b;
	*stack_a = (*stack_a)->next;
	pos++;
}

void spin_stack()
{
	
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
