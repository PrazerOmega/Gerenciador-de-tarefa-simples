#include "FUNCOES.H"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>

//Adicionar tarefa
//Listar tarefa
//Marcar tarefa concluida
//remover tarefa
//Sair do programa

void menu(){
    char escolha;
    printf("\nEscolha uma das opções.\n1 - Adicionar uma tarefa\n2 - Visualizar tarefas\n3 - Alterar Status\n4 - Excluir Tarefa\n0 - Fechar programa!\n");

 while(1){
    escolha = getch();
    //scanf("%d", &escolha);

    switch (escolha)
    {
    case '0':
        printf("Fechando o programa...");
        Sleep(3000);
        system("cls");
        printf("\nObrigado pela preferencia :)");
        Sleep(2050);
        system("cls");
        break;
    case '1':
        printf("Entrando no menu...");
        Sleep(2500);
        system("cls");
        adicionarTarefa();
        break;
    case '2':
        listarTarefas();
    /*case 3:
        marcarConcluida();
    case 4:
        removerTarefa();*/
    default:
    printf("Escolha invalida! Por favor slecione uma opção valida!");
    menu();
        }
    break;
    }
}

int escolhaCase(){
    int escolha[2], slot;
    printf("Digite o ID da tarefa a ser incluida:\n");  
    escolha[0] = getch();
    escolha[1] = getch();
    slot = escolha[1] == '\r'? escolha[0] - '0' : (escolha[0] - '0') * 10 + (escolha[1]- '0');

    return slot;
}




void adicionarTarefa(){
    char tarefa[30];
    int loop = 1, cont = 0, slot = escolhaCase();
    base[slot].status = 0;
    printf("Escreva a tarefa: ");
    fflush(stdin);
    fgets(tarefa,sizeof(tarefa),stdin);
    base[slot].id = slot;
    strcpy(base[slot].descricao, tarefa);
    printf("Carregando...\n");
    Sleep(1720);
    printf("Tarefas cadastradas com sucesso!\nDetalhes da tarefa:\n");
    printf("ID: %d\n",base[slot].id);
    printf("Tarefa: %s",base[slot].descricao);
    printf("Status: Pendente\n");
    Sleep(2000);
    pergunta();
}


  void pergunta(){
    int ret;    
    printf("\nDeseja continuar a acresentar tarefas?\n1-Sim\n2-Não\n");
    ret = getch() - '0';
   // scanf("%d", &escolha);
    if(ret == 1){
        adicionarTarefa();
    }else if(ret == 2){
        printf("Voltando ao menu...");
        Sleep(1500);
        system("cls");
        menu();
    }else{
        printf("Escolha invalida! Por favor selecione uma opção valida!");
        pergunta();
    }

}

void listarTarefas(){
    int escolha[2], slot;

printf("Digite a tarefa que voce deseja visualizar ou 0 para sair ");
escolha[0] = getch();
//scanf("%d", &escolha);

printf("Carregando...");
Sleep(1352);
system("cls");

if(base[escolha].descricao == NULL){
    printf("Nehuma tarefa adicionada");

}else{
    printf("Tarefa: %s\n", base[escolha].descricao);
base[escolha].status == 0?printf("Status: Pendente!") : printf("Concluida!");
} 

menu();

}

void marcarConcluida();
void removerTarefa();