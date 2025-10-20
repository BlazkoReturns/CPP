#include <iostream>
#include <string>

// 1. Inclua o cabeçalho do SQLite que está na mesma pasta.
#include "sqlite3.h"

int main() {
    sqlite3* db; // Ponteiro que representa a conexão com o banco de dados.
    char* zErrMsg = 0; // Armazenará mensagens de erro.
    int rc; // Armazenará os códigos de retorno das funções (rc = return code).

    // 2. Abre a conexão. O SQLite criará o arquivo se ele não existir.
    rc = sqlite3_open("agenda.db", &db);

    if (rc) {
        // Se a conexão falhar, imprime o erro e fecha.
        std::cerr << "Erro ao abrir/criar o banco de dados: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    } else {
        std::cout << "Banco de dados 'agenda.db' aberto/criado com sucesso." << std::endl;
    }

    // 3. Define o comando SQL para criar nossa tabela de contatos.
    // "IF NOT EXISTS" garante que o comando não dará erro se a tabela já existir.
    const char* sql = "CREATE TABLE IF NOT EXISTS contatos ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "nome     TEXT NOT NULL,"
                      "email    TEXT,"
                      "telefone TEXT);";

    // 4. Executa o comando SQL.
    rc = sqlite3_exec(db, sql, nullptr, 0, &zErrMsg);

    if (rc != SQLITE_OK) {
        // Se houver um erro na execução do SQL...
        std::cerr << "Erro de SQL: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg); // Libera a memória da mensagem de erro.
    } else {
        std::cout << "Tabela 'contatos' criada com sucesso ou ja existente." << std::endl;
    }

    // 5. Fecha a conexão com o banco de dados.
    sqlite3_close(db);

    return 0;
}
