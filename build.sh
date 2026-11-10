#!/bin/sh
echo "Compilando..."

if ! gcc Main.c FUNCOES.c -o main; then
    echo "Erro na compilação."
    exit 1
fi

echo "Compilação bem-sucedida!"
echo "Executando o programa:"
echo "============================"
./main
echo "============================"
