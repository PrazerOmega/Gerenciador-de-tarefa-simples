#include "FUNCOES.H"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>

//Adicionar tarefa*
//Listar tarefa*
//Marcar tarefa concluida*
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

void perguntaADD(){
    int ret;
    
    printf("\nDeseja continuar a acresentar tarefas?\n1-Sim\n2-Não\n");
    ret = converterUni(getch());
    //ret = getch() - '0';
   
    if(ret == 1){
        system("cls");
        Sleep(500);
        adicionarTarefa();
    }else if(ret == 2){
        printf("Voltando ao menu...");
        Sleep(1500);
        system("cls");
        menu();
    }else{
        printf("Escolha invalida! Por favor selecione uma opção valida!");

        perguntaADD();
    }

}

void perguntaCheck(){
    int digits[2],number,choice;
    printf("Escolha uma das opções:\n1-Ver ID unico\n2-Ver ID's disponiveis\n");
    choice = getch();
    
    choice = converterUni(choice);

    if(choice == 1){
    printf("Por favor, digite o ID que deseja visualizar\n");
    digits[0] = getch();
    digits[1] = getch();
    
    
     if (isdigit(digits[0]) != 0 && isdigit(digits[1]) != 0){
     number = converterDec(digits[0], digits[1]);
     printf("Carregando...");
     Sleep(1500);
     system("cls");
     printf("ID:%d\nTarefa:%sStatus:%s\n",base[number].id,base[number].descricao,base[number].status == 0?"Pendente":"Concluida");
     Sleep(3000);
        menu();
}else{
    printf("\nDigite valores numericos, por favor\n");
    listarTarefas();
}
    }else if(choice == 2){

    }

}

void perguntaChange(){
    int ret;    
    printf("\nDeseja alterar outra tarefa?\n1-Sim\n2-Não\n");
    ret = getch() - '0';
   
    if(ret == 1){
        alterarStatus();
    }else if(ret == 2){
        printf("Voltando ao menu...");
        Sleep(1500);
        system("cls");
        menu();
    }else{
        printf("Escolha invalida! Por favor selecione uma opção valida!");
        perguntaADD();
    }

}

void perguntaEx(){
    int ret;    
    printf("\nDeseja procurar novamente ou voltar ao menu?\n1-Procurar novamente\n2-Menu\n");
    ret = getch() - '0';
   
    if(ret == 1){
        removerTarefa();
    }else if(ret == 2){
        printf("Voltando ao menu...");
        Sleep(1500);
        system("cls");
        menu();
    }else{
        printf("Escolha invalida! Por favor selecione uma opção valida!");
        perguntaADD();
    }

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
    case '4':
        removerTarefa();
    default:
        printf("Escolha invalida! Por favor slecione uma opção valida!");
        menu();
        }
    break;
    }
}


int getId(){
    int numero, num1, num2;
    printf("Digite o ID:\n");
    num1 = getch();
    num2 = getch();
    numero = converterDec(num1, num2);
    return numero;
}


void adicionarTarefa(){
    char tarefa[30];
    int loop = 1, cont = 0, numero = getId();
    base[numero].status = 0;

    printf("Escreva a tarefa: ");
    fflush(stdin);
    fgets(tarefa,sizeof(tarefa),stdin);
    base[numero].id = numero;
    strcpy(base[numero].descricao, tarefa);
    base[numero].status = 0;
    printf("Carregando...\n");
    Sleep(1720);
    printf("Tarefa cadastradas com sucesso!\n");
    Sleep(1450);  
    system("cls");      
    printf("Detalhes da tarefa\n");
    Sleep(700);
    printf("ID: %d\n",base[numero].id);
    printf("Tarefa: %s",base[numero].descricao);
    printf("Status: %s\n", base[numero].status == 0? "Pendente" : "Concluida!");
    Sleep(2450);
    //system("cls");
    perguntaADD();
}





void listarTarefas(){
    perguntaCheck();
    int escolha[2], numero;


if (isdigit(escolha[0]) != 0 && isdigit(escolha[1]) != 0){
    numero = converterDec(escolha[0], escolha[1]);
//numero = (escolha[0] - '0') * 10 + (escolha[1] - '0');
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
    
    int escolha[3], numero = getId();

    printf("Digite o id da tarefa que deseja alterar:\n ");

    printf("ID: %d\nTarefa: %s\nStatus atual: %s", base[numero].id, base[numero].descricao, base[numero].status == 0?"Pendente\n" : "Concluida\n");
    printf("Deseja alterar o status para %s", base[numero].status == 0?"Concluida?\n" : "Pendente?\n");
    printf("1-Sim\n2-Não\n");
    escolha[2] = getch();
    if(escolha[2] == 49){
        if(base[numero].status == 0){
        base[numero].status = 1;
        }else{
            base[numero].status = 0;
        }
        printf("Alterando status...");
        Sleep(1500);
        printf("Status alterado com sucesso!\n");
        printf("ID: %d\nDescrição: %s\nStatus: %s", base[numero].id, base[numero].descricao,base[numero].status == 0?"Pendente!":"Concluida" );
        Sleep(1850);
        perguntaChange();
    }else if(escolha[2] == 50){
        printf("Voltando ao menu...");
        Sleep(2255);
        system("cls");
        menu();
    }

}


void removerTarefa(){
    int numero = getId();
    char text[] = "";

    for(int i = 0,cont = 0; i < sizeof(base[numero].descricao); i++){

    if(isalnum(base[numero].descricao[i])){
        cont++;
    }

    if (cont > 0){
        //Função de excluir tarefa
        printf("Excluindo tarefa... " );
        Sleep(1350);
        strcpy(base[numero].descricao, text);
        printf("Tarefa excluida com sucesso!");
        system("cls");
        perguntaEx();
        

}else{
    printf("não foi encontrado nenhuma tarefa, por favor digite novamente ou volte para o menu");
    }
    perguntaEx();

    }
}