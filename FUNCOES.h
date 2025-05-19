#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct
{
    int id;
    char descricao[100];
    int status;// 0 = não, 1 = sim
}Tarefa;

Tarefa base[100];



void adicionarTarefa();
//int convertorCharInt(char num1);
void pergunta();
void menu();
void listarTarefas();
void alterarStatus();
void removerTarefa();


#endif