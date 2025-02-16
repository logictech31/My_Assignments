FLAGS = -g -o
LIBS = -lpthread
BIN = lamports_logical_clock
SRC = main.c
COMPILER = g++
build:
	$(COMPILER) $(FLAGS) $(BIN) $(SRC) $(LIBS)
clean:
	rm -f $(BIN)
all: clean build

.PHONY: clean all