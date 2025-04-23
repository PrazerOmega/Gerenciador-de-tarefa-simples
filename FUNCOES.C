#include "FUNCOES.H"
#include <stdio.h>

//Adicionar tarefa
//Listar tarefa
//Marcar tarefa concluida
//remover tarefa
//Sair do programa

void adicionarTarefa(){
    int cont = 0;
    int loop = 1;
    char tarefa[100];
    Tarefa teste;


    while(loop != 0){
    printf("Digite a tarefa a ser incluida!");
    fflush(stdin);
    fgets(tarefa,100,stdin);
    teste.id[cont] = cont;
    teste.descricao[100] = tarefa[100];
    printf("ID: %d,\nTarefa: %s\n",teste.id[cont], teste.descricao);
        cont++;

        if(cont == 10){
            loop = 0;
            printf("Limite de tarefas atingido!");
        }


    }
}



void listarTarefas();
void marcarConcluida();
void removerTarefa();