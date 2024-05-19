/*
 * MIT License
 *
 * Copyright (c) 2024 Uriel García Rivas
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * https://github.com/zoningorg/zonterm/blob/main/LICENSE
 */

#ifndef __ZNG_OUTPUTSTREAM_H__
#define __ZNG_OUTPUTSTREAM_H__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// To make it bold, add 01; between the brace and the number

static bool __zng_use_colors;

__attribute__((constructor))
static void __zng_outputstream_initialize() {
  __zng_use_colors = isatty(STDOUT_FILENO)
                  && getenv("NO_COLOR") == NULL
                  && getenv("TERM") != NULL;
}

#define STDERR_RED(...)                              \
do {                                                 \
  if (__zng_use_colors) fprintf(stderr, "\033[91m"); \
  fprintf(stderr, __VA_ARGS__);                      \
  if (__zng_use_colors) fprintf(stderr, "\033[0m");  \
  fflush(stderr);                                    \
} while (0)

#define STDOUT_GREEN(...)                            \
do {                                                 \
  if (__zng_use_colors) fprintf(stdout, "\033[92m"); \
  fprintf(stdout, __VA_ARGS__);                      \
  if (__zng_use_colors) fprintf(stdout, "\033[0m");  \
  fflush(stdout);                                    \
} while (0)

#endif // __ZNG_OUTPUTSTREAM_H__
