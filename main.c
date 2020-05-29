#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *f = fopen("program.bf", "rb");
	fseek(f, 0, SEEK_END);
	long fsize = ftell(f);
	fseek(f, 0, SEEK_SET);  /* same as rewind(f); */
	
	int memsize = 255;
	int* mem = malloc(memsize);

	char *string = malloc(fsize + 1);
	fread(string, 1, fsize, f);
	fclose(f);

	string[fsize] = 0;
	
	for(int i; i < fsize; i++){
	
	}

	return 0;
}
