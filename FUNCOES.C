#include "Includes.h"

#define BUFFER 100
#define DESC_SIZE 256

typedef struct {
    int id; 
    char descricao[DESC_SIZE];
    int status; // 0 = pendente, 1 = concluída
} Tarefa;

/* Base de dados simples em memória */
Tarefa base[BUFFER];

/* Protótipos (as funções estão implementadas nas partes seguintes) */
void choreAdd(void);
void questionView(void);
void choreStatus(void);
void questionRemove(void);
void choreRemove(void);

/* --------------------------------------------------
   Inicializa 
   -------------------------------------------------- */
void noValues(void){
    for (int i = 0; i < BUFFER; ++i){
        base[i].id = i;
        base[i].descricao[0] = '\0';
        base[i].status = 0;
    }
}

/* Limpa o buffer de entrada (caso use fgets/scanf misturados) */
void clearInputBuffer(void){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

/* Leitura segura de linha (remove CR/LF) */
void lerLinha(char *buf, size_t size){
    if (fgets(buf, (int)size, stdin) == NULL){
        buf[0] = '\0';
        return;
    }
    size_t ln = strcspn(buf, "\r\n");
    buf[ln] = '\0';
}

/* Leitura segura de inteiro com prompt. Retorna 1 se OK, 0 em erro/EOF. */
int lerInt(const char *prompt, int *out){
    char buf[64];
    char *endptr;
    long val;

    while (1){
        if (prompt) printf("%s", prompt);
        if (fgets(buf, sizeof(buf), stdin) == NULL) return 0;
        size_t ln = strcspn(buf, "\r\n");
        buf[ln] = '\0';
        if (buf[0] == '\0'){
            printf("Entrada vazia. Tente novamente.\n");
            continue;
        }
        val = strtol(buf, &endptr, 10);
        if (endptr == buf){
            printf("Entrada invalida. Digite um numero.\n");
            continue;
        }
        *out = (int)val;
        return 1;
    }
}

void clearScreen(void){
    system("cls");
}



//Source file related to menu questions and actions

void questionAdd(){
    int ret;
    
    printf("\nDeseja continuar a acresentar tarefas?\n1-Sim\n2-Não\n");
    ret = converterUni(getch());
   
    if(ret == 1){
        system("cls");
        Sleep(500);
        choreAdd();
    }else if(ret == 2){
        printf("Voltando ao menu...");
        Sleep(1500);
        system("cls");
        menu();
    }else{
        printf("Escolha invalida! Por favor selecione uma opção valida!\n");
        Sleep(1000);
        questionAdd();
    }

}

void choreAdd(){
    char tarefa[BUFFER];
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
    questionAdd();
}


void questionView(){
    int digits[2],number,choice;
    printf("Escolha uma das opcoes:\n1-Ver ID unico\n2-Ver ID's disponiveis\n3-Voltar para o menu principal\n");
    choice = converterUni(getch());

    if(choice == 1){
     printf("Por favor, digite o ID que deseja visualizar\n");
     digits[0] = getch();
     digits[1] = getch();

        if (isdigit(digits[0]) != 0 && isdigit(digits[1]) != 0){
            number = converterDec(digits[0], digits[1]);
             printf("Carregando...");
               Sleep(1500);
                system("cls");
                printf("ID:%d\nTarefa:%sStatus:%s\n",number,base[number].descricao[0] == '\0'?"Nenhuma tarefa":base[number].descricao,base[number].status == 0?"Pendente\n":"Concluida\n");
                Sleep(2500);
                questionView();
    }else if(choice == 2){
     printf("\nDigite valores numericos, por favor\n");
        questionView();
    }  
 }else if (choice == 2){
    printf("Carregando...");
    Sleep(1250);
        for(int i = 0; i < BUFFER; i++){
            if(base[i].descricao[0] == '\0'){
                printf("%d\n",i);
            }
    }
    printf("...\n");
    Sleep(1250);
    questionView();
    }else if(choice == 3){
        printf("Aguarde...\n");
        Sleep(1500);
        system("cls");
        menu();
    }else{
        system("cls");
        printf("Escolha uma opcao valida!\n");
        Sleep(3000);
        system("cls");
        questionView();
    }
}

void choreView(){
    questionView();
    int escolha[2], numero;


if (isdigit(escolha[0]) != 0 && isdigit(escolha[1]) != 0){
    numero = converterDec(escolha[0], escolha[1]);

}else{
    printf("Digite valores numericos, por favor\n");
    choreView();
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


void questionStatus(){
    int ret;    
    printf("\nDeseja alterar outra tarefa?\n1-Sim\n2-Não\n");
    ret = getch() - '0';
   
    if(ret == 1){
        choreStatus();
    }else if(ret == 2){
        printf("Voltando ao menu...");
        Sleep(1500);
        system("cls");
        menu();
    }else{
        printf("Escolha invalida! Por favor selecione uma opção valida!");
        questionAdd();
    }

}

void choreStatus(){
    
    int escolha[3], numero = getId();

    printf("Digite o id da tarefa que deseja alterar:\n");

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
        Sleep(1950);
        printf("Status alterado com sucesso!\n");
        Sleep(2200);
        printf("ID:%d\nDescrição:%s\nStatus:%s", base[numero].id, base[numero].descricao,base[numero].status == 0?"Pendente!":"Concluida" );
        Sleep(1850);
        questionStatus();
    }else if(escolha[2] == 50){
        printf("Voltando ao menu...");
        Sleep(2255);
        system("cls");
        menu();
    }

}


void questionRemove(){
    int ret;    
    printf("\nDeseja procurar novamente ou voltar ao menu?\n1-Procurar novamente\n2-Menu\n");
    ret = getch() - '0';
   
    if(ret == 1){
        choreRemove();
    }else if(ret == 2){
        printf("Voltando ao menu...");
        Sleep(1500);
        system("cls");
        menu();
    }else{
        printf("Escolha invalida! Por favor selecione uma opção valida!");
        questionAdd();
    }

}

void choreRemove(){
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
        choreRemove();
        

}else{
    printf("não foi encontrado nenhuma tarefa, por favor digite novamente ou volte para o menu");
    }
    choreRemove();

    }
}



void menu(void){
    char buf[32];

    while (1){
        printf("\n=== GERENCIADOR DE TAREFAS ===\n");
        printf("1 - Adicionar uma tarefa\n");
        printf("2 - Visualizar tarefas\n");
        printf("3 - Alterar Status\n");
        printf("4 - Excluir Tarefa\n");
        printf("0 - Fechar programa\n");
        printf("Escolha uma opcao: ");

        lerLinha(buf, sizeof(buf));
        if (buf[0] == '\0'){
            printf("Escolha invalida. Tente novamente.\n");
            continue;
        }

        char opc = buf[0];

        switch (opc){
            case '0':
                printf("Fechando o programa...\n");
                Sleep(1500);
                clearScreen();
                printf("Obrigado pela preferencia :)\n");
                Sleep(1200);
                return; // sai do menu

            case '1':
                printf("Entrando no menu de adicionar...\n");
                Sleep(700);
                clearScreen();
                choreAdd();
                break;

            case '2':
                printf("Entrando no menu de visualizacao...\n");
                Sleep(700);
                clearScreen();
                questionView();
                break;

            case '3':
                printf("Entrando no menu de alteracao de status...\n");
                Sleep(700);
                clearScreen();
                choreStatus();
                break;

            case '4':
                printf("Entrando no menu de exclusao...\n");
                Sleep(700);
                clearScreen();
                questionRemove();
                break;

            default:
                printf("Escolha invalida! Por favor selecione uma opcao valida!\n");
                Sleep(1000);
                break;
        }
    }
}
