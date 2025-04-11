#include <stdlib.h>
#include <stdio.h>
#define BUFFER 100


//Adicionar tarefa
//Listar tarefa
//Marcar tarefa concluida
//remover tarefa
//Sair do programa

typedef struct
{
    int id[10];
    char descricao[100];
    int concluida;// 0 = não, 1 = sim
}Tarefa;


void adicionarTarefa();
void listarTarefas();
void marcarConcluida();
void removerTarefa();


int main(){
    adicionarTarefa();


return 0;
}


void adicionarTarefa(){
    int cont = 0;
    int loop = 1;
    Tarefa teste;


    while(loop != 0){
    printf("\nDigite a tarefa a ser incluida!\n");
    fflush(stdin);
    fgets(teste.descricao,BUFFER,stdin);
    printf("tarefa: %s",teste.descricao);


        void criaTarefa(int numero, char descricao[BUFFER], int status){
        Tarefa I = {numero, descricao, status};
        }

        criaTarefa(teste.id,teste.descricao[BUFFER],teste.status);

    printf("%d,%s,%d",I.id,I.descricao,I.id);

    /*printf("primeiro valor: %d", teste.id[cont]);
    printf("\n\nDigite o ID: ");
    scanf("%d", &teste.id[0]);
    //fgets(teste.id, BUFFER,stdin);
    printf(" %d", teste.id[0]);*/

    
        cont++;

        if(cont > 10){
            loop = 0;
            printf("Limite de tarefas atingido!");
        }


    }
}
