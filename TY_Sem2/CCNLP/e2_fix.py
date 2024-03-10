from WordNetLemmatizeFix import WordNetLemmatizeFix

text = input("Enter a string: ")
wnl = WordNetLemmatizeFix()
print(wnl.lemmatize_return_txt(text))