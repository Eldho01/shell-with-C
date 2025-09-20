#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "../builtins/builtins.h"

#define MAX_SHELL_INPUT 512
#define MAX_ARGS 32

void parse_input(char *input, char **args) {
    int i = 0;
    args[i] = strtok(input, " ");
    while (args[i] != NULL && i < MAX_ARGS - 1) {
        i++;
        args[i] = strtok(NULL, " ");
    }
    args[i] = NULL;
}

int main() {
    char input[MAX_SHELL_INPUT];
    char *args[MAX_ARGS];

    while (1) {
        printf("$ -> ");
        fflush(stdout);

        if (fgets(input, MAX_SHELL_INPUT, stdin) == NULL) {
            perror("fgets failed");
            continue;
        }

        // Remove trailing newline
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            printf("Exiting shell...\n");
            break;
        }

        parse_input(input, args);

        if (args[0] == NULL) continue;  // Skip empty input

        if (is_builtin(args[0])) {
          if (execute_builtin(args) == 1) {
            printf("Exiting shell...\n");
            break;
          }
          continue;
        }
      pid_t pid = fork();
        if (pid == 0) {
            // Child process
            if (execvp(args[0], args) == -1) {
                perror("execvp failed");
                exit(EXIT_FAILURE);
            }
        } else if (pid > 0) {
            // Parent process
            wait(NULL);
        } else {
            perror("fork failed");
         }
    }

    return 0;
}

