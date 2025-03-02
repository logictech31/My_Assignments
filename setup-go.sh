wget https://go.dev/dl/go1.24.0.linux-amd64.tar.gz
mv go1.24.0.linux-amd64.tar.gz ~/
cd ~/

# Remove old Go installation if it exists
rm -rf $HOME/go

# Extract the new Go version
tar -xvf go1.24.0.linux-amd64.tar.gz

# Create GOPATH directory
mkdir -p $HOME/gomods

# Set environment variables correctly
echo 'export GOPATH=$HOME/gomods' | tee -a ~/.bashrc
echo 'export GOROOT=$HOME/go' | tee -a ~/.bashrc
echo 'export GOBIN=$GOROOT/bin' | tee -a ~/.bashrc
echo 'export PATH=$PATH:$GOBIN' | tee -a ~/.bashrc

# Apply changes
source ~/.bashrc
rm -f ~/go1.24.0.linux-amd64.tar.gz
