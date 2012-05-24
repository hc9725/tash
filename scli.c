#include <stdio.h>

char prompt[12];

#ifdef READLINE
#include <readline/readline.h>
#include <readline/history.h>

int scli_init( void )
{
	return 0;
}

int scli_set_option( char * opt, const char * value )
{
	if( strcmp( opt, "prompt" ) == 0 ) {
		strcpy( prompt, value );
	} else if ( strcmp( opt, "disable-completion" ) == 0 ) {
		rl_variable_bind("disable-completion", "On");
	}
	return 0;
}

char *scli_getline( void )
{
	char *s;
	s=readline(prompt);
	if( s == NULL ) return NULL;
	add_history(s);				
	return s;
}
#endif

#ifdef NOREADLINE
int scli_init( void )
{
	return 0;
}

int scli_set_option( char * opt, const char * value )
{
	return 0;
}

char buf[1024];

char *scli_getline( void )
{
	return fgets( buf,sizeof(buf), stdin );
}
#endif

#ifdef LINENOISE
int scli_init( void )
{
	return 0;
}

int scli_set_option( char * opt, const char * value )
{
	return 0;
}

char buf[1024];

char *scli_getline( void )
{
	return NULL;
}

#endif

