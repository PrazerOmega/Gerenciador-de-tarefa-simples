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
    char descricao[10][100];
    int concluida;// 0 = não, 1 = sim
}Tarefa;

void menu();
void adicionarTarefa();
void criaTarefa();
void listarTarefas();
void marcarConcluida();
void removerTarefa();


int main(){

    
    
    //adicionarTarefa();
    //listarTarefas();
    //menu();

return 0;
}

void menu(){

    printf("Escolha uma das opções.\n1 - Adicionar uma tarefa\n2 - Visualizar tarefas\n3 - Alterar Status\n4 - Excluir Tarefa.");
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
  

void adicionarTarefa(){
    Tarefa acao;
    int i, escolha;
    char info[15];

//loop that raises the ID and recieves a chore to do.
while (1)
{
    printf("Oque deseja fazer?\n1- Alterar tarefa\n0- Voltar ao menu\n");
    scanf("%d", &escolha);
    if(escolha == 0){
        break;
    }else if(escolha == 1){

    printf("Escolha a tarefa pelo ID: ");
    scanf("%d", &i);
        switch (i)
        {
        case 1:
        criaTarefa(info, 0);
            break;
        case 2:
        criaTarefa(info, 1);
            break;
        case 3:
        criaTarefa(info, 2);
            break;
        case 4:
        criaTarefa(info, 3);
            break;
        case 5:
        criaTarefa(info, 4);
            break;
        case 6:
        criaTarefa(info, 5);
             break;
        case 7:
        criaTarefa(info, 6);
            break;
        case 8:
        criaTarefa(info, 7);
            break;   
        case 9:
        criaTarefa(info, 8);
            break;
        case 10:
        criaTarefa(info, 9);
            break;

        default:
        printf("Valor invalido\n");
            adicionarTarefa();
            
        }
     
       
    }else{
        printf("Escolha invalida!");
    }

    }
}
}

 void listarTarefas(){
    int *opcao;

    printf("Digite a opção que deseja.\n1- Visualizar tarefa unica\n2- Visualizar Todas as tarefas\n");
    scanf("%d", &opcao);

    if(opcao == 1){

    }

 }