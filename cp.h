

typedef int (*cmdhandler) ( void * );

int tpi_add_rule_class_entry(void *);
int tpi_del_rule_class_entry(void *);
int tpi_show_port_counter(void *);

cmdhandler cb;

const struct cp *findcp (register const char *, register unsigned int );


