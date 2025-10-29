# Autoria

- Aluna: Bianca R. R. Cesaretto, RA: 180155.
- Disciplina: Compiladores I.
- Curso: Engenharia da Computação, 8º Semestre.

# Descrição do projeto

- Este projeto implementa um **analisador léxico** (scanner) simples em linguagem C, desenvolvido como parte da disciplina de **Compiladores I**. O código (scanner.c), escrito em linguagem C, realiza a leitura de um arquivo teste (exemplo.c-) e identifica **tokens** como palavras reservadas, identificadores, números, operadores e símbolos. 
- O código do projeto foi feito de uma forma em que qualquer arquivo que contenha um código em C-
pode ser utilizado. Não precisa ser utilizado apenas o código teste disponibilizado (exemplo.c-).

# Objetivo

O objetivo deste projeto é construir um **sistema de varredura (scanner)** capaz de:
- Ler um arquivo de entrada, contendo um código teste.
- Reconhecer e classificar os tokens.
- Exibir o tipo de cada token identificado.

# Estrutura do Projeto

sistema-de-varredura-c (nome da pasta do projeto):
- scanner.c (Código do analisador léxico).
- exemplo.c- (Arquivo de teste).
- README.md (Documento explicativo do projeto).

# Funcionamento

1) O programa lê o arquivo caractere por caractere.
2) Ignora os espaços e quebra de linha.
3) Monta Tokens de acordo com o tipo:
    - Identificadores e Palavras reservadas.
    - Números.
    - Operadores.
    - Símbolos.
4) Exibe o tipo e o valor de cada Token reconhecido.

# Como compilar o projeto

Abra o terminal na pasta do projeto e execute:
- No Windows:  
  gcc sacanner.c -o sacanner
  
- No Linux/MacOS:  
  gcc scanner.c -o scanner

- Se não houver erros, um executável chamado scanner será gerado.

Após a compilação, execute o scanner passando o arquivo de teste como parâmetro:
- No Windows:  
  .\scanner exemplo.c-

- No Linux/MacOS:  
  ./scanner exemplo.c-

Se quiser utilizar outro arquivo como teste, é só passar o nome desse arquivo e conferir se ele está na
mesma pasta do projeto:
- Utilizando outro arquivo:
- No Windows:  
  .\scanner nome_do_arquivo.c-

- No Linux/MacOS:  
  ./scanner nome_do_arquivo.c-



