/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstis_sorted.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 18:31:12 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/14 13:33:47 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/push_swap.h"

int		ft_lstis_inorder_b(t_list *pile)
{
	int		connect;

	if (!pile)
		return (-1);
	connect = content(pile);
	if (!pile->next)
		return (ft_lstis_sorted_b(pile));
	while (pile->next && content(pile) > content(pile->next))
		pile = pile->next;
	if (!pile->next)
		return (1);
	pile = pile->next;
	while (pile->next && content(pile) > content(pile->next))
		pile = pile->next;
	if (!pile->next && content(pile) > connect)
		return (1);
	return (0);
}

int		ft_lstis_sorted_b(t_list *pile)
{
	t_list		*cur;
	t_list		*ahead;

	cur = pile;
	if (!cur)
		return (0);
	if (!(cur->next))
		return (1);
	ahead = cur->next;
	while (ahead && content(cur) > content(ahead))
	{
		cur = ahead;
		ahead = ahead->next;
	}
	if (!ahead)
		return (1);
	return (0);
}

/*
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
	while (ahead && content(cur) < content(ahead) && n--)
	{
		cur = ahead;
		ahead = ahead->next;
	}
	if (!n)
		return (1);
	return (0);
}
*/
