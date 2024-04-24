import spacy
from spacy import displacy

nlp = spacy.load('en_core_web_sm')

corpus = "Harry Potter was swinging his wand."

doc = nlp(corpus)

entities = [(e.label_, e.text) for e in doc.ents]
print(entities)

displacy.serve(doc, style="ent", auto_select_port=True)
