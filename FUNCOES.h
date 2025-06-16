#ifndef FUNCOES_H
#define FUNCOES_H
#define BUFFER 100

typedef struct
{
    int id;
    char descricao[500];
    int status;// 0 = não, 1 = sim
}Tarefa;

Tarefa base[BUFFER];



void questionAdd(),choreAdd();
void questionView(),choreView();
void questionStatus(),choreStatus();
void questionRemove(),choreRemove();
void menu();

int getId(), converterUni(int num), converterDec(int num1,int num2);
void noValues();



#endif