# Gerenciador de Tarefas Simples

Gerenciador de tarefas de linha de comando escrito em C, feito para o console do Windows.
É o segundo projeto de gerenciamento de tarefas do autor, numa versão mais simples: não gera
arquivos `.txt`, guarda as tarefas em memória e grava tudo num único arquivo binário ao sair.

## Funcionalidades

- Cadastrar uma tarefa em um ID escolhido (de `0` a `99`)
- Consultar uma tarefa pelo ID
- Listar os IDs que ainda estão livres
- Alternar o status de uma tarefa entre **Pendente** e **Concluída**
- Excluir uma tarefa
- Salvar as tarefas em `tarefa.dat` ao fechar o programa

## Requisitos

- **Windows**: o código usa `windows.h` (`Sleep`), `conio.h` e `system("cls")`
- **GCC via MinGW**: a configuração do VS Code espera o compilador em `C:/MinGW/bin/gcc.exe`
  e o depurador em `C:/MinGW/bin/gdb.exe`

No Linux ou no macOS o projeto não compila sem adaptações. Veja
[Limitações e problemas conhecidos](#limitações-e-problemas-conhecidos).

## Como compilar e executar

### Opção 1: `build.bat`

Na pasta do projeto, rode:

```bat
build.bat
```

O script compila `Main.c` e `FUNCOES.C`, gera `main.exe` e já abre o programa.

### Opção 2: VS Code

O projeto já vem com a pasta `.vscode` configurada:

- **Compilar**: `Ctrl+Shift+B` roda a task `build` (`gcc -g main.c funcoes.c -o main.exe`)
- **Depurar**: `F5` usa a configuração *Debug C com GCC*, que compila e abre o programa
  num console externo com o `gdb`

### Opção 3: na mão

```bat
gcc -x c Main.c FUNCOES.C -o main.exe
main.exe
```

O `-x c` força o GCC a tratar `FUNCOES.C` como C. Sem ele, a extensão `.C` em maiúsculo
é interpretada como C++ em sistemas que diferenciam maiúsculas de minúsculas.

## Como usar

Ao abrir, o programa carrega as tarefas salvas e mostra o menu principal:

```
=== GERENCIADOR DE TAREFAS ===
1 - Adicionar uma tarefa
2 - Visualizar tarefas
3 - Alterar Status
4 - Excluir Tarefa
0 - Fechar programa
Escolha uma opcao:
```

| Opção | O que faz |
|-------|-----------|
| `1` | Pede um ID (0 a 99) e a descrição. A tarefa nasce como **Pendente**. Se o ID já tiver uma tarefa, ela é substituída sem aviso. |
| `2` | Abre um submenu: `1` mostra a tarefa de um ID, `2` lista os IDs **livres** e `3` volta. |
| `3` | Mostra a tarefa do ID informado e pergunta se deve alterar. Confirmando, o status alterna entre Pendente e Concluída. |
| `4` | Apaga a descrição e zera o status do ID informado. Se o ID já estiver vazio, só avisa. |
| `0` | Sai do programa e salva as tarefas em `tarefa.dat`. |

Exemplo de cadastro:

```
Escolha uma opcao: 1
Digite o ID: 5
Escreva a tarefa: Comprar pão
Tarefa cadastrada com sucesso!
ID: 5
Tarefa: Comprar pão
Status: Pendente
```

> As tarefas só são gravadas no disco quando você sai pela opção `0`. Se fechar a janela
> do console, as alterações da sessão se perdem.

## Como os dados são guardados

As tarefas ficam num vetor fixo de 100 posições (`base[BUFFER]`). O ID de uma tarefa é a
própria posição dela no vetor. Uma posição está vazia quando a descrição é uma string vazia.

Cada tarefa é uma `struct`:

```c
typedef struct {
    int  id;
    char descricao[256];  // DESC_SIZE
    int  status;          // 0 = Pendente, 1 = Concluída
} Tarefa;
```

Ao sair, o vetor inteiro é gravado de uma vez com `fwrite` em `tarefa.dat`. São 100 registros
de 264 bytes, o que dá 26.400 bytes. Como é uma cópia direta da memória, o arquivo depende do
compilador e da arquitetura e não deve ser editado à mão.

## Estrutura do projeto

| Arquivo | Conteúdo |
|---------|----------|
| `Main.c` | Ponto de entrada: inicializa a base, carrega o arquivo, abre o menu e salva ao sair |
| `FUNCOES.C` | Toda a lógica: leitura de entrada, menu, cadastro, consulta, status, exclusão e persistência |
| `FUNCOES.h` | Constantes (`BUFFER`, `DESC_SIZE`), a `struct Tarefa` e os protótipos das funções |
| `Includes.h` | Junta os includes da biblioteca padrão, do Windows e do `FUNCOES.h` |
| `build.bat` | Script que compila e executa no Windows |
| `.vscode/` | Task de build, configuração de depuração e IntelliSense para MinGW |
| `tarefa.dat` | Base de tarefas salva (gerada pelo programa) |
| `main.exe`, `a.out`, `build/` | Arquivos gerados pela compilação que foram versionados |

### Funções principais

| Função | Papel |
|--------|-------|
| `noValues()` | Zera a base: cada posição recebe seu ID, descrição vazia e status 0 |
| `loadBase(arquivo)` / `saveBase(arquivo)` | Lê e grava a base inteira em binário |
| `menu()` | Laço do menu principal; decide pela primeira tecla digitada |
| `choreAdd()` | Cadastra ou substitui a tarefa de um ID |
| `choreView()` / `questionView()` | Submenu de consulta |
| `choreStatus()` | Alterna o status de uma tarefa |
| `choreRemove()` | Exclui a tarefa de um ID |
| `lerLinha()` / `lerInt()` / `getId()` | Leitura de texto, de número e de ID válido (0 a 99) pelo teclado |

`questionAdd()`, `questionStatus()` e `questionRemove()` perguntam se o usuário quer repetir
a operação, mas hoje não são chamadas pelo menu. `converterUni()`, `converterDec()` e
`clearScreen()` também estão no código sem uso.

## Limitações e problemas conhecidos

- **As tarefas não voltam na próxima execução.** O programa carrega `tarefas.dat` (com "s")
  mas salva em `tarefa.dat` (sem "s"), em `Main.c`. Por isso toda execução começa com a base
  vazia e mostra "Arquivo não encontrado".
- **Só funciona no Windows.** Depende de `windows.h`, `conio.h` e do comando `cls`.
- **Diferença de maiúsculas nos nomes de arquivo.** `FUNCOES.C` inclui `"includes.h"`, mas o
  arquivo se chama `Includes.h`. A task do VS Code também chama `main.c` e `funcoes.c`. No
  Windows funciona porque o sistema de arquivos ignora maiúsculas; em outros sistemas, não.
- **Não existe opção para listar todas as tarefas.** A opção "Ver IDs disponíveis" mostra só
  os IDs livres.
- **Cadastrar num ID ocupado sobrescreve a tarefa** sem pedir confirmação.
- **O menu lê só o primeiro caractere**: digitar `12` executa a opção `1`.
- **Alterar o status de um ID vazio é permitido.** O ID passa a constar como "Concluida"
  mesmo sem tarefa.
- **`lerInt()` aceita lixo depois do número**: `3abc` é lido como `3`.
- **Fim da entrada trava o programa.** Se a entrada acabar (`Ctrl+D` no Linux, `Ctrl+Z` no
  Windows, ou um arquivo redirecionado com `<`), o `menu()` lê uma linha vazia e repete o
  laço para sempre, sem salvar. Para sair, é preciso matar o processo.
- **Arquivos gerados estão versionados** (`main.exe`, `a.out`, `build/`, `tarefa.dat`) e o
  repositório não tem `.gitignore`.

## Autor e licença

Desenvolvido por Kaue Vinicius da Silva. Distribuído sob a [licença MIT](LICENSE).
