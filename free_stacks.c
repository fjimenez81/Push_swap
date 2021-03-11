/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:02:35 by fjimenez          #+#    #+#             */
/*   Updated: 2021/03/11 20:04:10 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_tab(char **s)
{
	int i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s[i]);
}

void	ft_free_stack(t_stacks *sts)
{
	t_stack *tmp;

	if (sts && sts->a)
	{
		while (sts->a)
		{
			tmp = sts->a->next;
			free(sts->a);
			sts->a = tmp;
		}
	}
	if (sts && sts->b)
	{
		while (sts->b)
		{
			tmp = sts->b->next;
			free(sts->b);
			sts->b = tmp;
		}
	}
	if (sts->args)
		ft_free_tab(sts->args);
}
