# Name: cleaning.py
# Purpose: To Perform tokenization, lemmatization, case folding in this file
# Author: Hrushikesh Pandit
from WordNetLemmatizeFix import WordNetLemmatizeFix
import spacy
from spacy import displacy
import PyPDF2

pdfFileObj = open('testcorpus.pdf', 'rb')
pdfReader = PyPDF2.PdfReader(pdfFileObj)
class cleaning:
    def create_corpus(self):
        total_pages = len(pdfReader.pages)
        print(total_pages)
        corpusholder = ''
        for i in range(1, total_pages-2):
            corpusholder = corpusholder + (pdfReader.pages[i].extract_text().lower())
        return corpusholder

    def lemmatize_tokenize(self, corpus):
        lemm = WordNetLemmatizeFix()
        res = lemm.lemmatize_return_txt(text=corpus)
        return res

    def NER_with_Spacy(self):
        corpus = ''
        nlp = spacy.load("en_core_web_sm")
        corpus = self.create_corpus()
        corpus = self.lemmatize_tokenize(corpus)
        doc = nlp(corpus)
        entlist = []
        for ent in doc.ents:
            entlist.append([(ent.text, ent.label_)])
        return entlist

obj = cleaning()
entlist = obj.NER_with_Spacy()
print(entlist)