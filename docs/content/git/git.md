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

## archive

+ [example](https://tosbourn.com/using-git-to-create-an-archive-of-changed-files/)

```text
git archive -o update.zip HEAD
git diff --name-only HEAD^
git archive -o update.zip HEAD $(git diff --name-only HEAD^)`
```

## diff

+ listed only the files names that changed between two commits

```text
git diff --name-only SHA1 SHA2
git diff --name-only HEAD~10 HEAD~5
```

## Advance skill

+ Get a file from a particular commit

```text
# list commit for a particular file
git rev-list <branch name> -- data.c

# Get file
git cat-file -p e51bdf2:./project_info/hisense/la672c/release_note.txt > test.log
git show e51bdf2:./project_info/hisense/la672c/release_note.txt > test.log
```

## clean

+ clean untracked files and directories

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

## format-patch

[format patch reference](https://mijingo.com/blog/creating-and-applying-patch-files-in-git)

```text
# Create patch files with a branch
$ git format-patch <branch> -o <destpath>

# Specifying a Single Commit
$ git format-patch a_big_feature_branch -1 1ecb5853f53ef0a75a633ffef6c67efdea3560c4 -o patches
  outgoing/0001-a-nice-change-that-i-d-like-to-include-on-production.patch
```

## am

```text
$ git am [-i] [-3] ...
$ git am -i patches/*.patch
$ git am patches/fix...patch
```

## remote

```text
# add a url to remote
git remote add "remote name" url_address

# rename
git remote rename <old name> <new name>

# set new url
git remote set-url <remote name> <newurl>
```

## Merge

+ Combined more commits in a commit

```bash
git branch
git merge --squash topic
git commit
```

+ Merge a branch and no commit

```text
git merge <branch> --no-commit
```

