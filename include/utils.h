/**
 * utils.h
 *
 * Copyright (C) 2017 Nickolas Burr <nickolasburr@gmail.com>
 */

#ifndef KEUKA_UTILS_H
#define KEUKA_UTILS_H

#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "common.h"

/**
 * String utilities
 */

char *base_name(char *);
int compare(char *, char *);
char *concat(char *, char *);
char *copy(char *, char *);
char *dir_name(char *);
int index_of(char *, char **, size_t);
int in_array(char *, char **, size_t);
int length(char *);

/**
 * Filesystem utilities
 */

DIR *get_dir(int *, const char *);
FILE *get_file(int *, const char *, const char *);

FILE *open_pipe(int *, const char *, const char *);
int close_pipe(FILE *);

int is_dir(const char *);
int is_file(const char *);
int is_link(const char *);
int is_sock(const char *);
int is_fifo(const char *);
int is_block(const char *);
int is_char(const char *);

#endif /* KEUKA_UTILS_H */
