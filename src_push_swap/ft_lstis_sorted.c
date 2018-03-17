/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstis_sorted.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:21:05 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 18:21:05 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/push_swap.h"

int		ft_lstis_inorder(t_list *pile)
{
	int		connect;

	if (!pile)
		return (-1);
	connect = content(pile);
	if (!pile->next)
		return (ft_lstis_sorted(pile));
	while (pile->next && content(pile) < content(pile->next))
		pile = pile->next;
	if (!pile->next)
		return (1);
	pile = pile->next;
	while (pile->next && content(pile) < content(pile->next))
		pile = pile->next;
	if (!pile->next && content(pile) < connect)
		return (1);
	return (0);
}

int		ft_lstis_sorted(t_list *pile)
{
	t_list		*cur;
	t_list		*ahead;

	cur = pile;
	if (!cur)
		return (0);
	if (!(cur->next))
		return (1);
	ahead = cur->next;
	while (ahead && content(cur) < content(ahead))
	{
		cur = ahead;
		ahead = ahead->next;
	}
	if (!ahead)
		return (1);
	return (0);
}

int		ft_stepis_sorted(t_list *pile, int n)
{
	t_list		*cur;
	t_list		*ahead;

	cur = pile;
	if (!cur)
		return (0);
	if (!(cur->next))
		return (1);
	ahead = cur->next;
	n--;
	while (n-- && ahead && content(cur) < content(ahead))
	{
		cur = ahead;
		ahead = ahead->next;
	}
	if (n == -1)
		return (1);
	return (0);
}
