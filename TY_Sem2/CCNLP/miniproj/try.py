import PyPDF2

pdfFileObj = open('libX11.pdf', 'rb')
pdfReader = PyPDF2.PdfReader(pdfFileObj)

print(len(pdfReader.pages))
pageObj = pdfReader.pages[3]

print(pageObj.extract_text())

pdfFileObj.close()
