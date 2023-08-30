## Character Array
- In `char` you can able to store only one character. Ex. `char ch = 'a';`.
- But to store many characters we need character array.
- String is 1 dimentional character array. Ex. `|a|b|c|d|e|f|`.

In `int arr[10];` arr will store address of 1st element of that array. And by that base address we can traverse entire array.
Similary for char,
`char ch[10];` to make character array. ch will store address of 1st element of character array. And by that base address we can traverse entire char array.

To take input for character array,
```
char name[15];
cin >> name;
```

**REMEMBER: Whenever we take input then automatically at the end of input compiler automatically adds a character to the (end + 1) position called NULL character `('\0')`.** It's ASCII value is zero and we use it as a terminator. So that we know that where the string ends.
Example: 
input -> 'Taehyung'
```
|T|a|e|h|y|u|n|g|\0| | | | | | |
```
Here, when we print name then it will only shows 'Taehyung' and not remaining 6 (assume total size of array to 15) block's garbage value.

**Note:** `cin` stops execution, whenever you give 'space (_)', 'tab (\t)', 'new line(\n)'
If you give input as "Kim Taehyung" then it will only print "Kim" and not next word "Taehyung". Because before reaching to character 'T' compiler gets Null character '\0'.


## Converstion of character case (Lowercase, Uppercase)
1. By using **`<ctype.h>`**:
    This function takes a character as an argument and returns its uppercase equivalent if it is a lowercase letter `ch = toupper(ch);`
    Same for uppercase to lower `ch = tolower(ch);`

2. By **Bit Manipulation**:
    You can flip the 32nd bit of the character’s ASCII value to change its case. only works for ASCII value.
    ```
    char c = 'a';
    c &= ~' ';
    cout << c << endl; // prints 'A'
    ```

3. By using **ASCII chars**:
    This works because the ASCII values of the characters `'A' to 'Z'` are in the range `65` to `90`, while the ASCII values of the characters `'a' to 'z'` are in the range `97` to `122`. 
    The difference between the ASCII values of an uppercase and a lowercase character is `32`. So, when you subtract `'A'` from an uppercase character, you get a value between `0` and `25`, representing its position in the alphabet. 
    When you add `'a'` to this value, you get the ASCII value of the corresponding lowercase character.
    ```
    ch - 'A' + 'a' // For Uppercase to Lowercase
    ch - 'a' + 'A' // For Lowercase to Uppercase
    ```


## String
String is a class. It stores its data internally in the form of a null-terminated C-string, but normal usage does not allow you to access null terminator.
<a href="https://stackoverflow.com/questions/40716515/do-stdstrings-end-in-0-when-initialized-with-a-string-literal">stackoverflow link -> </a>

```
string myString("Hello, World!");

// Internal Buffer...
// [ H | e | l | l | o | , |   | W | o | r | d | ! | \0 ]
//                                                   ^ Null terminator.
```
In this example, the null terminator was NOT copied from the end of the string literal, but added internally by `std::string`.

- `str.length()` to find length.