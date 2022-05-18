/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:19:00 by yboudoui          #+#    #+#             */
/*   Updated: 2022/05/11 16:28:56 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(int argv, char **argc)
{
	int	fd = open(argc[1], O_RDONLY);
	char o[1000] = {0};
	int	rr = read(-42, o, 0);
	printf("%d,%s|\n", rr, o);
	close(fd);
}
