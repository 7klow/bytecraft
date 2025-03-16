# `📖` <bytecraft.h>

Welcome to **ByteCraft** 🛠️, a C library designed for encoding and decoding various formats: binary, hexadecimal, base64, and more! 🎉  

## `📦` Installation  

Simply add `bytecraft.h` and `bytecraft.c` to your project, then include the header in your code:  

```c
  #include "bytecraft.h"
```  

## `🎯` Features

  - `🔢` Binary Encoding & Decoding
  - `🧮` Hexadecimal Conversion
  - `🔡` Base64 Support
  - `📜` More encodings coming soon!  


## `🚀` Usage  

### `🔢` Binary Conversion  
```c
  void str2bin  (const char *input, char *output);  // Converts a string to binary
  void bin2str  (const char *binary, char *output); // Decodes a binary string into text (ASCII characters)
```

### `🧮` Hexadecimal Conversion  
```c
  void str2hexa (const char *input, char *output);  // Converts a string to hexadecimal
  void hexa2str (const char *hexa , char *output);  // Decodes a hexadecimal string into text (ASCII characters)
```

### `🔡` Base64 Encoding  
```c
  void str2base64 (const char *input,  char *output); // Converts a string to base64
  void base64tostr(const char *base64, char *output); // Decodes a base64 string into text (ASCII characters)
```

## `🤝` Contributing  
Contributions are welcome! Open an issue or submit a pull request to add new features. `🛠️ ` 

## `📝` License  
```This project is licensed under the GNU License 📜.```
