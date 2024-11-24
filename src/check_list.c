/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:26:14 by barjimen          #+#    #+#             */
/*   Updated: 2024/11/24 18:50:43 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_it_ordered(t_stack **stack_src)
{
	t_stack	*aux;
	t_stack	*check;

	aux = *stack_src;
	while (aux)
	{
		check = (aux)->next;
		while (check)
		{
			if (aux->content >= check->content)
				return (0);
			check = check->next;
		}
		aux = aux->next;
	}
	return (1);
}

void	duplicated_nb(t_stack **stack_src)
{
	t_stack	*aux;
	t_stack	*check;

	aux = *stack_src;
	while (aux)
	{
		check = (aux)->next;
		while (check)
		{
			if (aux->content == check->content)
				exit_msg(NULL);
			check = check->next;
		}
		aux = aux->next;
	}
}

void	check_list(t_stack **stack_src)
{
	if (stack_size(*stack_src) < 2)
		exit_msg(NULL);
	duplicated_nb(stack_src);
	if (is_it_ordered(stack_src))
		exit(EXIT_SUCCESS);
}
