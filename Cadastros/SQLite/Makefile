# --- Variáveis de Compilação ---
# Define o compilador C++ que vamos usar
CXX = g++
# Define o compilador C (para o sqlite3.c)
CC = gcc

# Define as flags do compilador C++ (padrões de C++17, otimização, avisos)
CXXFLAGS = -std=c++17 -O2 -Wall
# Define as flags do compilador C
CFLAGS = -O2

# Define as bibliotecas que precisamos linkar no final
LDFLAGS = -lpthread -lws2_32

# --- Arquivos do Projeto ---
# Nome do nosso programa executável final
EXECUTABLE = agenda.exe

# Lista de arquivos fonte C++
CXX_SOURCES = main.cpp
# Lista de arquivos fonte C
C_SOURCES = sqlite3.c

# Gera automaticamente a lista de arquivos objeto (.o) a partir dos fontes
OBJECTS = $(CXX_SOURCES:.cpp=.o) $(C_SOURCES:.c=.o)

# --- Regras de Compilação ---

# A primeira regra é a padrão. Diz que para criar o executável,
# precisamos primeiro ter todos os arquivos objeto.
all: $(EXECUTABLE)

# Regra para linkar: como criar o executável a partir dos objetos.
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXECUTABLE) $(LDFLAGS)

# Regra genérica para compilar qualquer arquivo .cpp para .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra genérica para compilar qualquer arquivo .c para .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra "clean": para limpar os arquivos gerados pela compilação
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

# Diz ao 'make' que 'all' e 'clean' não são nomes de arquivos
.PHONY: all clean
