#include "m61.hh"
#include <cstdio>
#include <cassert>
#include <cstring>
// Check detection of one-byte boundary write error of character \0.

int main() {
    const char* string1 = "Hello, this is a string! I exist to demonstrate a common error.";
    char* copy_of_string1 = (char*) m61_malloc(strlen(string1));
        // Whoops! Forgot to allocate space for the '\0' that ends the string.
    strcpy(copy_of_string1, string1); // == boundary write error
    fprintf(stderr, "About to free %p\n", copy_of_string1);
    m61_free(copy_of_string1);
    m61_print_statistics();
}

//! About to free ??{0x\w+}=ptr??
//! MEMORY BUG???: detected wild write during free of pointer ??ptr??
//! ???
//!!ABORT
