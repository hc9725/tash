

typedef int (*cmdhandler) ( void * d );

int add_rule_class_entry(void *);
int del_rule_class_entry(void *);
int show_port_counter(void *);

cmdhandler cb;

