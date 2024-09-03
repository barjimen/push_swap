/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 20:58:24 by barjimen          #+#    #+#             */
/*   Updated: 2024/09/04 00:10:10 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate(t_stack **stack_src, char name, int print)
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

void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(*stack_a) > 1 && stack_size(*stack_b) > 1)
	{
		rotate(stack_a, 'r', 0);
		rotate(stack_b, 'r', 0);
		printf("rr\n");
	}
	else
		printf("unable to rotate both\n");
}

void	rotate_reverse(t_stack **stack_src, char name, int print)
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

void	rotate_reverse_both(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(*stack_a) > 1 && stack_size(*stack_b) > 1)
	{
		rotate_reverse(stack_a, 'r', 0);
		rotate_reverse(stack_b, 'r', 0);
		printf("rrr\n");
	}
	else
		printf("unable to reverse rotate both\n");
}
