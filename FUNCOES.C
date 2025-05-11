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
    int escolha, slot;
    printf("Digite o ID da tarefa a ser incluida:\n");  
    escolha = getch();
    slot = escolha - '0';

    return slot;
}




void adicionarTarefa(){
    char tarefa[30];
    int loop = 1, cont = 0, slot = escolhaCase();
    base[slot].concluida = 0;
    printf("Escreva a tarefa: ");
    fflush(stdin);
    fgets(tarefa,sizeof(tarefa),stdin);
    base[slot].id = slot;
    strcpy(base[slot].descricao, tarefa);
    printf("Carregando...\n");
    Sleep(1720);
    printf("Tarefas cadastradas com sucesso!\nDetalhes:\n");
    printf("ID: %d\n",base[slot].id);
    printf("Tarefa: %s",base[slot].descricao);
    base[slot].concluida == 1? printf("Status: Concluido\n") : printf("Status: Pendente\n");
    Sleep(2000);
    pergunta();
}


//modelo original
/*
    while(1){
    
    switch (slot)
    {
    case '1':
    
    printf("Escreva a tarefa: ");
    fflush(stdin);
    fgets(tarefa,sizeof(tarefa),stdin);
    base.id[slot] = escolha;
    strcpy(base.descricao, tarefa);
    printf("ID: %c\nTarefa: %s", base.id[slot], base.descricao);
    pergunta();
        break;
    

*/
  

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
    int escolha;
printf("Digite a tarefa que voce deseja visualizar ou 0 para sair ");
scanf("%d", &escolha);

switch(escolha){

    case 0:
    menu();
    case 1:
    printf("Tarefa:%s\nStatus:%d",base[1].descricao,base[1].concluida);
    break;
    case 2:
    printf("Tarefa:%s\nStatus:%d",base[2].descricao,base[2].concluida);
    break;
    case 3:
    printf("Tarefa:%s\nStatus:%d",base[3].descricao,base[3].concluida);
    break;
    case 4:
    printf("Tarefa:%s\nStatus:%d",base[4].descricao,base[4].concluida);
    break;
    case 5:
    printf("Tarefa:%s\nStatus:%d",base[5].descricao,base[5].concluida);
    break;
    case 6:
    printf("Tarefa:%s\nStatus:%d",base[6].descricao,base[6].concluida);
    break;
    case 7:
    printf("Tarefa:%s\nStatus:%d",base[7].descricao,base[7].concluida);
    break;
    case 8:
    printf("Tarefa:%s\nStatus:%d",base[8].descricao,base[8].concluida);
    break;
    case 9:
    printf("Tarefa:%s\nStatus:%d",base[9].descricao,base[9].concluida);
    break;
    case 10:
    printf("Tarefa:%s\nStatus:%d",base[10].descricao,base[10].concluida);
    break;
    default:
    printf("Opção invalida!\n Escolha outro numero.");
    listarTarefas();
}
menu();


}
void marcarConcluida();
void removerTarefa();