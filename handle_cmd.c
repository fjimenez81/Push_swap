/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 19:24:36 by fjimenez          #+#    #+#             */
/*   Updated: 2021/03/08 13:14:27 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_handle_s(t_stack **st, char *s)
{
	int val;

	if (*st && (*st)->next)
	{
		val = (*st)->elem;
		(*st)->elem = (*st)->next->elem;
		(*st)->next->elem = val;
		if (s)
			ft_putendl_fd(s, 1);
		return (1);
	}
	return (-1);
}

int ft_handle_p(t_stack **first, t_stack **second, char *s)
{
	if (*first)
	{
		ft_push_front(second, ft_pop_front(first));
		if (s)
			ft_putendl_fd(s, 1);
		return (1);
	}
	return (-1);
}

int ft_handle_r(t_stack **st, char *s)
{
	if (*st && (*st)->next)
	{
		ft_push_back(st, ft_pop_front(st));
		if (s)
			ft_putendl_fd(s, 1);
		return (1);
	}
	return (-1);
}

int ft_handle_rr(t_stack **st, char *s)
{
	if (*st && (*st)->next)
	{
		ft_push_front(st, ft_pop_back(st));
		if (s)
			ft_putendl_fd(s, 1);
		return (1);
	}
	return (-1);
}