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
    char descricao[100];
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
    
    char info[15];

//loop that raises the ID and recieves a chore to do.
while (1)
{
    for (int i = 1; i < 11; i++)
    {
        switch (i)
        {
        case 1:
        printf("Diga qual tarefa voce deseja incluir:\n");
        fflush(stdin);
        fgets(info,15,stdin);
        snprintf(acao.descricao, BUFFER, "%s",info);
        acao.id[0] = 1;
        acao.concluida = 0;
        printf("Tarefa: %s, \nID: %d e status: %d", acao.descricao, acao.id[0], acao.concluida);
            break;
        

        default:
            break;
        }

    } 

        
        



        


        //casafgets(Tarefa,BUFFER,stdin);
       
    }
    
    




    }
