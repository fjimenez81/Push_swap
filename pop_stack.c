/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:50:32 by fjimenez          #+#    #+#             */
/*   Updated: 2021/03/04 19:20:39 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_pop_front(t_stack **st)
{
	t_stack *aux;

	if (!*st)
		return (NULL);
	aux = *st;
	if (!(*st)->next)
		*st = NULL;
	else
		*st = aux->next;
	aux->next = NULL;
	return (aux);
}

t_stack	*ft_pop_back(t_stack **st)
{
	t_stack *aux;
	t_stack *previus;

	if (!*st)
		return (NULL);
	aux = *st;
	previus = *st;
	if (!(*st)->next)
		*st = NULL;
	else
	{
		while (previus->next && previus->next->next)
			previus = previus->next;
		aux = previus->next;
		previus->next = NULL;
	}
	return (aux);
}