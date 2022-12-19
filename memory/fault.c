#include <stdio.h>

char *text1 = "Hello, world!";
char *text2 = NULL;
char *text3;
char *text4;
char *text5 = "Hello, class!";
char *text6;

int main(void) {
    text3 = text1 + 7; // Ok, within bounds of text1
    text4 = text1 + 70000000; // BAD!!!
    text6 = text1 + 14; // BAD!!!
    puts(text1);        // Writes "Hello, world!\n" to stdout
    //puts(text2);      // Segmentation fault / page fault
    puts(text3);        // Writes "world!\n" to stdout
    //puts(text4);        // (Most likely) Segmentation fault / page fault
    puts(text5);        // Writes "Hello, class!\n" to stdout
    puts(text6);        // Writes "Hello, class!\n" to stdout (by sheer accident) - BAD!!!
}
