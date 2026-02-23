// Question1/Student.c
// ------------------------------------------------------------
// CS Lab - Valid Parentheses (STACK PRACTICE)
//
// Task:
// Implement `isValid(const char *s)`.
// Given a string s containing only: () {} []
// return true if it is a valid parentheses string, else false.
//
// Valid rules:
// 1) Open brackets must be closed by the same type of brackets.
// 2) Open brackets must be closed in the correct order.
// 3) Every close bracket has a corresponding open bracket.
//
// Examples:
//   s = "()"        -> true
//   s = "()[]{}"    -> true
//   s = "(]"        -> false
//   s = "([)]"      -> false
//   s = "{[]}"      -> true
//   s = ""          -> true   (empty string is valid)
//
// How to run tests (from the folder containing the Makefile):
//   make run1
// ------------------------------------------------------------

#include "Student.h"
#include <stdbool.h>
#include <stddef.h>  // size_t
#include <string.h>  // strlen
#include <stdlib.h>

struct Node
{
    char val;
    struct Node* next;
};

struct Node* push(struct Node* head, char val);
char pop(struct Node* head, struct Node** head_ptr);

bool isValid(const char *s) {
    // TODO: Implement using a stack.
    //
    // Recommended approach:
    // - Use a char array as a stack to store opening brackets.
    // - Scan the string from left to right:
    //   - If you see an opening bracket, push it.
    //   - If you see a closing bracket:
    //       * stack must not be empty
    //       * top of stack must match the closing bracket type
    //       * then pop
    // - At the end, stack must be empty.
    //
    // Helpful matching pairs:
    //   ')' matches '('
    //   ']' matches '['
    //   '}' matches '{'
    //
    // Corner cases:
    // - s == NULL -> return false
    // - odd length strings can’t be valid 
    //
    // Note:
    // - Input contains only bracket characters, per the prompt.

    if (strlen(s) % 2 != 0)
    {
        return false;
    }

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->val = *s;
    head->next = NULL;

    if (head->val == '}' || head->val == ')' || head->val == ']')
    {
        return false;
    }

    for (int i = 1; i < (int)strlen(s); i++)
    {
        if (*(s+i) == '{' || *(s+i) == '(' || *(s+i) == '[')
        {
            head = push(head, *(s+i));
        }
        else
        {
            char c = pop(head, &head);
            if (!((*(s+i) == '}' && c == '{') || (*(s+i) == ']' && c == '[') || (*(s+i) == ')' && c == '(')))
            {
                return false;
            }
        }
    }
    return true;
}


struct Node* push(struct Node* head, char val)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->val = val;
    new_node->next = head;
    return new_node;
}

char pop(struct Node* head, struct Node** head_ptr)
{
    if (head == NULL)
    {
        return 0;
    }
    char temp_val = head->val;
    struct Node* temp_ptr = head->next;
    free(head);
    *head_ptr = temp_ptr;
    return temp_val;
}