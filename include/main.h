#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

typedef struct line{
	const char* line;
	int length_line;
} Line;

typedef struct DATA_TEXT{
    size_t size_file;
    char* buf;
    size_t amount_lines;
    Line* lines;
} Data_t;

enum CONFIG{
	NORMAL,
	REVERSE
};

enum ERROR{
	ERROR                = -1,
	ERROR_OPEN_FILE      = -2,
	ERROR_POINTER_NULL   = -3,
	ERROR_READ_TEXT      = -4,
	ERROR_UNREAL_VALUE   = -5,
	ERROR_BORDER_MASSIVE = -6,
	ERROR_CLOSE_FILE     = -7
};

size_t search_size_file(FILE *fp_src, Data_t* text, int* error_check);

char* create_buf(FILE *fp_src, Data_t* text, int* error_check);

Line* split_lines(Data_t *text, int* error_check);

int sorted_text(Data_t* text, int config, const char* pth);

int compare(const void *arg1, const void *arg2);

int compare_reverse(const void* arg1, const void* arg2);

#endif
