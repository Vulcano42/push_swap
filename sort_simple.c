/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thialima <thialima@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 23:04:22 by thialima          #+#    #+#             */
/*   Updated: 2026/08/15 23:04:24 by thialima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_simple(t_ps *ps)
{
	while (is_sorted(&ps->a) == 0)
	{
		rot_to_top(ps, &ps->a, min_pos(&ps->a), 0);
		do_op(ps, PB);
	}
	while (ps->b.size > 0)
		do_op(ps, PA);
}
