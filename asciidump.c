#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "wrapper.h"

static char asciinames[256][6];
static void list_ascii_characters(char *argv[]);
static void list_ascii();
static void print_help();
static void dump_ascii(int argc, char *argv[]);

static struct option long_options[] = {
	{"help", no_argument, NULL, 'h'},
	{NULL, 0, NULL, 0}
};

static int stringArgs = 0;

int main(int argc, char *argv[]) {

	int c;
	while ((c = getopt_long_only(argc, argv, "v:lhs", long_options, NULL)) != -1)
	{
		switch (c) {
			case 'v':
				list_ascii_characters(argv);
				exit(0);
			case 'l':
				list_ascii();
				exit(0);
			case 'h':
				print_help();
				exit(0);
			case 's':
				stringArgs = 1;
				break;
		}
	}

	dump_ascii(argc, argv);
}

static void list_ascii_characters(char *argv[]) {

}

static void list_ascii() {

}

static void print_help() {

}

static int printable(char c);

static void dump_ascii_char(char c) {
	if (printable(c)) {
		printf("%c", c);
	} else {
		printf("%s", asciinames[(unsigned char) c]);
	}
}

static void dump_ascii_string(char *string) {
	for (int i = 0; string[i] != '\0'; i++) {
		dump_ascii_char(string[i]);
	}
}

static void dump_ascii_file(FILE *fp) {
	int c;
	while ((c = Getc(fp, "Read error")) != EOF) {
		dump_ascii_char((char) c);
	}
}

static void dump_ascii(int argc, char *argv[]) {
	if (optind == argc) {
		dump_ascii_file(stdin);
	}

	for (int i = optind; i < argc; i++) {
		char *arg = argv[i];
		if (stringArgs) {
			dump_ascii_string(arg);
			continue;
		}

		FILE *fp = Fopen(arg, "rb", "Error opening file");
		dump_ascii_file(fp);
	}

	printf("\n");
}

static int printable(char c) {
	return c >= 33 && c <= 126 && c != 92 && c != 94;
}

static char asciinames[256][6] = {
	"\\0",
	"^A",
	"^B",
	"^C",
	"^D",
	"^E",
	"^F",
	"\\a",
	"\\b",
	"\\t",
	"\\n",
	"\\v",
	"\\f",
	"\\r",
	"^N",
	"^O",
	"^P",
	"^Q",
	"^R",
	"^S",
	"^T",
	"^U",
	"^V",
	"^W",
	"^X",
	"^Y",
	"^Z",
	"^[",
	"^\\",
	"^]",
	"^^",
	"^_",
	"\\s",
	"!", /* 33 - DIRECTLY PRINTABLE */
	"\"",
	"#",
	"$",
	"%",
	"&",
	"'",
	"(",
	")",
	"*",
	"+",
	",",
	"-",
	".",
	"/",
	"0",
	"1",
	"2",
	"3",
	"4",
	"5",
	"6",
	"7",
	"8",
	"9",
	":",
	";",
	"<",
	"=",
	">",
	"?",
	"@",
	"A",
	"B",
	"C",
	"D",
	"E",
	"F",
	"G",
	"H",
	"I",
	"J",
	"K",
	"L",
	"M",
	"N",
	"O",
	"P",
	"Q",
	"R",
	"S",
	"T",
	"U",
	"V",
	"W",
	"X",
	"Y",
	"Z",
	"[",
	"\\\\", /* 92 - NOT DIRECTLY PRINTABLE */
	"]",
	"\\^", /* 94 - NOT DIRECTLY PRINTABLE */
	"_",
	"`",
	"a",
	"b",
	"c",
	"d",
	"e",
	"f",
	"g",
	"h",
	"i",
	"j",
	"k",
	"l",
	"m",
	"n",
	"o",
	"p",
	"q",
	"r",
	"s",
	"t",
	"u",
	"v",
	"w",
	"x",
	"y",
	"z",
	"{",
	"|",
	"}",
	"~", /* 126 - DIRECTLY PRINTABLE END */
	"^?",
	"\\M-^@",
	"\\M-^A",
	"\\M-^B",
	"\\M-^C",
	"\\M-^D",
	"\\M-^E",
	"\\M-^F",
	"\\M-^G",
	"\\M-^H",
	"\\M-^I",
	"\\M-^J",
	"\\M-^K",
	"\\M-^L",
	"\\M-^M",
	"\\M-^N",
	"\\M-^O",
	"\\M-^P",
	"\\M-^Q",
	"\\M-^R",
	"\\M-^S",
	"\\M-^T",
	"\\M-^U",
	"\\M-^V",
	"\\M-^W",
	"\\M-^X",
	"\\M-^Y",
	"\\M-^Z",
	"\\M-^[",
	"\\M-^\\",
	"\\M-^]",
	"\\M-^^",
	"\\M-^_",
	"\\M-\\s",
	"\\M-!",
	"\\M-\"",
	"\\M-#",
	"\\M-$",
	"\\M-%",
	"\\M-&",
	"\\M-'",
	"\\M-(",
	"\\M-)",
	"\\M-*",
	"\\M-+",
	"\\M-,",
	"\\M--",
	"\\M-.",
	"\\M-/",
	"\\M-0",
	"\\M-1",
	"\\M-2",
	"\\M-3",
	"\\M-4",
	"\\M-5",
	"\\M-6",
	"\\M-7",
	"\\M-8",
	"\\M-9",
	"\\M-:",
	"\\M-;",
	"\\M-<",
	"\\M-=",
	"\\M->",
	"\\M-?",
	"\\M-@",
	"\\M-A",
	"\\M-B",
	"\\M-C",
	"\\M-D",
	"\\M-E",
	"\\M-F",
	"\\M-G",
	"\\M-H",
	"\\M-I",
	"\\M-J",
	"\\M-K",
	"\\M-L",
	"\\M-M",
	"\\M-N",
	"\\M-O",
	"\\M-P",
	"\\M-Q",
	"\\M-R",
	"\\M-S",
	"\\M-T",
	"\\M-U",
	"\\M-V",
	"\\M-W",
	"\\M-X",
	"\\M-Y",
	"\\M-Z",
	"\\M-[",
	"\\M-\\",
	"\\M-]",
	"\\M-^",
	"\\M-_",
	"\\M-`",
	"\\M-a",
	"\\M-b",
	"\\M-c",
	"\\M-d",
	"\\M-e",
	"\\M-f",
	"\\M-g",
	"\\M-h",
	"\\M-i",
	"\\M-j",
	"\\M-k",
	"\\M-l",
	"\\M-m",
	"\\M-n",
	"\\M-o",
	"\\M-p",
	"\\M-q",
	"\\M-r",
	"\\M-s",
	"\\M-t",
	"\\M-u",
	"\\M-v",
	"\\M-w",
	"\\M-x",
	"\\M-y",
	"\\M-z",
	"\\M-{",
	"\\M-|",
	"\\M-}",
	"\\M-~",
	"\\M-^?",
};

