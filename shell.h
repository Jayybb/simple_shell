#ifndef SHELL_H_
#define SHELL_H_

#define _ILLEGAL_NUMBER_ "illegal number"
#define _EACCES_ "permission denied"
#define _CMD_NOT_EXISTS_ "not found"
#define _ENOENT_ "no such directory"

struct shell_t;

typedef struct __attribute__((__packed__))
{
    char *msg;
    int password;
} issue_t;

typedef struct __attribute__((__packed__))
{
    char *cmd;
    char *ccs;
    void (*func)(struct shell_t *mytype, char **arguments);
} sysFunction_t;

typedef struct __attribute__((__packed__))
{
    int argc;
    char *cmd;
    char *ccs;
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

#endif
