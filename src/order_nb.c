/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 00:13:30 by barjimen          #+#    #+#             */
/*   Updated: 2024/10/13 20:22:02 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	search_small(t_stack **stack_src)
{
	t_stack	*aux;
	int		pos;
	int		nb;

	aux = *stack_src;
	pos = 0;
	nb = aux->content;
	while (aux)
	{
		if (nb > aux->content)
			nb = aux->content;
		aux = aux->next;
	}
	aux = *stack_src;
	while (aux)
	{
		if (nb == aux->content)
			return (pos);
		aux = aux->next;
		pos++;
	}
	return (0);
}

void	push_small(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;
	int	size;

	pos = search_small(stack_a);
	size = stack_size(*stack_a);
	if (pos == 1)
		swap(*stack_a, 'a');
	else if (pos > (size / 2))
	{
		while (pos < size--)
			rotate_reverse(stack_a, 'a', 1);
	}
	else
	{
		while (pos--)
			rotate(stack_a, 'a', 1);
	}
	push(stack_a, stack_b, 'b');
}

void	order_three(t_stack *stack_src)
{
	int	nb_one;
	int	nb_two;
	int	nb_three;

	nb_one = stack_src->content;
	nb_two = stack_src->next->content;
	nb_three = stack_src->next->next->content;
	if (nb_one < nb_two && nb_two < nb_three)
		return ;
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

void	order_four_five(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 5)
		push_small(stack_a, stack_b);
	push_small(stack_a, stack_b);
	order_three(*stack_a);
	push(stack_b, stack_a, 'a');
	if (size == 5)
		push(stack_b, stack_a, 'a');
}

void	order_nb(t_stack **stack_src, t_stack **stack_dst)
{
	int	size;

	size = stack_size(*stack_src);
	if (size == 2)
		swap(*stack_src, 'a');
	else if (size == 3)
		order_three(*stack_src);
	else if (size == 4 || size == 5)
		order_four_five(stack_src, stack_dst, size);
	else
		order_more(stack_src, stack_dst);
}
