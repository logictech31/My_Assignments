# Name: cleaning.py
# Purpose: To Perform tokenization, lemmatization, case folding in this file
# Author: Hrushikesh Pandit
from WordNetLemmatizeFix import WordNetLemmatizeFix
import spacy
from spacy import displacy
import PyPDF2
import regex as re

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
        print(corpus)
        entset = {("zero", "0")}
        for ent in doc.ents:
            temp = {(ent.text, ent.label_)}
            entset = entset.union(temp)
        return entset

obj = cleaning()
entset = obj.NER_with_Spacy()
print()
print(entset)