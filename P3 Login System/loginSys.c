#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>



// #define MAX_ATTEMPTS 3
#define MAX_LINE 256
#define FILE_NAME "user_details.txt"


typedef struct {
    char username[64];
    char password[64];
} Info;

void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
void loginSystem (Info *info);
void registerInfo (Info *info);
void saveDetails (const Info * info);


int main() {
    Info info;

    int option;
    char user[64];
    char pass[64];
    
    memset(&info, 0, sizeof(info));

    printf("1.Login\n2.Register\n3.Exit\n");
    printf("Enter your option: ");
    scanf("%d", &option);
    getchar();

    if (option == 1){
        clearScreen();
        printf("\n[*]--- THIS LOGING PAGE ---[*]\n\n");
        printf("Enter a password: ");
        fgets(user,sizeof(user), stdin);
        user[strcspn(user, "\n")] = '\0';

        printf("Enter a username: ");
        fgets(pass,sizeof(pass), stdin);
        pass[strcspn(pass, "\n")] = '\0';

        strcpy(info.username, user);
        strcpy(info.password, pass);

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
    bool loggedIn = false;

    if (!fp){
        printf("Please register your account, then login!\n");
        return;
    }  
        
    while (fgets(fileOutput, sizeof(fileOutput), fp)) {
        char pass[64], user[64];
        sscanf(fileOutput,"%[^,],%s", user, pass);
        if (strcmp(info->password,pass) == 0 && strcmp(info->username, user) == 0){
            printf("Access Granted!\n");               
            loggedIn = true;
            break;
        }
    }

    if (!loggedIn){
        printf("Access Denied! Invalid username or password.\n");
    }
    
    fclose(fp);
}

void registerInfo (Info *info) {
    clearScreen();
    printf("\n[*]--- THIS REGISTER PAGE ---[*]\n\n");
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




