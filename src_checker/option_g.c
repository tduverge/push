#include "../header/push_swap.h"

int				loop_funct(void *param)
{
	t_param		*p;

	p = param;
	if (p->nb == 0 && p->g)
		graphic(*(p->a), *(p->b), p);
	if (p->stop == 0)
		one_step(param);
	return (1);
}

int				one_step(void *param)
{
	t_param		*p;

	p = param;
	if (p->commands)
		apply_actions(p->a, p->b, p);
	else if (p->end == 0)
	{
		if (ft_is_sorted(*(p->a)) && !*(p->b))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		p->end = 1;
	}
	return (1);
}

int				key_funct(int keycode, void *param)
{
	t_param		*p;

	p = param;
	if (keycode == 53)
		exit(2);
	if (keycode == 1)
		p->stop = (p->stop == 0) ? 1 : 0;
	if (keycode == 49 && p->stop == 1)
		one_step(p);
	return (1);
}

void			option_g(t_list **a, t_list **b, t_param *p)
{
	t_list		*tmp;

	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, 1000, 800, "Pushswap");
	p->max = *(int*)((*a)->content);
	tmp = *a;
	while (tmp)
	{
		if ((*(int*)(tmp->content)) > 0 && (*(int*)(tmp->content)) > p->max)
			p->max = *(int*)(tmp->content);
		if ((*(int*)(tmp->content)) < 0 && -(*(int*)(tmp->content)) > p->max)
			p->max = -(*(int*)(tmp->content));
		tmp = tmp->next;
	}
	p->max = p->max == 0 ? 1 : p->max;
	p->a = a;
	p->b = b;
	p->nb = 0;
	p->end = 0;
	mlx_key_hook(p->win, key_funct, p);
	mlx_loop_hook(p->mlx, loop_funct, p);
	mlx_loop(p->mlx);
}
