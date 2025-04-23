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


void criaTarefa(char informacao[BUFFER], int arrayDes){
    printf("Diga qual tarefa voce deseja incluir:\n");
    fflush(stdin);
    fgets(informacao,15,stdin);
    snprintf(acao.descricao[arrayDes], BUFFER, "%s",informacao);
    acao.id[arrayDes] = 1;
    acao.concluida = 0;
    printf("\nTarefa: %sID: %d\nStatus: %s\n", acao.descricao[arrayDes], acao.id[arrayDes],
         acao.concluida?"concluida\n" : "Pendente\n");
  


void menu(){

    printf("Escolha uma das opções.\n1 - Adicionar uma tarefa\n2 - Visualizar tarefas\n3 - Alterar Status\n4 - Excluir Tarefa.");
}


void listarTarefas();
void marcarConcluida();
void removerTarefa();