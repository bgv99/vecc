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

    vec_alloc->elements = malloc(size);

    if(vec_alloc->elements == NULL) {
        printf("null pointer - initialisation failed\n");
        exit(1);
    }

    vec_alloc->capacity = size;
    vec_alloc->length = 0;

    return vec_alloc;
}

void Vec_put(Vec *vec, unsigned int index, void *value) {
    if(vec->elements == NULL) {
        printf("null pointer - can not put value\n");
        exit(1);
    }

    if(vec->capacity < index) {
        vec->elements = realloc(vec->elements, vec->capacity + index);
        vec->capacity += index;
    }

    vec->elements[index] = value;
    vec->length += 1;
}

void Vec_destroy(Vec *vec) {
    free(vec->elements);
    free(vec);
}

void Vec_remove(Vec *vec, unsigned int index) {
    if(vec->elements == NULL) {
        printf("null pointer - can not remove the value\n");
        exit(1);
    }

    vec->elements[index] = 0;
    vec->length -= 1;
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