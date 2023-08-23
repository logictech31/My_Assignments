#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #define is a preprocessor directive that is used to define macros in a C program
// The program always starts from the main function
#define MAX 128
// It is always good to declare your functions like this
/*
	Functions and their respective libraries:
	fgets -> string.h
	memset -> string.h
	malloc -> stdlib.h
	puts -> string.h
*/
char* caesar_cipher_encrypt(char* plain_text);
char* caesar_cipher_decrypt(char* plain_text);

char* caesar_cipher_encrypt(char* plain_text) {
	char *ciphered_text, *temp;
	int shift_key = 3;

	ciphered_text = (char*) malloc(MAX * sizeof(char));
	memset(ciphered_text, 0, MAX);
	temp = ciphered_text;

	while(*plain_text != '\0') {
		*temp = (*plain_text) + shift_key;
		plain_text++;
		temp++;
	}

	return ciphered_text;
}

char* caesar_cipher_decrypt(char* plain_text) {
	char *ciphered_text, *temp;
	int shift_key = 3;

	ciphered_text = (char*) malloc(MAX * sizeof(char));
	memset(ciphered_text, 0, MAX);
	temp = ciphered_text;

	while(*plain_text != '\0') {
		*temp = (*plain_text) - shift_key;
		plain_text++;
		temp++;
	}

	return ciphered_text;
}
// Program starts here
int main() {
	// two character pointers are declared
	char *plain_text, *ciphered_text;

	/* plain_text gets the address of newly allocated memory block of size MAX
	In simple terms MAX blocks (Check #DEFINE at start) of memory are allocated of sizeof(char)
	Meaning of the syntax below is:
	malloc() name of the function called memory allocate
	malloc(MAX[The number of blocks required] * sizeof(char)[gives the size of character datatype])
	The entire math above gives you the number of bytes to be allocated
	(char*) => the malloc is typecasted here to return a pointer, which is stored in plain_text
	*/
	plain_text = (char*) malloc(MAX * sizeof(char));
	// memset basically assigns a default value (Which in this case is 0) to the MAX number of memory blocks,
	// Note: It is not necessary to always assign to MAX number, you can write it as
	// memset(plain_text, 0, ANY NUMBER) here
	// Basic syntax is memset(variable, value, number of blocks)
	memset(plain_text, 0, MAX);

	printf("Enter the data: ");
	// fgets in this case is used to get MAX number of characters as input
	// gets means File Get String, in which it gets input from a file stream
	// the file stream here is std IN stream
	// which is standard input stream
	(void)fgets(plain_text, MAX, stdin);

	// ciphered_text gets the returned value from caesar_cipher_encrypt
	ciphered_text = caesar_cipher_encrypt(plain_text);
	printf("\nThe Encrypted message is ");
	puts(ciphered_text);
	printf("\nThe Decrypted message is ");
	puts(caesar_cipher_decrypt(ciphered_text));

	return 0;
}
