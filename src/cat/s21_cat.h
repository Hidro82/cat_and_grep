#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

struct cat_flags {
    int b_flag;
    int E_flag;
    int n_flag;
    int s_flag;
    int T_flag;
    int v_flag;
};

int flag_checker(int argc, char *argv[], struct cat_flags *flags);
int long_flag(char *str, struct cat_flags *flags);
void printer(FILE *file, struct cat_flags flags);
int blank_check(char *str);
void invisible(char str);

#endif  // SRC_CAT_S21_CAT_H_
