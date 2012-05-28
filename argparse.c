#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <memory.h>
#include "app.h"

#include "dict.h"
#include "argparse.h"


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

int get_dict_str(void *dict, char* s, char* des_str)
{
	char *str =  dict_get(dict, s, NULL);	
	if(str != NULL){
		*des_str = *str;
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


int argparse_parse(struct argparse *argps, dict *d)
{
	int i;
	char *str_k;
	for(; argps->options->type != OPTION_END; argps->options++){
		str_k = argps->options->key;
		switch(argps->options->type){
			case OPTION_INTEGER:{
				i = get_dict_int(d, str_k, (int *)argps->options->value);
				if(i == -1){
					if(argps->options->def_value){
						*(int *)argps->options->value = *(int *)argps->options->def_value;
						return 1;
					}
					else if(argps->options->force == 1)  
						return -1; // return -1: 	no key/value in the dict & no def_value.
					else return 2;//return 2: the value is NULL 
				}
			} break;

			case OPTION_STRING:{
				i = get_dict_str(d, str_k, (char *)argps->options->value);
				if(i == -1){
					if(argps->options->def_value){
						*(char *)argps->options->value = *(char *)argps->options->def_value;
					return 1; // return 1 : no key/value in the dict, using the def_value
					}
					else if(argps->options->force == 1) 
						return -1; // return -1: 	no key/value in the dict & no def_value.
					else return 2;//return 2: the value is NULL 
				}
			} break;

			case OPTION_IP: {
				i = get_dict_ip(d, str_k, (int *)argps->options->value);
				if(i == -1){
					if(argps->options->def_value){
						*(int *)argps->options->value = *(char *)argps->options->def_value;
						return 1; // return 1 : no key/value in the dict, using the def_value
					}else if(argps->options->force == 1) 
						return -1; // return -1: 	no key/value in the dict & no def_value.
					else return 2;//return 2: the value is NULL 
				}
			} break;

			case OPTION_INTEGER64:{
				i = get_dict_int64(d, str_k, (int64 *)argps->options->value);
				if(i == -1){
					if(argps->options->def_value){
						*(int64 *)argps->options->value = *(int64 *)argps->options->def_value;
						return 1; // return 1 : no key/value in the dict, using the def_value
					
					}
					else if(argps->options->force == 1) 
						return -1; // return -1: 	no key/value in the dict & no def_value.
					else return 2;//return 2: the value is NULL 
				}
			} break;
			
			case OPTION_BOOLEAN:
				break;
			default:
				return 3;//return 3:  wrong option type: ,argps->options->type
				break;
		}
		
	}
	return 0;		
}


