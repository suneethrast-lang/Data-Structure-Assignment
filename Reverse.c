/*
 * FILE: Reverse.c
 * PURPOSE: Reverse a string using a stack data structure
 * DESCRIPTION: This program takes a string as input and reverses it using a
 *              character stack. It pushes each character onto the stack and
 *              then pops them in reverse order to obtain the reversed string.
 * AUTHOR: Data Structure Assignment
 * DATE: 2024
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 101              // Maximum size of the stack
char stack[Max];            // Character stack to store string characters
int top=-1;                 // Stack pointer initialized to -1 (empty stack)

/*
 * FUNCTION: push
 * PURPOSE: Push all characters of a string onto the stack
 * PARAMETERS: ptr - pointer to the input string
 * RETURN: void
 * DESCRIPTION: Iterates through each character in the string and pushes
 *              it onto the stack until the null terminator is encountered.
 *              Checks for stack overflow (top == Max-1).
 */
void push(char *ptr)
{
    if(top==Max-1)           // Check for stack overflow
    {
        return;
    }
    else
    {
        // Iterate through each character in the string and push to stack
        for(int i=0;*(ptr+i)!='\0';i++)
        {
            top++;            // Increment top pointer
            stack[top]=*(ptr+i);  // Push character at current position
        }
    }
}

/*
 * FUNCTION: pop
 * PURPOSE: Remove and return the top character from the stack
 * PARAMETERS: None
 * RETURN: char - the character at the top of the stack, or '\0' if empty
 * DESCRIPTION: If stack is empty (top == -1), returns null character.
 *              Otherwise, retrieves the top element, decrements top,
 *              and returns the character.
 */
char pop()
{
    if(top==-1)              // Check if stack is empty
    {
        return '\0';         // Return null character if empty
    }
    else
    {
        char value=stack[top];  // Retrieve character at top
        top--;                   // Decrement top pointer
        return value;            // Return the character
    }
}

/*
 * FUNCTION: main
 * PURPOSE: Main driver function to reverse a string
 * ALGORITHM:
 *   1. Read string input from user
 *   2. Remove trailing newline from fgets input
 *   3. Push all characters onto the stack
 *   4. Pop all characters one by one into reverse array
 *   5. Add null terminator and display result
 */
int main()
{
    char string[101];        // Array to store input string
    printf("Enter the string::");
    fgets(string, sizeof(string), stdin);  // Read string with fgets
    string[strcspn(string, "\n")] = '\0';  // Remove trailing newline
    char reverse[101];       // Array to store reversed string

    // Push all characters of the input string onto the stack
    char *ptr=string;
    push(ptr);
    
    // Pop all characters from stack in reverse order
    for(int i=0;i<strlen(string);i++)
    {
        reverse[i]=pop();
    }
    reverse[strlen(string)]='\0';  // Add null terminator

    // Display original and reversed strings
    printf("The reversered string of %s is %s",string,reverse);
    return 0;
}