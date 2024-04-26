import dgl
import torch
# Define a simple GNN class
class GNN_NER:
    def __init__(self, in_feats, hidden_feats, out_feats):
        super(GNN_NER, self).__init__()
        self.linear = torch.nn.Linear(in_feats, hidden_feats)

    def forward(self, g, features):
        # Message passing function (simple addition here)
        def message_func(edges):
            return {'msg': edges.src['h']}

        # Reduce function (simple addition here)
        def reduce_func(nodes, messages):
            return {'h': torch.sum(messages['msg'], dim=0)}

        # Update node features with message passing
        g.update_all(message_func, reduce_func)

        # Apply linear transformation to updated features
        out = self.linear(g.ndata['h'])
        return out

# Create a DGL graph (modify as needed for your data)
g = dgl.graph((torch.tensor([0, 1, 2]), torch.tensor([1, 0, 2])))

# Define node features (replace with your actual features)
features = torch.randn(3, 5)  # 3 nodes, 5 feature dimensions

# Create the GNN model
model = GNN_NER(in_feats=5, hidden_feats=10, out_feats=2)  # Input features, hidden features, output features

# Train the model (replace with your training loop)
# ...

# Get the predicted output for each node
summary = ""
print(summary)
