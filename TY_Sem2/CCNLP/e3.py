import gensim
import pprint
from gensim import corpora 
from gensim.utils import simple_preprocess

doc_list = []
doc_list.append(input("Enter String 1: "))
doc_list.append(input("Enter String 2: "))
doc_tokenized = [simple_preprocess(doc) for doc in doc_list]
dict = corpora.Dictionary()
BoW_corp = [dict.doc2bow(doc, allow_update=True) for doc in doc_tokenized]
print(BoW_corp)
