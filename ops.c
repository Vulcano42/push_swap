/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thialima <thialima@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 23:07:08 by thialima          #+#    #+#             */
/*   Updated: 2026/08/15 23:07:13 by thialima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_swap(t_stack *s)
{
	int	tmp;

	if (s->size < 2)
		return ;
	tmp = s->v[s->top];
	s->v[s->top] = s->v[(s->top + 1) % s->cap];
	s->v[(s->top + 1) % s->cap] = tmp;
}

static void	op_push(t_stack *src, t_stack *dst)
{
	int	x;

	if (src->size == 0)
		return ;
	x = src->v[src->top];
	src->top = (src->top + 1) % src->cap;
	src->size--;
	dst->top = (dst->top + dst->cap - 1) % dst->cap;
	dst->v[dst->top] = x;
	dst->size++;
}

static void	op_rot(t_stack *s)
{
	if (s->size < 2)
		return ;
	s->v[(s->top + s->size) % s->cap] = s->v[s->top];
	s->top = (s->top + 1) % s->cap;
}

static void	op_rrot(t_stack *s)
{
	if (s->size < 2)
		return ;
	s->top = (s->top + s->cap - 1) % s->cap;
	s->v[s->top] = s->v[(s->top + s->size) % s->cap];
}

void	do_op(t_ps *ps, t_op op)
{
	if (op == SA || op == SS)
		op_swap(&ps->a);
	if (op == SB || op == SS)
		op_swap(&ps->b);
	if (op == PA)
		op_push(&ps->b, &ps->a);
	if (op == PB)
		op_push(&ps->a, &ps->b);
	if (op == RA || op == RR)
		op_rot(&ps->a);
	if (op == RB || op == RR)
		op_rot(&ps->b);
	if (op == RRA || op == RRR)
		op_rrot(&ps->a);
	if (op == RRB || op == RRR)
		op_rrot(&ps->b);
	ps->count[op]++;
	if (!ps->quiet)
		ft_putstr_fd(op_name(op), 1);
}
