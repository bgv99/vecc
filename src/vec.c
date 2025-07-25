#include "include/vec.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Vec {
    unsigned int length;
    unsigned int capacity;
    void **elements;
} Vec;

Vec *Vec_init(unsigned int size) {
    Vec *vec_alloc = malloc(sizeof(Vec));

    if(vec_alloc == NULL) {
        printf("null pointer - initialisation failed\n");
        exit(1);
    }

    vec_alloc->elements = malloc(sizeof(void *) * size);

    if(vec_alloc->elements == NULL) {
        printf("null pointer - initialisation failed\n");
        Vec_destroy(vec_alloc);
        exit(1);
    }

    vec_alloc->capacity = size;
    vec_alloc->length = 0;

    return vec_alloc;
}

void Vec_put(Vec *vec, unsigned int index, void *value) {
    if(vec->elements == NULL) {
        printf("null pointer - can not put value\n");
        Vec_destroy(vec);
        exit(1);
    }

    if(vec->capacity <= index) {
        int increment = (index - vec->capacity) * sizeof(void *);
        int current = vec->capacity * sizeof(void *);

        if((vec->elements = realloc(vec->elements, current + increment)) != NULL) {
            vec->capacity = vec->capacity + (index - vec->capacity);
        } else {
            printf("null pointer - reallocation failed\n");
            Vec_destroy(vec);
            exit(1);
        }
    }

    vec->elements[index] = value;
    vec->length++;
}

void Vec_destroy(Vec *vec) {
    free(vec->elements);
    free(vec);
}

void Vec_remove(Vec *vec, unsigned int index) {
    if(vec->elements == NULL) {
        printf("null pointer - can not remove the value\n");
        Vec_destroy(vec);
        exit(1);
    }

    for(int i = index; i < (Vec_capacity(vec) - 1); i++) {
        void *backup = vec->elements[i];

        vec->elements[i] = vec->elements[i + 1];
        vec->elements[i + 1] = backup;
    }

    int current = vec->capacity * sizeof(void *);

    if((vec->elements = realloc(vec->elements, current - sizeof(void *))) != NULL) {
        vec->capacity--;
        vec->length--;
    } else {
        printf("null pointer - reallocation failed\n");
        Vec_destroy(vec);
        exit(1);
    }
}

void *Vec_get(Vec *vec, unsigned int index) {
    return vec->elements[index];
}

unsigned int Vec_len(Vec *vec) {
    return vec->length;
}

unsigned int Vec_capacity(Vec *vec) {
    return vec->capacity;
}