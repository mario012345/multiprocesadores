CC_FLAGS = -Wall -Wextra -Wpedantic -fopenmp -lm -g -o

default: run

run: ram rom cache
	./output_ram
	./output_rom
	./output_cache

cache:
	cc cache_threads.c $(CC_FLAGS) output_cache
	
ram:
	cc ram_threads.c $(CC_FLAGS) output_ram

rom:
	cc rom_threads.c $(CC_FLAGS) output_rom

.PHONY: clean run

clean:
	rm -rf output* *.txt
