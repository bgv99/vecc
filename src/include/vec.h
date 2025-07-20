typedef struct Vec Vec;

Vec *Vec_init(unsigned int);
void Vec_put(Vec *, unsigned int, void *);
void Vec_destroy(Vec *);
void Vec_remove(Vec *, unsigned int);
void *Vec_get(Vec *, unsigned int);
unsigned int Vec_len(Vec *);
unsigned int Vec_capacity(Vec *);
void Vec_popBack(Vec *);