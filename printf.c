/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 08:08:36 by yboudoui          #+#    #+#             */
/*   Updated: 2022/05/18 12:21:51 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#define BARRE "\u2502"

char	*barre(size_t size)
{
	char	barre[]	= "\u2502";
	char	*out	= calloc(sizeof(char), size);

	if (out)
		sprintf(out, "%s%%s%s\n", barre, barre);
	return(out);
}

char	**allocate(size_t d, size_t s)
{
	char	**out;
	size_t	index;

	index = 0;
	out = calloc(sizeof(char *), d);
	while (out && index < d)
	{
		out[index] = calloc(sizeof(char), s);
		if (!out[index])
		{
			index = 0;
			while (index < d)
				free(out[index++]);
			return (NULL);
		}
		index++;
	}
	return(out);
}

char	*format(char *flag, char type)
{
	char	**format;

	format = allocate(3, 30);
	sprintf(format[0], "%s%4s%c %s %%s %s\n", BARRE, flag, type, BARRE, BARRE);
	sprintf(format[1], format[0], "%%%s%c");
	sprintf(format[2], format[1], flag, type);
	return (format[2]);
}

int	main(void)
{
	int		a[2] = {42, -42};
	char	b[] = "hey";
	
//	printf(base, "0123456789");

	char *type;
	char *f = " -0#10.10";

	type = format(f, 'd');
	printf(type, a[0]);
	printf(type, a[1]);
	
	type = format(f, 's');
	printf(type, b);
}
