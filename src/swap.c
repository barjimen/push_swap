/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:51:34 by barjimen          #+#    #+#             */
/*   Updated: 2024/09/08 21:13:46 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_stack *stack, char name)
{
	int	aux;

	if (stack && stack_size(stack) > 1)
	{
		aux = stack->content;
		stack->content = stack->next->content;
		stack->next->content = aux;
		printf("s%c\n", name);
	}
	else
		printf("unable to s%c\n", name);
}

void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	int	aux;

	if (stack_a && stack_size(stack_a) > 1)
	{
		aux = stack_a->content;
		stack_a->content = stack_a->next->content;
		stack_a->next->content = aux;

		aux = stack_b->content;
		stack_b->content = stack_b->next->content;
		stack_b->next->content = aux;
		printf("ss\n");
	}
	else
		printf("unable to ss\n");
}

void	push(t_stack **stack_src, t_stack **stack_dst, char name)
{
	t_stack	*aux;

	if (*stack_src)
	{
		aux = new_wagon((*stack_src)->content);
		aux->next = *stack_dst;
		if (aux->next)
			aux->next->prev = aux;
		*stack_dst = aux;
		aux = (*stack_src)->next;
		free(*stack_src);
		*stack_src = aux;
		if (*stack_src)
			(*stack_src)->prev = NULL;
		printf("p%c\n", name);
	}
	else
		printf("unable to p%c\n", name);
}
