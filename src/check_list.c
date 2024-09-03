/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:26:14 by barjimen          #+#    #+#             */
/*   Updated: 2024/09/04 00:25:45 by barjimen         ###   ########.fr       */
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
			{
				printf("DUPLICATED NB!\n");
				exit(EXIT_SUCCESS);
			}
			check = check->next;
		}
		aux = aux->next;
	}
}

void	check_list(t_stack **stack_src)
{
	if (stack_size(*stack_src) < 2)
	{
		printf("ERROR: List to short!\n");
		exit(EXIT_SUCCESS);
	}
	duplicated_nb(stack_src);
	if (is_it_ordered(stack_src))
		exit(EXIT_SUCCESS);
}
