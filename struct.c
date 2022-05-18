/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:57:52 by yboudoui          #+#    #+#             */
/*   Updated: 2022/05/14 13:12:23 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_yo {
	int				a;
	char			*b;

	struct s_yo		*next;

} t_yo;

int	main(void)
{
	t_yo	p;
	t_yo	H;
	t_yo	R;
	int 	a;


	a  = 42;


	char *t = "helo";
	p = {45, t};

	p = {.a = 45, .b = t};

	H = {.a = -87, .b = NULL, .next = &p};

	R = {.next = &H};

	p.a = 45;
	p.b = t;

	H.next->a; == p.a

	R.next->next->b = t;



	t_yo	Y;

	Y.next = R.next->next;
	R.next = &Y;

	R.next->next->b = t
}
