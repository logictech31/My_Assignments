from transformers import AutoTokenizer, AutoModelForQuestionAnswering
from gnn import GNN_NER_Summarize
import spacy

# Load spacy model
nlp = spacy.load('en_core_web_sm')

# Load DistilBERT tokenizer and model
tokenizer = AutoTokenizer.from_pretrained("distilbert/distilbert-base-uncased")
model = AutoModelForQuestionAnswering.from_pretrained("distilbert/distilbert-base-uncased")

def question_answer(question, corpus):
    # Initialize GNN_NER_Summarize object with corpus
    obj = GNN_NER_Summarize(corpus)
    # Get top sentences from summarization
    top_sentences = obj.summarize(5)
    
    # Extract entities from the question using spaCy
    doc = nlp(question)
    key_of_interest = doc.ents[0].text if doc.ents else None
    
    # Find the topmost sentence containing the key entity
    topmost_sentence_for_key = None
    if key_of_interest:
        for sentence in top_sentences:
            if key_of_interest in sentence:
                topmost_sentence_for_key = sentence
                break
    
    # If the key entity is not found or no entities detected, use the first sentence from top_sentences
    if not topmost_sentence_for_key:
        topmost_sentence_for_key = top_sentences[0] if top_sentences else None
    
    if topmost_sentence_for_key:
        # Tokenize question and topmost sentence
        inputs = tokenizer(question, topmost_sentence_for_key, return_tensors="pt")
        # Perform question answering
        outputs = model(**inputs)
        answer_start = outputs.start_logits.argmax().item()
        answer_end = outputs.end_logits.argmax().item()
        answer = tokenizer.convert_tokens_to_string(tokenizer.convert_ids_to_tokens(inputs['input_ids'][0][answer_start:answer_end+1]))
        print("Answer:", answer)
    else:
        print("No suitable context found for answering the question.")