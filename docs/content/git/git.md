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

# [HTTP authentication](https://stackoverflow.com/questions/53914241/bash-script-adding-git-credentials-from-bash-script)

```text
git clone http://USERNAME:PASSWORD@some_git_server.com/project.git

# bash or shell script example (delete a branch)
git push http://USERNAME:PASSWORD@some_git_server.com/project.git :dbg-system-block-0c47903
```

# ls-tree

+ list all files for a specific branch

```text
git ls-tree -r master --name-only

-r: option will let it recurse into subdirectories and print each file currently under version
control.
```

+ list of all files that ever existed

```text
git log --pretty=format: --name-only --diff-filter=A  | sort -u
```

## archive

+ Created an archive of the entire repository

```text
git archive -o update.zip HEAD
```

+ archive only changes made between two commits

```text
git archive --output=<file> HEAD $(git diff --name-only commit1SHA commit2SHA)
# <file> can be demo.zip
``

+ subdirectory

```text
git archive -o ../subarchive.zip HEAD:subdir

git archive --format=tar HEAD:subdir | tar t
git archive --format=tar HEAD subdir | tar t
```

+ I don't know when these commands can be used

```text
git archive --output=files.tar HEAD $(git diff-tree -r --no-commit-id --name-only
--diff-filter=ACMRT HEAD)

git archive --format=zip --output=files.zip HEAD $(git diff-tree -r --no-commit-id --name-only
--diff-filter=ACMRT HEAD)
```

# diff-tree

+ list all changed

```text
git diff-tree -r --no-commit-id --name-only --diff-filter=ACMRT HEAD
or
git diff-tree -r --no-commit-id --name-only --diff-filter=ACMRT commit1SHA commit2SHA
or
git diff-tree -r --no-commit-id --name-only --diff-filter=ACMRT commit1SHA..commit2SHA

A = Added
C = Copied
M = Modified
R = Renamed
T = Changed
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

+ format-patch for a single file

```text
git format-patch -1 origin/master test/test_module.c
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

# Trouble Shoot

+ [error: RPC failed; HTTP 400 curl 22 The requested URL returned error: 400 Bad Request](https://stackoverflow.com/questions/52142214/git-push-heroku-master-fails-by-http-400-curl-22-the-requested-url-returned-err)

```text
fixed:
git config http.postBuffer 524288000
```

