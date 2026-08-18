/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thialima <thialima@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 23:35:55 by thialima          #+#    #+#             */
/*   Updated: 2026/08/15 23:35:56 by thialima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_ps(t_ps *ps)
{
	int	i;

	ps->a.v = NULL;
	ps->b.v = NULL;
	ps->bench = 0;
	ps->quiet = 0;
	ps->strat = ADAPTIVE;
	ps->used = ADAPTIVE;
	ps->disorder = 0;
	i = 0;
	while (i < 11)
		ps->count[i++] = 0;
}

void	st_init(t_ps *ps, t_stack *s, int cap)
{
	s->v = malloc(sizeof(int) * cap);
	if (!s->v)
		error_exit(ps);
	s->cap = cap;
	s->top = 0;
	s->size = 0;
}

int	st_get(t_stack *s, int i)
{
	return (s->v[(s->top + i) % s->cap]);
}

int	is_sorted(t_stack *s)
{
	int	i;

	i = 1;
	while (i < s->size)
	{
		if (st_get(s, i - 1) > st_get(s, i))
			return (0);
		i++;
	}
	return (1);
}

void	free_ps(t_ps *ps)
{
	free(ps->a.v);
	free(ps->b.v);
	ps->a.v = NULL;
	ps->b.v = NULL;
}
