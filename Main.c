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


void adicionarTarefa();
void listarTarefas();
void marcarConcluida();
void removerTarefa();


int main(){

    
    
    adicionarTarefa();


return 0;
}


void adicionarTarefa(){
    Tarefa acao;
    int i, escolha;
    char info[15];

//loop that raises the ID and recieves a chore to do.
while (1)
{
    printf("Oque deseja fazer?\n1- Alterar tarefa\n2- Voltar ao menu");
    scanf("%d", &escolha);
    if(escolha == 0){
        break;
    }else if(escolha == 1){

    printf("Escolha a tarefa pelo ID: ");
    scanf("%d", &i);
        switch (i)
        {
        case 1:
        printf("Diga qual tarefa voce deseja incluir:\n");
        fflush(stdin);
        fgets(info,15,stdin);
        snprintf(acao.descricao[0], BUFFER, "%s",info);
        acao.id[0] = 1;
        acao.concluida = 0;
        printf("\nTarefa: %sID: %d\nStatus: %s\n", acao.descricao[0], acao.id[0],
             acao.concluida?"concluida" : "Pendente");
            break;
        case 2:
        printf("Diga qual tarefa voce deseja incluir:\n");
        fflush(stdin);
        fgets(info,15,stdin);
        snprintf(acao.descricao[1], BUFFER, "%s",info);
        acao.id[1] = 2;
        acao.concluida = 0;
        printf("\nTarefa: %sID: %d\nStatus: %s\n", acao.descricao[1], acao.id[1],
             acao.concluida?"concluida" : "Pendente");
            break;
        case 3:
        printf("Diga qual tarefa voce deseja incluir:\n");
        fflush(stdin);
        fgets(info,15,stdin);
        snprintf(acao.descricao[2], BUFFER, "%s",info);
        acao.id[2] = 3;
        acao.concluida = 0;
        printf("\nTarefa: %sID: %d\nStatus: %s\n", acao.descricao[2], acao.id[2],
             acao.concluida?"concluida" : "Pendente");
            break;
        case 4:
        printf("Diga qual tarefa voce deseja incluir:\n");
        fflush(stdin);
        fgets(info,15,stdin);
        snprintf(acao.descricao[3], BUFFER, "%s",info);
        acao.id[3] = 1;
        acao.concluida = 0;
        printf("\nTarefa: %sID: %d\nStatus: %s\n", acao.descricao[3], acao.id[3],
             acao.concluida?"concluida" : "Pendente");
            break;
        case 5:
        printf("Diga qual tarefa voce deseja incluir:\n");
        fflush(stdin);
        fgets(info,15,stdin);
        snprintf(acao.descricao[4], BUFFER, "%s",info);
        acao.id[4] = 1;
        acao.concluida = 0;
        printf("\nTarefa: %sID: %d\nStatus: %s\n", acao.descricao[4], acao.id[4],
             acao.concluida?"concluida" : "Pendente");
            break;
        case 6:
         printf("Diga qual tarefa voce deseja incluir:\n");
         fflush(stdin);
         fgets(info,15,stdin);
         snprintf(acao.descricao[5], BUFFER, "%s",info);
         acao.id[5] = 1;
         acao.concluida = 0;
         printf("\nTarefa: %sID: %d\nStatus: %s\n", acao.descricao[5], acao.id[5],
              acao.concluida?"concluida" : "Pendente");
             break;
        case 7:
        printf("Diga qual tarefa voce deseja incluir:\n");
        fflush(stdin);
        fgets(info,15,stdin);
        snprintf(acao.descricao[6], BUFFER, "%s",info);
        acao.id[6] = 1;
        acao.concluida = 0;
        printf("\nTarefa: %sID: %d\nStatus: %s\n", acao.descricao[6], acao.id[6],
             acao.concluida?"concluida" : "Pendente");
            break;
        case 8:
        printf("Diga qual tarefa voce deseja incluir:\n");
        fflush(stdin);
        fgets(info,15,stdin);
        snprintf(acao.descricao[7], BUFFER, "%s",info);
        acao.id[7] = 1;
        acao.concluida = 0;
        printf("\nTarefa: %sID: %d\nStatus: %s\n", acao.descricao[7], acao.id[7],
             acao.concluida?"concluida" : "Pendente");
            break;   
        case 9:
        printf("Diga qual tarefa voce deseja incluir:\n");
        fflush(stdin);
        fgets(info,15,stdin);
        snprintf(acao.descricao[0], BUFFER, "%s",info);
        acao.id[8] = 1;
        acao.concluida = 0;
        printf("\nTarefa: %sID: %d\nStatus: %s\n", acao.descricao[8], acao.id[8],
             acao.concluida?"concluida" : "Pendente");
            break;
        case 10:
        printf("Diga qual tarefa voce deseja incluir:\n");
        fflush(stdin);
        fgets(info,15,stdin);
        snprintf(acao.descricao[9], BUFFER, "%s",info);
        acao.id[9] = 1;
        acao.concluida = 0;
        printf("\nTarefa: %sID: %d\nStatus: %s\n", acao.descricao[9], acao.id[9],
             acao.concluida?"concluida" : "Pendente");
            break;

        default:
        printf("Valor invalido\n");
            adicionarTarefa();
            
        }
     
       
    }else{
        printf("Escolha invalid'")
    }

    }
}