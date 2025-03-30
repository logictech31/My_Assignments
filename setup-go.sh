#!/bin/bash

# Download Go
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
if [[ "$SHELL" == *bash* || "$SHELL" == *zsh* ]]; then
  echo 'export GOPATH=$HOME/gomods' | tee -a ~/.bashrc ~/.zshrc
  echo 'export GOROOT=$HOME/go' | tee -a ~/.bashrc ~/.zshrc
  echo 'export GOBIN=$GOROOT/bin' | tee -a ~/.bashrc ~/.zshrc
  echo 'export PATH=$PATH:$GOBIN' | tee -a ~/.bashrc ~/.zshrc

  # Apply changes
  if [[ -f ~/.bashrc ]]; then
    source ~/.bashrc
  fi
  if [[ -f ~/.zshrc ]]; then
    source ~/.zshrc
  fi
elif [[ "$SHELL" == *fish* ]]; then
  echo 'set -Ux GOPATH $HOME/gomods' | tee -a ~/.config/fish/config.fish
  echo 'set -Ux GOROOT $HOME/go' | tee -a ~/.config/fish/config.fish
  echo 'set -Ux GOBIN $GOROOT/bin' | tee -a ~/.config/fish/config.fish
  echo 'fish_add_path $GOBIN' | tee -a ~/.config/fish/config.fish
  # Apply changes
  source ~/.config/fish/config.fish
fi

# Clean up the downloaded archive
rm -f ~/go1.24.0.linux-amd64.tar.gz

# Verify installation
go version
