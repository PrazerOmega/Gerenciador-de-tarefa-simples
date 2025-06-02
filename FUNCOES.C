#include "Includes.h"

//Adicionar tarefa*
//Listar tarefa*
//Marcar tarefa concluida*
//remover tarefa
//Sair do programa

void noValues(){
for(int i = 0; i < sizeof(BUFFER); i++){

    char noValue[BUFFER] = "0";
    strcpy(base[i].descricao,noValue);

    }
}

int converterUni(int num){
    int convertido = num - '0';

    return convertido;
}

int converterDec(int num1, int num2){
    int convertido = (num1 - '0') * 10 + (num2 - '0');

    return convertido;
}


int getId(){
    int numero, num1, num2;
    printf("Digite o ID:\n");
    num1 = getch();
    num2 = getch();
    numero = converterDec(num1, num2);
    return numero;
}
