//Henrique Fortuna Accorinti	RA:20.00080-4
//				RA:
//				RA:
//				RA:

#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#define MAX 500

void ExibirTabela(sqlite3_stmt *stmt)
{
    int i;
    // exibe o cabeçalho
    for (i = 0; i < sqlite3_column_count(stmt); i++)
        printf("%s\t\t", sqlite3_column_name(stmt,i));
    printf("\n");

    // para cada linha da tabela
    while(sqlite3_step(stmt) != SQLITE_DONE)
    {
        // para cada coluna da linha
        for (i = 0; i < sqlite3_column_count(stmt); i++)
            if (sqlite3_column_type(stmt, i) == SQLITE_FLOAT)
                printf("%.2f\t", sqlite3_column_double(stmt,i)); // formata valores reais com 2 casas
            else
                printf("%s\t", sqlite3_column_text(stmt,i));
        printf("\n");
    }
    printf("\n");
}

void mostraMenu()
{
printf("\nInforme a opcao desejada:\n1 - Nova venda\n2 - Adicionar ao carrinho\n3 - Fechar venda\n4 - Gerenciar Estoque\n5 - Sair\n\n");
}

int main()
{
    sqlite3 *db = NULL;
    sqlite3_stmt *stmt = NULL;
    char sql[MAX];
    int conexao;
    int cod, qtd, opcao;

    //Abre a conexão com o banco
    conexao = sqlite3_open("Lojinha.db", &db);
    if (conexao != SQLITE_OK)
    {
        printf("Erro ao conectar ao banco\n");
        exit(-1);
    }

    // laço principal
    do
    {
        // Faz a chamada do menu e a leitura da opção do usuário
        system("cls");
        mostraMenu();
        printf("Opcao: ");
        scanf("%i", &opcao);

        // se deseja fazer uma consulta
        if (opcao != 5)
        {

            // verifica a opção desejada
            switch(opcao)
            {
            case 1:
            {
                //Nova venda: deve determinar o valor do identificador da venda que será realizada. Para isso, deve-se
                //verificar qual o último código de venda utilizado ou definir o valor da primeira venda da loja como 1.
                sprintf(sql,"SELECT MAX(idVenda) FROM vendas");
                printf("\n%s\n\n", sql); // POPPA
                sqlite3_prepare(db, sql, -1, &stmt, NULL);
                ExibirTabela(stmt);
                break;
            } // fim do case 1

            case 2:
            {
                //Adicionar ao carrinho
                sprintf(sql, "SELECT * FROM estoque");
                printf("\n%s\n\n", sql); // POPPA
                sqlite3_prepare(db, sql, -1, &stmt, NULL);

                //Apresentar a tabela do estoque
                ExibirTabela(stmt);

                //Permitir ao usuário digitar o código do produto, bem como a quantidade que o cliente deseja
                printf("Codigo do produto: ");
                scanf("%i", &cod);

                printf("Quantidade: ");
                scanf("%i", &qtd);

                break;
            } // fim do case 2

            case 3:
            {
                //Fechar venda: Exibe todos os dados da venda atual, além de calcular e exibir o valor total da venda.
                sprintf(sql,"");
                printf("\n%s\n\n", sql); // POPPA
                sqlite3_prepare(db, sql, -1, &stmt, NULL);
                ExibirTabela(stmt);
                break;
            } // fim do case 3

            case 4:
            {
                //Gerenciar estoque
                sprintf(sql,"");
                printf("\n%s\n\n", sql); // POPPA
                sqlite3_prepare(db, sql, -1, &stmt, NULL);
                ExibirTabela(stmt);
                break;
            } // fim do case 4
            } // fim do switch
            system("pause");
        }
    }
    while(opcao != 5);

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 0;
}
