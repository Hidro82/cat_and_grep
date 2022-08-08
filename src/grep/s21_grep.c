#include "s21_grep.h"

int flag_checker(int argc, char *argv[], struct grep_flags *flags, char *regular) {
    int correct = 0;
    int counter = 0;
    char insider[2056];

    while ((counter = getopt_long(argc, argv, "e:ivcln", NULL, NULL)) != -1) {
        switch (counter) {
            case 'e':
                strcpy(insider, regular);
                flags->e_flag = 1;
                sprintf(regular, "%s%s%s", insider, *regular == '\0' ? "\0" : "|", optarg);
                break;
            case 'i':
                flags->i_flag = 1;
                break;
            case 'v':
                flags->v_flag = 1;
                break;
            case 'c':
                flags->c_flag = 1;
                break;
            case 'l':
                flags->l_flag = 1;
                break;
            case 'n':
                flags->n_flag = 1;
                break;
            default:
                correct = 1;
                break;
        }
    }
    return correct;
}

void printer(FILE *file, struct grep_flags flags, regex_t reg, char *filename, int single) {
    regmatch_t matcher;
    char buffer[2056];
    int line_number = 1;
    int match = 0;
    int match_num = 0;
    int execute = 0;

    while (fgets(buffer, 2056, file) != NULL) {
        execute = regexec(&reg, buffer, 1, &matcher, 0);
        if ((!execute && flags.v_flag == 0)
        || (execute == REG_NOMATCH && flags.v_flag == 1)) {
            match = 1;
            match_num++;
        }
        if (match == 1 && flags.c_flag == 0 && flags.l_flag == 0) {
            if (single != 1)
                printf("%s:", filename);
            if (flags.n_flag == 1)
                printf("%d:", line_number);
            printf("%s", buffer);
            match = 0;
        }
        line_number++;
    }
    if (flags.c_flag == 1) {
        if (single != 1)
            printf("%s:", filename);
        printf("%d\n", match_num);
    }
    if (flags.l_flag == 1 && match_num > 0) {
        printf("%s\n", filename);
    }
}
