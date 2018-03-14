/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_actions.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 19:20:19 by kbedene      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/27 19:20:27 by kbedene     ###    #+. /#+    ###.fr     */
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

static void		ps_pushes(int apply, t_list **a, t_list **b)
{
	if (apply == 0)
		push_pile(a, b);
	else
		push_pile(b, a);
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

void			apply_actions(t_list **a, t_list **b, t_list *cmds, char v)
{
	int		cmd;

	if (!cmds)
		return ;
	while (cmds)
	{
		cmd = *(int *)(cmds->content);
		if (cmd / 10 == 0)
			ps_swaps(cmd % 10, a, b);
		else if (cmd / 10 == 1)
			ps_pushes(cmd % 10, a, b);
		else if (cmd / 10 == 2)
			ps_rotates(cmd % 10, a, b);
		else if (cmd / 10 == 3)
			ps_revrots(cmd % 10, a, b);
		cmds = cmds->next;
		if (v)
			print_lsts(cmd, *a, *b);
	}
}
