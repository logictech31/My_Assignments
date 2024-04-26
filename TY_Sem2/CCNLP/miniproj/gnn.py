import dgl
import torch.nn as nn
import torch
import nltk
import networkx as nx
import matplotlib.pyplot as plt
import spacy
from WordNetLemmatizeFix import WordNetLemmatizeFix
from nltk.corpus import inaugural
from nltk.sentiment import SentimentIntensityAnalyzer
from nltk.tokenize.treebank import TreebankWordDetokenizer
import math
nlp = spacy.load('en_core_web_sm')
class GNN_NER_Summarize:
    def __init__(self, corpus):
        self.nlp = spacy.load('en_core_web_sm')
        self.corpus = corpus.lower()
        self.corpus = self.corpus.replace('"', '')
        self.NER_vec = {}
        self.top_sentences = []

    def getSentimentScore(self):
        sid = SentimentIntensityAnalyzer()
        sentiment_scores = []
        for sentence in self.sent_token:
            scores = sid.polarity_scores(sentence)
            sentiment_scores.append(scores['compound'])  # Compound score ranges from -1 to 1
        return sentiment_scores

    def assignWeightsAndSents(self):
        graph = nx.Graph()
        sentiment_scores = self.getSentimentScore()  # Get sentiment scores for each sentence
        base = len(self.sent_token)
        for i, sent in enumerate(self.sent_token):
            for j, entity in enumerate(self.NER_vec):
                count = sent.count(entity)
                if count > 0:
                    weight = math.sqrt(count * abs(sentiment_scores[i]) + 1)  
                    graph.add_node(entity)  # Add the entity as a node
                    graph.add_node(i)  # Add the sentence index as a node
                    graph.add_edge(entity, i, weight=weight)  # Add an edge with the adjusted weight
        return graph

    def preprocess(self):
        self.sent_token = nltk.sent_tokenize(self.corpus)
        len(self.sent_token)
        doc = nlp(self.corpus)
        constant = False
        while constant == False:
            txt = ''
            for e in doc.ents:
                txt = txt + e.text + ' '
            doc = nlp(txt)
            history_len = len(self.NER_vec)
            self.NER_vec = {}
            for e in doc.ents:
                self.NER_vec[e.text] = e.label_
            if history_len == len(self.NER_vec):
                constant = True
        self.weights = self.assignWeightsAndSents()
        print(len(self.NER_vec), len(self.weights))

    def get_context(self, top_n=5):
        self.preprocess()
        sentence_scores = {}
        self.assignWeightsAndSents()

        for node in self.weights.nodes:
            if isinstance(node, int):
                sentence_score = 0
                for neighbor, data in self.weights[node].items():
                    sentence_score += data['weight']
                sentence_scores[node] = sentence_score

        self.top_sentences = sorted(sentence_scores.items(), key=lambda x: x[1], reverse=True)[:top_n]
        summary = []
        for sentence_index, _ in self.top_sentences:
            summary.append(self.sent_token[sentence_index])
        
        return [self.sent_token[sentence_index] for sentence_index, _ in self.top_sentences]


    def summarize(self, top_n=5):
        self.preprocess()
        sentence_scores = {}
        self.assignWeightsAndSents()

        for node in self.weights.nodes:
            if isinstance(node, int):
                sentence_score = 0
                for neighbor, data in self.weights[node].items():
                    sentence_score += data['weight']
                sentence_scores[node] = sentence_score

        self.top_sentences = sorted(sentence_scores.items(), key=lambda x: x[1], reverse=True)[:top_n]
        summary = []
        for sentence_index, _ in self.top_sentences:
            summary.append(self.sent_token[sentence_index])
        
        return ' '.join(summary)

# corpus = open('testcorpus2.txt', 'r')
# corpus = corpus.read()
# obj = GNN_NER_Summarize(corpus=corpus)
# print(obj.summarize(5))
