import nltk
import spacy
from nltk.stem.snowball import SnowballStemmer

def lemmatize(tokens):
    wnl = SnowballStemmer("english")
    lemmatized_tokens = [wnl.stem(tk) for tk in tokens]
    # txt = ' '.join([word for tokens in lemmatized_tokens])
    return lemmatized_tokens


print(lemmatize(nltk.word_tokenize(input("Enter a string to lemmatize it: "))))
