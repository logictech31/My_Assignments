import nltk
from nltk.stem import WordNetLemmatizer
from nltk.tokenize import word_tokenize

def lemmatize_text(text):
    lemmatizer = WordNetLemmatizer()
    tokens = word_tokenize(text)
    lemmatized_tokens = [lemmatizer.lemmatize(token) for token in tokens]
    lemmatized_text = ' '.join(lemmatized_tokens)
    return lemmatized_text

input_text = "The cats are chasing mice"
output_text = lemmatize_text(input_text)

print(f"Input Text: {input_text}")
print(f"Lemmatized Text: {output_text}")

import nltk
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize

nltk.download('stopwords')
nltk.download('punkt')

def remove_stopwords(text):
    # Tokenize the text
    words = word_tokenize(text)
    
    # Get the English stopwords from nltk
    stop_words = set(stopwords.words('english'))
    
    # Remove stopwords from the tokenized words
    filtered_words = [word for word in words if word.lower() not in stop_words]
    
    # Join the filtered words back into a sentence
    filtered_text = ' '.join(filtered_words)
    
    return filtered_text

# Example usage
text = "This is an example sentence with some stopwords."
filtered_text = remove_stopwords(text)

print("Original Text:", text)
print("Text without Stopwords:", filtered_text)
