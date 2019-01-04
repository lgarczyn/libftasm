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

#define			CONCAT_INNER(A, B) A##B
#define			CONCAT(A, B) CONCAT_INNER(A, B)

#define			TRY(F) {printf(": %s\n", F ? "success" : "failure");}

#ifdef LINUX
	#define PREFIX _ft_
#else
	#define PREFIX _ft
#endif

#define			CALL(F) {printf(#F); TRY(CONCAT(PREFIX, F));}
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

	CALL(isprint('c') != 0);
	CALL(isprint('\0') == 0);
	CALL(toupper('c') == 'C');
	CALL(toupper('C') == 'C');
	CALL(toupper('\0') == '\0');
	CALL(tolower('c') == 'c');
	CALL(tolower('C') == 'c');
	CALL(tolower('\0') == '\0');
	
	CALL(puts("test"));
	CALL(strlen("test") == 4);
	
	CALL(memset(test, 'c', 49));
	memset(test_ref, 'c', 49);
	TEST(memcmp(test, test_ref, 100) == 0);

	CALL(memcpy(test, test + 50, 50));
	memcpy(test_ref, test_ref + 50, 50);
	TEST(memcmp(test, test_ref, 100) == 0);	
	
	CALL(strdup(test));
	CALL(cat(open("main.c", O_RDONLY)));
}
