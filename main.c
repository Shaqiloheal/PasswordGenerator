/*
    Password Generator Program

    This program generates random passwords and saves them to a CSV file along with usernames.
    Users input their first name, last name, and desired password length. The program then generates
    a username using the first two letters of the first name and six letters of the last name.
    The generated password is a combination of numbers, lowercase letters, uppercase letters, and symbols.
    The usernames, passwords, and program execution history are saved in a CSV file named "passwords.csv".

    Author: Warren Spalding
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS

// Function to clear the content of the CSV file and write headers
void clearCSVFile() {
    FILE* file;
    if (fopen_s(&file, "passwords.csv", "w") != 0) {
        fprintf(stderr, "\t\033[31mFailed to open passwords.csv for writing\033[0m\n");
        return;
    }

    // Write CSV headers
    fprintf(file, "username,password\n");

    fclose(file);
}

// Function to write username and password to the CSV file
void writeUsernamePasswordToCSV(const char* username, const char* password) {
    FILE* file;
    if (fopen_s(&file, "passwords.csv", "a") != 0) {
        fprintf(stderr, "\t\033[31mFailed to open passwords.csv for writing\033[0m\n");
        return;
    }

    fprintf(file, "%s,%s\n", username, password);
    fclose(file);
}

// Function to generate a random password
void randomPasswordGeneration(int n, const char* username) {
    int i = 0;
    srand((unsigned int)(time(NULL)));

    char numbers[] = "0123456789";
    char letter[] = "abcdefghijklmnoqprstuvwyzx";
    char LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
    char symbols[] = "!@#$^&*?";

    int max_length = n * 4;

    char* password = (char*)malloc((max_length + 1) * sizeof(char));

    if (password == NULL) {
        fprintf(stderr, "\t\033[31mMemory allocation failed\033[0m\n");
        exit(1);
    }

    for (i = 0; i < n; i++) {
        int randomizer = rand() % 4;

        if (randomizer == 0) {
            password[i] = numbers[rand() % 10];
        }
        else if (randomizer == 1) {
            password[i] = symbols[rand() % 8];
        }
        else if (randomizer == 2) {
            password[i] = LETTER[rand() % 26];
        }
        else {
            password[i] = letter[rand() % 26];
        }
    }

    password[n] = '\0';
    printf("\n\t\033[33mGenerated password: \033[32m %s\n", password);
    writeUsernamePasswordToCSV(username, password);
    free(password);
}

int main() {
    int n;
    char choice;
    char firstName[50];
    char lastName[50];
    char username[10]; // Adjust the size for the new username format

    printf("\n");
    printf("\033[36m");
    printf("\t______                                   _   _____                           _             \n");
    printf("\t| ___ \\                                 | | |  __ \\                         | |            \n");
    printf("\t| |_/ __ _ ___ _____      _____  _ __ __| | | |  \\/ ___ _ __   ___ _ __ __ _| |_ ___  _ __ \n");
    printf("\t|  __/ _` / __/ __\\ \\ /\\ / / _ \\| '__/ _` | | | __ / _ | '_ \\ / _ | '__/ _` | __/ _ \\| '__|\n");
    printf("\t| | | (_| \\__ \\__ \\  V  V | (_) | | | (_| | | |_\\ |  __| | | |  __| | | (_| | || (_) | |   \n");
    printf("\t\\_|  \\__,_|___|___/ \\_/\\_/ \\___/|_|  \\__,_|  \\____/\\___|_| |_|\\___|_|  \\__,_|\\__\\___/|_|   \n");
    printf("\033[0m");
    printf("\n");
    printf("\n");

    clearCSVFile(); // Clear the content of the CSV file and write headers

    // Loop to generate passwords
    do {
        printf("\033[33m");
        printf("\n\tEnter your first name: \033[32m");
        scanf_s("%s", firstName, sizeof(firstName));
        printf("\t\033[33mEnter your last name: \033[32m");
        scanf_s("%s", lastName, sizeof(lastName));

        // Generate a username using the first two letters of the first name and six letters of the last name
        snprintf(username, sizeof(username), "%.2s%.6s", firstName, lastName);

        printf("\n\t\033[33mGenerated username: \033[32m%s\033[33m\n", username);

        printf("\n\tEnter the desired password length (up to 100 characters): \033[32m");
        if (scanf_s("%d", &n) != 1) {
            printf("\t\033[31mInvalid input.\033[0m\n");
            return 1;
        }

        if (n <= 0 || n > 100) {
            printf("\n\t\033[31mInvalid password length.\033[0m\n");
            return 1;
        }

        // Generate and display random password, then save to CSV
        randomPasswordGeneration(n, username);

        printf("\n\t\033[0mGenerate another password? (y/n): ");
        getchar(); // Consume newline from previous input
        choice = getchar();
    } while (choice == 'y' || choice == 'Y');

    printf("\n\t\033[0mPress Enter to close the program...");
    getchar();
    getchar();

    return 0;
}
