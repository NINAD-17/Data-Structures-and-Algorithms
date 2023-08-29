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