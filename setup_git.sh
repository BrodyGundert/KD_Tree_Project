#!/bin/bash
# Setup Git configuration for this project

echo "Setting up Git configuration..."

# Set your email and name
git config user.email "brodygundert@gmail.com"
git config user.name "Brodster"

echo ""
echo "Configuration complete!"
echo ""
echo "Your Git config:"
git config --list | grep user

echo ""
echo "Now you can run:"
echo "  git add ."
echo "  git commit -m 'Initial KD-tree project setup'"
echo "  git push origin main"

