@echo off
echo Compilando...

gcc Main.c FUNCOES.C -o main

if %errorlevel% neq 0 (
    echo Erro na compilação.
    pause
    exit /b
)

echo Compilação bem-sucedida!
echo Executando o programa:
echo ============================
main.exe
echo ============================
pause
