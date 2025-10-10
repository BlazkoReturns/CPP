#include <iostream>
#include <string>
#include <limits> 

struct Contato {
    int id; 
    std::string nome;
    std::string email;
    std::string telefone;
};

std::istream& operator>>(std::istream& is, Contato& c) {
    std::cout << "Nome: ";
    std::getline(is >> std::ws, c.nome);

    std::cout << "Email: ";
    is >> c.email;

    std::cout << "Telefone: ";
    is >> c.telefone;

    return is;
}

int main() {
    Contato novo_contato;

    std::cout << "--- Cadastro de Novo Contato ---" << std::endl;

    std::cin >> novo_contato;

    std::cout << "\n--- Contato Cadastrado ---" << std::endl;
    std::cout << "Nome: " << novo_contato.nome << std::endl;
    std::cout << "Email: " << novo_contato.email << std::endl;
    std::cout << "Telefone: " << novo_contato.telefone << std::endl;

    return 0;
}
