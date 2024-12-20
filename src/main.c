/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:16:49 by barjimen          #+#    #+#             */
/*   Updated: 2024/10/19 22:33:54 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stack(t_stack **list)
{
	t_stack	*flist;
	t_stack	*aux;

	flist = *list;
	while (flist)
	{
		aux = flist->next;
		free(flist);
		flist = aux;
	}
}

int	arg_handler(t_automata *a, int argc, char **argv, t_stack **stack)
{
	int	state;
	int	i;

	i = 1;
	if (argc < 2)
		return (1);
	while (argv[i])
	{
		automata_init(a, stack);
		a->str = argv[i++];
		state = evaluate(a);
		if (state == NUMBER)
			save_numbers(a, a->data);
		if (print_out_error(a, state))
			exit_msg(NULL);
		free_aut(a);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_automata	a;
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!arg_handler(&a, argc, argv, &stack_a))
	{
		check_list(&stack_a);
		order_nb(&stack_a, &stack_b);
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
}
