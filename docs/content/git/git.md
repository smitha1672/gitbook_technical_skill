
## add
```bash
# add all modification files.
git add -u .

# add untrack files
git add -f file.o
```

## worktree
```text
# List Worktree
git worktree list

# Add a Worktree
git worktree add ../tmptree -b fix_bug

# Removing a Worktree
rm -rf /home/smith/worktree
git worktree prune --dry-run
git worktree prune --verbose
git worktree list
```

## push
```text
# Uploading local branch to origin branch
git push origin local/foo

# push local branch to remote branch
git push origin local/branch:remote/branch

# Delete a origin branch
git push origin :foo
```

## pull

```text
# 下載origin 儲存庫上所有分支的變更內容
git pull origin

# Downloading foo branch of origin to local foo branch
git origin remote/foo

# Downloading foo branch of origin to local bar branch
git pull origin remote/foo:local/bar
```

## remote

```text
# add a url to remote
git remote add "remote name" url_address
```

## 將多個提交合而為一之後在合併

```bash
git branch
git merge --squash topic
git commit
```
