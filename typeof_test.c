/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeof_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:41:10 by yboudoui          #+#    #+#             */
/*   Updated: 2022/05/10 13:41:49 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static struct s_gglol {
	int	lol;
	struct s_gglol *node;
} myfunc(struct s_gglol *node, int olo)
{
	struct s_gglol MEGA_LOL;
	MEGA_LOL.lol = olo;
	MEGA_LOL.node = node;
return (MEGA_LOL);

}

int	main(void)
{
	char	*a;

	typeof(a) b = "hello world";
	typeof(myfunc(0, 0)) YY;
	YY.lol = 666;
	typeof(myfunc(0, 0)) GG = myfunc(&YY, 42);
	printf("%s\n%d\n", b, GG.lol);
	GG.lol = -42;
	printf("%s\n%d\n", b, GG.node->lol);
}
