#Alcides Gomes Beato Neto   RA: 19060987
#Henrique Sartori Siqueira  RA: 19240472
#Rafael Silva Barbon        RA: 19243633
# Compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall -g

# Códigos fonte
FONTES = $(wildcard *.c)

# Arquivos objetos
OBJETOS = $(FONTES:.C=.O)

# Arquivo executável
EXE = proj2

# Variável para o executável
all: $(EXE)

# Atribuir os objetos a um executável
$(EXE): $(OBJETOS)
	$(CC) -o $@ $^

# Cria os objetos
%.o: %.c
	$(CC) -c $(CFLAGS) $^

# Exclui os objetos
clean:
	rm -rf *.o

# Exclui o executável
rmproper: clean
	rm -rf $(EXE)