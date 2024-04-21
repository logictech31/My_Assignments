from nltk.stem import WordNetLemmatizer
import nltk

class WordNetLemmatizeFix:
    def lemmatize(self, text):
        pos_tokens = nltk.word_tokenize(text)
        pos_tokens = nltk.pos_tag(pos_tokens)
        wnl_obj = WordNetLemmatizer()
        lemmatized_tokens = []
        punctuations = ['.', ',','--', '!', '?', ';', ':', "'", '"', ' " ', '(', ')', '[', ']', '{', '}', '-', '—', '–', '...', '/', '\\', '&', '*', '%', '$', '#', '@', '`', '``', '....', '+', '-', '=', '<', '>', '|', '~']
        for word, tag in pos_tokens:
            if word not in punctuations:
                wntag = tag[0].lower()
                wntag = wntag if wntag in ['a', 'r', 'n', 'v'] else None
                if not wntag:
                    lemma = word
                else:
                    lemma = wnl_obj.lemmatize(word, wntag)
                lemmatized_tokens.append(lemma)
        return lemmatized_tokens
    
    def lemmatize_return_txt(self, text):
        result = self.lemmatize(text)
        result = ' '.join(token for token in result)
        return result
