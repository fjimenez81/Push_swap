/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:29:02 by fjimenez          #+#    #+#             */
/*   Updated: 2021/03/11 17:24:18 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_maxnum(t_stack *st)
{
    int		max;
	t_stack *tmp;

    max = 0;
	if (st)
		max = st->elem;
	tmp = st;
    while (tmp)
    {
        if (tmp->elem > max)
            max = tmp->elem;
		tmp = tmp->next;
    }
	return (max);
}

int ft_check_minnum(t_stack *st)
{
    int		min;
	t_stack *tmp;

    min = 0;
	if (st)
		min = st->elem;
	tmp = st;
    while (tmp)
    {
        if (tmp->elem < min)
            min = tmp->elem;
		tmp = tmp->next;
    }
	return (min);
}

int ft_sorted(t_stack *st, int flag)
{
    int		ret;
    t_stack *tmp;

    ret = 0;
    tmp = st;
    while (tmp && tmp->next)
    {
        if (tmp->elem > tmp->next->elem)
        {
            ret++;
            if (!flag)
                return (0);
        }
        tmp = tmp->next;
    }
    if (tmp->elem > st->elem)
        ret++;
    if (ret > 1 && flag)
        return (0);
    return (1);
}

int ft_stack_size(t_stack *st)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = st;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

void ft_search_min(t_stacks *sts)
{
	int min;
	int c;
	t_stack *tmp;

	min = ft_check_minnum(sts->a);
	tmp = sts->a;
	c = 0;
	while (tmp)
	{
		if (tmp->elem == min)
			break ;
		c++;
		tmp = tmp->next;
	}
	ft_change_stack_a(sts, c);
}
