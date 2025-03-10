#ifndef BYTECRAFT_H
#define BYTECRAFT_H

// BINARY ENCODING
int  detectByteSize (unsigned int num);                           // Détecte la taille en octets d'un entier
void convertBinary  (const void *input, int size, char *output);  // Convertit n'importe quel type (char, int, string) en binaire
void decodeBinary   (const char *binary, char *output);           // Décode une chaîne binaire en texte (caractères ASCII)

// USAGE: convertBinary(&number, sizeof(number), binaryOutput);
// USAGE: decodeBinary(binaryOutput, decodedOutput);

#endif
