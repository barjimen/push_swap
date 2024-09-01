/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 20:58:24 by barjimen          #+#    #+#             */
/*   Updated: 2024/09/01 21:15:16 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate_first(t_stack **stack_src, char name, int print)
{
	t_stack	*aux;
	int		i;

	if (*stack_src)
	{
		aux = *stack_src;
		while ((*stack_src)->next != NULL)
		{
			i = (*stack_src)->content;
			(*stack_src)->content = (*stack_src)->next->content;
			(*stack_src)->next->content = i;
			(*stack_src) = (*stack_src)->next;
		}
		(*stack_src) = aux;
		if (print)
			printf("r%c\n", name);
	}
	else
		printf("unable to rotate r%c\n", name);
}

void	rotate_both_first(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(*stack_a) > 1 && stack_size(*stack_b) > 1)
	{
		rotate_first(stack_a, 'r', 0);
		rotate_first(stack_b, 'r', 0);
		printf("rr\n");
	}
}

void	rotate_last(t_stack **stack_src, char name, int print)
{
	int i;

	if (*stack_src)
	{
		while ((*stack_src)->next != NULL)
			(*stack_src) = (*stack_src)->next;
		while ((*stack_src)->prev != NULL)
		{
			i = (*stack_src)->content;
			(*stack_src)->content = (*stack_src)->prev->content;
			(*stack_src)->prev->content = i;
			(*stack_src) = (*stack_src)->prev;
		}
		if (print)
			printf("rr%c\n", name);
	}
	else
		printf("unable to rotate r%c\n", name);
}

void	rotate_both_last(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(*stack_a) > 1 && stack_size(*stack_b) > 1)
	{
		rotate_last(stack_a, 'r', 0);
		rotate_last(stack_b, 'r', 0);
		printf("rrr\n");
	}
}
