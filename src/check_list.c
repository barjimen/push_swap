/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:26:14 by barjimen          #+#    #+#             */
/*   Updated: 2024/09/01 22:19:39 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_list(t_stack **stack_src)
{
	t_stack	*aux;
	t_stack	*check;

	if (stack_size(*stack_src) < 2)
	{
		printf("ERROR: List to short!\n");
		exit(EXIT_SUCCESS);
	}
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
