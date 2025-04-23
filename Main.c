#include <stdlib.h>
#include <stdio.h>


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
<<<<<<< Updated upstream
    adicionarTarefa();

=======
    
    //adicionarTarefa();
    //listarTarefas();
    //menu();
>>>>>>> Stashed changes

return 0;
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
