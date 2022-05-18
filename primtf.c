/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primtf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:23:55 by yboudoui          #+#    #+#             */
/*   Updated: 2022/05/12 13:21:12 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

__attribute__((format (printf, 2, 3)))
void	my_printf(char *msg, const char *fmt, ...)
{
	va_list	args;

	printf("%s\n", msg);
	va_start (args, fmt);
	printf(fmt, args);
}

int	main(void)
{
	int	*a;

	my_printf("hello world", "%d\n", 5);
	a = (int [2]){
	0, 
	[0] = 1,
	};
	printf("%v\n", a[1]);
}
