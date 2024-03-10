from nltk.stem import WordNetLemmatizer
import nltk

def lemmatize(pos_tags):
    wnl = WordNetLemmatizer()
    lemmatized_tokens = [wnl.lemmatize() for tup in pos_tags]
    return lemmatized_tokens

txt = input("Enter some text to lemmatize it: ")
tokens = nltk.word_tokenize(txt)
pos_tags = nltk.pos_tag(tokens)

print(lemmatize(pos_tags))
