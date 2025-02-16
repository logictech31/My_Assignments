SRC = main.x
COMPILER = rpcgen
RPCGENFLAGS = -a -C
gen:
	$(COMPILER) $(RPCGENFLAGS) $(SRC)
build:
	make -f Makefile.main
clean:
	rm -f *.h *.c *.main
all: clean gen

.PHONY: clean all