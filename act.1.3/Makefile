CC_FLAGS = -Wall -Wextra -Wpedantic -fopenmp -g -o
SRC_NAME = openmp_hilos.c
OUT_NAME = output

default: run

run: output
	./$(OUT_NAME)

output: $(SRC_NAME)
	cc $(SRC_NAME) $(CC_FLAGS) $(OUT_NAME)

.PHONY: clean run

clean:
	rm -rf output
