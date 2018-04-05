#include "../header/push_swap.h"

void	fill_pixel(char *my_image, int x, int y, int color)
{
	int		start;

	if ((0 <= y && y < 800) && (0 <= x && x < 500))
	{
		start = 4 * (x + 500 * y);
		my_image[start] = (color & 0xFF);
		my_image[start + 1] = (color & 0xFF00) >> 8;
		my_image[start + 2] = (color & 0xFF0000) >> 16;
	}
}

void	make_img(t_list *a, t_param *p, char **img)
{
	int		x;
	int		y;
	int		x_len;
	int		y_size;

	y = 799;
	while (a)
	{
		x_len = *(int*)(a->content) * 400 / p->max;
		x_len = x_len > 0 ? x_len : -x_len;
		y_size = (float)700 / p->elem;
		while (y_size--)
		{
			x = 0;
			while (x <= x_len)
			{
				fill_pixel(*img, x, y, *(int*)(a->content) >= 0 ?
				(55 + x_len / 2) * 65536 + (int)(255 - x_len / 1.6) * 256 + 10 :
				10 * 65536 + (int)(255 - x_len / 1.6) * 256 +  55 + x_len / 2);
				x++;
			}
			y--;
		}
		a = a->next;
	}
}

int		drawer(t_list *a, t_list *b, t_param *p)
{
	void		*img;
	char		*img_add;
	int			i[3];

	img = mlx_new_image(p->mlx, 500, 800);
	img_add = mlx_get_data_addr(img, i, i + 1, i + 2);
	make_img(a, p, &img_add);
	mlx_put_image_to_window(p->mlx, p->win, img, 0, 0);
	mlx_destroy_image(p->mlx, img);
	img = mlx_new_image(p->mlx, 500, 800);
	img_add = mlx_get_data_addr(img, i, i + 1, i + 2);
	make_img(b, p, &img_add);
	mlx_put_image_to_window(p->mlx, p->win, img, 500, 0);
	mlx_destroy_image(p->mlx, img);
	return (1);
}

int		legend(t_param *p)
{
	char	*str;

	str = ft_itoa(p->nb);
	mlx_string_put(p->mlx, p->win, 20, 20, 0xFFFFFF, str);
	free(str);
	mlx_string_put(p->mlx, p->win, 700, 20, 0xFFFFFF,
		"S     : Stop or Start.");
	mlx_string_put(p->mlx, p->win, 700, 40, 0xFFFFFF,
		"Space : One step.");
	mlx_string_put(p->mlx, p->win, 700, 60, 0xFFFFFF,
		"ESC   : Close the program.");
	return (1);
}

int		graphic(t_list *a, t_list *b, t_param *p)
{
	drawer(a, b, p);
	legend(p);
	return (1);
}
