%.out: %.c
	gcc -g -o $@ -fopenmp $< -lpthread

.PHONY: clean
clean:
	rm -f *.out
	rm -f *.out