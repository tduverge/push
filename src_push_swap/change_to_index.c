/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   change_to_index.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 18:21:04 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 18:21:04 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void		apply_index_tolst(int *tab, t_list *a)
{
	int			i;
	t_list		*cur;

	i = 0;
	cur = a;
	while (cur)
	{
		i = 0;
		while (*(int *)cur->content != tab[i])
			i++;
		*(int *)cur->content = i;
		cur = cur->next;
	}
}

void			change_to_index(t_list *a)
{
	int			length;
	int			*frsh;
	int			*tmp;
	t_list		*cur;
	int			i;

	length = ft_lstlen(a);
	if (!(frsh = ft_memalloc(length * sizeof(int))))
		return ;
	i = 0;
	cur = a;
	while (cur)
	{
		frsh[i] = *(int *)cur->content;
		cur = cur->next;
		i++;
	}
	tmp = frsh;
	frsh = ft_bubble_sort(frsh, length);
	i = 0;
	apply_index_tolst(frsh, a);
	free(tmp);
	free(frsh);
}
