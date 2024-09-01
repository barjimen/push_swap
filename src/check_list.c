/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:26:14 by barjimen          #+#    #+#             */
/*   Updated: 2024/09/01 22:05:44 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void check_list(t_stack **stack_src)
{
    t_stack *aux;
    t_stack *check;

    if (stack_size(*stack_src) < 2)
    {
        printf("ERROR: List to short!\n");
        exit(EXIT_SUCCESS);
    }
        
    while (*stack_src)
    {
        aux = *stack_src;
        while (aux != NULL)
        {
            check = (*stack_src)->next;
            while (check != NULL)
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
}
