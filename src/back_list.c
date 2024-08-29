/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 00:11:07 by barjimen          #+#    #+#             */
/*   Updated: 2024/08/30 00:34:22 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//Función para crear un nodo
t_stack	*new_wagon(int content)
{
	t_stack	*memi;

	memi = (t_stack *) malloc(sizeof (t_stack));
	if (!memi)
		return (NULL);
	memi->content = content;
    memi->prev = NULL;
	memi->next = NULL;
	return (memi);
}

//Función para saber el tamaño de una lista
int	stack_size(t_stack *lst)
{
	int		cont;
	t_stack	*lstaux;

	if (!lst)
		return (0);
	lstaux = lst;
	cont = 1;
	while (lstaux->next != NULL)
	{
		cont++;
		lstaux = lstaux->next;
	}
	return (cont);
}

t_stack	*last_wagon(t_stack *lst)
{
	t_stack	*lstaux;

	if (!lst)
		return (NULL);
	lstaux = lst;
	while (lstaux->next != NULL)
		lstaux = lstaux->next;
	return (lstaux);
}

void	add_last_wagon(t_stack **lst, t_stack *new)
{
	t_stack	*lstaux;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lstaux = last_wagon(*lst);
	lstaux->next = new;
    new->prev = lstaux;
}
