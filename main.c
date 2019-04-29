/*******************************************************************************
 *                                                                             *
 * English Text Ciphers - Programming Assignment 1                             *
 *                                                                             *
 * This program can be used to encrypt and decrypt english text with rotation  *
 * or substitution ciphers using a key. The user is prompted to choose whether *
 * they would like to use a rotation or substitution cipher to encrypt or      *
 * decrypt a message. The program uses stdin to accept user messages and       *
 * values.                                                                     *
 *                                                                             *
 *                                                                             *
 *                                                                             *
 *                                                                             *
 * By Angelos Karvelis - 29/04/19                                              *
 *                                                                             *
 * Indentation style - K&R variant: Stroutsup                                  *
 *                                                                             *
 ******************************************************************************/ 

#include <stdio.h>

void rotation(char message[], int key, int choice1, int choice2);                                       //rotation function
void substitution(char message [], char key [], char aplhabet [], int choice1, int choice2);            //substitution function

int main () {
    int choice1;
    int choice2;
    
    printf("Would you like to use ROTATION CIPHER (Press 1) or SUBSTITUTION CIPHER (Press 2):");        //user prompt to choose cipher type
    scanf("%d", &choice1);                                                                              //sets choice1 value for duration of program
    
    if(choice1 == 1){                                                                                   //if user chooses rotation cipher
        printf("Would you like to ENCRYPT (Press 1) or DECRYPT (Press 2) a message: ");                 //user prompt to choose method
        scanf("%d", &choice2);                                                                          //sets choice2 value for duration of program
    
        if (choice2 == 1) {                                                                             //if user chooses to encrypt a message
    
            char message[1024];                                                                         //alows user to enter message of max 1024 characters                                                         
            int key;                                                                                    //
    
            printf("Enter message to encrypt (UPPER CASE ONLY): ");                                     //user prompt to enter message
            scanf(" %[^\n]s", message);                                                                 //reads message including whitespace until newline character is reached
    
            printf("Enter rotation amount: ");                                                          //user prompt to enter rotation amount for encryption
            scanf("%d", &key);                                                                          //reads rotation amount as integer
    
            rotation(message, key, choice1, choice2);                                                   //passing string and integer values to function (allows for use in later functions)
    
            return 0;
        }
        else if (choice2 == 2); {                                                                       //if user chooses to decrypt a message
        
            char message[1024];                                                                         //alows user to enter message of max 1024 characters
            int key;                                                                                    //
    
            printf("Enter message to decrypt (UPPER CASE ONLY): ");                                     //user prompt to enter message
            scanf(" %[^\n]s", message);                                                                 //reads message including whitespace until newline character is reached
    
            printf("Enter rotation amount: ");                                                          //user prompt to enter rotation amount for encryption
            scanf("%d", &key);                                                                          //reads rotation amount as integer
    
            rotation(message, key, choice1, choice2);                                                   //passing string and integer values to function
    
            return 0;
        }
    }
    
    if(choice1 == 2){                                                                                   //if user chooses substitution cipher
        printf("Would you like to ENCRYPT (Press 1) or DECRYPT (Press 2) a message: ");                 //user prompt to choose method
        scanf("%d", &choice2);                                                                          //sets value of choice2 for duration of program
    
        if (choice2 == 1) {                                                                             //if user chooses to encrypt a message
            int i = 0;                                                                                  //
            char L = 65;                                                                                //L variable used for loop to print characters starting at 'A'
            char message [1024];                                                                        //alows user to enter message of max 1024 characters
            char alphabet [26] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90}; //array containing upper case letters from 'A' to 'Z'
            char key [26];                                                                              //array containing 26 characters that user will input later on
        
            printf("Enter message (UPPER CASE ONLY): ");
            scanf(" %[^\n]s", message);
        
            printf("Enter key (UPPER CASE ONLY):\n");
            for (i = 0; i < 26; i++){
                printf("%c : ", L);
                scanf("%s", &key[i]);
                L++;
            }
        
            printf("Key is: ");
            for (i = 0; i < 26; i++){
            printf("%c", key[i]);
            }
        
            substitution(message, key, alphabet, choice1, choice2);
        
            return 0;
        }
        else if (choice2 == 2){
            int i = 0;
            char L = 65;
            char message [1024];                                                                        //alows user to enter message of max 1024 characters
            char alphabet [26] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
            char key [26];
        
            printf("Enter message (UPPER CASE ONLY): ");
            scanf(" %[^\n]s", message);
        
            printf("Enter key (UPPER CASE ONLY):\n");
            for (i = 0; i < 26; i++){
                printf("%c : ", L);
                scanf("%s", &key[i]);
                L++;
            }
        
            printf("\nKey is: ");
            for (i = 0; i < 26; i++){
                printf("%c", key[i]);
            }
        
            substitution(message, key, alphabet, choice1, choice2);
        
            return 0;
        }
    }
}

void rotation(char message[], int key, int choice1, int choice2) {                                      //rotation cipher function
    int i = 0;
    int key2;
    int startpoint;
    
    if(choice1 != 1){                                                                                   //if user did not choose 'ROTATION CIPHER'
        return;                                                                                         //exit function early/flow to next function (if user did not choose rotation, go to substitution)
    }

    while(message[i] != '\0') {                                                                         //loop until end of string 'null' is reached
        if(choice2 == 1){
            if((message[i]+key) >= 65 && (message[i]+key) <= 90) {                                      //if character plus key is between 'A' and 'Z' e.g. A=65, key=5...65+5=70, 70 is between 65 and 90. But Y=89, key=5...89+5=94 so not true, go to else if
                message[i] += (key);                                                                    //new value of message character equals old message character value plus key value e.g. A=65, key=5... new value of A is 65 + 5 = 70, therefore new character is F
            }
            else if (message[i] != 32) {                                                                //else if statement is code to make letters rotate back to the start of the alphabet, e.g. if key=1, Z (90) will then become A (65) instead of [ (91). Also takes into account for whitespace so sentences can retain their form wihtout becoming a huge string with no spaces
                key2 = 90 - message[i];                                                                 //{if character + key exceeds 'Z', start again from 'A'
                startpoint = 64 - key2;                                                                 //
                message[i] = startpoint + key;                                                          //}
            }
        i++;                                                                                            //increments 'i' so next array element (next character in message) can be read by loop
        }
        
        if(choice2 == 2){
            if((message[i]-key) >= 65 && (message[i]-key) <= 90) {
                message[i] -= (key);                                            //if between 'A' and 'Z' add key to character
            }
            else if(message[i] != 32) {
                key2 = message[i] - 64;                                        //if character + key exceeds 'Z', start again from 'A'
                startpoint = 90 + key2;
                message[i] = startpoint - key;
            }
        i++;                                                            //next array element to be read by loop
        }   
    }
    if(choice2 == 1){
        printf("\nEncrypted message: %s", message);                         //print message encrypted with key on a new line
    }
    else {
        printf("\nDecrypted message: %s", message);                     //print message encrypted with key on a new line
    }
}

void substitution(char message [], char key [], char alphabet [], int choice1, int choice2) {
    int i=0;
    int j=0;
    
    if(choice1 != 2){
        return;
    }
    
    if (choice2 == 1){
        printf("\n\nEncrypted message: ");
    
        while (message[i] != '\0'){
        
            for(j = 0; j < 26; j++){
                if (alphabet [j] == message [i]){
                    printf("%c", key[j]);
                }
            }
            i++;
        }
    }
    
    else {
        printf("\n\nDecrypted message: ");
        
        while (message[i] != '\0'){
        
            for(j = 0; j < 26; j++){
                if (key [j] == message [i]){
                    printf("%c", alphabet[j]);
                }
            }
            i++;
        }
    }
}

