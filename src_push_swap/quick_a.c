/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   quick_a.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:21:05 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/10 15:34:27 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/push_swap.h"

static float	calc_median_a(t_list *lst, int treat)
{
	int		min;
	int		max;

	min = content(lst);
	max = content(lst);
	while (treat--)
	{
		if (content(lst) < min)
			min = content(lst);
		if (content(lst) > max)
			max = content(lst);
		lst = lst->next;
	}
	return ((float)2 * (max - min) / 3 + min);
}

static void		rotate_or_push_a(t_list **a, t_list **b, int c, int *i)
{
	if (!c)
		apply_actions_pshswp(a, b, RA, "ra\n");
	else
		apply_actions_pshswp(a, b, PB, "pb\n");
	(*i)++;
}

static int		start_move(t_list **a, t_list **b, int *step, int i)
{
	if ((content(*a) == get_elem_last(*a) + 1) || step[i] == 1)
	{
		apply_actions_pshswp(a, b, RA, "ra\n");
		(step[i])--;
		quick_a(a, b, step, 1);
		return (1);
	}
	if (content((*a)->next) == get_elem_last(*a) + 1)
	{
		apply_actions_pshswp(a, b, SA, "sa\n");
		apply_actions_pshswp(a, b, RA, "ra\n");
		(step[i])--;
		quick_a(a, b, step, 1);
		return (1);
	}
	return (0);
}

static void		change_step(t_list **a, t_list **b, int *step, int treat)
{
	int		i;

	i = 0;
	while (step[i + 1])
		i++;
	if (treat == 4)
		change_step_4(a, b, treat);
	else if (treat == 3)
		change_step_3(a, b);
	else if (treat == 2)
		change_step_2(a, b);
	step[i] = 0;
	quick_a(a, b, step, 1);
}

void			quick_a(t_list **a, t_list **b, int *step, int test)
{
	int		treat;
	int		i;
	int		j[2];
	float	median;

	i = 0;
	while (step[i + 1])
		i++;
	if (test && start_move(a, b, step, i))
		return ;
	treat = step[i];
	median = calc_median_a(*a, treat);
	if (0 < treat && treat <= 4)
		return (change_step(a, b, step, treat));
	j[0] = 0;
	j[1] = 0;
	while (treat-- && j[1] < (2 * step[i] + 1) / 3)
		((float)content(*a)) > median ? rotate_or_push_a(a, b, 0, j) :
			rotate_or_push_a(a, b, 1, j + 1);
	step[i] -= j[1];
	while (j[0]-- && test)
		((float)content(*b) <= calc_median_b(*b)) ?
			apply_actions_pshswp(a, b, RRR, "rrr\n") :
			apply_actions_pshswp(a, b, RRA, "rra\n");
	step[0] ? quick_b(a, b, step) : 0;
}
