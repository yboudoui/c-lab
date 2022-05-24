/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:51:33 by yboudoui          #+#    #+#             */
/*   Updated: 2022/05/10 07:37:58 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

# ifdef ALL
# define ISALNUM
# define MEMMOVE
# endif 

#ifdef	ISALNUM

#include <ctype.h>
int	ft_isalnum(int c);

void	isalnum_test(void)
{
	int		i;
	i = -1;
	while (i < 530)
	{
		int	ft = !!ft_isalnum(i);
		int og = !!isalnum(i);
		if (ft != og)
			printf("FAIL at %d : %d - %d\n", i, ft, og);
		i++;
	}
}
#endif

#ifdef MEMMOVE
#include <string.h>
void	*ft_memmove(void *dest, const void *src, size_t n);

void	memmove_test(void)
{
	char	dst[30];
	char	*src = "Hello World";
	char	*res = memmove(NULL, NULL, 3);
	char	*fres = ft_memmove(NULL, NULL, 3);
	printf("%p\n%p\n", res, fres);
}
#endif

#ifdef MEMCPY
void	*ft_memcpy(void *dest, const void *src, size_t n);

int	main(void)
{
	char	dst[30];
	char	*src = "Hello World";
	char	*res = memcpy(NULL, NULL, 3);
	char	*fres = ft_memcpy(NULL, NULL, 3);
	printf("%p\n%p\n", res, fres);
}
#endif

int	main(void)
{

# ifdef ISALNUM
	isalnum_test();
#endif
# ifdef MEMMOVE
	memmove_test();
#endif

}
