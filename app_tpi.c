#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "app_tpi.h"
#include "app.h"

#include "dict.h"
#include "argparse.h"


int tpi_add_rule_class_entry(void * dict)
{
	struct ce ce;//memset();
	int i=0;// define  enum  
	int ret = 0;
	struct argparse_option options[] = 
	{
		OPT_INTEGER(NULL,"sip", &ce.sip, &i, NO),
		OPT_INTEGER(NULL,"dip", &ce.dip, &i, NO),
		OPT_INTEGER(NULL,"sport", &ce.sport, &i, NO),
		OPT_INTEGER(NULL,"dport", &ce.dport, &i, NO),
		OPT_INTEGER64(NULL,"protocol", &ce.protocol, &i, NO),
		OPT_END(),
	};

	ret = argparse_parse((struct argparse_option *)&options, dict); //if  
	if(ret == -1){
		fprintf(stderr, "no value get and the value can't be NULL\n");
		return -1;
	}
		
	add_rule_class_entry(&ce);
	return 0;
}

int tpi_del_rule_class_entry(void *dict)
{
	struct ce ce;
	int i=0;// define  enum  
	int ret = 0;
	struct argparse_option options[] = 
	{
		OPT_INTEGER(NULL,"sip", &ce.sip, &i, NO),
		OPT_INTEGER(NULL,"dip", &ce.dip, &i, NO),
		OPT_INTEGER(NULL,"sport", &ce.sport, &i, NO),
		OPT_INTEGER(NULL,"dport", &ce.dport, &i, NO),
		OPT_INTEGER64(NULL,"protocol", &ce.protocol, &i, NO),
		OPT_END(),
	};

	ret = argparse_parse((struct argparse_option *)&options,dict);
	if(ret == -1){
		fprintf(stderr, "no value get and the value can't be NULL\n");
		return -1;
	}

	del_rule_class_entry(&ce);
	return 0;
}

int tpi_show_port_counter(void *dict)
{
	int port = 0;
	int i=0;// define  enum  
	int ret = 0;
	struct argparse_option options[] = 
	{
		OPT_INTEGER(NULL,"sport", &port, &i, NO),
	};

	ret =  argparse_parse((struct argparse_option *)&options,dict);
	if(ret == -1){
		fprintf(stderr, "no value get and the value can't be NULL\n");
		return -1;
	}

	show_port_counter(port);
	return 0;
}



