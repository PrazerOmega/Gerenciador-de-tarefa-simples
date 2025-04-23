#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct
{
    int id[10];
    char descricao[100];
    int concluida;// 0 = não, 1 = sim
}Tarefa;


void adicionarTarefa();
void menu();
void listarTarefas();
void marcarConcluida();
void removerTarefa();


#endif