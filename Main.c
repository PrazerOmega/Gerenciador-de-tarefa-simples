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
    char info[15];

//laço que recebe tarefa e aumenta o ID
    for (int i = 11; i > cont; cont++)
    {
        printf("Diga qual tarefa voce deseja incluir:\n");
        fflush(stdin);
        fgets(info,15,stdin);
        printf("%s", info);


        Tarefa info


        //casafgets(Tarefa,BUFFER,stdin);
       
    }
    
    




    }
