BINARY = ring_election
SRC = main.cxx cll.cxx election.cxx
FLAGS = -g -o
all:
	@echo "Generating binary"
	g++ $(FLAGS) $(BINARY) $(SRC)
clean:
	@echo "Removing binary"
	rm -f $(BINARY)

.PHONY: clean all