#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main() {
    //take user input, store it in string
    printf("What would you like to do? ");
    char input[100];
    fgets(input, sizeof(input), stdin);
    char s[100];
    strncpy(s, input, strlen(input)-1);

    //take string, split it into array of arguements

    char * arr[100];
    char * str = s;
    char * arg;
    int i = 0;
    while((arg = strsep(&str, " ")) != NULL) {
        arr[i] = arg;
        i++;
    }

    //run array of arguments using execvp
    execvp(arr[0], arr);

}
