#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *
load_file(char *filename)
{
	char *buf = NULL;
	FILE *f = fopen(filename, "r");
	if (f == NULL) {
		fprintf(stderr, "unable to open %s\n", filename);
		return NULL;
	}

	fseek(f, 0, SEEK_END);
	uint32_t len = ftell(f);
	rewind(f);
	buf = calloc(len + 1, sizeof(uint8_t));
	fread(buf, sizeof(uint8_t), len, f);

	return buf;
}

int
main(int argc, char **argv)
{
	if (argc < 2) {
		fprintf(stderr, "aa [file]\n");
		return 1;
	}

	char *file = load_file(argv[1]);
	printf("%s", file);
	printf("%lu\n", strlen(file));
	return 0;
}
