## Character Array
- In `char` you can able to store only one character. Ex. `char ch = 'a';`.
- But to store many characters we need character array.
- String is 1 dimentional character array. Ex. `|a|b|c|d|e|f|`.

In `int arr[10];` 'arr' will store address of 1st element of that array. And by that base address we can traverse entire array.
Similary for char,
`char ch[10];` to make character array. 'ch' will store address of 1st element of character array. And by that base address we can traverse entire char array.

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


## String VS Char Arrays
- As String is a class so is provided with various built-in function substring(), charAt() etc. but for Char array no built in functions.


**ERROR example 1:**
```
for(int i = 0; i < str.length(); i++) {
    if(str[i] == " ") {
        
    }
}
```
Here, `str[i] == " "` gives you an error because you are comparing a char (str[i]) with a string literal (" "). In C++, a string literal is enclosed in double quotes (" ") and represents an array of characters, while a character is enclosed in single quotes (' ') and represents a single character. therefore use `' '` instead of `" "`.


## cin VS getline Cin

If you input a string by cin,
Ex. My name is xyz then it will only take My and not other words in that sentences.
To take all sentence up to newline use `getline(cin, str)`;

```
  std::string s;
  int i;
  std::cin >> s; // Read a single word from std::cin
  std::cin >> i; // Read a single number from std::cin
  std::getline(std::cin, s); // Read an entire line (up to \n) from std::cin
```

## cin.getline(str, len) VS getline(cin, str)
- `cin.getline(str, len)` is a member function of the istream class, which cin is an instance of. It reads characters from the input stream and stores them in the character array pointed to by str, until either `(len - 1)` characters have been read or a newline character `('\n')` is encountered. The newline character is extracted from the input stream but not stored in the resulting string. The resulting string is always null-terminated.

`getline(cin, str)` is a non-member function that reads characters from the input stream (cin) and stores them in a std::string object (str), until a delimiter character is encountered. The delimiter character is extracted from the input stream but not stored in the resulting string. By default, the delimiter character is a newline character ('\n'), but you can specify a different delimiter by passing it as the third argument to the getline function1. For example, to read a line of text until a comma (',') is encountered, you can use getline(cin, str, ',').

- In general, you should prefer to use `getline(cin, str)` over `cin.getline(str, len)`when reading lines of text from the standard input stream into a `std::string` object, as it provides better memory safety and ease of use.


### Reverse Words in a sentence
```
for(int i = 0; i < str.length(); i++) { 
        if(str[i] == ' ' || str[i] == '\0') { 
            temp = reverseString(temp);
            ans += temp + " ";
            temp = "";
            continue;
        }
        temp += str[i];
    }
```

Here, above code might work and give you correct output also but this code is not good according to cpp standards.
When i is equal to str.length(), str[i] will access the character one position past the end of the string, which is a null character (\0). This will trigger the condition str[i] == '\0', causing the last word to be reversed and attached to the final output.
However, it’s important to note that accessing a character past the end of a std::string object using the [] operator is undefined behavior according to the C++ standard. While it might work as expected on some implementations, it could also cause unexpected behavior or even crash your program on others.

A safer way to reverse and attach the last word of the sentence would be to add an additional check after the for loop.