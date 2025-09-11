#include "includes.h"

Tarefa base[BUFFER];


void noValues(void){
    for (int i = 0; i < BUFFER; ++i){
        base[i].id = i;
        base[i].descricao[0] = '\0';
        base[i].status = 0;
    }
}


void lerLinha(char *buf, size_t size){
    if (fgets(buf, (int)size, stdin) == NULL){
        buf[0] = '\0';
        return;
    }
    size_t ln = strcspn(buf, "\r\n");
    buf[ln] = '\0';
}

/* Leitura segura de inteiro com prompt. Retorna 1 se OK, 0 em erro/EOF. */
int lerInt(const char *prompt, int *out){
    char buf[64];
    char *endptr;
    long val;

    while (1){
        if (prompt) printf("%s", prompt);
        if (fgets(buf, sizeof(buf), stdin) == NULL) return 0;
        size_t ln = strcspn(buf, "\r\n");
        buf[ln] = '\0';
        if (buf[0] == '\0'){
            printf("Entrada vazia. Tente novamente.\n");
            continue;
        }
        val = strtol(buf, &endptr, 10);
        if (endptr == buf){
            printf("Entrada invalida. Digite um numero.\n");
            continue;
        }
        *out = (int)val;
        return 1;
    }
}

void clearScreen(void){
    system("cls");
}

int converterUni(int ch){return ch - '0';}
int converterDec(int d1, int d2){return (d1 - '0') * 10 +(d2 - '0');}

int getId(void){
    int Id;
    while(1){
        if(!lerInt("Digite o ID: ", &Id)) return -1;
        if(Id < 0 || Id >= BUFFER){
            printf("ID inválido. Digite entre 0 e %d\n", BUFFER-1);
            continue;
        }
        return Id;
    }
}

void saveBase(const char *filename){
    FILE *f = fopen(filename, "wb"); // wb = escrita binária
    if(!f){
        printf("Erro ao abrir o arquivo para salvar.\n");
        return;
    }

    size_t written = fwrite(base, sizeof(Tarefa), BUFFER, f);
    if(written != BUFFER){
        printf("Erro ao salvar algumas tarefas.\n");
    }

    fclose(f);
    printf("Base salva com sucesso!\n");
}

// Carrega a base de tarefas de um arquivo binário
void loadBase(const char *filename){
    FILE *f = fopen(filename, "rb"); // rb = leitura binária
    if(!f){
        printf("Arquivo não encontrado. Inicializando base vazia.\n");
        noValues(); // inicializa a base se o arquivo não existir
        return;
    }

    size_t read = fread(base, sizeof(Tarefa), BUFFER, f);
    if(read != BUFFER){
        printf("Aviso: nem todas as tarefas foram carregadas corretamente.\n");
    }

    fclose(f);
    printf("Base carregada com sucesso!\n");
}

void questionAdd(){

    int ret;
    printf("\nDeseja continuar a acresentar tarefas?\n1-Sim\n2-Não\n");
    lerInt("> ", &ret);

    if(ret == 1){
        system("cls");
        choreAdd();
    }else if(ret == 2){
        printf("Voltando ao menu...");
        Sleep(1500);
        system("cls");
    }else{
        printf("Escolha invalida!\n");
        Sleep(1000);
        questionAdd();
    }

}

void choreAdd(){

    char tarefa[DESC_SIZE];
    int numero = getId();
    if(numero < 0) return;

    printf("Escreva a tarefa: ");
    lerLinha(tarefa, sizeof(tarefa));

    base[numero].id = numero;
    strncpy(base[numero].descricao, tarefa, DESC_SIZE-1);
    base[numero].descricao[DESC_SIZE-1] = '\0';
    base[numero].status = 0;

    printf("Tarefa cadastrada com sucesso!\n");
    Sleep(1000);
    printf("ID: %d\nTarefa: %s\nStatus: %s\n",
            base[numero].id,
            base[numero].descricao,
            base[numero].status == 0? "Pendente" : "Concluida");
}


void questionView(void){
int choice;
printf("\n1- ver por ID\n2- Ver IDs disponiveis\n3- Voltar\n");
lerInt("> ", &choice);

    if(choice == 1){
        int id = getId();
        if(id >=0){
            printf("ID:%d\nTarefa:%s\nStatus:%s\n", 
            base[id].id,
            base[id].descricao[0] == '\0' ? "Nenhuma tarefa" : base[id].descricao,
            base[id].status == 0 ? "Pendente" : "Concluida");
        }
    }else if(choice == 2){
        printf("IDs disponiveis:\n");
        for(int i = 0; i < BUFFER; i++){
            if(base[i].descricao[0] == '\0') printf("%d\n", i);
        }
    }else if(choice ==  3){
            return;
        }
    else{
        printf("Opção invalida!\n");
    }
}


void choreView(void){
    questionView();
}

void questionStatus(void){
    int ret;
    printf("Voce deseja alterar outra tarefa?\n1-Sim\n2-Não\n");
    lerInt("> ", &ret);

    if(ret == 1){
    choreStatus();
    }
}

void choreStatus(void){
    int numero = getId();
    if(numero < 0) return;

    printf("ID: %d\nDescricao: %s\nStatus: %s\n", 
        base[numero].id,
        base[numero].descricao,
        base[numero].status == 0? "Pendente" : "Concluida");

        printf("Deseja alterar? \n1- Sim \n2 - Não");
        int escolha;
        lerInt("> ", &escolha);

        if(escolha == 1){
            base[numero].status = !base[numero].status;
            printf("Status alterado!\n");
        }
}

void questionRemove(){
int ret;
printf("\nDeseja remover outra tarefa?\n1- Sim\n2-Não\n");
lerInt("> ", &ret);
if(ret == 1) choreRemove();

}

void choreRemove(){
int numero = getId();
if(numero < 0) return;

if(base[numero].descricao[0] != '\0'){
    printf("Excluindo tarefa...\n");
    Sleep(1000);
    base[numero].descricao[0] = '\0';
    base[numero].status = 0;
    printf("Tarefa excluida com sucesso!\n");
}else{
    printf("Nenhuma tarefa salva nesse ID\n");
 }
}

void menu(void){
    char buf[32];

    while (1){
        printf("\n=== GERENCIADOR DE TAREFAS ===\n");
        printf("1 - Adicionar uma tarefa\n");
        printf("2 - Visualizar tarefas\n");
        printf("3 - Alterar Status\n");
        printf("4 - Excluir Tarefa\n");
        printf("0 - Fechar programa\n");
        printf("Escolha uma opcao: ");

        lerLinha(buf, sizeof(buf));
        if (buf[0] == '\0') continue;

        switch (buf[0]){
            case '0':
            printf("Saindo...\n");
            Sleep(1000);
            return;
            case '1':
            choreAdd(); break;
            case '2':
            choreView(); break;
            case '3':
            choreStatus(); break;
            case '4':
            choreRemove(); break;
            default:
            printf("Opção invalida!\n");
        }
    }
}
