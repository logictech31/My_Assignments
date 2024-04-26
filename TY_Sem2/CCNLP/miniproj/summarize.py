from transformers import AutoTokenizer, AutoModelForSeq2SeqLM

# Load the pre-trained summarization model and tokenizer
model_name = "sshleifer/distilbart-cnn-12-6"
tokenizer = AutoTokenizer.from_pretrained(model_name)
model = AutoModelForSeq2SeqLM.from_pretrained(model_name)
def summ(corpus):
    # Define the input text and convert it to tokens
    input_ids = tokenizer.encode(corpus, return_tensors="pt")

    # Perform text summarization using the pre-trained model
    outputs = model.generate(input_ids, max_length=len(corpus), num_beams=4, early_stopping=True)
    summary = tokenizer.decode(outputs[0])

    # Print the summary
    print(summary)