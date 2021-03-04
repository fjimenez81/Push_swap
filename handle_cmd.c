/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 19:24:36 by fjimenez          #+#    #+#             */
/*   Updated: 2021/03/04 19:25:03 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_handle_s(t_stack **st)
{
	int val;

	if (*st && (*st)->next)
	{
		val = (*st)->elem;
		(*st)->elem = (*st)->next->elem;
		(*st)->next->elem = val;
		return (1);
	}
	return (-1);
}

int ft_handle_p(t_stack **first, t_stack **second)
{
	if (*first)
	{
		ft_push_front(second, ft_pop_front(first));
		return (1);
	}
	return (-1);
}

int ft_handle_r(t_stack **st)
{
	if (*st && (*st)->next)
	{
		ft_push_back(st, ft_pop_front(st));
		return (1);
	}
	return (-1);
}

int ft_handle_rr(t_stack **st)
{
	if (*st && (*st)->next)
	{
		ft_push_front(st, ft_pop_back(st));
		return (1);
	}
	return (-1);
}