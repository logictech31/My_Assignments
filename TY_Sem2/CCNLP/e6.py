import nltk
from nltk.sentiment.vader import SentimentIntensityAnalyzer

# Initialize NLTK's Vader Sentiment Analyzer
nltk.download('vader_lexicon')
sid = SentimentIntensityAnalyzer()

# Sample text for analysis
text = "I'm feeling great today!"

# Sentiment Analysis with NLTK's Vader
sentiment_scores = sid.polarity_scores(text)

# Interpret sentiment scores
if sentiment_scores['compound'] >= 0.05:
    print("Positive sentiment")
elif sentiment_scores['compound'] <= -0.05:
    print("Negative sentiment")
else:
    print("Neutral sentiment")

