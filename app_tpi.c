#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "app_tpi.h"
#include "app.h"

#include "dict.h"
#include "argparse.h"

enum force
{
	NO =0,
	YES =1,
};


int tpi_add_rule_class_entry(void * dict)
{
	struct ce ce;//memset();
	struct argparse *argps; //del 
	int i=0,j=1;// define  enum  
	int ret;
	struct argparse_option options[] = 
	{
		OPT_INTEGER(NULL,"sip", &ce.sip, &i, j),
		OPT_INTEGER(NULL,"dip", &ce.dip, &i, j),
		OPT_INTEGER(NULL,"sport", &ce.sport, &i, j),
		OPT_INTEGER(NULL,"dport", &ce.dport, &i, j),
		OPT_INTEGER64(NULL,"protocol", &ce.protocol, &i, j),
		OPT_END(),
	};

	argps = (struct argparse*) malloc(sizeof(*argps));
	argps->options = options;
	
	ret = argparse_parse(argps, dict); //if  
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
	struct argparse *argps; //del 
	int i=0,j=1;// define  enum  
	int ret;
	struct argparse_option options[] = 
	{
		OPT_INTEGER(NULL,"sip", &ce.sip, &i, j),
		OPT_INTEGER(NULL,"dip", &ce.dip, &i, j),
		OPT_INTEGER(NULL,"sport", &ce.sport, &i, j),
		OPT_INTEGER(NULL,"dport", &ce.dport, &i, j),
		OPT_INTEGER64(NULL,"protocol", &ce.protocol, &i, j),
		OPT_END(),
	};

	argps = (struct argparse*) malloc(sizeof(*argps));
	argps->options = options;
	
	ret = argparse_parse(argps,dict);
	if(ret == -1){
		fprintf(stderr, "no value get and the value can't be NULL\n");
		return -1;
	}

	del_rule_class_entry(&ce);
	return 0;
/*
	struct ce ce;
	int ret;
	ret = get_dict_ip(dict, "sip",&ce.sip);
	if(ret == -1)
		return -1;

	ret  = get_dict_ip(dict, "dip",&ce.dip);
	if(ret == -1)
		return -1;

	ret = get_dict_int(dict, "sport", &ce.sport);
	if(ret == -1)
		return -1;

	ret =  get_dict_int(dict, "dport",&ce.dport);
	if(ret == -1)
		return -1;

	ret = get_dict_int64(dict, "protocol",&ce.protocol);
	if(ret == -1)
		return -1;

	del_rule_class_entry(&ce);
	return 0;
	*/
}

int tpi_show_port_counter(void *dict)
{
	int port = 0;
	struct argparse *argps; //del 
	int i=0,j=1;// define  enum  
	int ret;
	struct argparse_option options[] = 
	{
		OPT_INTEGER(NULL,"sport", &port, &i, j),
	};
	argps = (struct argparse*) malloc(sizeof(*argps));
	argps->options = options;
	ret =  argparse_parse(argps,dict);
	if(ret == -1){
		fprintf(stderr, "no value get and the value can't be NULL\n");
		return -1;
	}

	show_port_counter(port);
	return 0;
}



