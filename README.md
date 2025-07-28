### Example Code
    #include "include/vec.h"
    #include <stdio.h>

    int main() {
        Vec *vec = Vec_init(sizeof(int), 3);
        int a = 10, b = 20, c = 30;

        Vec_push(vec, &a);
        Vec_push(vec, &b);
        Vec_push(vec, &c);

        for(int i = 0; i < Vec_length(vec); i++) {
            printf("%d ", *(int *) Vec_get(vec, i));
        }

        putchar('\n');

        Vec_destroy(vec);

        return 0;
    }