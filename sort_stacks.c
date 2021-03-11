/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:18:40 by fjimenez          #+#    #+#             */
/*   Updated: 2021/03/11 19:58:01 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stacks *sts)
{
	int min;

	min = ft_check_minnum(sts->a);
	if (!ft_sorted(sts->a, 1))
		ft_handle_s(&sts->a, "sa");
	if (sts->a->elem != min)
	{
		if (sts->a->next->elem == min)
			ft_handle_r(&sts->a, "ra");
		else
			ft_handle_rr(&sts->a, "rra");
	}
}

void	ft_sort_fourty(t_stacks *sts)
{
	while (!ft_sorted(sts->a, 1) && ft_stack_size(sts->a) > 3)
	{
		ft_check_stb(sts);
		ft_handle_p(&sts->a, &sts->b, "pb");
	}
	ft_sort_three(sts);
	while (sts->b)
	{
		ft_check_sta(sts);
		ft_handle_p(&sts->b, &sts->a, "pa");
	}
	ft_search_min(sts);
}
