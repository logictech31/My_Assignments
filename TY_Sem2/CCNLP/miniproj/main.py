from gnn import GNN_NER_Summarize
from qna import question_answer
question = "";
corpus = open('testcorpus2.txt', 'r')
corpus = corpus.read()
summary = ''
summarize_obj = GNN_NER_Summarize(corpus)
while(question != ( "exit" or "quit")):
    question = input("What is your question?\nQ: ");
    question = question.lower();
    if question.__contains__('exit'):
        break
    if question.__contains__('summarize') | question.__contains__('summarise'):
        if summary == '':
            summary = summarize_obj.summarize(5)
        print(summary)
    else:
        question_answer(question=question, corpus=corpus)
