#ifndef SHELL_H_
#define SHELL_H_

#define _ILLEGAL_NUMBER_ "illegal number"
#define _EACCES_ "permission denied"
#define _CMD_NO_EXISTS "not found"
#define _ENOENT_ "no such directory"

typedef struct  {
char *cmd;

} sysfunction_t;

typedef struct {
int argc;
char *cmd;
char *env;
int pid;
int n_cmd;
int cur_path;
char *cmd_path;
char **argv;
char *buf;
int error_digit;
char **args;
int code_stat;
int it_mode;

} shell_t;

typedef struct {
char *msg;
int password;
} issue_t;

#endif
