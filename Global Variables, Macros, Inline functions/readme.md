# Macros

- `#include <iostream>` it's called preprocessor directive. It means before compilation of our program, file which you've included will be copied to your code. Code which you've written related to it was reffered from it.
- Ex. `cout` is defined in file called `iostream`
- **Directives:** In C++, a directive is a one-line command that instructs the compiler to preprocess information before compilation. Directives are also known as preprocessors.
- Directives begin with the # (hash) symbol, followed by a pre-processor instruction. For example, #include, #define, #ifdef, #elif, and #error.

## Define a Macro
- Macro is a piece of code in a program that is replaced by value of macro.
- Macro is defined by `#define` directive.
- Example: `#define PI 3.14`. 
- This means that during preprocessing, the preprocessor will replace all occurrences of `PI` with `3.14`. This can be particularly useful for defining constants that are used multiple times throughout your code.
- Example: `#define AREA(l, b) (l * b)` Whenever the compiler finds `AREA(l, b)` in the program it replaces it with the macros definition i.e., `(l*b)`.