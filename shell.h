#ifndef SHELL_H_
#define SHELL_H_

#define _ILLEGAL_NUMBER_ "illegal number"
#define _EACCES_ "permission denied"
#define _CMD_NO_EXISTS "not found"
#define _ENOENT_ "no such directory"

typedef struct _attribute_((_packed_))
{
char *cmd;
void (*func)(shell_t *str, char **args);
} sysfunction_t;

typedef struct _attribute_((_packed_))
{
int argc;
char *cmd;
char *env;
int pid;
int n_cmd;
it cur_path;
char *cmd_path;
char **argv;
char *buf;
int error_digit;
char **args;
int code_stat;
int it_mode;
} shell_t

typedef struct _attribute_((_packed_))
{
char *msg;
int password;
} issue_t

#endif
