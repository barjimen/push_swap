/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:16:49 by barjimen          #+#    #+#             */
/*   Updated: 2024/08/17 21:50:54 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/push_swap.h"

void funct(t_automata *a)
{
    int state;
    
    
   
   
    automata_init(a, NULL);
    a->str = " -5 -3 -4 ";
    state = evaluate(a);
    if (state == NUMBER)
        test(a, a->data);
    print_out_error(a, state);
    free_aut(a);
}

int main()
{
    t_automata a;

   funct(&a);
    
}