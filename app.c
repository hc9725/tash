#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "app.h"

#include "dict.h"


static char *ipaddress(int ip)
{
	struct in_addr in;
	in.s_addr=ip;
	return(inet_ntoa(in));
}

int64 get_dict_int64(void *dict, char* s, int64* n)
{
	char *endptr;
	
	char *str =  dict_get(dict, s, NULL);	
	if(str != NULL){
		*n = strtoull(str, &endptr,0);
		return 0;		
	}
	return -1;
}

int get_dict_int(void *dict, char* s, int* n)
{
	char *endptr;
	
	char *str =  dict_get(dict, s, NULL);	
	if(str != NULL){
		*n = strtol(str, &endptr,0);
		return 0;		
	}
	return -1;
}

int  get_dict_ip(void *dict, char *s,int *ip)
{
	struct in_addr addr;
	char *str =  dict_get(dict, s, NULL);
	if(inet_aton(str, &addr) == 0){
		fprintf(stderr,"A  wrong ip.");
		return -1;
	}
	*ip = addr.s_addr;

	return 0;
}


int do_add_rule_class_entry(struct ce *ce)
{
	printf("add:\n");
	printf("%s\n",ipaddress(ce->sip));
	printf("%s\n",ipaddress(ce->dip));
	printf("%d\n",ce->sport);
	printf("%d\n",ce->dport);
	printf("%llu\n",ce->protocol);
	return 0;
}


int do_del_rule_class_entry(struct ce *ce)
{
	printf("del:\n");
	printf("%s\n",ipaddress(ce->sip));
	printf("%s\n",ipaddress(ce->dip));
	printf("%d\n",ce->sport);
	printf("%d\n",ce->dport);
	printf("%llu\n",ce->protocol);
	return 0;
}

int do_show_port_counter(int port)
{
	printf("sport=%d\n",port);
	return 0;
}

int add_rule_class_entry(void * dict)
{
	struct ce ce;
	//读取dict中的值，得用得到的值，初始化ce结构体，
	int ret;
	ret = get_dict_ip(dict, "sip", &ce.sip);
	if(ret == -1)
		return -1;

	ret  = get_dict_ip(dict, "dip", &ce.dip);
	if(ret == -1)
		return -1;

	ret = get_dict_int(dict, "sport", &ce.sport);
	if(ret == -1)
		return -1;

	ret =  get_dict_int(dict, "dport",&ce.dport);
	if(ret == -1)
		return -1;

	ret = get_dict_int64(dict, "protocol", &ce.protocol);
	if(ret == -1)
		return -1;

	do_add_rule_class_entry(&ce);
	return 0;
}

int del_rule_class_entry(void *dict)
{
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

	do_del_rule_class_entry(&ce);
	return 0;
}

int show_port_counter(void *dict)
{
	int port =0;
	int ret;
	ret = get_dict_int(dict,"sport", &port);
	if(ret == -1)
		return -1;
	do_show_port_counter(port);
	return 0;
}

