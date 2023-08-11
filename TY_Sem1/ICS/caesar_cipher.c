#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 128

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

int main() {
	char *plain_text, *ciphered_text;
	
	plain_text = (char*) malloc(MAX * sizeof(char));
	memset(plain_text, 0, MAX);

	printf("Enter the data: ");
	(void)fgets(plain_text, MAX, stdin);

	ciphered_text = caesar_cipher_encrypt(plain_text);
	printf("\nThe Encrypted message is ");
	puts(ciphered_text);
	printf("\nThe Decrypted message is ");
	puts(caesar_cipher_decrypt(ciphered_text));

	return 0;
}
