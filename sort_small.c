/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thialima <thialima@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 23:27:14 by thialima          #+#    #+#             */
/*   Updated: 2026/08/15 23:27:15 by thialima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_ps *ps);

void	sort_small(t_ps *ps)
{
	if (is_sorted(&ps->a) == 1)
		return ;
	if (ps->a.size == 2)
	{
		do_op(ps, SA);
		return ;
	}
	while (ps->a.size > 3)
	{
		rot_to_top(ps, &ps->a, min_pos(&ps->a), 0);
		do_op(ps, PB);
	}
	if (is_sorted(&ps->a) == 0)
		sort_three(ps);
	while (ps->b.size > 0)
		do_op(ps, PA);
}

static void	sort_three(t_ps *ps)
{
	int	x;
	int	y;
	int	z;

	x = st_get(&ps->a, 0);
	y = st_get(&ps->a, 1);
	z = st_get(&ps->a, 2);
	if (x > y && y < z && x < z)
		do_op(ps, SA);
	else if (x > y && y > z)
	{
		do_op(ps, SA);
		do_op(ps, RRA);
	}
	else if (x > y && x > z)
		do_op(ps, RA);
	else if (x < y && y > z && x < z)
	{
		do_op(ps, RRA);
		do_op(ps, SA);
	}
	else if (x < y && y > z)
		do_op(ps, RRA);
}
