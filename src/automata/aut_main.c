/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aut_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:39:06 by barjimen          #+#    #+#             */
/*   Updated: 2024/10/19 22:28:37 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

//      " ", +-, nb, cualquier otra cosa
// primera linea es 0 -> empty
// segunda linea es 1 -> found sing
// tercera linea es 2 -> invalid chr
// cuarta linea es 3 -> number
// quinta linea es 4 -> space between number
int	get_state(int x, int y)
{
	const int	states[][4] = {
	{0, 1, 3, 2},
	{2, 2, 3, 2},
	{2, 2, 2, 2},
	{4, 2, 3, 2},
	{4, 1, 3, 2},
	};

	return (states[x][y]);
}

int	idx(char *alphabet[], char c)
{
	int	i;

	i = -1;
	while (alphabet[++i])
		if (ft_chrpos(alphabet[i], c) != -1)
			return (i);
	return (i);
}

int	evaluate(t_automata *a)
{
	a->ostate = 0;
	a->i = -1;
	while (++a->i < (int)ft_strlen(a->str))
	{
		a->state = a->get_state(a->state, idx(a->alphabet, a->str[a->i]));
		if (a->fsa[a->state])
			a->fsa[a->state](a, a->data);
		if (a->fta[a->ostate][a->state])
			a->fta[a->ostate][a->state](a, a->data);
		a->ostate = a->state;
	}
	return (a->state);
}

void	free_aut(t_automata *a)
{
	int	i;

	if (a->alphabet)
	{
		i = 0;
		while (a->alphabet[i])
		{
			free(a->alphabet[i]);
			i++;
		}
		free(a->alphabet);
	}
	if (a->errors)
	{
		i = 0;
		while (a->errors[i])
		{
			free(a->errors[i]);
			i++;
		}
		free(a->errors);
	}
}

int	print_out_error(t_automata *a, int state)
{
	if (state <= a->errorlen)
		return (exit_msg(NULL));
	return (0);
}
