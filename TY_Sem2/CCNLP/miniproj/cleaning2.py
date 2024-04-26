from booknlp.booknlp import BookNLP

model_params = {
		"pipeline":"entity,quote,supersense,event,coref", 
		"model":"big"
	}

booknlp=BookNLP("en", model_params)

input_file = "testcorpus3.txt"
output_dir = "outputbooknlp/"
book_id = "gnn_ner1"

booknlp.process(input_file, output_dir, book_id)