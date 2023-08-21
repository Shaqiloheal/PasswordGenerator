# Password Generator Program

## Overview

The Password Generator Program is a C program that allows users to generate random passwords based on their first name, last name, and desired password length. The program also generates usernames using the first two letters of the first name and six letters of the last name. The generated usernames, passwords, and program execution history are saved in a CSV file named "passwords.csv".

## Author

**Author:** Warren Spalding

## Getting Started

To use the Password Generator Program, follow these steps:

1. **Compile the Program:** Compile the C code using a C compiler. If you are using a GCC compiler, you can compile the code with the following command:

    ```bash
    gcc -o password_generator password_generator.c
    ```

2. **Run the Program:** After compiling, run the compiled executable:

    ```bash
    ./password_generator
    ```

## How to Use

1. When you run the program, you'll see the program's banner followed by prompts to enter your first name and last name.

2. **Enter Your Name:** Enter your first name and last name when prompted.

3. **Generated Username:** The program will generate a username for you using the first two letters of your first name and the first six letters of your last name. This username will be displayed on the screen.

4. **Enter Password Length:** You'll be prompted to enter the desired password length (up to 100 characters). Enter a number between 1 and 100.

5. **Generated Password:** The program will generate a random password for you consisting of numbers, lowercase letters, uppercase letters, and symbols. The generated password will be displayed on the screen.

6. **Save to CSV:** The generated username and password will be saved to a CSV file named "passwords.csv".

7. **Generate Another Password:** After generating and saving a password, you'll be prompted whether you want to generate another password. Type 'y' or 'Y' to generate another password or any other key to exit the program.

8. **Exit the Program:** When you're done generating passwords, press Enter to close the program.

## Notes

- The program generates passwords randomly based on a combination of numbers, lowercase letters, uppercase letters, and symbols.
- The generated usernames, passwords, and program execution history are saved in the "passwords.csv" file in the same directory as the program.

## Disclaimer

Please be aware that this program is a simple example and may not meet the security requirements for generating strong passwords in real-world applications. It is recommended to use dedicated password management tools for creating and managing secure passwords.
