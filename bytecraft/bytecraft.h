#ifndef BYTECRAFT_H
#define BYTECRAFT_H


// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ BINARY ENCODING ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━


void str2bin  (const char *input, char *output);  // Converts a string to binary
void bin2str  (const char *binary, char *output); // Decodes a binary string into text (ASCII characters)

// USAGE: str2bin     ("Hello"     , binaryOutput);
//                        |> String      |
//                                       |> String that stores encoded bits

// USAGE: bin2str     (binaryOutput, decodedOutput);
//                       |               |> String that stores decoded text
//                       |                   
//                       |> Binary input (String that stores encoded bits)


// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ HEXA ENCODING ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━


void str2hexa (const char *input, char *output);  // Converts a string to hexadecimal
void hexa2str (const char *hexa, char *output);   // Decodes a hexadecimal string into text (ASCII characters)

// USAGE: str2hexa    ("Hello"     , hexaOutput);
//                        |> String      |
//                                       |> String that stores encoded bits

// USAGE: hexa2str    (hexaOutput  , decodedOutput);
//                       |               |> String that stores decoded text
//                       |
//                       |> Hexadecimal input (String that stores encoded bits)


// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ BASE64 ENCODING ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━


void str2base64 (const char *base,   char *output); // Converts a string to base64
void base64tostr(const char *base64, char *output); // Decodes a base64 string into text (ASCII characters)

// USAGE: str2base64  ("Hello"     , base64Output);
//                        |> String      |
//                                       |> String that stores encoded bits

// USAGE: base64tostr (base64Output, decodedOutput);
//                       |               |> String that stores decoded text
//                       |
//                       |> Base64 input (String that stores encoded bits)

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

#endif
