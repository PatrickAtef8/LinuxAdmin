#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Wrong entry, Usage: sudo ./a.out <0 or 1>\n");
        return 1; // Exit if no argument is passed
    }

    int variable = open("/sys/class/leds/input2::capslock/brightness", O_RDWR);

    if (variable < 0) {
        perror("Error opening LED brightness file");
        return 1; // Exit if the file cannot be opened
    }

    printf("argc = %d\n", argc);       // Print argument count
    printf("argv[1] = %s\n", argv[1]); // Print the first argument

    dprintf(variable, "%s\n", argv[1]); //Write the value to the brightness file
					
    if (strcmp(argv[1],"1")==0)
    {
	printf("Capslock led ON");
    }
   else if (strcmp(argv[1],"0")==0)
    {
	printf("Capslock led OFF");
    } 

      return 0;
}

