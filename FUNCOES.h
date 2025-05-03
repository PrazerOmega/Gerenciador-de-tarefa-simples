#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct
{
    int id[10];
    char descricao[100];
    int concluida;// 0 = não, 1 = sim
}Tarefa;

Tarefa base;



void adicionarTarefa();
//int convertorCharInt(char num1);
void pergunta();
void menu();
void listarTarefas();
void marcarConcluida();
void removerTarefa();


#endif