/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <yboudoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 23:31:18 by yboudoui          #+#    #+#             */
/*   Updated: 2022/05/30 00:42:51 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#define BIG (SIZE_MAX)

void m(char x)
{
	printf("%c", x);
}

void t(__int128_t u)
{
	if (u >= 10)
	{
		t(u/10);
		t(u%10);
	}
	else
		m(u + '0');
}

void ds(void)
{
	void* p = (void*)-1;
	printf("\n-: %llu", (unsigned long long)p);
}

int	main(void)
{
	unsigned long long int h = BIG;
	size_t	GG = BIG;
	long double g = BIG;
	__int128_t	k = BIG;
	void *z = (void*)BIG;
	printf("G: %llu\nh: %llu \ng: %llu\nz: %llu\nk: ", GG, h, g, z);
	t(k*200);
//	printf("\n\nh: %d\ng: %d\nz: %d\nk: %d\n", sizeof(h), sizeof(g), sizeof(z), sizeof(k));
	ds();
}
