/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 09:36:14 by fjimenez          #+#    #+#             */
/*   Updated: 2021/03/04 19:54:33 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_create_node(char *s, t_stacks *sts)
{
	t_stack	*new;
	int		val;

	val = ft_atoi(s);
	if (!ft_check_duplicate(sts->a, val) ||
		!(new = (t_stack*)malloc(sizeof(t_stack))))
		return (0);
	new->elem = val;
	new->next = NULL;
	ft_push_back(&sts->a, new);
	return (1);
}

int ft_add_cmd_aux(char *line, t_stacks *sts, int len, int ret)
{
	if (len == 2 && (line[0] == 'r' && line[1] == 'a'))
		ret = ft_handle_r(&sts->a);
	else if (len == 2 && (line[0] == 'r' && line[1] == 'b'))
		ret = ft_handle_r(&sts->b);
	else if (len == 2 && (line[0] == 'r' && line[1] == 'r'))
		ret = ft_handle_r(&sts->a);
	else if (len == 3 && (line[0] == 'r' && line[1] == 'r' && line[2] == 'a'))
		ret = ft_handle_rr(&sts->a);
	else if (len == 3 && (line[0] == 'r' && line[1] == 'r' && line[2] == 'b'))
		ret = ft_handle_rr(&sts->b);
	else if (len == 3 && (line[0] == 'r' && line[1] == 'r' && line[2] == 'r'))
		ret = ft_handle_rr(&sts->a);
	return (ret);
}

int ft_add_cmd(char *line, t_stacks *sts)
{
	int len;
	int ret;

	len = ft_strlen(line);
	ret = 0;
	if (len == 2 && (line[0] == 's' && line[1] == 'a'))
		ret = ft_handle_s(&sts->a);
	else if (len == 2 && (line[0] == 's' && line[1] == 'b'))
		ret = ft_handle_s(&sts->b);
	else if (len == 2 && (line[0] == 's' && line[1] == 's'))
		ret = ft_handle_s(&sts->a);
	else if (len == 2 && (line[0] == 'p' && line[1] == 'a'))
		ret = ft_handle_p(&sts->b, &sts->a);
	else if (len == 2 && (line[0] == 'p' && line[1] == 'b'))
		ret = ft_handle_p(&sts->a, &sts->b);
	ret = ft_add_cmd_aux(line, sts, len, ret);
	if (ret == -1)
		ret = 1;
	return (ret);
}

int ft_check_elements(t_stacks *sts)
{
	int val;
	t_stack *tmp;

	if (sts->b != NULL)
		return (0);
	tmp = sts->a;
	val = sts->a->elem;
	while (tmp)
	{
		if (val > tmp->elem)
			return (0);
		val = tmp->elem;
		tmp = tmp->next;
	}
	return (1);
}

int main(int ac, char **av)
{
	int i;
	char *line;
	char **aux;
	char **tmp;
	t_stacks *sts;
	
	if (!(sts = (t_stacks*)malloc(sizeof(t_stacks))))
		return (1);
	sts->a = NULL;
	sts->b = NULL;
	aux = NULL;
	if (ac == 2 && ft_strchr(av[1], ' '))
		aux = ft_split(av[1], ' ');
	tmp = (aux) ? aux : av;
	i = (aux) ? -1 : 0;
	while (tmp[++i])
	{
		if (!ft_check_digit(tmp[i]) || !ft_create_node(tmp[i], sts))
		{
			ft_putendl_fd("Error", 1);
			ft_free_stack(&sts);
			system("leaks checker");
			return (1);
		}
	}
	while (get_next_line(0, &line))
	{
		if (!ft_add_cmd(line, sts))
		{
			ft_putendl_fd("Error", 1);
			ft_free_stack(&sts);
			free(line);
			system("leaks checker");
			return (1);
		}
		if (line)
			free(line);
	}
	if (!ft_check_elements(sts))
		ft_putendl_fd("KO", 1);
	else
		ft_putendl_fd("OK", 1);
	ft_free_stack(&sts);
	if (aux)
		ft_free_tab(aux);
	system("leaks checker");
	return (0);
}