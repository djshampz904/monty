#include "monty.h"

/*
 * read_file - reads a file and returns the contents
 * @filename: the file to read
 * Return: the contents of the file
*/

char *read_file(const char *filename)
{
	FILE *file;
	char *code;
	long file_size;

	file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", filename);
		exit(EXIT_FAILURE);
	}

	fseek(file, 0, SEEK_END);
	file_size = ftell(file);
	fseek(file, 0, SEEK_SET);

	code = malloc(file_size + 1);
	if (code == NULL)
	{
		printf("Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	fread(code, 1, file_size, file);
	code[file_size] = '\0';

	fclose(file);

	return (code);
}
