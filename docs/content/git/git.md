#
## Branching Strategies

+ Mainline Branch Development
+ Branch-Per-Feature Deployment
+ State Branching
+ Scheduled Deployment (GitFlow)

<img src="gitflow_f38.png"
width="90%"
height="90%"
alt=""
align=center />

<img src="gitflow_f39.png"
width="90%"
height="90%"
alt=""
align=center />

<img src="gitflow_f310.png"
width="90%"
height="90%"
alt=""
align=center />

<img src="gitflow_f311.png"
width="90%"
height="90%"
alt=""
align=center />

<img src="gitflow_f312.png"
width="90%"
height="90%"
alt=""
align=center />

## clean untracked files and directories

```bash
$ git clean -f or -d or -fd
```

## tag

```text
You just need to push an 'empty' reference to the remote tag name:
git push origin :tagname

Or, more expressively, use the --delete option (or -d if your git version is older than 1.8.0):
git push --delete origin tagname

If you also need to delete the local tag, use:
git tag --delete tagname
```

## Ignoring Files

```bash
# set gitignore path
$ git config --global core.excludesfile ~/.gitignore
```

## stash

```bash
$ git stash #save current changed work directory
$ git stash save "message" # save current changed work directory + message
$ git list # showed all stash list
$ git apply stash{x} # applied some stash point
```

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
## Branches

+ Listing Branches

```text
Listing local branches
$ git branch --list

List all branches
$ git branch --all

List remote branches
$ git branch --remotes
```

+ Creating New Branches

```text
Switched to branch 'master'
$ git checkout master

create a new branch
$ git branch 1-process_notes

check out the new branch
$ git checkout 1-process_notes

Creating a new development branch from the master branch
$ git checkout -b 1-process_notes master

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

