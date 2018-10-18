#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/*
https://pt.stackoverflow.com/questions/108678/como-ler-arquivos-de-texto-e-colocar-as-palavras-em-um-vetor
https://pt.stackoverflow.com/questions/42585/ler-dados-de-arquivos-separados-por-v%C3%ADrgulas-em-c
*/

struct funcionario
{
    char nome[30];
    char sexo[2];
    float salario;

};

int main()
{
    int i = 0;
    int numPalavras = 0;
    const char s[2] = "&";
    char* palavras[20];  /// ponteiro
    char line[22];
    char* result;

    FILE *arquivo;
    arquivo = fopen("funcionario.txt", "r");

    setlocale(LC_ALL, "PORTUGUESE");

    if (arquivo == NULL)
        return EXIT_FAILURE;

    while(!feof(arquivo))
    {
        fgets(line, sizeof line, arquivo);

        //printf("%c",line[20]);
        //break;
        ///Adiciona cada palavra no vetor
        palavras[i] = strdup(line);
       //strncpy(palavras, line ,20);
       //printf("[%s] \n",palavras);
       //break;

        i++;

        ///Conta a quantidade de palavras
        numPalavras++;
    }

    int j;

    for (j = 0; j < numPalavras; j++)
        printf("\n%s", palavras[j]); ///Exibi as palavras que estao no vetor.

    printf("\n\n");
    printf("Palavras: %i", numPalavras);

    fclose(arquivo);

    return EXIT_SUCCESS;
}
