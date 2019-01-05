/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 19:40:32 by lgarczyn          #+#    #+#             */
/*   Updated: 2018/01/26 13:56:42 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define			TRY(F) {printf(": %s\n", F ? "success" : "failure");}

#define			CALL(F) {printf(#F); TRY(ft_##F);}
#define			TEST(F) {printf(#F); TRY(F);}

int				main(int argc, char **argv)
{
	char		test[101];
	char		test_ref[101];

	test[100] = '\0';
	test_ref[100] = '\0';

	bzero(test_ref, 100);
	CALL(bzero(test, 100));
	TEST(memcmp(test, test_ref, 100) == 0);

	for (int i = 0; i < 130; i++)
	{
		// if (i == 129)
		// {
		// 	i = 10000;
		// }
		printf("%i [%c]: %c ~%c O%c 1%c I%c a%c A%c ^%c v%c\n",
			i,
			ft_isprint(i) ? i : '?',
			ft_isascii(i) ? 'Y' : 'N',
			ft_isprint(i) ? 'Y' : 'N',
			ft_isalnum(i) ? 'Y' : 'N',
			ft_isdigit(i) ? 'Y' : 'N',
			ft_isalpha(i) ? 'Y' : 'N',
			ft_islower(i) ? 'Y' : 'N',
			ft_isupper(i) ? 'Y' : 'N',
			ft_isprint(i) ? ft_toupper(i) : '?',
			ft_isprint(i) ? ft_tolower(i) : '?');
	}

	CALL(puts("test"));
	CALL(strlen("test") == 4);
	
	CALL(memset(test, 'c', 49));
	memset(test_ref, 'c', 49);
	TEST(memcmp(test, test_ref, 100) == 0);

	CALL(strcat(test, "test again"));
	strcat(test_ref, "test again");
	TEST(memcmp(test, test_ref, 100) == 0);

	CALL(memcpy(test, test + 50, 50));
	memcpy(test_ref, test_ref + 50, 50);
	TEST(memcmp(test, test_ref, 100) == 0);	
	
	CALL(strdup(test));
	CALL(cat(open("src/ft_strlen.s", O_RDONLY)));
}
