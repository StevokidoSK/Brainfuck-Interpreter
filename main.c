#include <stdio.h>
#include <stdlib.h>
#define MAX_MEMORY 255

int main(int argc, char** argv){
	
	if(argc < 2){
		printf("Correct usage: brainfuck FILE_PATH\n");
		return -1;
	}

	//read file
	FILE *f = fopen(argv[1], "rb");
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
		if(program[i] == '[' && mem[ptr] == 0){
			int j = i;
			int loopcnt = 0;
			while(1){
				j++;
				if(program[j] == ']' && loopcnt == 0){
					i = j + 1;
					break;
				} else if(program[j] == '['){
					loopcnt++;
				} else if(program[j] == ']' && loopcnt != 0){
					loopcnt--;
				}
			}
		}
		if(program[i] == ']' && mem[ptr] != 0){
			int j = i;
			int loopcnt = 0;
			while(1){
				j--;
				if(program[j] == '[' && loopcnt == 0){
					i = j + 1;
					break;
				} else if(program[j] == ']') {
					loopcnt++;
				} else if(program[j] == '[' && loopcnt != 0) {
					loopcnt--;
				}
			}
		}
	}
#if defined MEMORY_DUMP
	for(int i = 0; i < MAX_MEMORY; i++) printf("%c", mem[i]);
#endif
	return 0;
}
