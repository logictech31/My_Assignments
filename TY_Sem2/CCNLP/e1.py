import nltk

sentence = input("Enter a sentence: ")
tokens = nltk.word_tokenize(sentence)
print("Tokenization: ", tokens)

tags = nltk.pos_tag(tokens)
print("Parts of Speech Tagging: ", tags)

entities = nltk.chunk.ne_chunk(tags)
print("NE Chunk: ", entities)
