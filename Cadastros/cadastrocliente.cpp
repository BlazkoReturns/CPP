#include <string>
#include <iostream>

struct Contato {
    int id;
    std::string nome;
    std::string email;
    std::string telefone;
};

void adicionar_contato(){
   Contato novo_contato;
   std::cin >> novo_contato;   
}

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
    int opcao;
    
    do {
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                adicionar_contato();
                break;
            case 0:
                std::cout << "Saindo..." << std::endl;
                break;
            default:
                std::cout << "Opção inválida!" << std::endl;
        }
    } while (opcao != 0);

    return 0;
}
