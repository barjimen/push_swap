/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aut_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:37:51 by barjimen          #+#    #+#             */
/*   Updated: 2024/08/17 21:54:33 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/push_swap.h"

void test(t_automata *a, void *data)
{
    (void)data;
    (void)a;
    printf("%d\n", ft_atoi(a->str + a->j));
    a->j = a->i;
}
