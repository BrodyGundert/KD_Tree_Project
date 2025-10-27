#!/bin/bash
# Script to commit and push your KD-tree project

echo "=== Git Status ==="
git status

echo ""
echo "=== Adding all files ==="
git add .

echo ""
echo "=== Committing changes ==="
git commit -m "Initial project setup with KD-tree framework"

echo ""
echo "=== Pushing to GitHub ==="
git push origin main

echo ""
echo "=== Done! ==="
echo "Your project is now saved to GitHub!"

