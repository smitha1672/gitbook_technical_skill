
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
# Uploading local branch to origin branch
git push origin foo

# push local branch to remote branch
git push origin local/branch:remote/branch

# Delete a origin branch
git push origin :foo
```

## Pull
```text
# 下載origin 儲存庫上所有分支的變更內容
git pull origin

# Downloading foo branch of origi to local foo branch
git origin fool

# Downloading foo branch of origi to local bar branch
git pull origin foo:bar
```
