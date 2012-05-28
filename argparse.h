#ifndef ARGPARSE_H
#define ARGPARSE_H
enum force {
	NO = 0,
	YES = 1,
};

enum argparse_option_type {
        OPTION_END,
	OPTION_BOOLEAN,
	OPTION_INTEGER,
	OPTION_INTEGER64,
	OPTION_STRING,
	OPTION_IP,
};


#define OPT_END() { OPTION_END }
#define OPT_BOOLEAN(n, k, v, d, f) { OPTION_BOOLEAN, (n), (k), (v), (d), (f) }
#define OPT_INTEGER(n, k, v, d, f) { OPTION_INTEGER, (n), (k), (v), (d), (f) }
#define OPT_INTEGER64(n, k, v, d, f) { OPTION_INTEGER64, (n), (k), (v), (d), (f) }
#define OPT_STRING( n, k, v, d, f) { OPTION_STRING,(n), (k), (v), (d), (f) }
#define OPT_IP(n, k, v, d, f) { OPTION_IP, (n), (k), (v), (d), (f) }

struct argparse_option
{
	enum argparse_option_type type;//类型
	char *name;//名
	char *key;
	void *value;//值
	void *def_value;//缺省值
	enum force  force;//是否可以为空
};

 struct argparse
{
	struct argparse_option *options;
	int unuseint;
	char* unusestr;
};

int64 get_dict_int64(void *dict, char* s, int64* n);
int get_dict_int(void *dict, char* s, int* n);
int get_dict_str(void *dict, char* s, char* des_str);
int  get_dict_ip(void *dict, char *s,int *ip);
int argparse_parse(struct argparse_option *options, dict *d);
//int argparse_parse(struct argparse *argparse, dict *d);
#endif
