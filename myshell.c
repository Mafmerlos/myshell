#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

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
            printf("Saindo shell... Volte sempre!\n");
            break;
        }

        printf("Análise do comando:\n");
        for (int j = 0; j < i; j++) {
            printf("  Argumento[%d]: %s\n", j, args[j]);
        }
        printf("--- Fim da análise ---\n");
    }

    printf("Meu shell foi encerrado...\n");
    return 0;
}
