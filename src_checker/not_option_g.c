#include "../header/push_swap.h"

void			not_option_g(t_list **a, t_list **b, t_param *p)
{
	p->a = a;
	p->b = b;
	p->nb = 0;
	p->end = 0;
	while (p->end == 0)
		one_step(p);
}
