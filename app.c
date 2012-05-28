
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "app.h"

static char *ipaddress(int ip)
{
	struct in_addr in;
	in.s_addr=ip;
	return(inet_ntoa(in));
}

int add_rule_class_entry(struct ce *ce)
{
	printf("add:\n");
	printf("%s\n",ipaddress(ce->sip));
	printf("%s\n",ipaddress(ce->dip));
	printf("%d\n",ce->sport);
	printf("%d\n",ce->dport);
	printf("%llu\n",ce->protocol);
	return 0;
}


int del_rule_class_entry(struct ce *ce)
{
	printf("del:\n");
	printf("%s\n",ipaddress(ce->sip));
	printf("%s\n",ipaddress(ce->dip));
	printf("%d\n",ce->sport);
	printf("%d\n",ce->dport);
	printf("%llu\n",ce->protocol);
	return 0;
}

int show_port_counter(int port)
{
	printf("sport=%d\n",port);
	return 0;
}

