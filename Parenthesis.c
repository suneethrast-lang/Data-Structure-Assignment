#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 10001

char stack[Max]; // Maximum size of stack
int top=-1; // 'top' keeps track of the top element of stack

// -------------------- PUSH FUNCTION --------------------
void push(char no)
{
    if(top==Max-1)
    {
        printf("Overflow");
    }
    else
    {
        top++; // Move top to next position
        stack[top]=no; // Insert element at top
    }
}

// -------------------- POP FUNCTION --------------------
char pop()
{
    if(top==-1)
    {
        printf("Underflow");
        return '\0';
    }
    else
    {
        char val = stack[top]; // Store the top element
        top--; // Decrease top (remove element)
        return val; // Return popped element
    }
}

// -------------------- CHECKING FUNCTION FOR THE BRACKETS --------------------
int ismatching(char no1, char no2)
{
    if(no1=='{' && no2=='}')
    {
        return 1;
    }
    else if(no1=='(' && no2==')')
    {
        return 1;
    }
    else if(no1=='[' && no2==']')
    {
        return 1;
    }
    else if(no1=='<' && no2=='>')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// -------------------- MAIN FUNCTION --------------------
int main()
{
    int flag=0; //To check whether the expression is valid or not
    char exp[1001]; //From lines 67-69, we input and store the expression
    printf("Enter the expression ::");
    fgets(exp, sizeof(exp), stdin);

    for(int i=0;i<strlen(exp);i++) 
    {
        if(exp[i]=='{' || exp[i]=='[' || exp[i]=='(' || exp[i]=='<') // If the character is a opening bracket, directly add it to the stack
        {
            push(exp[i]);
        }
        else if(exp[i]=='}' || exp[i]==']' || exp[i]==')' || exp[i]=='>') // If the character is a closing bracket, pop out all the elements in the stack 
        {
            if(ismatching(pop(),exp[i])) //Check the popped element in the stack and closing bracket
            {
                flag=0; //Keep the flag if the condition is false
            }
            else
            {
                flag=1; //Change the flag if the condition is True
            }
        }
        else
        {
            flag=0; //Keep the flag if there is no elements in the stack
        }
    }

    if(flag==0) //Use the flag to give the required output
    {
        printf("Valid Expression");
    }
    else
    {
        printf("Invalid Expression");
    }
    return 0;
}