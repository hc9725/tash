#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>

#include "scli.h"
#include "strutil.h"
#include "dict.h"
#include "cp.h"
#include "app.h"
#include "argparse.h"

struct cp { char *name; cmdhandler cb; };

void do_rqst(char *s)
{
	int n;
	char *p = s;
	char *cmd = NULL;
	const struct cp* cp;
	dict *d;

	p = str_next(s, &n);
	if (p == NULL)
		return;

	cmd = strndupa(p, n);
	printf("cmd={%s}\n", cmd);
	p += n;

	d = dict_new();

	parse_kvstring( p, d );
	if ( (cp=findcp(cmd, n )) != NULL ) {
		cp->cb( (void *)d );
	}

	dict_free( d );

	return;
}

int main()
{

	char *s;

	scli_init();
	scli_set_option("prompt", "# ");

	while ((s = scli_getline()) != NULL) {
		do_rqst(s);
	}

	exit(0);
}
