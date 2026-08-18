/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thialima <thialima@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 23:26:53 by thialima          #+#    #+#             */
/*   Updated: 2026/08/15 23:26:55 by thialima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_strategy(t_ps *ps);

int	main(int argc, char **argv)
{
	t_ps	ps;
	int		i;

	init_ps(&ps);
	i = parse_flags(&ps, argc, argv);
	if (i >= argc)
		return (0);
	parse_numbers(&ps, argc - i, argv + i);
	ps.disorder = disorder_bp(&ps.a);
	to_ranks(&ps);
	run_strategy(&ps);
	if (ps.bench == 1)
		print_bench(&ps);
	free_ps(&ps);
	return (0);
}

static void	run_strategy(t_ps *ps)
{
	ps->used = ps->strat;
	if (ps->strat == ADAPTIVE)
	{
		if (ps->disorder < 2000)
			ps->used = SIMPLE;
		else if (ps->disorder < 5000)
			ps->used = MEDIUM;
		else
			ps->used = COMPLEX;
		if (ps->a.size <= 5)
		{
			ps->used = SIMPLE;
			sort_small(ps);
			return ;
		}
	}
	if (ps->used == SIMPLE)
		sort_simple(ps);
	else if (ps->used == MEDIUM)
		sort_medium(ps);
	else
		sort_complex(ps);
}
