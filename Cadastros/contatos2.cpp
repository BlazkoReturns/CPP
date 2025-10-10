#include <iostream>
#include <string>

// Uma função auxiliar para facilitar a movimentação do cursor
void gotoxy(int x, int y) {
    // \033 é o caractere de ESCAPE, que inicia a sequência de comando
    std::cout << "\033[" << y << ";" << x << "H";
}

// Uma função para limpar a tela
void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

int main() {
    std::string nome, email, telefone;

    clearScreen();

    // 1. Imprime o "formulário" estático primeiro
    std::cout << "--- Cadastro de Novo Contato ---" << std::endl;
    std::cout << "Nome:     " << std::endl;
    std::cout << "Email:    " << std::endl;
    std::cout << "Telefone: " << std::endl;
    std::cout << "--------------------------------" << std::endl;

    // 2. Move o cursor para o local de input do Nome
    gotoxy(11, 2); // Coluna 11, Linha 2
    std::getline(std::cin, nome);

    // 3. Move o cursor para o local de input do Email
    gotoxy(11, 3); // Coluna 11, Linha 3
    std::getline(std::cin, email);

    // 4. Move o cursor para o local de input do Telefone
    gotoxy(11, 4); // Coluna 11, Linha 4
    std::getline(std::cin, telefone);

    // 5. Move o cursor para baixo do formulário para mostrar o resultado
    gotoxy(1, 6);
    std::cout << "Contato salvo com sucesso!" << std::endl;
    std::cout << "Nome: " << nome << ", Email: " << email << ", Telefone: " << telefone << std::endl;

    return 0;
}
