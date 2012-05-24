#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>

#include "strutil.h"
#include "scli.h"
#include "dict.h"
#include "cp.h"
#include "app.h"

void do_rqst(char *s)
{
	char *p = s;
	char *cmd = NULL;
	int n;
	dict *d;

	p = str_next(s, &n);
	if (p == NULL)
		return;

	cmd = strndupa(p, n);
	printf("cmd={%s}\n", cmd);
	p += n;

	d = dict_new();

	parse_kvstring( p, d );

	//struct cp* cp;
	//if ( (cp=findcp(cmd, n )) != NULL )
	//	cp->cb( d );


	//dict_dump( d , stdout );

	add_rule_class_entry(d);
	show_port_counter(d);

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
