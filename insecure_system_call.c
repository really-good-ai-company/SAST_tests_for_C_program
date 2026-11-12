/*
    The program takes user input and appends it directly to a system command string 
    without any sanitization or validation.
    An attacker could exploit this by entering a command that executes arbitrary code.
    For example, a user could input ; rm -rf / which, when appended to the command 
    string and executed, could potentially delete files on the system 
    (or perform other malicious actions).
    The use of system in combination with unsanitized user input is a textbook
    example of a command injection vulnerability.
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main() {
    char userInput[256];

    printf("Enter a command: ");
    fgets(userInput, sizeof(userInput), stdin);
    userInput[strcspn(userInput, "\n")] = 0; // Remove newline character

    // Reject anything the shell would interpret as a separator, redirection or expansion
    if (strpbrk(userInput, ";|&$`\\\"'<>(){}[]*?~!#/\n\r") != NULL) {
        printf("Input contains characters that are not allowed.\n");
        return 1;
    }

    // Run echo directly instead of through a shell
    execlp("echo", "echo", userInput, (char *)NULL);
    perror("execlp");
    return 1;

    return 0;
}
