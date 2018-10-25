#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

/*
https://pt.stackoverflow.com/questions/108678/como-ler-arquivos-de-texto-e-colocar-as-palavras-em-um-vetor
https://pt.stackoverflow.com/questions/42585/ler-dados-de-arquivos-separados-por-v%C3%ADrgulas-em-c
*/

typedef struct
{
    char nome[30];
    char sexo[2];
    float salario;

}funcionario;

int main()
{
    funcionario func[18];
    int i = 0;
    int k = 0;
    int bloco = 0;
    int numPalavras = 0;
    char line[22];
    char name[22];
    bool teste = false;

    FILE *arquivo;
    arquivo = fopen("funcionario.txt", "r");

    setlocale(LC_ALL, "PORTUGUESE");

    printf("Digite o nome para Busca:\n");
    scanf("%s",name);
    name[strlen(name)+1] = '\0';
    name[strlen(name)] = '&';
    //puts(name);
    //printf(">> %s - %d\n", name, strlen(name));

    printf("\n");

    if (arquivo == NULL)
        return EXIT_FAILURE;

    while(!feof(arquivo) && teste == false)
    {
        for(k=0; k<3; k++)
        {
            fgets(line, 22, arquivo);
            sscanf(line, "%s %s %f" ,func[i].nome, func[i].sexo, &func[i].salario);
            //printf("%s %s %f\n" ,func[i].nome, func[i].sexo, func[i].salario);
            getc(arquivo);

            ///Conta a quantidade de palavras

            numPalavras++;
           // printf("%s - %d\n", func[i].nome, strlen(func[i].nome));

            if(strcmp(name, func[i].nome) == 0)
            {
                printf("Nome: %s\nSexo: %s\nSalário: %0.2f\n",func[i].nome ,func[i].sexo ,func[i].salario);
                teste = true;
                //break;
            }
            i++;
            if(teste)
                break;
        }

        bloco++;

    }
    printf("\nBlocos: %d\n",bloco);
    printf("Comparações: %d\n",i);


    //int j;

    /*for (j = 0; j < numPalavras; j++)
        printf("\n%s", func[j].nome); ///Exibi as palavras que estao no vetor.

    printf("\n\n");*/


   //printf("Palavras: %i", numPalavras);

    fclose(arquivo);

    return EXIT_SUCCESS;
}
