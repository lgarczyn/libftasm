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

#define			CONCAT_INNER(A, B) A##B
#define			CONCAT(A, B) CONCAT_INNER(A, B)
#define			CALL(F) {printf(#F"\n"); CONCAT(PREFIX, F);}

int				main(int argc, char **argv)
{
	char		test[100];

	CALL(bzero(test, 100));
	CALL(isprint('c'));
	CALL(isprint('\0'));
	CALL(toupper('c'));
	CALL(toupper('C'));
	CALL(toupper('\0'));
	CALL(tolower('c'));
	CALL(tolower('C'));
	CALL(tolower('\0'));
	CALL(puts("test"));
	CALL(strlen("test"));
	CALL(memset(test, 'c', 100));
	CALL(memcpy(test, test + 50, 50));
	CALL(strdup(test));
	CALL(cat(open("main.c", O_RDONLY)));
}
