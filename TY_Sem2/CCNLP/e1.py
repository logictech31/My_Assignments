import nltk

sentence = input("Enter a sentence: ")
tokens = nltk.word_tokenize(sentence)
print(tokens)

tags = nltk.pos_tag(tokens)
print(tags)

entities = nltk.chunk.ne_chunk(tags)
print(entities)
