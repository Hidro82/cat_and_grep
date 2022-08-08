#include "s21_cat.h"

int main(int argc, char *argv[]) {
    FILE *file;
    struct cat_flags flags = {0};
    int correct = 0;
    int counter = 0;
    int i = 1;

    correct = flag_checker(argc, argv, &flags);
    if (correct != 1) {
        for (; i < argc; i++) {
            if ((file = fopen(argv[i], "r")) != NULL) {
                printer(file, flags);
                fclose(file);
                counter++;
            }
        }
    }
    return 0;
}
