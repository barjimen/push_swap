/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:16:49 by barjimen          #+#    #+#             */
/*   Updated: 2024/08/30 01:08:32 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void free_stack(t_stack **list)
{
	t_stack *flist;
	t_stack *aux;
	
	flist = *list;
	while (flist)
	{
		aux = flist->next;
		free(flist);
		flist = aux;
	}
}

void	arg_handler(t_automata *a, int argc, char **argv, t_stack **stack)
{
	int	state;
	int	i;

	i = 1;
	if (argc < 2)
		return ;
	while (argv[i])
	{
		automata_init(a, stack);
		a->str = argv[i++];
		state = evaluate(a);
		if (state == NUMBER)
			test(a, a->data);
		print_out_error(a, state);
		free_aut(a);
	}
}

int	main(int argc, char **argv)
{
    t_automata	a;
	t_stack *stack_a;
	t_stack *aux;
	
	stack_a = NULL;
	arg_handler(&a, argc, argv, &stack_a);
	aux = stack_a;
	while (stack_a)
	{
    	printf("Numb is: %d\n", stack_a->content);
    	stack_a = stack_a->next;
	}
	stack_a = aux;
	free_stack(&stack_a);
}
