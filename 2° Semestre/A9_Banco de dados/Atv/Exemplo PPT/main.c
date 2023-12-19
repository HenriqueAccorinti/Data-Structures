#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#include <strings.h>
#define MAX 150

void exibeBanco(sqlite3 *db){
    sqlite3_stmt *stmt = NULL;
    char sql[MAX];
    int i;

    sprintf(sql, "SELECT * FROM vendas");

    sqlite3_prepare(db, sql , -1, &stmt, NULL);

    // escreve o cabeçalho com o nome das colunas
    for (i = 0; i < sqlite3_column_count(stmt); i++)
        printf("%s\t", sqlite3_column_name(stmt, i));
    printf("\n"); // termina a exibição do cabeçalho

    // para cada linha da tabela resultado
    // while (sqlite3_step(stmt) == SQLITE_ROW)  OU
    while (sqlite3_step(stmt) != SQLITE_DONE)
    {
        // para cada coluna
        for (i = 0; i < sqlite3_column_count(stmt); i++)
            printf("%s\t", sqlite3_column_text(stmt, i));
        printf("\n"); // termina a exibição de uma linha
    }
}

int main()
{
    sqlite3 *db = NULL;
    sqlite3_stmt *stmt = NULL;
    int conexao, i;

    char sql[MAX];

    printf("Criando conexao com o banco:\n");
    conexao = sqlite3_open("pokemonCenter.db", &db);

    if (conexao != SQLITE_OK)
    {
        printf("Erro ao conectar ao banco\n");
        exit(-1);
    }

    printf("Sucesso na conexao!\n");

    int id = 104;
    int qtd = 10;
    float valor = 10.4;
    char nome[] = "teste1";

    // inserindo no banco...

    // escreve a query na string sql
    //
    // textos precisam estar entre "" ou '' para serem inseridos no banco, assim,
    // para incluir as aspas dentro de outras aspas, use:
    //
    // \ antes das aspas ---> \"texto\"
    // ou
    // ' ---> 'texto'
    //
    sprintf(sql, "INSERT INTO vendas (id, quant, valor, nome) VALUES (%i, %i, %.2f, '%s')",id,qtd,valor,nome);
    printf("\n%s\n",sql);

    // prepara a consulta ao banco
    sqlite3_prepare(db, sql, -1, &stmt, NULL);

    // executa a consulta
    sqlite3_step(stmt);

    exibeBanco(db);

    // atualizando informacoes no banco
    id = 101;
    qtd = 1;
    sprintf(sql, "UPDATE vendas SET quant=quant-%i WHERE id=%i",qtd,id);
    printf("\n%s\n",sql);

    sqlite3_prepare(db, sql, -1, &stmt, NULL);
    sqlite3_step(stmt);

    exibeBanco(db);

    // retornando um unico valor
    id = 101;
    char valor_como_texto[10];
    int valor_como_int;
    float valor_como_float;
    sprintf(sql, "SELECT quant*valor FROM vendas WHERE id=%i", id);
    printf("\n%s\n",sql);

    sqlite3_prepare(db, sql, -1, &stmt, NULL);

    if(sqlite3_step(stmt) == SQLITE_ROW){
        strcpy(valor_como_texto,sqlite3_column_text(stmt,0));
        valor_como_int = sqlite3_column_int(stmt,0);
        valor_como_float = sqlite3_column_double(stmt,0);
    }

    printf("\n");
    printf("Como texto: %s\n", valor_como_texto);
    printf("Como int: %i\n", valor_como_int);
    printf("Como float: %f\n", valor_como_float);

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 0;
}
