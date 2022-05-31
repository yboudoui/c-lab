/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_generator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozzy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:55:41 by ozzy              #+#    #+#             */
/*   Updated: 2022/05/31 16:22:11 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#define BUFFER_SIZE 500

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
#define LINE "───────────────────────────────────"
#define COLOR "\033[0;36m"
#define RESET "\033[0m"
t_double_char_array	*ft_format(char *flags)
{
	char				type;
	int					n[2];
	t_double_char_array	*out;

	type = 128;
	out = ft_allocate(128, BUFFER_SIZE);
	while (out && --type)
		sprintf(out->array[(int)type],
		"\n"
		"%s"
		"╭%.*s╮\n"
		"│%s %n%%%%%s%c%n %s╞═>%s%%%s%c%s<═╣\n"
		"╰%.*s╯"
		"\033[0m\n",
		COLOR,
		((n[1] - n[0] + 1) * 3), LINE,
		RESET,
		&n[0], flags, type, &n[1],
		COLOR, RESET,
		flags, type,
		COLOR,
		((n[1] - n[0] + 1) * 3), LINE,
		RESET);
	return (out);
}

int	main(int argc, char **argv)
{
	t_double_char_array	*format;

	if (argc != 2)
		return (0);
	printf(
	"\n->\t'0' considere the actual size of data and then adding padding (only on the left side) to furfill the witdh parameter"
	"\n\t'-' Override this flag"
	"\n\tthis flag filled with zero character ONLY thoses type : 'd' 'i' 'u' 'x' 'X'"
	"\n\tand filled witf space character ONLY thoses type : 'c' 's'"
	"\n\thowever with 'p' type the behaviour change if the data is NULL or not."
	"\n\t\tSo considere when you expect value it will be padded with zeros"
	"\n\t\tand you get '(nil)' or any kind of `text` it will be padded with space."
	"\n\n->\t'width ALWAYS try to pad with space if the len of data is lower than width. It works with '-' how change the padding side");
	format = ft_format(argv[1]);

	printf(format->array['c'], 'Y');

	printf(format->array['s'], NULL);
	printf(format->array['s'], "Hello world");

	printf(format->array['p'], NULL);
	printf(format->array['p'], argv);

	printf(format->array['d'], 42);
	printf(
			"\t' ' '+'\n"
			"\t'0' fill only left side with 0");
	printf(format->array['i'], 42);
	printf(
			"\t' ' '+'\n");

	printf(format->array['u'], 42);

	printf(format->array['x'], 42);
	printf(
			"\t'#'\n");

	printf(format->array['X'], 42);
	printf(
			"\t'#'\n");

	printf(format->array['%'], 42);
	printf("\tprint ONLY %%");
	printf(format->array['k'], 42);
	printf("\tprint ONLY the wrong format");
	ft_free(format);
}

