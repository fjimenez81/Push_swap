/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:29:26 by fjimenez          #+#    #+#             */
/*   Updated: 2021/03/11 10:31:17 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_push_back(t_stack **sts, t_stack *new)
{
	t_stack *aux;

	if (*sts == NULL)
		*sts = new;
	else
	{
		aux = ft_get_last_node(*sts);
		aux->next = new;
	}
}

void ft_push_front(t_stack **first, t_stack *second)
{
	if (*first == NULL)
		*first = second;
	else
	{
		second->next = *first;
		*first = second;
	}
}
