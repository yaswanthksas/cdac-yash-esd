# what is the difference between step over, step into, continue , stepout in vs code 

In Visual Studio Code (VS Code), when debugging code, the terms **Step Over**, **Step Into**, **Step Out**, and **Continue** are related to how you control the flow of the program during the debugging process.

### 1. **Step Over**
- **Purpose**: Execute the current line of code and move to the next line, without stepping into any functions or methods that the current line might call.
- **When to Use**: You want to execute a function or method but aren't interested in debugging its internal code.
- **Example**: If the current line calls a function, `Step Over` will execute the entire function but keep you in the current context (you won’t enter the function's body).

### 2. **Step Into**
- **Purpose**: Execute the current line of code and, if it includes a function or method call, it will "step into" the function, allowing you to debug its internal execution line by line.
- **When to Use**: You want to dive into the details of a function or method to see what happens inside it.
- **Example**: If the current line calls a function, `Step Into` will take you to the first line of the function.

### 3. **Step Out**
- **Purpose**: Finish executing the rest of the current function or method, then return to the line that called the function.
- **When to Use**: You are inside a function or method and want to skip the rest of it, but return to the calling function to continue debugging.
- **Example**: If you're inside a function and don't need to debug it any further, `Step Out` will run the rest of the function and bring you back to the point where it was called.

### 4. **Continue**
- **Purpose**: Resume execution of the program and run it until the next breakpoint (or until the program finishes if no more breakpoints are set).
- **When to Use**: You’re done with the current inspection and want to move forward until something else stops the program (a breakpoint or the program's end).
- **Example**: If you’ve debugged a few lines and are ready to move ahead, `Continue` will let the program run without stopping until it reaches a point of interest (e.g., a breakpoint).

### Summary:
- **Step Over**: Skip over function/method calls but execute them.
- **Step Into**: Enter the function/method to debug it.
- **Step Out**: Finish the current function/method and go back to the caller.
- **Continue**: Resume execution until the next breakpoint or the end of the program.

These debugging controls allow you to manage how deeply and where you want to inspect the program’s behavior during runtime.


## USE THIS DEBUGGING TECHNIQUE APPROACHES IN VSCODE TO OVERCOME SEGMENTATION FAULTS
