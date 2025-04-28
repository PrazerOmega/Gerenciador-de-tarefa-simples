#include "FUNCOES.H"
#include <stdio.h>
#include <stdlib.h>

//Adicionar tarefa
//Listar tarefa
//Marcar tarefa concluida
//remover tarefa
//Sair do programa

void menu(){
    printf("\nEscolha uma das opções.\n1 - Adicionar uma tarefa\n2 - Visualizar tarefas\n3 - Alterar Status\n4 - Excluir Tarefa.");
}


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


/*void criaTarefa(char informacao[BUFFER], int arrayDes){
    printf("Diga qual tarefa voce deseja incluir:\n");
    fflush(stdin);
    fgets(informacao,15,stdin);
    snprintf(acao.descricao[arrayDes], BUFFER, "%s",informacao);
    acao.id[arrayDes] = 1;
    acao.concluida = 0;
    printf("\nTarefa: %sID: %d\nStatus: %s\n", acao.descricao[arrayDes], acao.id[arrayDes],
         acao.concluida?"concluida\n" : "Pendente\n");*/
  

void listarTarefas(){
    int escolha;
printf("Digite a tarefa que voce deseja visualizar: ");
scanf("%d", &escolha);

switch(escolha){

    case 1:
    printf("Tarefa:%s\nStatus:%d",base.descricao[0],base.concluida);
    break;
    case 2:
    printf("Tarefa:%s\nStatus:%d",base.descricao[1],base.concluida);
    break;
    case 3:
    printf("Tarefa:%s\nStatus:%d",base.descricao[2],base.concluida);
    break;
    case 4:
    printf("Tarefa:%s\nStatus:%d",base.descricao[3],base.concluida);
    break;
    case 5:
    printf("Tarefa:%s\nStatus:%d",base.descricao[4],base.concluida);
    break;
    case 6:
    printf("Tarefa:%s\nStatus:%d",base.descricao[5],base.concluida);
    break;
    case 7:
    printf("Tarefa:%s\nStatus:%d",base.descricao[6],base.concluida);
    break;
    case 8:
    printf("Tarefa:%s\nStatus:%d",base.descricao[7],base.concluida);
    break;
    case 9:
    printf("Tarefa:%s\nStatus:%d",base.descricao[8],base.concluida);
    break;
    case 10:
    printf("Tarefa:%s\nStatus:%d",base.descricao[9],base.concluida);
    break;
    default:
    printf("Opção invalida!\n Escolha outro numero.");
    listarTarefas;
}
menu();


}
void marcarConcluida();
void removerTarefa();