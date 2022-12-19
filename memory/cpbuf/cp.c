#include <stdio.h>
#include <stdlib.h>

// WARNING!
// This program still has bugs!
// Not everything about this program is good or correct!

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "%s: error: Wrong number of arguments.\n", argv[0]);
        fprintf(stderr, "Usage: %s BUF_SIZE INFILE OUTFILE\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    size_t buf_size = (size_t) atol(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];

    FILE *in = fopen(infile, "r");
    if (!in) {
        fprintf(stderr, "%s: error: Can't open file for reading.\n", infile);
        exit(EXIT_FAILURE);
    }
    FILE *out = fopen(outfile, "w");
    if (!out) {
        fprintf(stderr, "%s: error: Can't open file for writing.\n", outfile);
        fclose(out);
        exit(EXIT_FAILURE);
    }

    char *buf = malloc(buf_size);
    if (buf) {
        for (size_t bytesRead; (bytesRead = fread(buf, 1, buf_size, in)) != 0;) {
            fwrite(buf, bytesRead, 1, out);
        }
        free(buf);
    } else {
        fprintf(stderr, "%s: error: Couldn't allocate buffer, maybe try a smaller buffer size?\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fclose(out);
    fclose(in);
    return EXIT_SUCCESS;
}
