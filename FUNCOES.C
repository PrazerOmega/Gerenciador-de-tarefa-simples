#include "FUNCOES.H"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>

//Adicionar tarefa
//Listar tarefa
//Marcar tarefa concluida
//remover tarefa
//Sair do programa


int converterUni(int num){
    int convertido = num - '0';

    return convertido;
}

int converterDec(int num1, int num2){
    int convertido = (num1 - '0') * 10 + (num2 - '0');


    return convertido;
}

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
        printf("Entrando no menu...");
        Sleep(2500);
        system("cls");
        listarTarefas();
    case '3':
        printf("Entrando no menu...");
        Sleep(2500);
        system("cls");
        alterarStatus();
    /*case '4':
        removerTarefa();*/
    default:
        printf("Escolha invalida! Por favor slecione uma opção valida!");
        menu();
        }
    break;
    }
}


int escolhaCase(){
    int escolha[2], numero;
    printf("Digite o ID da tarefa a ser incluida:\n");  
    escolha[0] = getch();
    escolha[1] = getch();
    converterDec(escolha[0], escolha[1]);
   // numero = escolha[1] == '\r'? escolha[0] - '0' : (escolha[0] - '0') * 10 + (escolha[1]- '0');

    return numero;
}


void adicionarTarefa(){
    char tarefa[30];
    int loop = 1, cont = 0, numero = escolhaCase();
    base[numero].status = 0;

    printf("Escreva a tarefa: ");
    fflush(stdin);
    fgets(tarefa,sizeof(tarefa),stdin);
    base[numero].id = numero;
    strcpy(base[numero].descricao, tarefa);
    base[numero].status = 0;
    printf("Carregando...\n");
    Sleep(1720);
    printf("Tarefa cadastradas com sucesso!\nDetalhes da tarefa\n");
    printf("ID: %d\n",base[numero].id);
    printf("Tarefa: %s",base[numero].descricao);
    printf("Status: %s\n", base[numero].status == 0? "Pendente" : "Concluida!");
    Sleep(2000);
    pergunta();
}


void pergunta(){
    int ret;    
    printf("\nDeseja continuar a acresentar tarefas?\n1-Sim\n2-Não\n");
    ret = getch() - '0';
   
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
    int escolha[2], numero;

printf("Digite a tarefa que voce deseja visualizar ou 0 para sair ");
escolha[0] = getch();
escolha[1] = getch();
//scanf("%d", &escolha);

if (isdigit(escolha[0]) != 0 && isdigit(escolha[1]) != 0){
numero = (escolha[0] - '0') * 10 + (escolha[1] - '0');
}else{
    printf("Digite valores numericos, por favor\n");
    listarTarefas();
}

printf("\nCarregando...\n");
Sleep(1352);
system("cls");

for(int i = 0,cont = 0; i < sizeof(base[numero].descricao); i++){

    if(isalnum(base[numero].descricao[i])){
        cont++;
    }

    if (cont > 0)
    {
        printf("Tarefa %d \nDescrição: %s \nStatus: %s", base[numero].id, base[numero].descricao, base[numero].status == 0? "Pendete" : "Concluida");
        
    }else{   
    printf("Sem tarefa!");   
}
menu();
    }   
        }


void alterarStatus(){
    setlocale(LC_ALL,"");
    int escolha[3], numero, menu;

    printf("Digite o id da tarefa que deseja alterar:\n ");

    escolha[0]  = getch();
    escolha[1]  = getch();

    //numero = (escolha[0] - '0') * 10 + (escolha[1] - '0');
    converterDec(escolha[0],escolha[1]);

    printf("ID: %d\nTarefa: %s\nStatus atual: %s", base[numero].id, base[numero].descricao, base[numero].status == 0?"Pendente\n" : "Concluida\n");
    printf("Deseja alterar o status para %s", base[numero].status == 0?"Concluida?\n" : "Pendente?\n");
    printf("1-Sim\n2-Não\n");
    escolha[2] = getche();
    if(escolha[2] == 49){
        base[numero].status = 1;
    }else if(escolha[2] == 50){
        printf("Deseja voltar ao menu principal?\n1-Sim\n2-Não\n");
        menu = getch();
        if (menu == 49)
        {
            base[numero].status
        }
        
    }

}



















void removerTarefa();