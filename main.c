#include <stdio.h>
#include <stdlib.h>
#define MAX_MEMORY 255

int main(){
	//read file
	FILE *f = fopen("program.bf", "rb");
	fseek(f, 0, SEEK_END);
	long fsize = ftell(f);
	fseek(f, 0, SEEK_SET);  /* same as rewind(f); */
	
	char *program = malloc(fsize + 1);
	fread(program, 1, fsize, f);
	fclose(f);
	program[fsize] = 0;
	
	//allocate program memory
	int ptr = 0;
	char mem[MAX_MEMORY];
	for(int i = 0; i < MAX_MEMORY; i++){
		mem[i] = 0; 
	}

	//execute program
	for(int i = 0; i < fsize; i++){
		if(program[i] == '+') mem[ptr] += 1;
		if(program[i] == '-') mem[ptr] -= 1;
		if(program[i] == '>' && ptr != MAX_MEMORY) ptr += 1;
		if(program[i] == '<' && ptr != 0) ptr -= 1;
		if(program[i] == '.') printf("%c", mem[ptr]);
		if(program[i] == ',') mem[ptr] = getchar();
	}
#if defined MEMORY_DUMP
	for(int i = 0; i < MAX_MEMORY; i++) printf("%c", mem[i]);
#endif
	return 0;
}
