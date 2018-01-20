#include <filler.h>


int get_coord_board(int val, int max)
{
	if (val < 0)
		val = max - (val % (-1 * max));
	return (val % max);
}

void normalize_vector(t_vec *vec)
{
	float	norme;

	norme = ft_sqrt(vec->x * vec->x + vec->y * vec->y);
	vec->x /= norme;
	vec->y /= norme;
}

float ft_sqrt(int nbr)
{
	float	i;

	i = 0;
	dprintf(4, "entered.\n");
	if (!i)
		return (0);
	while (42)
	{
		dprintf(4, "in boucle----\n");
		if (i * i > nbr)
		{
			dprintf(4, "%f, %d\n", i, nbr);
			while (i * i > nbr)
			{
				dprintf(4, "%f, %d\n", i, nbr);
						i -= 0.1;
			}
			while (i * i > nbr)
			{
				dprintf(4, "%f, %d\n", i, nbr);
				i -= 0.01;
			}
			while (i * i > nbr)
			{
				dprintf(4, "%f, %d\n", i, nbr);
				i -= 0.001;
			}
			dprintf(4, "returned\n");
			return (i);
		}
		i++;
	}
}