#include <stdio.h>
#include <stdbool.h>
#include <string.h>


#define MAX_ATTEMPTS 3
#define MAX_LINE 256
#define FILE_NAME "user_details.txt"

typedef struct {
    char username[64];
    char password[64];
} Info;

void loginSystem (Info *info);
void registerInfo (Info *info);
void saveDetails (const Info * info);

int main() {
    int option;
    char user[64];
    char pass[64];

    Info info;
    memset(&info, 0, sizeof(info));

    printf("1.Login\n2.Register\n3.Exit\n");
    scanf("%d", &option);

    if (option == 1){
        printf("Enter a password: ");
        fgets(user,sizeof(user), stdin);
        user[strcspn(user, "\n")] = '\0';

        printf("Enter a username: ");

        fgets(pass,sizeof(pass), stdin);
        pass[strcspn(pass, "\n")] = '\0';

        loginSystem(&info);
    }
    else if (option == 2){
        registerInfo(&info);
    }
    else {
        printf("Program Exiting...\n");
    }
    return 0;
}

void loginSystem (Info *info) {
    FILE *fp = fopen(FILE_NAME, "r");
    char fileOutput[MAX_LINE];

    if (!fp)
        return;

    while (fgets(fileOutput, sizeof(fileOutput), fp)) {
        char pass[64], user[64];
        sscanf(fileOutput,"%[^,],%s", pass, user);
        if (strcmp(info->password,pass) == 0 && strcmp(info->username, user) == 0){
            printf("Access Granted!\n");               

        }
    }
}

void registerInfo (Info *info) {

    printf("Enter your name: ");
    fgets(info->username, sizeof(info->username), stdin);
    info->username[strcspn(info->username, "\n")] = '\0';
    
    printf("Enter your password: ");
    fgets(info->password, sizeof(info->password), stdin);
    info->password[strcspn(info->password, "\n")] = '\0';

    saveDetails(info);
}

void saveDetails (const Info * info) {
    FILE *fp = fopen(FILE_NAME, "a");

    if (fp) {
        fprintf(fp, "%s,%s\n", info->username, info-> password);
        fclose(fp);
        printf("Registration completed, you can login now!\n"); 
    } 
    else {
        printf("Error: Unable to write to file.\n");
    }
}






//this can't work!!!!