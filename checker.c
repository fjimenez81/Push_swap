/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 09:36:14 by fjimenez          #+#    #+#             */
/*   Updated: 2021/03/08 13:15:11 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_add_cmd_aux(char *line, t_stacks *sts, int len, int ret)
{
	if (len == 2 && (line[0] == 'r' && line[1] == 'a'))
		ret = ft_handle_r(&sts->a, NULL);
	else if (len == 2 && (line[0] == 'r' && line[1] == 'b'))
		ret = ft_handle_r(&sts->b, NULL);
	else if (len == 2 && (line[0] == 'r' && line[1] == 'r'))
		ret = ft_handle_r(&sts->a, NULL);
	else if (len == 3 && (line[0] == 'r' && line[1] == 'r' && line[2] == 'a'))
		ret = ft_handle_rr(&sts->a, NULL);
	else if (len == 3 && (line[0] == 'r' && line[1] == 'r' && line[2] == 'b'))
		ret = ft_handle_rr(&sts->b, NULL);
	else if (len == 3 && (line[0] == 'r' && line[1] == 'r' && line[2] == 'r'))
		ret = ft_handle_rr(&sts->a, NULL);
	return (ret);
}

int ft_add_cmd(char *line, t_stacks *sts)
{
	int len;
	int ret;

	len = ft_strlen(line);
	ret = 0;
	if (len == 2 && (line[0] == 's' && line[1] == 'a'))
		ret = ft_handle_s(&sts->a, NULL);
	else if (len == 2 && (line[0] == 's' && line[1] == 'b'))
		ret = ft_handle_s(&sts->b, NULL);
	else if (len == 2 && (line[0] == 's' && line[1] == 's'))
		ret = ft_handle_s(&sts->a, NULL);
	else if (len == 2 && (line[0] == 'p' && line[1] == 'a'))
		ret = ft_handle_p(&sts->b, &sts->a, NULL);
	else if (len == 2 && (line[0] == 'p' && line[1] == 'b'))
		ret = ft_handle_p(&sts->a, &sts->b, NULL);
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
	char *line;
	t_stacks sts;
	
	if (!ft_parse_args(ac, av, &sts))
		return (1);
	while (get_next_line(0, &line))
	{
		if (!ft_add_cmd(line, &sts))
		{
			ft_putendl_fd("Error", 1);
			ft_free_stack(&sts);
			free(line);
			//system("leaks checker");
			return (1);
		}
		if (line)
			free(line);
	}
	if (!ft_check_elements(&sts))
		ft_putendl_fd("\033[1;31mKO", 1);
	else
		ft_putendl_fd("\033[1;32mOK", 1);
	ft_free_stack(&sts);
	//system("leaks checker");
	return (0);
}