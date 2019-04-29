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
 * User interface notes:                                                       *
 *                                                                             *
 * Choose between ROTATION or SUBSTITUTION by entering 1 or 2 on the keyboard  *
 * Choose between ENCRYPTION or DECRYPTION by entering 1 or 2 on the keyboard  *
 *                                                                             *
 * FOR ROTATION - Enter your message using UPPER CASE letters only             *
 * (max 1024 characters). Enter your key as a number from 1 to 26.             *
 *                                                                             *
 *                                                                             *
 * FOR SUBSTITUTION - Enter your message using UPPER CASE letters only         *
 * (max 1024 characters). Enter your key using UPPER CASE letters only         *
 * (26 characters).                                                            *
 *                                                                             *                                                                 
 *                                                                             *                                                              
 * By Angelos Karvelis - 29/04/19                                              *                                            
 *                                                                             *                                                            
 * Indentation style - K&R variant: Stroutsup                                  *                                
 *                                                                             *                                 
 ******************************************************************************/ 

#include <stdio.h>

void rotation(char message[], int key, int choice1, int choice2);       //rotation function
void substitution(char message [], char key [], char aplhabet [], int choice1, int choice2);        //substitution function

int main () {
    int choice1;
    int choice2;
    
    printf("Would you like to use ROTATION CIPHER (Press 1) or SUBSTITUTION CIPHER (Press 2):");        //user prompt to choose cipher type
    scanf("%d", &choice1);      //sets choice1 value for duration of program
    
    if(choice1 == 1){       //if user chooses rotation cipher
        printf("\nWould you like to ENCRYPT (Press 1) or DECRYPT (Press 2) a message: ");       //user prompt to choose method
        scanf("%d", &choice2);      //sets choice2 value for duration of program
    
        if (choice2 == 1) {     //if user chooses to encrypt a message
    
            char message[1024];     //alows user to enter message of max 1024 characters                                                         
            int key;                                                                                    //
    
            printf("\nEnter message to encrypt (UPPER CASE ONLY): ");       //user prompt to enter message
            scanf(" %[^\n]s", message);     //reads message including whitespace until newline character is reached
    
            printf("\nEnter rotation amount: ");        //user prompt to enter rotation amount for encryption
            scanf("%d", &key);      //reads rotation amount as integer
    
            rotation(message, key, choice1, choice2);       //passing string and integer values to function (allows for use in later functions)
    
            return 0;
        }
        else if (choice2 == 2); {       //if user chooses to decrypt a message
        
            char message[1024];     //alows user to enter message of max 1024 characters
            int key;                                                                                    
    
            printf("\nEnter message to decrypt (UPPER CASE ONLY): ");       //user prompt to enter message
            scanf(" %[^\n]s", message);     //reads message including whitespace until newline character is reached
    
            printf("\nEnter rotation amount: ");        //user prompt to enter rotation amount for encryption
            scanf("%d", &key);      //reads rotation amount as integer
    
            rotation(message, key, choice1, choice2);       //passing string and integer values to function
    
            return 0;
        }
    }
    
    if(choice1 == 2){       //if user chooses substitution cipher
        printf("\nWould you like to ENCRYPT (Press 1) or DECRYPT (Press 2) a message: ");       //user prompt to choose method
        scanf("%d", &choice2);      //sets value of choice2 for duration of program
    
        if (choice2 == 1) {     //if user chooses to encrypt a message
            int i = 0;     
            char L = 65;        //L variable used for loop to print characters starting at 'A'
            char message [1024];        //alows user to enter message of max 1024 characters
            char alphabet [26] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};      //array containing upper case letters from 'A' to 'Z'
            char key [26];      //array containing 26 characters that user will input later on
        
            printf("\nEnter message (UPPER CASE ONLY): ");      //user prompt to enter message
            scanf(" %[^\n]s", message);     //scans message as string including whitespace characters until new line is reached
        
            printf("\nEnter key (UPPER CASE ONLY):\n");     //user prompt to enter key
            for (i = 0; i < 26; i++){       //loops for i = 0 to 26, reads key array elements as a string
                printf("%c : ", L);     //prints string elements next to their corresponding alphabet letters in the same position, L is used as a variable to store ASCII character values. e.g. %c 65 would print the letter A and store it in L
                scanf("%s", &key[i]);       //reads the input values for key as a string
                L++;        //increments L so value is now 66, next time in loop, %c, L will print B. etc.
            }
        
            printf("\nKey is: ");       
            for (i = 0; i < 26; i++){
            printf("%c", key[i]);       //prints key as a one line string for user satisfaction
            }
        
            substitution(message, key, alphabet, choice1, choice2);     //passing string and integer values to function
        
            return 0;
        }
        else if (choice2 == 2){
            int i = 0;
            char L = 65;
            char message [1024];        //alows user to enter message of max 1024 characters
            char alphabet [26] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
            char key [26];
        
            printf("\nEnter message (UPPER CASE ONLY): ");
            scanf(" %[^\n]s", message);
        
            printf("\nEnter key (UPPER CASE ONLY):\n");
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

void rotation(char message[], int key, int choice1, int choice2) {      //rotation cipher function
    int i = 0;
    int key2;
    int startpoint;
    
    if(choice1 != 1){       //if user did not choose 'ROTATION CIPHER'
        return;     //exit function early/flow to next function (if user did not choose rotation, go to substitution)
    }

    while(message[i] != '\0') {     //loop until end of string 'null' is reached
        if(choice2 == 1){       //if user chose encrypt
            if((message[i]+key) >= 65 && (message[i]+key) <= 90) {      //if character plus key is between 'A' and 'Z' e.g. A=65, key=5...65+5=70, 70 is between 65 and 90. But Y=89, key=5...89+5=94 so not true, go to else if
                message[i] += (key);        //new value of message character equals old message character value plus key value e.g. A=65, key=5... new value of A is 65 + 5 = 70, therefore new character is F
            }
            else if (message[i] != 32) {        //else if statement is code to make letters rotate back to the start of the alphabet, e.g. if key=1, Z (90) will then become A (65) instead of [ (91). Also takes into account for whitespace so sentences can retain their form wihtout becoming a huge string with no spaces
                key2 = 90 - message[i];         //{if character + key exceeds 'Z', start again from 'A'
                startpoint = 64 - key2;         //
                message[i] = startpoint + key;  //}
            }
        i++;        //increments 'i' so next array element (next character in message) can be read by loop
        }
        
        if(choice2 == 2){       //if user chose decrypt
            if((message[i]-key) >= 65 && (message[i]-key) <= 90) {      //if message minus key is between 65 and 90
                message[i] -= (key);        //new value of message character equals old message character value minus key value e.g. F=70, key=5... new value of F is 70 - 5 = 65, therefore new character is A
            }
            else if(message[i] != 32) {
                key2 = message[i] - 64;         //if character - key falls short of 'A', start again from 'Z'{
                startpoint = 90 + key2;         //
                message[i] = startpoint - key;  //}
            }
        i++;        //next array element to be read by loop
        }   
    }
    if(choice2 == 1){
        printf("\nEncrypted message: %s", message);         //print message encrypted with key on a new line
    }
    else {
        printf("\nDecrypted message: %s", message);         //print message encrypted with key on a new line
    }
}

void substitution(char message [], char key [], char alphabet [], int choice1, int choice2) {       //substitution cipher function
    int i=0;        //
    int j=0;
    
    if(choice1 != 2){       //if user chooses rotation exit function
        return;
    }
    
    if (choice2 == 1){      //if user chooses substitution
        printf("\n\nEncrypted message: ");      //an output statement before the while loop so it is only printed once
    
        while (message[i] != '\0'){     //loop until end of string 'null' is reached
        
            for(j = 0; j < 26; j++){                    //j used to compare different array elements
                if (alphabet [j] == message [i]){       //if alphabet value equals a value in message, print the key value corresponding to the same alphabet alphabet value. e.g. if A (0) in alphabet = A (i) in message, print key K (0)
                    printf("%c", key[j]);
                }
            }
            i++;        //next message element
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

