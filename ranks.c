/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thialima <thialima@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 23:04:08 by thialima          #+#    #+#             */
/*   Updated: 2026/08/15 23:04:09 by thialima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_ranks(t_ps *ps)
{
	int	*r;
	int	i;
	int	j;

	r = malloc(sizeof(int) * ps->a.size);
	if (r == NULL)
		error_exit(ps);
	i = -1;
	while (++i < ps->a.size)
	{
		r[i] = 0;
		j = -1;
		while (++j < ps->a.size)
			if (ps->a.v[j] < ps->a.v[i])
				r[i]++;
	}
	i = -1;
	while (++i < ps->a.size)
		ps->a.v[i] = r[i];
	free(r);
}
