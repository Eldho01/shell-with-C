#include "builtins.h"


int is_builtin(char *cmd) {
    return (
        strcmp(cmd, "cd") == 0 ||
        strcmp(cmd, "pwd") == 0 
    );
}

int execute_builtin(char **args) {
    if (strcmp(args[0], "cd") == 0) {
        return handle_cd(args);
    } else if (strcmp(args[0], "pwd") == 0) {
        return handle_pwd();
    }

    return 0;
}

