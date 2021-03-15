/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:05:37 by fjimenez          #+#    #+#             */
/*   Updated: 2021/03/15 10:33:34 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_digit(char *s)
{
	int i;

	i = -1;
	while (s[++i])
	{
		if (i == 0 && s[i] == '-' && ft_isdigit(s[i + 1]) && s[i + 1] != '0')
			i++;
		if (!ft_isdigit(s[i]))
			return (0);
	}
	return (1);
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

int		ft_parse_args(int ac, char **av, t_stacks *sts)
{
	char	**tmp;
	int		i;

	if (ac == 1)
		return (0);
	ft_bzero(sts, sizeof(t_stacks));
	if (ac == 2 && ft_strchr(av[1], ' '))
		sts->args = ft_split(av[1], ' ');
	tmp = (sts->args) ? sts->args : av;
	i = (sts->args) ? -1 : 0;
	while (tmp[++i])
	{
		if (!ft_check_digit(tmp[i]) || !ft_create_node(tmp[i], sts))
		{
			ft_putendl_fd("Error", 2);
			ft_free_stack(sts);
			return (0);
		}
		sts->len++;
	}
	return (1);
}

int		ft_create_node(char *s, t_stacks *sts)
{
	t_stack	*new;
	int64_t	val;

	val = ft_ctm_atoi(s);
	if (val > INT_MAX || val < INT_MIN || !ft_check_duplicate(sts->a, val) ||
		!(new = (t_stack*)malloc(sizeof(t_stack))))
		return (0);
	new->elem = val;
	new->next = NULL;
	ft_push_back(&sts->a, new);
	return (1);
}
