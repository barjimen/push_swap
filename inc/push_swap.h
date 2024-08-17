/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:13:30 by barjimen          #+#    #+#             */
/*   Updated: 2024/08/17 21:45:42 by barjimen         ###   ########.fr       */
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

void		test(t_automata *a, void *data);

#endif