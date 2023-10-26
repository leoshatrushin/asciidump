#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void custom_msg_error(const char *msg) {
	fprintf(stderr, "%s", msg);
	fprintf(stderr, ": %s\n", strerror(errno));
	exit(EXIT_FAILURE);
}

FILE *Fopen(const char *pathname, const char *mode, const char *error_msg) {
	FILE *fp = fopen(pathname, mode);
	if (fp == NULL) {
		custom_msg_error(error_msg);
	}
	return fp;
}

int Getc(FILE *stream, const char *error_msg) {
	int c = getc(stream);
	if (c == EOF) {
		if (feof(stream)) {
			return EOF;
		}
		custom_msg_error(error_msg);
	}
	return c;
}
