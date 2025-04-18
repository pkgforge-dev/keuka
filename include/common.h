/**
 * common.h
 *
 * Copyright (C) 2017 Nickolas Burr <nickolasburr@gmail.com>
 */

#ifndef KEUKA_COMMON_H
#define KEUKA_COMMON_H

#include <ctype.h>
#include <errno.h>
#include <getopt.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifdef __APPLE__
#include <limits.h>
#else
#include <linux/limits.h>
#endif

#define KEUKA_VERSION "1.0.6"

#define _GNU_SOURCE  1
#define NOT_FOUND   -1
#define NUL_BYTE     1

#endif /* KEUKA_COMMON_H */
