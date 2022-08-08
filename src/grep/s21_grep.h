#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#include <regex.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>

struct grep_flags {
    int e_flag;
    int i_flag;
    int v_flag;
    int c_flag;
    int l_flag;
    int n_flag;
};

int flag_checker(int argc, char *argv[], struct grep_flags *flags, char *regular);
void printer(FILE *file, struct grep_flags flags, regex_t reg, char *filename, int single);
int blank_check(char *str);

#endif  // SRC_GREP_S21_GREP_H_
