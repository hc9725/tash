#ifndef APP_H
#define APP_H
typedef unsigned long long int int64;

struct ce {

int sip;
int dip;
int sport;
int dport;
int64  protocol;

};

int add_rule_class_entry(struct ce *ce);
int del_rule_class_entry(struct ce *ce);
int show_port_counter(int port);

#endif
