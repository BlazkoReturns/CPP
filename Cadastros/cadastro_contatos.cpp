#include "tabelas.cpp"

void gotoxy(int x, int y) {
   std::cout << "\033[" << y << ";" << x << "H";
}

void clearScreen() {
   std::cout << "\033[2J\033[1;1H";
}

void CadastrarCliente(){
   clearScreen();

   std::cout << "--- Cadastro de Novo Contato ---" << std::endl;
   std::cout << "Nome:     " << std::endl;
   std::cout << "Email:    " << std::endl;
   std::cout << "Telefone: " << std::endl;
   std::cout << "--------------------------------" << std::endl;

   Contatos contato;

   gotoxy(11, 2); 
   std::getline(std::cin, contato.nome);

   gotoxy(11, 3);
   std::getline(std::cin, contato.email);

   gotoxy(11, 4); 
   std::getline(std::cin, contato.telefone);

   gotoxy(1, 6);
   std::cout << "Contato salvo com sucesso!" << std::endl;
   std::cout << "Nome: " << contato.nome << ", Email: " << contato.email << ", Telefone: " << contato.telefone << std::endl;
}

int main() {
     CadastrarCliente();
     return 0;
}
