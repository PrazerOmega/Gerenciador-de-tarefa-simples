#include "Includes.h"


//Adicionar tarefa
//Listar tarefa
//Marcar tarefa concluida
//remover tarefa
//Sair do programa

int main(void){
    setlocale(LC_ALL,"");

    noValues();

    loadBase("tarefas.dat");

    menu();

    saveBase("tarefa.dat");

    return 0;

}