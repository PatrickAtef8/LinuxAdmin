#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    char buffer[1024]; // Temporary buffer to store the formatted string
    int length = vsnprintf(buffer, sizeof(buffer), format, args); // Format the string

    if (length < 0) {
        va_end(args);
        return -1; // Error in formatting
    }

    // Write the formatted string to the standard output
    ssize_t written = write(STDOUT_FILENO, buffer, length);
    va_end(args);

    return (written < 0) ? -1 : length; // Return the number of bytes written or -1 on error
}

int main() {
    my_printf("Hello, %s! This is your own printf function Made in %d.\n", "Patrick", 2024);
    return 0;
}

