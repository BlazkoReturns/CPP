#include <iostream>
#include <string>
#include "sqlite3.h"

/**
 * Função para criar a tabela de contatos, se ela não existir.
 */
void criarTabela(sqlite3* db) {
    const char* sql = "CREATE TABLE IF NOT EXISTS contatos ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "nome     TEXT NOT NULL,"
                      "email    TEXT,"
                      "telefone TEXT);";
    
    char* zErrMsg = 0;
    int rc = sqlite3_exec(db, sql, nullptr, 0, &zErrMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "Erro de SQL ao criar tabela: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    } else {
        std::cout << "Tabela 'contatos' verificada com sucesso." << std::endl;
    }
}

/**
 * Função para pedir dados ao usuário e cadastrar um novo contato.
 */
void adicionarContato(sqlite3* db) {
    std::string nome, email, telefone;

    // 1. Obter os dados do usuário
    std::cout << "--- Novo Contato ---" << std::endl;
    std::cout << "Nome: ";
    // std::ws consome qualquer espaço em branco/quebra de linha
    // que possa ter sobrado de um 'cin' anterior.
    std::getline(std::cin >> std::ws, nome);

    std::cout << "Email: ";
    std::getline(std::cin, email);

    std::cout << "Telefone: ";
    std::getline(std::cin, telefone);

    // 2. Preparar o "molde" da query SQL com placeholders (?)
    const char* sql_insert = "INSERT INTO contatos (nome, email, telefone) VALUES (?, ?, ?);";
    sqlite3_stmt* stmt; // Este é o objeto "Prepared Statement"

    // 3. Compilar o molde
    int rc = sqlite3_prepare_v2(db, sql_insert, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Erro ao preparar o statement: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    // 4. Vincular (Bind) os dados do usuário aos placeholders
    // Os índices dos placeholders começam em 1, não em 0.

    // sqlite3_bind_text(statement, index, valor, tamanho, tipo_de_copia)
    // Usamos .c_str() para converter std::string para const char*
    // SQLITE_TRANSIENT diz ao SQLite para fazer sua própria cópia do texto.
    sqlite3_bind_text(stmt, 1, nome.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, email.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, telefone.c_str(), -1, SQLITE_TRANSIENT);

    // 5. Executar o statement
    rc = sqlite3_step(stmt);

    if (rc != SQLITE_DONE) {
        // SQLITE_DONE significa que a execução terminou com sucesso.
        std::cerr << "Erro ao executar o statement: " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "\nContato '" << nome << "' cadastrado com sucesso!" << std::endl;
    }

    // 6. Finalizar (destruir) o statement para liberar recursos
    sqlite3_finalize(stmt);
}

// --- Função Principal ---
int main() {
    sqlite3* db;
    int rc = sqlite3_open("agenda.db", &db);

    if (rc) {
        std::cerr << "Erro ao abrir/criar o banco de dados: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    } else {
        std::cout << "Banco de dados 'agenda.db' aberto." << std::endl;
    }

    // Garante que a tabela exista
    criarTabela(db);

    // Chama a função para adicionar um novo contato
    adicionarContato(db);

    // Fecha a conexão
    sqlite3_close(db);
    return 0;
}
