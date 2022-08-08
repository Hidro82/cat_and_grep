#include "s21_grep.h"

int main(int argc, char *argv[]) {
    struct grep_flags flags = {0};
    char regular[2056];
    int correct = 0;
    int counter = 0;
    int i = 1;
    FILE *file;
    regex_t reg;

    correct = flag_checker(argc, argv, &flags, regular);
    if (flags.e_flag == 0) {
        sprintf(regular, "%s", argv[optind++]);
        i = optind++;
    }
    for (int j = i; j < argc; j++) {
        if ((file = fopen(argv[j], "r")) != NULL) {
            counter++;
            fclose(file);
        }
    }
    regcomp(&reg, regular, (flags.i_flag == 1) ? REG_ICASE | REG_EXTENDED
                                               : REG_EXTENDED);
    if (correct != 1) {
        for (; i < argc; i++) {
            if ((file = fopen(argv[i], "r")) != NULL) {
                printer(file, flags, reg, argv[i], counter);
                fclose(file);
            }
        }
    }
    regfree(&reg);
}
