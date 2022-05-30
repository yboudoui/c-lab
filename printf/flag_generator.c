/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_generator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozzy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:55:41 by ozzy              #+#    #+#             */
/*   Updated: 2022/05/30 12:17:22 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef	struct s_double_char_array {
	char	**array;
	struct {
		size_t	x;
		size_t	y;
	}	size;
}	t_double_char_array;

void	ft_free(t_double_char_array *in)
{
	if (!in)
		return ;
	while (in->size.x--)
		free(in->array[in->size.x]);
	free(in->array);
	free(in);
}

t_double_char_array	*ft_allocate(size_t x, size_t y)
{
	t_double_char_array	*out;

	out = calloc(1, sizeof(t_double_char_array));
	if (!out)
		return (NULL);
	out->size.x = x;
	out->size.y = y;
	out->array = calloc(x, sizeof(char*));
	if (!out->array)
		return (NULL);
	while (--x)
	{
		out->array[x] = calloc(y, sizeof(char));
		if (!out->array[x])
			return(ft_free(out), NULL);
	}
	return (out);
}

t_double_char_array	*ft_format(char *flags)
{
	char				type;
	t_double_char_array	*out;

	type = 128;
	out = ft_allocate(128, BUFFER_SIZE);
	while (out && --type)
		sprintf(out->array[(int)type], "│ %%%%%s%c │%%%s%c│\n", flags, type, flags, type);
	return (out);
}

int	main(int argc, char **argv)
{
	t_double_char_array	*format;

	if (argc != 2)
		return (0);
	format = ft_format(argv[1]);
	printf(format->array['c'], 'Y');
	printf(format->array['s'], "Hello world");
	printf(format->array['p'], NULL);
	printf(format->array['d'], 42);
	printf(format->array['i'], 42);
	printf(format->array['u'], 42);
	printf(format->array['x'], 42);
	printf(format->array['X'], 42);
	printf(format->array['%'], 42);
	printf(format->array['k'], 42);
	ft_free(format);
}

