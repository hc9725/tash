#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <string.h>

#include "dict.h"

char *str_next(char *s,int *length)
{
	char *p=s;
	size_t n;

	n=strspn(p," \t\r\n");
	p+=n;

	n=strcspn(p," \t\r\n");

	if( n < 1 ) return NULL;

	*length=n;

	return p;
}


int parse_kvstring( char *s, dict *d )
{
	char *p=s;
	int n=0, dis=0;

	while ((p = str_next(p, &n)) != NULL) {
		dis=strcspn( p, "=" );
		if( ( dis < n ) && ( dis > 0 ) ) {
			dict_add( d , strndupa( p, dis ), strndupa( p+dis+1, n-dis-1 ) );
		}
		p += n;
	}

	return 0;
}
