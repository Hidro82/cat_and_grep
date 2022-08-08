#include "s21_cat.h"

int flag_checker(int argc, char *argv[], struct cat_flags *flags) {
    int correct = 0;
    int counter = 0;
    int index = 0;
    static struct option lflags[] = {
        {"number-nonblank", 0, 0, 'b'},
        {"number", 0, 0, 'n'},
        {"squeeze-blank", 0, 0, 's'},
        {0, 0, 0, 0}
    };

    while ((counter = getopt_long(argc, argv, "beEtTnsv", lflags, &index)) != -1) {
        switch (counter) {
            case 'b':
                flags->b_flag = 1;
                break;
            case 'e':
                flags->E_flag = 1;
                flags->v_flag = 1;
                break;
            case 'E':
                flags->E_flag = 1;
                break;
            case 'n':
                flags->n_flag = 1;
                break;
            case 's':
                flags->s_flag = 1;
                break;
            case 't':
                flags->T_flag = 1;
                flags->v_flag = 1;
                break;
            case 'T':
                flags->T_flag = 1;
                break;
            case 'v':
                flags->v_flag = 1;
                break;
            default:
                correct = 1;
                break;
        }
    }
    return correct;
}

void printer(FILE *file, struct cat_flags flags) {
    char c;
    char past = '\n';
    int line_number = 1;
    int blank = 0;

    while ((c = fgetc(file)) != EOF) {
        if (flags.b_flag == 1 && flags.n_flag == 1)
            flags.n_flag = 0;
        if (flags.s_flag == 1 && c == '\n' && past == '\n') {
            blank++;
            if (blank > 1)
                continue;
        } else {
                blank = 0;
        }
        if (flags.b_flag == 1 && c != '\n' && past == '\n')
            printf("%6d\t", line_number++);
        if (flags.n_flag == 1 && past == '\n')
            printf("%6d\t", line_number++);
        if (c == '\t' && (flags.T_flag == 1)) {
            printf("%s", "^I");
        } else if (((c >= 0 && c < 32 && c != 9 && c != 10 && c != 13)
        || c == 127) && flags.v_flag == 1) {
            invisible(c);
        } else if (c == '\n' && flags.E_flag == 1) {
            putchar('$');
            putchar(c);
        } else {
            putchar(c);
        }
        past = c;
    }
}

int blank_check(char *str) {
    int result = 0;

    for (; *str != '\n'; str++)
        result = 1;
    return result;
}

void invisible(char str) {
    switch (str) {
        case 0:
            printf("%s", "^@");
            break;
        case 1:
            printf("%s", "^A");
            break;
        case 2:
            printf("%s", "^B");
            break;
        case 3:
            printf("%s", "^C");
            break;
        case 4:
            printf("%s", "^D");
            break;
        case 5:
            printf("%s", "^E");
            break;
        case 6:
            printf("%s", "^F");
            break;
        case 7:
            printf("%s", "^G");
            break;
        case 8:
            printf("%s", "^H");
            break;
        case 11:
            printf("%s", "^K");
            break;
        case 12:
            printf("%s", "^L");
            break;
        case 14:
            printf("%s", "^N");
            break;
        case 15:
            printf("%s", "^O");
            break;
        case 16:
            printf("%s", "^P");
            break;
        case 17:
            printf("%s", "^Q");
            break;
        case 18:
            printf("%s", "^R");
            break;
        case 19:
            printf("%s", "^S");
            break;
        case 20:
            printf("%s", "^T");
            break;
        case 21:
            printf("%s", "^U");
            break;
        case 22:
            printf("%s", "^V");
            break;
        case 23:
            printf("%s", "^W");
            break;
        case 24:
            printf("%s", "^X");
            break;
        case 25:
            printf("%s", "^Y");
            break;
        case 26:
            printf("%s", "^Z");
            break;
        case 27:
            printf("%s", "^[");
            break;
        case 28:
            printf("%s", "^\\");
            break;
        case 29:
            printf("%s", "^]");
            break;
        case 30:
            printf("%s", "^^");
            break;
        case 31:
            printf("%s", "^_");
            break;
        case 127:
            printf("%s", "^?");
            break;
    }
}
