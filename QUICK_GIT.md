# Quick Git Commands

Since you have Git Bash installed, here's how to use it:

## ⚠️ First Time Setup (One-time only)

If you get an email error, configure Git first:
```bash
bash setup_git.sh
```

Or manually:
```bash
git config user.email "brodygundert@gmail.com"
git config user.name "Brodster"
```

## Method 1: Using Git Bash (Recommended)

1. **Open Git Bash** (right-click in this folder → "Git Bash Here" OR search for "Git Bash" in Start menu)

2. **Run these commands:**
```bash
git status              # See what files changed
git add .               # Add all files
git commit -m "Initial KD-tree project setup"    # Save with a message
git push origin main    # Upload to GitHub
```

## Method 2: Run the Script

Or just run the script I created:
```bash
bash commit_and_push.sh
```

## Method 3: Individual Commands

If you want to do it step-by-step:
```bash
# See what changed
git status

# Add all files
git add .

# Commit (save snapshot)
git commit -m "Describe your changes here"

# Push to GitHub
git push origin main
```

---

## Your Files Are Already Saved Locally!

All your files are in: `C:\Users\Brodster\KD_Tree_Project\`

Git just helps you:
- Back up to GitHub (cloud)
- Share with your teammates
- Track changes over time

