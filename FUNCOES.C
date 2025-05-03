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
        printf("\nObrigado pela preferencia :)");
        Sleep(3000);
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

int convertorCharInt(char num1){
int result = num1 - '0';

return result;

}

void pergunta(){
    int escolha;    
    printf("Deseja continuar a acresentar tarefas?\n1-Sim\n2-Não");
    scanf("%d", &escolha);
    if(escolha == 1){
        adicionarTarefa();
    }else if(escolha == 2){
        menu();
    }else{
        printf("Escolha invalida! Por favor slecione uma opção valida!");
        pergunta();
    }

}

void adicionarTarefa(){
    setlocale(LC_ALL, "");
    int loop = 1, cont = 0, slot;
    char escolha, tarefa[200];
    printf("Digite o ID da tarefa a ser incluida:\n");  

    while(1){
    escolha = getch();
    //scanf("%d", &escolha);
    switch (escolha)
    {
    case '1':
    slot = (int)escolha;
    printf("Escreva a tarefa: ");
    fflush(stdin);
    fgets(tarefa,sizeof(tarefa),stdin);
    base.id[slot] = escolha;
    strcpy(base.descricao, tarefa);
    printf("ID: %c\nTarefa: %s", base.id[slot], base.descricao);
    printf("o teste: %c\n", base.id[0]);
    pergunta();
        break;
    
    
    default:
        break;
    }
    fflush(stdin);
    fgets(tarefa,100,stdin);
    base.id[cont] = cont;
    base.descricao[100] = tarefa[100];
    printf("ID: %d,\nTarefa: %s\n",base.id[cont], base.descricao);
        cont++;

        if(cont == 10){
            loop = 0;
            printf("Limite de tarefas atingido!");
            break;
        }


    
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
    listarTarefas();
}
menu();


}
void marcarConcluida();
void removerTarefa();