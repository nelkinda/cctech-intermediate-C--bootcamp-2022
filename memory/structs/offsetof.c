#include <stdalign.h>
#include <stdio.h>
#include <stdint.h>

struct Sample {
    char otherFlags;
    char *name;
    long timestamp;
    char flags;
};

#define offsetof(s, f) ((intptr_t) &(((s *) 0)->f))

int main(void) {
    // How big is the entire structure?
    printf("Q: How big is the entire struct Sample?\nA: %zu\n\n", sizeof(struct Sample));

    // How big is field otherFlags?
    printf("Q: How big is field otherFlags?\nA: %zu\n\n", sizeof(((struct Sample *) 0)->otherFlags));

    // How big is field name?
    printf("Q: How big is field name?\nA: %zu\n\n", sizeof(((struct Sample *) 0)->name));

    // How big is field timestamp?
    printf("Q: How big is field timestamp?\nA: %zu\n\n", sizeof(((struct Sample *) 0)->timestamp));

    // How big is field flags?
    printf("Q: How big is field flags?\nA: %zu\n\n", sizeof(((struct Sample *) 0)->flags));

    // What is the offset of field otherFlags?
    printf("Q: What is the offset of field otherFlags?\nA: %zu\n\n", offsetof(struct Sample, otherFlags));

    // What is the offset of field name?
    printf("Q: What is the offset of field name?\nA: %zu\n\n", offsetof(struct Sample, name));

    // What is the offset of field timestamp?
    printf("Q: What is the offset of field timestamp?\nA: %zu\n\n", offsetof(struct Sample, timestamp));

    // What is the offset of field flags?
    printf("Q: What is the offset of field flags?\nA: %zu\n\n", offsetof(struct Sample, flags));

    // What is the required alignment of the entire structure?
    printf("Q: What is the alignment requirement of the entire structure?\nA: %zu\n\n", alignof(struct Sample));

    // What is the required alignment of field otherFlags?
    printf("Q: What is the alignment requirement of field otherFlags?\nA: %zu\n\n", alignof(((struct Sample *)0)->otherFlags));

    // What is the required alignment of field name?
    printf("Q: What is the alignment requirement of field name?\nA: %zu\n\n", alignof(((struct Sample *)0)->name));

    // What is the required alignment of field timestamp?
    printf("Q: What is the alignment requirement of field timestamp?\nA: %zu\n\n", alignof(((struct Sample *)0)->timestamp));

    // What is the required alignment of field flags?
    printf("Q: What is the alignment requirement of field flags?\nA: %zu\n\n", alignof(((struct Sample *)0)->flags));

    // How many padding bytes are between field otherFlags and field name?
    printf("Q: How many padding bytes are between field otherFlags and field name?\nA: %zu\n\n",
           offsetof(struct Sample, name) - (offsetof(struct Sample, otherFlags) + sizeof(((struct Sample *)0)->otherFlags)));

    // How many padding bytes are between field name and field timestamp?
    printf("Q: How many padding bytes are between field name and field timestamp?\nA: %zu\n\n",
           offsetof(struct Sample, timestamp) - (offsetof(struct Sample, name) + sizeof(((struct Sample *)0)->name)));

    // How many padding bytes are between field timestamp and field flags?
    printf("Q: How many padding bytes are between field timestamp and field flags?\nA: %zu\n\n",
           offsetof(struct Sample, flags) - (offsetof(struct Sample, timestamp) + sizeof(((struct Sample *)0)->timestamp)));

    // How many padding bytes are after field flags?
    printf("Q: How many padding bytes are after field flags?\nA: %zu\n\n",
           sizeof(struct Sample) - (offsetof(struct Sample, flags) + sizeof(((struct Sample *)0)->flags)));
}
