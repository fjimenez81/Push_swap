/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:41:40 by fjimenez          #+#    #+#             */
/*   Updated: 2021/03/09 09:57:20 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_maxnum(t_stack *st)
{
    int max;
	t_stack *tmp;

    max = 0;
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
    int min;
	t_stack *tmp;

    min = st[0].elem;
	tmp = st;
    while (tmp)
    {
        if (tmp->elem < min)
            min = tmp->elem;
		tmp = tmp->next;
    }
	return (min);
}

void ft_sort_three(t_stacks *sts)
{
	if (!ft_sorted(sts->a))
		ft_handle_s(&sts->a, "sa");
}

int main(int ac, char **av)
{
    t_stacks sts;

    if (!ft_parse_args(ac, av, &sts))
		return (1);
    //if (sts.len < 4)
		//ft_sort_three(&sts);
    return (0);
}