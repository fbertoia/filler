#include <filler.h>

int		delpiece(t_d *data)
{
	int i;

	i = 0;
	while(i < data->piece_x)
	{
		ft_memdel((void**)&(data->piece)[i]);
		i++;
	}
	ft_memdel((void**)(&data->piece));
	return (1);
}

int		delboard(t_d *data)
{
	int i;

	i = 0;
	while(i < data->size_x)
	{
		ft_memdel((void**)&(data->board)[i]);
		i++;
	}
	ft_memdel((void**)(&data->board));
	return (1);
}