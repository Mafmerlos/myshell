#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


int main(){
char total_linhas[256];
char *saida;

while(true){
	printf("myshell> ");

	 if(fgets(total_linhas,sizeof(total_linhas),stdin)==NULL){
	 printf("\n");
	 break;
      }

	saida = (strtok(total_linhas," \n\r\t\a"));

	if(saida == NULL){
	continue;
	}

	if(strcmp(saida,"exit")==0){
		printf("Saindo shell... Volte sempre!\n");
		break;
}
		printf("Comando digitado ainda está na parte de desenvolvimento...\n");

}

printf("Meu shell foi encerrado...");
 return 0;
}
