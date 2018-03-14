/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_actions_pshswp.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/28 16:58:10 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/13 12:09:58 by kbedene     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void		ps_swaps(int apply, t_list **a, t_list **b)
{
	if (apply == 0 || apply == 2)
		swap_pile(a);
	if (apply == 1 || apply == 2)
		swap_pile(b);
}

static void		ps_rotates(int apply, t_list **a, t_list **b)
{
	if (apply == 0 || apply == 2)
		rotate_pile(a);
	if (apply == 1 || apply == 2)
		rotate_pile(b);
}

static void		ps_revrots(int apply, t_list **a, t_list **b)
{
	if (apply == 0 || apply == 2)
		revrot_pile(a);
	if (apply == 1 || apply == 2)
		revrot_pile(b);
}

void			apply_actions_pshswp(t_list **a, t_list **b, int cmd, char *v)
{
	int		apply;

	if (v)
		ft_putstr(v);
	apply = cmd % 10;
	cmd /= 10;
	if (cmd == 0)
		ps_swaps(apply, a, b);
	else if (cmd == 1)
	{
		if (apply == 0)
			push_pile(a, b);
		else
			push_pile(b, a);
	}
	else if (cmd == 2)
		ps_rotates(apply, a, b);
	else
		ps_revrots(apply, a, b);
}
