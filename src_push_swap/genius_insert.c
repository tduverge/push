/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   genius_insert.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/09 17:17:49 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/10 12:18:51 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/push_swap.h"

int			where_insert(t_list **b, int value)
{
	t_list		*tmp;
	int			i;
	t_list		*last;
	int			len;
	int			max;

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
	{
		max = get_elem_max(*b);
		tmp = *b;
		i = 0;
		while (content(tmp) != max)
		{
			tmp = tmp->next;
			i++;
		}
	}
	return (i);
}

int			how_many(t_list **a, t_list **b, int pos_in_a, int pos_in_b)
{
	int		dist_a;
	int		dist_b;
	int		ret;

	dist_a = pos_in_a > (int)ft_lstlen(*a) / 2 ? pos_in_a - ft_lstlen(*a) : pos_in_a;
	dist_b = pos_in_b > (int)ft_lstlen(*b) / 2 ? pos_in_b - ft_lstlen(*b) : pos_in_b;
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

int			do_insert(t_list **a, t_list **b, int pos_in_a, int pos_in_b)
{
	int		dist_a;
	int		dist_b;
	int		max;

	dist_a = pos_in_a > (int)ft_lstlen(*a) / 2 ? pos_in_a - ft_lstlen(*a) : pos_in_a;
	dist_b = pos_in_b > (int)ft_lstlen(*b) / 2 ? pos_in_b - ft_lstlen(*b) : pos_in_b;
	if (dist_a >= 0 && dist_b >= 0)
	{
		max = dist_a > dist_b ? dist_a : dist_b;
		while (max)
		{
			if (dist_a && dist_b)
			{
				apply_actions_pshswp(a, b, RR, "rr\n");
				dist_a--;
				dist_b--;
			}
			else if (dist_a)
				apply_actions_pshswp(a, b, RA, "ra\n");
			else if (dist_b)
				apply_actions_pshswp(a, b, RB, "rb\n");
			max--;
		}
	}
	else if (dist_a < 0 && dist_b < 0)
	{
		max = dist_a < dist_b ? -dist_a : -dist_b;
		while (max)
		{
			if (dist_a && dist_b)
			{
				apply_actions_pshswp(a, b, RRR, "rrr\n");
				dist_a++;
				dist_b++;
			}
			else if (dist_a)
				apply_actions_pshswp(a, b, RRA, "rra\n");
			else if (dist_b)
				apply_actions_pshswp(a, b, RRB, "rrb\n");
			max--;
		}
	}
	else
	{
		while (dist_a)
		{
			dist_a > 0 ? apply_actions_pshswp(a, b, RA, "ra\n") : apply_actions_pshswp (a, b, RRA, "rra\n");
			dist_a > 0 ? dist_a-- : dist_a++;
		}
		while (dist_b)
		{
			dist_b > 0 ? apply_actions_pshswp(a, b, RB, "rb\n") : apply_actions_pshswp (a, b, RRB, "rrb\n");
			dist_b > 0 ? dist_b-- : dist_b++;
		}
	}
	apply_actions_pshswp(a, b, PB, "pb\n");
	return (dist_a > dist_b ? dist_a : dist_b);
}

void		one_insert(t_list **a, t_list **b)
{
	t_list		*tmp;
	int			pos_in_a;
	int			pos_in_b;
	int			min;
	int			save[2];

	pos_in_a = 0;
	min = -1;
	tmp = *a;
	while (tmp)
	{
		pos_in_b = where_insert(b, content(tmp));
		if (min == -1 || min > how_many(a, b, pos_in_a, pos_in_b))
		{
			save[0] = pos_in_a;
			save[1] = pos_in_b;
			min = how_many(a, b, pos_in_a, pos_in_b);
		}
		tmp = tmp->next;
		pos_in_a++;
	}
	do_insert(a, b, save[0], save[1]);
}

void		genius_insert(t_list **a, t_list **b)
{
	int		len;
	int		move;
	t_list	*tmp;

	move = 0;
	len = ft_lstlen(*a);
	while (len)
	{
		one_insert(a, b);
		len--;
	}
	tmp = *b;
	while (content(tmp) != 0)
	{
		tmp = tmp->next;
		move++;
	}
	if (move > len / 2)
	{
		move = len - move;
		while (move++ <= 0)
			apply_actions_pshswp(a, b, RB, "rb\n");
	}
	else
		while (move-- >= 0)
			apply_actions_pshswp(a, b, RRB, "rrb\n");
	len =ft_lstlen(*b);
	while (len)
	{
		apply_actions_pshswp(a, b, PA, "pa\n");
		len--;
	}
}
