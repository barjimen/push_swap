/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:16:49 by barjimen          #+#    #+#             */
/*   Updated: 2024/09/16 22:36:33 by barjimen         ###   ########.fr       */
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
	t_stack *stack_b;
	t_stack *aux;
	
	stack_a = NULL;
	stack_b = NULL;
	arg_handler(&a, argc, argv, &stack_a);
	check_list(&stack_a);
	order_nb(&stack_a, &stack_b);
	aux = stack_a;
	printf("STACK A:\n");
	while (stack_a)
	{
		printf("----------------NEW NODE---------------\n");
		//printf("adress	is: %p\n", stack_a);
    	printf("Numb	is: %d\n", stack_a->content);
		//printf("padress	is: %p\n", stack_a->prev);
		//printf("nadress	is: %p\n", stack_a->next);
		printf("cost: %d\n", stack_a->cost);
		printf("ra: %d\n", stack_a->moves.ra);
		printf("rra: %d\n", stack_a->moves.rra);
		printf("rb: %d\n", stack_a->moves.rb);
		printf("rrb: %d\n", stack_a->moves.rrb);
		printf("pb: %d\n", stack_a->moves.pb);
    	stack_a = stack_a->next;
	}
	stack_a = aux;
	aux = stack_b;
	printf("STACK B:\n");
	while (stack_b)
	{
    	printf("----------------NEW NODE---------------\n");
		printf("adress	is: %p\n", stack_b);
    	printf("Numb	is: %d\n", stack_b->content);
		printf("padress	is: %p\n", stack_b->prev);
		printf("nadress	is: %p\n", stack_b->next);
    	stack_b = stack_b->next;
	}
	stack_b = aux;
	free_stack(&stack_a);
	free_stack(&stack_b);
}
