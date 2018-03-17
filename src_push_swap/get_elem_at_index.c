/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_elem_at_index.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:21:05 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 18:21:05 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/push_swap.h"

int		content(t_list *lst)
{
	return (*(int *)lst->content);
}

int		get_elem(t_list *pile, int elem)
{
	int		i;

	i = 0;
	while (pile && content(pile) != elem)
	{
		pile = pile->next;
		i++;
	}
	if (!pile)
		return (-1);
	return (i);
}

int		get_elem_last(t_list *pile)
{
	while (pile->next)
		pile = pile->next;
	return (content(pile));
}

int		get_elem_max(t_list *pile)
{
	int		max;

	max = content(pile);
	while (pile)
	{
		if (content(pile) > max)
			max = content(pile);
		pile = pile->next;
	}
	return (max);
}

int		get_elem_min(t_list *pile)
{
	int		min;

	min = content(pile);
	while (pile)
	{
		if (content(pile) < min)
			min = content(pile);
		pile = pile->next;
	}
	return (min);
}
