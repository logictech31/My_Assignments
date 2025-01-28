SERVER_SRC = server.c
CLIENT_SRC = client.c
FLAGS = -g -o
LIBS = -lpthread
SERVER_BIN = server
CLIENT_BIN = client
server:
	gcc $(FLAGS) $(SERVER_BIN) $(SERVER_SRC) $(LIBS)
client:
	gcc $(FLAGS) $(CLIENT_BIN) $(CLIENT_SRC) $(LIBS)
clean:
	rm -f $(CLIENT_BIN) $(SERVER_BIN)

.PHONY: cleanc