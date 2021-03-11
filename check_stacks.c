/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:22:12 by fjimenez          #+#    #+#             */
/*   Updated: 2021/03/11 19:55:29 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_stb(t_stacks *sts)
{
	int max;

	if (sts->a->elem < ft_check_minnum(sts->b) ||
		sts->a->elem > ft_check_maxnum(sts->b))
		max = ft_search_max(sts, 0);
	else
		max = ft_search_max(sts, 1);
	ft_change_stack_b(sts, max);
}

void	ft_check_sta(t_stacks *sts)
{
	int		c;
	t_stack *tmp;

	tmp = sts->a;
	if (sts->b->elem < ft_check_minnum(tmp) ||
		sts->b->elem > ft_check_maxnum(tmp))
	{
		ft_search_min(sts);
		return ;
	}
	c = 0;
	while (tmp)
	{
		c++;
		if (tmp->next && sts->b->elem > tmp->elem &&
			sts->b->elem < tmp->next->elem)
			break ;
		tmp = tmp->next;
	}
	ft_change_stack_a(sts, c);
}

void	ft_change_stack_a(t_stacks *sts, int max)
{
	int i;
	int size;

	size = ft_stack_size(sts->a);
	if (max <= size / 2)
	{
		i = -1;
		while (++i < max)
			ft_handle_r(&sts->a, "ra");
	}
	else
	{
		i = -1;
		while (++i < (size - max))
			ft_handle_rr(&sts->a, "rra");
	}
}

void	ft_change_stack_b(t_stacks *sts, int max)
{
	int i;
	int size;

	size = ft_stack_size(sts->b);
	if (max <= size / 2)
	{
		i = -1;
		while (++i < max)
			ft_handle_r(&sts->b, "rb");
	}
	else
	{
		i = -1;
		while (++i < (size - max))
			ft_handle_rr(&sts->b, "rrb");
	}
}

int		ft_search_max(t_stacks *sts, int flag)
{
	t_stack *tmp;
	int		ret;

	tmp = sts->b;
	ret = 0;
	sts->max = ft_check_maxnum(sts->b);
	while (tmp)
	{
		if (flag)
			ret++;
		if (!flag && tmp->elem == sts->max)
			return (ret);
		if (!flag)
			ret++;
		if (flag && tmp->next && sts->a->elem < tmp->elem &&
			sts->a->elem > tmp->next->elem)
			break ;
		tmp = tmp->next;
	}
	return (ret);
}
