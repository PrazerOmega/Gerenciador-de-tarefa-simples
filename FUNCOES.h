#ifndef FUNCOES_H
#define FUNCOES_H

#include <stddef.h>

#define BUFFER 100
#define DESC_SIZE 256

typedef struct
{
    int id;
    char descricao[DESC_SIZE];
    int status;// 0 = não, 1 = sim
}Tarefa;

extern Tarefa base[BUFFER];

void noValues(void);
void menu(void);

void lerLinha(char*buf, size_t size);
int lerInt(const char *prompt, int *out);

int converterUni(int num);
int converterDec(int num1,int num2);
int getId(void);


void questionAdd(),choreAdd();
void questionView(),choreView();
void questionStatus(),choreStatus();
void questionRemove(),choreRemove();

void saveBase(const char*filename);
void loadBase(const char*filename);

#endif