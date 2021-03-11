/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:41:40 by fjimenez          #+#    #+#             */
/*   Updated: 2021/03/11 20:19:18 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_limit(t_stack *st, int limit)
{
	t_stack *tmp;

	tmp = st;
	while (tmp)
	{
		if (tmp->elem <= limit)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_change_pack(t_stacks *sts, int limit)
{
	while (sts->a && ft_check_limit(sts->a, limit))
	{
		if (sts->a->elem <= limit)
		{
			ft_check_stb(sts);
			ft_handle_p(&sts->a, &sts->b, "pb");
		}
		else
			ft_handle_r(&sts->a, "ra");
	}
	ft_change_stack_b(sts, ft_search_max(sts, 0));
}

void	ft_sort_infinite(t_stacks *sts)
{
	int pack;
	int div;
	int i;

	div = (sts->len <= 200) ? 5 : 11;
	pack = (ft_check_maxnum(sts->a) - ft_check_minnum(sts->a) / div);
	i = 0;
	while (++i < div)
		ft_change_pack(sts, pack * i);
	ft_change_pack(sts, ft_check_maxnum(sts->a) + 1);
	while (sts->b)
		ft_handle_p(&sts->b, &sts->a, "pa");
}

int		main(int ac, char **av)
{
	t_stacks sts;

	if (!ft_parse_args(ac, av, &sts))
		return (1);
	if (sts.len <= 3)
		ft_sort_three(&sts);
	else if (sts.len <= 40)
		ft_sort_fourty(&sts);
	else
		ft_sort_infinite(&sts);
	ft_free_stack(&sts);
	return (0);
}
