# Autoria

Aluna: Bianca R. R. Cesaretto, RA: 180155.
Disciplina: Compiladores I.
Curso: Engenharia da Computação, 8º Semestre.

## Descrição do projeto

Este projeto implementa um **analisador léxico** (scanner) simples em linguagem C, desenvolvido como parte da disciplina de **Compiladores I**. O código (scanner.c), escrito em linguagem C, realiza a leitura de um arquivo teste (exemplo.c-) e identifica **tokens** como palavras reservadas, identificadores, números, operadores e símbolos. 

### Objetivo

O objetivo deste projeto é construir um **sistema de varredura (scanner)** capaz de:
- Ler um arquivo de entrada, contendo um código teste.
- Reconhecer e classificar os tokens.
- Exibir o tipo de cada token identificado.

#### Estrutura do Projeto

sistema-de-varredura:
    - scanner.c -> Código do analisador léxico.
    - exemplo.c- -> Arquivo de teste.
    - README.md -> Documento explicativo do projeto.

##### Funcionamento

1) O programa lê o arquivo caractere por caractere.
2) Ignora os espaços e quebra de linha.
3) Monta Tokens de acordo com o tipo:
    - Identificadores e Palavras reservadas.
    - Números.
    - Operadores.
    - Símbolos.
4) Exibe o tipo e o valor de cada Token reconhecido.

###### Como compilar o projeto

Abra o terminal na pasta do projeto e execute:
    No Windows:
    gcc scanner.c -o scanner

    No Linux/MacOS:
    gcc scanner.c -o scanner

    Se não houver erros, um executável chamado scanner será gerado.

Após a compilação, execute o scanner passando o arquivo de teste como parâmetro:
    No Windows:
    .\scanner exemplo.c-

    No Linux/MacOS:
    ./scanner exemplo.c-

