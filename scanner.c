#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LEN 100

// Função auxiliar para verificar se é palavra reservada
int is_keyword(const char *str) {
    const char *keywords[] = {"if", "else", "int", "void", "return", "while"};
    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

// Função principal do scanner
void scan(FILE *fp) {
    char c;
    char token[MAX_TOKEN_LEN];
    int pos = 0;

    while ((c = fgetc(fp)) != EOF) {
        // Ignora espaços, tabs e quebras de linha
        if (isspace(c))
            continue;

        // Identificadores e palavras reservadas
        if (isalpha(c)) {
            pos = 0;
            token[pos++] = c;
            while (isalnum(c = fgetc(fp))) {
                token[pos++] = c;
            }
            token[pos] = '\0';
            ungetc(c, fp);
            if (is_keyword(token))
                printf("Palavra reservada -> %s\n", token);
            else
                printf("Identificador -> %s\n", token);
        }

        // Números
        else if (isdigit(c)) {
            pos = 0;
            token[pos++] = c;
            while (isdigit(c = fgetc(fp))) {
                token[pos++] = c;
            }
            token[pos] = '\0';
            ungetc(c, fp);
            printf("Numero -> %s\n", token);
        }

        // Operadores e símbolos
        else {
            switch (c) {
                case '+': case '-': case '*':
                    printf("Operador -> %c\n", c);
                    break;
                case '/': // Operador ou comentário
                    if ((c = fgetc(fp)) == '/') {
                        while ((c = fgetc(fp)) != '\n' && c != EOF);
                    } else {
                        printf("Operador -> /\n");
                        ungetc(c, fp);
                    }
                    break;
                case '=':
                    if ((c = fgetc(fp)) == '=')
                        printf("Operador -> ==\n");
                    else {
                        printf("Operador -> =\n");
                        ungetc(c, fp);
                    }
                    break;
                case '<':
                    if ((c = fgetc(fp)) == '=')
                        printf("Operador -> <=\n");
                    else {
                        printf("Operador -> <\n");
                        ungetc(c, fp);
                    }
                    break;
                case '>':
                    if ((c = fgetc(fp)) == '=')
                        printf("Operador -> >=\n");
                    else {
                        printf("Operador -> >\n");
                        ungetc(c, fp);
                    }
                    break;
                case '!':
                    if ((c = fgetc(fp)) == '=')
                        printf("Operador -> !=\n");
                    else {
                        printf("Simbolo -> !\n");
                        ungetc(c, fp);
                    }
                    break;
                case ';': case ',': case '(': case ')': case '{': case '}':
                    printf("Simbolo -> %c\n", c);
                    break;
                default:
                    printf("Caractere desconhecido -> %c\n", c);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    // Verifica se o usuário passou o nome de um arquivo como argumento
    if (argc < 2) {
        printf("Uso: %s <arquivo.c->\n", argv[0]); 
        return 1;
    }

    // Abre o arquivo passado como argumento para leitura
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    scan(fp);
    fclose(fp);
    return 0;
}
