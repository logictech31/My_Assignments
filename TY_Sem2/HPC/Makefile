%.out: %.c
	gcc -g -pg -o $@ -fopenmp $< -lpthread

.PHONY: clean
clean:
	rm -f *.out
	rm -f *.o
