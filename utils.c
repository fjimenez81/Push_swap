/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:05:37 by fjimenez          #+#    #+#             */
/*   Updated: 2021/03/04 17:57:46 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_digit(char *s)
{
	int i;

	i = -1;
	while (s[++i])
	{
		if (!ft_isdigit(s[i]))	
			return (0);
	}
	return (1);
}

void	ft_free_tab(char **s)
{
	int i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s[i]);
}

void	ft_free_stack(t_stacks **sts)
{
	t_stack *tmp;

	if (*sts && (*sts)->a)
	{
		while ((*sts)->a)
		{
			tmp = (*sts)->a->next;
			free((*sts)->a);
			(*sts)->a = tmp;
		}
	}
	if (*sts && (*sts)->b)
	{
		while ((*sts)->b)
		{
			tmp = (*sts)->b->next;
			free((*sts)->b);
			(*sts)->b = tmp;
		}
	}
	if (*sts)
		free(*sts);
}

t_stack	*ft_get_last_node(t_stack *st)
{
	while (st->next)
		st = st->next;
	return (st);
}

int		ft_check_duplicate(t_stack *check, int val)
{
	while (check)
	{
		if (check->elem == val)
			return (0);
		check = check->next;
	}
	return (1);
}