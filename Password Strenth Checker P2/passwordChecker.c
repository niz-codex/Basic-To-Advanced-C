#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    
    if (argc != 2){
        printf("Usage %s <password>\n", argv[0]);
        return 1;
    }
    char *password = argv[1];
    int lower = 0, upper = 0, digit = 0, special = 0, length = 0;

    int len = strlen(password);

    if (len >= 8)
        length = 1;

    for(int i = 0; i < len; i ++)
        if (isupper(password[i])) upper = 1;
        else if (islower(password[i])) lower = 1;
        else if (isdigit(password[i])) digit = 1;
        else if (ispunct(password[i])) special = 1;
    

    int result = upper + lower + digit + special + length;

    printf("Password: %s\n", password);
    printf("Strength: ");
    if (result == 5) printf("Strong\n");
    else if (result >= 3) printf("Medium\n");
    else printf("Weak\n");

    if (!length) printf("- Minimum length (8> characters)!\n");
    if (!upper) printf("- At least one uppercase letter!\n");
    if (!lower) printf("- At least one lowecase letter!\n");
    if (!digit) printf("- At least one digit!\n");
    if (!special) printf("- At least one special character (like `!@#$%^&*`)!\n");

    return 0;
}



// 1. return 1; without braces
// Only the first line after if runs inside it. Without {}, return 1; runs always causing bugs. Always use braces to group multiple lines.

// 2. for with if-else if chain without braces
// if-else if chain counts as one statement, so the for loop can run it without braces. But for multiple separate statements, braces are needed.
