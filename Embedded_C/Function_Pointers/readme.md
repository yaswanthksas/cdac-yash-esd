# Basics 

## Function Pointer Using Structure Typedef (.) operator
Here's a basic explanation and example of a function pointer typedef in C:

🔧 What is a Function Pointer?
A function pointer is a variable that can hold the address of a function, and can be used to call that function indirectly.

✅ Basic Syntax of Function Pointer Typedef
c
Copy
Edit
typedef return_type (*alias_name)(argument_types);
📘 Simple Example
✅ Goal: Pointer to a function that takes int and returns void
c
Copy
Edit
typedef void (*func_ptr_t)(int);
This means:

func_ptr_t is now a type name

It points to a function like: void myFunc(int x)

🔨 Example Usage
c
Copy
Edit
#include <stdio.h>

void greet(int times) {
    for (int i = 0; i < times; i++) {
        printf("Hello\n");
    }
}

// Typedef
typedef void (*func_ptr_t)(int);

int main() {
    func_ptr_t fptr = greet;   // Assign function to pointer
    fptr(3);                   // Call function via pointer
    return 0;
}
🔁 Other Examples
1. Pointer to a function that returns int and takes two ints:
c
Copy
Edit
typedef int (*math_func_t)(int, int);

int add(int a, int b) { return a + b; }

math_func_t f = add;
int result = f(2, 3);  // result = 5
2. No arguments, returns void:
c
Copy
Edit
typedef void (*void_func_t)(void);
🧠 Summary
Use case	Typedef syntax
No args, void return	typedef void (*func_t)(void);
Takes int, returns int	typedef int (*math_t)(int);
Takes 2 floats, returns float	typedef float (*calc_t)(float, float);

Let me know if you'd like a real-world embedded example (e.g., ISR vector table or callback handler).











Tools


