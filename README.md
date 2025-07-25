### Example Code
    #include "include/vec.h"
    #include <stdio.h>

    int main() {
        Vec *my_vec = Vec_init(3);

        Vec_put(my_vec, 0, "Rust");
        Vec_put(my_vec, 1, "Java");
        Vec_put(my_vec, 2, "Python");

        for(int i = 0; i < Vec_len(my_vec); i++) {
            printf("%s ", Vec_get(my_vec, i));
        }

        Vec_destroy(my_vec);

        return 0;
    }