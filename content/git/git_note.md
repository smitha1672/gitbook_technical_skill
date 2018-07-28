
## Adding All modication files
```bash
git add -u .
```

## Worktree
```text
# List Worktree
```bash
git worktree list

# Add a Worktree
```bash
git worktree add ../tmptree -b fix_bug

# Removing a Worktree
bash
rm -rf /home/smith/worktree
git worktree prun --dry--run
git worktree purn --verbose
git worktree list
```

## Push
```text
# push local branch to remote branch
git push origin local/branch:remote/branch



