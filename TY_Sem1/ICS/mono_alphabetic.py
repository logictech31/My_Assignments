import pdb
ch = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j']
enc_str = ['Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P']

def mono_alphabetic_encrypt(plain_text):
	encoded = ""
	i = 0
	#pdb.set_trace()
	for x in plain_text:
		index = ch.index(x) 
		encoded = encoded + enc_str[index]
		i = i + 1
	return encoded

def mono_alphabetic_decrypt(ciphered):
	decoded = ""
	i = 0
	#pdb.set_trace()
	for x in ciphered:
		index = enc_str.index(x) 
		decoded = decoded + ch[index]
		i = i + 1
	return decoded

plain_text = input("Enter the message: ")
encoded = mono_alphabetic_encrypt(plain_text)
print("Encoded message is ", encoded)
print("Decoded message is ", mono_alphabetic_decrypt(encoded))


