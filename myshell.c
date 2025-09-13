#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define DELIMITADORES " \t\r\n\a"

int main() {
    char total_linhas[256];
    char *args[64];
    int i;

    while (true) {
        printf("myshell> ");

        if (fgets(total_linhas, sizeof(total_linhas), stdin) == NULL) {
            printf("\n");
            break;
        }

        i = 0;
        args[i] = strtok(total_linhas, DELIMITADORES);

        if (args[0] == NULL) {
            continue;
        }

        while (args[i] != NULL) {
            i++;
            args[i] = strtok(NULL, DELIMITADORES);
        }

        if (strcmp(args[0], "exit") == 0) {
            printf("Saindo do MyShell...\n");
            break;
        }

        pid_t pid = fork();

        if (pid < 0) {
            perror("myshell: erro no fork");
        } else if (pid == 0) {
            if (execvp(args[0], args) < 0) {
                perror("myshell");
                exit(EXIT_FAILURE);
            }
        } else {
            wait(NULL);
        }
    }

    printf("Programa encerrado.\n");
    return 0;
}
