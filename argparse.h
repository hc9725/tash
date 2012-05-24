
enum argparse_option_type {
        OPTION_END,
	OPTION_BOOLEAN,
	OPTION_INTEGER,
	OPTION_STRING,
};


#define OPT_END() { OPTION_END }
#define OPT_BOOLEAN(s, l, v, h, c) { OPTION_BOOLEAN, (s), (l), (v), (h), (c) }
#define OPT_INTEGER(s, l, v, h, c) { OPTION_INTEGER, (s), (l), (v), (h), (c) }
#define OPT_STRING(s, l, v, h, c) { OPTION_STRING, (s), (l), (v), (h), (c) }

struct argparse
{

}
