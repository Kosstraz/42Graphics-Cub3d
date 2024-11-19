#include "cub3d.h"

	// char[3] to color
t_color	ctocol(t_uchar r, t_uchar g, t_uchar b)
{
	t_color	ret;
	ret.r = r;
	ret.g = g;
	ret.b = b;
	ret._overflow = FALSE;
	return (ret);
}

	// color to int (hexa val) 0xRRGGBBAA with A=f
unsigned int	coltohexa(t_color col)
{
	return (
		(col.r << 16)
		| (col.g << 8)
		| (col.b << 4)
		| 0x000000ff
	);
}

t_color	stocol(const char *str)
{
	size_t	i;
	int		tmp;
	t_color	ret;

	ret._overflow = FALSE;
	i = 0;
	while (!ft_isdigit(str[i++]))
		;
	tmp = ft_atoi(&str[i]);
	if (tmp > 255)
		ret._overflow = TRUE;
	ret.r = tmp;
	while (ft_isdigit(str[i++]))
		;
	while (!ft_isdigit(str[i++]))
		;
	tmp = ft_atoi(&str[i]);
	if (tmp > 255)
		ret._overflow = TRUE;
	ret.g = tmp;
	while (ft_isdigit(str[i++]))
		;
	while (!ft_isdigit(str[i++]))
		;
	tmp = ft_atoi(&str[i]);
	if (tmp > 255)
		ret._overflow = TRUE;
	ret.b = tmp;
	return (ret);
}
