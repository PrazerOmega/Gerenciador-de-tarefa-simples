#ifndef FUNCOES_H
#define FUNCOES_H
#define BUFFER 100

typedef struct
{
    int id;
    char descricao[100];
    int status;// 0 = não, 1 = sim
}Tarefa;

Tarefa base[BUFFER];



void questionAdd(),choreAdd();
void questionView(),choreView();
void questionStatus(),choreStatus();
void questionRemove(),choreRemove();
void menu();


#endif