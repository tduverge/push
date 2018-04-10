/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   one_genius_insert.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/10 16:37:38 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/10 16:43:21 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/push_swap.h"

void		do_insert_first(t_list **a, t_list **b, int dist_a, int dist_b)
{
	int		max;

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

void		do_insert_second(t_list **a, t_list **b, int dist_a, int dist_b)
{
	int		max;

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

void		do_insert_third(t_list **a, t_list **b, int dist_a, int dist_b)
{
	while (dist_a)
	{
		dist_a > 0 ? apply_actions_pshswp(a, b, RA, "ra\n") :
			apply_actions_pshswp(a, b, RRA, "rra\n");
		dist_a > 0 ? dist_a-- : dist_a++;
	}
	while (dist_b)
	{
		dist_b > 0 ? apply_actions_pshswp(a, b, RB, "rb\n") :
			apply_actions_pshswp(a, b, RRB, "rrb\n");
		dist_b > 0 ? dist_b-- : dist_b++;
	}
}

void		do_insert(t_list **a, t_list **b, int pos_in_a, int pos_in_b)
{
	int		dist_a;
	int		dist_b;

	dist_a = pos_in_a > (int)ft_lstlen(*a) / 2 ?
		pos_in_a - ft_lstlen(*a) : pos_in_a;
	dist_b = pos_in_b > (int)ft_lstlen(*b) / 2 ?
		pos_in_b - ft_lstlen(*b) : pos_in_b;
	if (dist_a >= 0 && dist_b >= 0)
		do_insert_first(a, b, dist_a, dist_b);
	else if (dist_a < 0 && dist_b < 0)
		do_insert_second(a, b, dist_a, dist_b);
	else
		do_insert_third(a, b, dist_a, dist_b);
	apply_actions_pshswp(a, b, PB, "pb\n");
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
