/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   genius_insert.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/09 17:17:49 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/10 16:42:36 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/push_swap.h"

int			how_many(t_list **a, t_list **b, int pos_in_a, int pos_in_b)
{
	int		dist_a;
	int		dist_b;
	int		ret;

	dist_a = pos_in_a > (int)ft_lstlen(*a) / 2 ?
		pos_in_a - ft_lstlen(*a) : pos_in_a;
	dist_b = pos_in_b > (int)ft_lstlen(*b) / 2 ?
		pos_in_b - ft_lstlen(*b) : pos_in_b;
	if (dist_a >= 0 && dist_b >= 0)
		ret = dist_a > dist_b ? dist_a : dist_b;
	else if (dist_a < 0 && dist_b < 0)
		ret = dist_a < dist_b ? -dist_a : -dist_b;
	else
	{
		dist_a = dist_a > 0 ? dist_a : -dist_a;
		dist_b = dist_b > 0 ? dist_b : -dist_b;
		ret = dist_a + dist_b;
	}
	return (ret);
}

static int	extreme_insert(t_list **b)
{
	int		i;
	int		max;
	t_list	*tmp;

	max = get_elem_max(*b);
	tmp = *b;
	i = 0;
	while (content(tmp) != max)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int			where_insert(t_list **b, int value)
{
	t_list		*tmp;
	int			i;
	t_list		*last;
	int			len;

	if ((len = ft_lstlen(*b)) < 2)
		return (0);
	tmp = *b;
	while (tmp->next)
		tmp = tmp->next;
	last = tmp;
	tmp->next = *b;
	i = 0;
	while (!(content(tmp) > value && content(tmp->next) < value) && i <= len)
	{
		i++;
		tmp = tmp->next;
	}
	last->next = NULL;
	if (i == len + 1)
		return (extreme_insert(b));
	return (i);
}

static void	final_move(t_list **a, t_list **b)
{
	int		move;
	t_list	*tmp;
	int		max;
	int		len;

	move = 0;
	tmp = *b;
	max = get_elem_max(*b);
	while (content(tmp) != max)
	{
		tmp = tmp->next;
		move++;
	}
	len = (int)ft_lstlen(*b);
	if (move > len / 2)
	{
		move = len - move;
		while (move-- > 0)
			apply_actions_pshswp(a, b, RRB, "rrb\n");
	}
	else
		while (move-- > 0)
			apply_actions_pshswp(a, b, RB, "rb\n");
}

void		genius_insert(t_list **a, t_list **b)
{
	int		len;

	len = ft_lstlen(*a);
	while (len)
	{
		one_insert(a, b);
		len--;
	}
	final_move(a, b);
	len = ft_lstlen(*b);
	while (len)
	{
		apply_actions_pshswp(a, b, PA, "pa\n");
		len--;
	}
}
