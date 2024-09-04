/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 00:13:30 by barjimen          #+#    #+#             */
/*   Updated: 2024/09/04 22:57:07 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	order_three(t_stack *stack_src)
{
	int	nb_one;
	int	nb_two;
	int	nb_three;

	nb_one = stack_src->content;
	nb_two = stack_src->next->content;
	nb_three = stack_src->next->next->content;
	if (nb_one > nb_two && nb_one > nb_three)
	{
		rotate(&stack_src, 'a', 1);
		if (nb_three < nb_one && nb_three < nb_two)
			swap(stack_src, 'a');
	}
	else if (nb_two > nb_one && nb_two > nb_three)
	{
		rotate_reverse(&stack_src, 'a', 1);
		if (nb_one < nb_three)
			swap(stack_src, 'a');
	}
	else
		swap(stack_src, 'a');
}

void	order_four(t_stack *stack_src, t_stack *stack_dst)
{
	
}

void	order_nb(t_stack **stack_src, t_stack **stack_dst)
{
	if (stack_size(*stack_src) == 2)
		swap(*stack_src, 'a');
	if (stack_size(*stack_src) == 3)
		order_three(*stack_src);
	if (stack_size(*stack_src) == 4)
		order_four(*stack_src, *stack_dst);
}
