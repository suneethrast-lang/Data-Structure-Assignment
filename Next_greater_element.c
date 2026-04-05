/*
 * FILE: Next_greater_element.c
 * PURPOSE: Find the next greater element for each array element
 * DESCRIPTION: This program implements an efficient algorithm to find the
 *              next greater element for each element in an array using a stack.
 *              For each element, the next greater element is the first element
 *              to its right that is larger than it. If no such element exists,
 *              the result is -1.
 * ALGORITHM: Stack-based approach with O(n) time complexity
 * AUTHOR: Data Structure Assignment
 * DATE: 2024
 */

#include<stdio.h>
#include<stdlib.h>
#define Max 101          // Maximum size of arrays
int top=-1;              // Stack pointer for index stack
int stack[Max];          // Stack to store array elements

/*
 * FUNCTION: push
 * PURPOSE: Push a value onto the stack
 * PARAMETERS: value - the integer value to push
 * RETURN: void
 * DESCRIPTION: Adds the given value to the top of the stack.
 *              Checks for stack overflow condition.
 */
void push(int value)
{
    if(top==Max-1)       // Check for stack overflow
    {
        return;
    }
    else
    {
        top++;            // Increment top pointer
        stack[top]=value; // Push value onto stack
    }
}

/*
 * FUNCTION: pop
 * PURPOSE: Remove and return the top value from the stack
 * PARAMETERS: None
 * RETURN: int - the value at top of stack, or -2 if stack is empty
 * DESCRIPTION: If stack is empty, returns -2 (sentinel value).
 *              Otherwise retrieves top element, decrements pointer, and returns value.
 */
int pop()
{
    if(top==-1)          // Check if stack is empty
    {
        return -2;       // Return sentinel value
    }
    else
    {
        int value=stack[top];  // Retrieve top value
        top--;                 // Decrement top pointer
        return value;          // Return the value
    }
}

/*
 * FUNCTION: nextGreater
 * PURPOSE: Find the next greater element for each array element
 * PARAMETERS: array[] - input array of integers
 *             n - number of elements in the array
 * RETURN: void (prints results)
 * DESCRIPTION: Uses a stack-based approach to efficiently find the next
 *              greater element for each element in O(n) time.
 *              - Maintains a stack of indices
 *              - For each element, pops indices whose values are smaller
 *              - Assigns the current element as their next greater element
 *              - Elements remaining in stack have no greater element (-1)
 */
void nextGreater(int array[], int n)
{
    int result[Max];         // Array to store next greater element for each index
    int indexStack[Max];     // Stack to maintain indices
    int top2=-1;             // Top pointer for index stack
    
    // Traverse array from left to right
    for (int i=0;i<n;i++)
    {
        // Pop all indices whose values are smaller than current element
        while (top2!=-1 && array[indexStack[top2]]<array[i])
        {
            result[indexStack[top2]]=array[i];  // Store answer at correct index
            top2--;                              // Remove from stack
        }
        indexStack[++top2]=i;   // Push current index onto stack
    }
    
    // Remaining elements in stack have no greater element on the right
    while (top2!=-1)
    {
        result[indexStack[top2]]=-1;  // Set result to -1 (no greater element)
        top2--;
    }
    
    // Print results in original array order
    for (int i=0;i<n;i++)
    {
        printf("%d->%d\n",array[i],result[i]);
    }
}

/*
 * FUNCTION: main
 * PURPOSE: Main driver function for next greater element program
 * ALGORITHM:
 *   1. Get array size from user
 *   2. Read array elements
 *   3. Call nextGreater function to find and display results
 * OUTPUT: Prints each element and its next greater element (or -1 if none)
 */
int main()
{
    int array[101];          // Array to store input integers
    int len;                 // Number of elements in array
    
    // Get array size
    printf("Enter the no.of values in the array::");
    scanf("%d",&len);
    
    // Read array elements
    for(int i=0;i<len;i++)
    {
        printf("Enter the value for %dith value::",i);
        scanf("%d",&array[i]);
    }

    // Find and display next greater elements
    nextGreater(array,len);
    return 0;
}