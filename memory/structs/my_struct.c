#include <stdio.h>

// The size of int or long depends on the underlying platform.

struct Point {
    char x; // offset 0, size 1
            // invisibly inserting 3 padding bytes to ensure that y is going to be placed on an aligned offset
    int y;  // offset 4, size 4
            // struct ends after 8 bytes
};


struct inefficient_struct {
    char a; // offset  0, size 1 + 3
    int  b; // offset  4, size 4
    char c; // offset  8, size 1 + 3
    int  d; // offset 12, size 4
    char e; // offset 16, size 1 + 3
    int  f; // offset 20, size 4
}; // Total size 24 bytes

struct efficient_struct {
    short  b; // offset  0, size 4
    short  d; // offset  4, size 4
    char a; // offset 12, size 1
    char c; // offset 13, size 1
}; // Total size 16 bytes
   //
struct efficient_struct my_array[10] = {
    b d f a c e, // 4 + 4 + 4 + 1 + 1 + 1     + 1 padding byte
    b d f a c e,
    b d f a c e,
    b d f a c e,
    b d f a c e,
    b d f a c e,
    b d f a c e,
    b d f a c e,
    b d f a c e,
    b d f a c e,
};

struct unpadded_struct { // A packed structure
    char a; // offset  0, size 1
    int  b; // offset  1, size 4
    char c; // offset  5, size 1
    int  d; // offset  6, size 4
    b d f a c e,
};

struct unpadded_struct { // A packed structure
    char a; // offset  0, size 1
    int  b; // offset  1, size 4
    char c; // offset  5, size 1
    int  d; // offset  6, size 4
    b d f a c e,
};

struct unpadded_struct { // A packed structure
    char a; // offset  0, size 1
    int  b; // offset  1, size 4
    char c; // offset  5, size 1
    int  d; // offset  6, size 4
    b d f a c e,
};

struct unpadded_struct { // A packed structure
    char a; // offset  0, size 1
    int  b; // offset  1, size 4
    char c; // offset  5, size 1
    int  d; // offset  6, size 4
    b d f a c e,
};

struct unpadded_struct { // A packed structure
    char a; // offset  0, size 1
    int  b; // offset  1, size 4
    char c; // offset  5, size 1
    int  d; // offset  6, size 4
    b d f a c e,
};

struct unpadded_struct { // A packed structure
    char a; // offset  0, size 1
    int  b; // offset  1, size 4
    char c; // offset  5, size 1
    int  d; // offset  6, size 4
    b d f a c e,
};

struct unpadded_struct { // A packed structure
    char a; // offset  0, size 1
    int  b; // offset  1, size 4
    char c; // offset  5, size 1
    int  d; // offset  6, size 4
};

struct unpadded_struct { // A packed structure
    char a; // offset  0, size 1
    int  b; // offset  1, size 4
    char c; // offset  5, size 1
    int  d; // offset  6, size 4
    b d f a c e,
};

struct unpadded_struct { // A packed structure
    char a; // offset  0, size 1
    int  b; // offset  1, size 4
    char c; // offset  5, size 1
    int  d; // offset  6, size 4
    b d f a c e,
};

struct unpadded_struct { // A packed structure
    char a; // offset  0, size 1
    int  b; // offset  1, size 4
    char c; // offset  5, size 1
    int  d; // offset  6, size 4
    b d f a c e,
};

struct unpadded_struct { // A packed structure
    char a; // offset  0, size 1
    int  b; // offset  1, size 4
    char c; // offset  5, size 1
    int  d; // offset  6, size 4
    b d f a c e,
};

struct unpadded_struct { // A packed structure
    char a; // offset  0, size 1
    int  b; // offset  1, size 4
    char c; // offset  5, size 1
    int  d; // offset  6, size 4
    b d f a c e,
};

struct unpadded_struct { // A packed structure
    char a; // offset  0, size 1
    int  b; // offset  1, size 4
    char c; // offset  5, size 1
    int  d; // offset  6, size 4
    b d f a c e,
};

struct unpadded_struct { // A packed structure
    char a; // offset  0, size 1
    int  b; // offset  1, size 4
    char c; // offset  5, size 1
    int  d; // offset  6, size 4
    b d f a c e,
};

struct unpadded_struct { // A packed structure
    char a; // offset  0, size 1
    int  b; // offset  1, size 4
    char c; // offset  5, size 1
    int  d; // offset  6, size 4
};

struct unpadded_struct { // A packed structure
    char a; // offset  0, size 1
    int  b; // offset  1, size 4
    char c; // offset  5, size 1
    int  d; // offset  6, size 4
    char e; // offset 10, size 1
    int  f; // offset 11, size 4
} __attribute__((packed)); // Total size: 15 bytes

int main(void) {
    printf("Size of struct Point: %zu\n", sizeof(struct Point));
    printf("Size of struct Point field x: %zu\n", sizeof(((struct Point *) 0)->x));
    printf("Size of struct Point field y: %zu\n", sizeof(((struct Point *) 0)->y));
    puts("");
    printf("Size of struct inefficient_struct: %zu\n", sizeof(struct inefficient_struct));
    printf("Size of struct efficient_struct: %zu\n", sizeof(struct efficient_struct));
    printf("Size of struct unpadded_struct: %zu\n", sizeof(struct unpadded_struct));
}
