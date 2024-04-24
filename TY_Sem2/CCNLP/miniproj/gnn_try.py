import torch
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim

class TextSummarizationGNN(nn.Module):
    def __init__(self, input_dim, hidden_dim, num_layers):
        super(TextSummarizationGNN, self).__init__()
        self.gcn_layers = nn.ModuleList([GraphConvolution(input_dim, hidden_dim) for _ in range(num_layers)])
        self.linear = nn.Linear(hidden_dim, 1)
    
    def forward(self, x, adj):
        for layer in self.gcn_layers:
            x = F.relu(layer(x, adj))
        scores = self.linear(x).squeeze(-1)
        return scores

class GraphConvolution(nn.Module):
    def __init__(self, input_dim, output_dim):
        super(GraphConvolution, self).__init__()
        self.weight = nn.Parameter(torch.FloatTensor(input_dim, output_dim))
        self.bias = nn.Parameter(torch.FloatTensor(output_dim))
        self.reset_parameters()
    
    def reset_parameters(self):
        torch.nn.init.xavier_uniform_(self.weight)
        if self.bias is not None:
            torch.nn.init.zeros_(self.bias)
    
    def forward(self, x, adj):
        support = torch.matmul(x, self.weight)
        output = torch.matmul(adj, support) + self.bias.unsqueeze(0)
        return output

# Example usage
# Assume you have text data in `texts`
texts = [
    "This is the first sentence.",
    "This is the second sentence, it contains more information.",
    "And this is the third sentence, providing further details."
]

# Preprocess text data (e.g., tokenize, extract features)
# For simplicity, let's assume each sentence is represented by a vector of fixed size (e.g., using word embeddings)

# Construct adjacency matrix based on sentence similarities (e.g., using cosine similarity)
# Here, we use a simple example where adjacency matrix is based on sentence positions
adjacency_matrix = torch.eye(len(texts))
# Convert text data to PyTorch tensor
texts_tensor = torch.randn(len(texts), input_dim)  # Placeholder for sentence embeddings
adjacency_matrix_tensor = adjacency_matrix.unsqueeze(0)  # Add batch dimension

# Initialize and train the model
input_dim = 300  # Dimensionality of sentence embeddings
hidden_dim = 128
num_layers = 2
model = TextSummarizationGNN(input_dim, hidden_dim, num_layers)
optimizer = optim.Adam(model.parameters(), lr=0.01)
criterion = nn.BCEWithLogitsLoss()  # Binary cross-entropy loss

# Assuming ground truth for summary sentences
summary_ground_truth = torch.tensor([1, 0, 1], dtype=torch.float32)

# Training loop
for epoch in range(10):
    optimizer.zero_grad()
    scores = model(texts_tensor, adjacency_matrix_tensor)
    loss = criterion(scores, summary_ground_truth)
    loss.backward()
    optimizer.step()
    print("Epoch {}: Loss {:.4f}".format(epoch+1, loss.item()))

# After training, you can use the model to predict summary sentences
# For example, select sentences with highest scores
predicted_summary = torch.sigmoid(scores) > 0.5
print("Predicted summary:", predicted_summary.tolist())

