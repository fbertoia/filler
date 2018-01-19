#include <filler.h>

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
	while (42)
	{
		dprintf(4, "in boucle\n");
		if (i * i > nbr)
		{
			while (i * i > nbr)
				i -= 0.1;
			while (i * i > nbr)
				i -= 0.01;
			while (i * i > nbr)
				i -= 0.001;
			dprintf(4, "returned\n");
			return (i);
		}
		i++;
	}
}