/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:13:30 by barjimen          #+#    #+#             */
/*   Updated: 2024/09/19 19:58:00 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/Libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

//Estructura del autómata 
typedef struct s_automata
{
	void	*data;
	char	**alphabet;
	char	**errors;
	char	*str;
	int		errorlen;
	int		state;
	int		ostate;
	int		i;
	int		j;
	void	(*fsa[20])(struct s_automata *a, void *data);
	void	(*fta[20][20])(struct	s_automata
			*a, void
			*data);
	int		(*get_state)(int state, int abc_idx);
}			t_automata;

int			get_state(int x, int y);
int			evaluate(t_automata *a);
void		automata_init(t_automata *a, void *data);
int			print_out_error(t_automata *a, int state);
void		free_aut(t_automata *a);

typedef enum e_states
{
	EMPTY,
	SIGN,
	INVALID,
	NUMBER,
	SPACE
}	t_states;

typedef struct s_moves
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	sa;
	int	sb;
	int	pa;
	int	pb;
}	t_moves;

typedef struct s_stack
{
	int					content;
	int					cost;
	t_moves				moves;
	struct s_stack		*prev;
	struct s_stack		*next;
}	t_stack;

void		test(t_automata *a, void *data);
void	print_state(t_automata *a, void *data);
t_stack	*new_wagon(int content);
int	stack_size(t_stack *lst);
t_stack	*last_wagon(t_stack *lst);
void	add_last_wagon(t_stack **lst, t_stack *new);
void	swap(t_stack *stack, char	name);
void	swap_both(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack **stack_src, t_stack **stack_dst, char	name);
void	rotate(t_stack **stack_src, char name, int print);
void	rotate_both(t_stack **stack_a, t_stack **stack_b);
void	rotate_reverse(t_stack **stack_src, char name, int print);
void	rotate_reverse_both(t_stack **stack_a, t_stack **stack_b);
void 	check_list(t_stack **stack_src);
int		is_it_ordered(t_stack **stack_src);
void	order_nb(t_stack **stack_src, t_stack **stack_dst);
void	order_three(t_stack *stack_src);

void	calcular_costes_parejas(t_stack **stack_a, t_stack **stack_b);
void	calcular_movimientos_a(t_stack **stack);
void	calcular_movimientos_b(t_stack **stack);
void	order_more(t_stack **stack_a, t_stack **stack_b);


#endif