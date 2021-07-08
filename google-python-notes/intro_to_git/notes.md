#

```=
diff file1 file2
```

```=
diff -u file1 file2
```
* includes some context when showing the output

```=
diff -u file1 file2 > change.diff
```
* create a diff/patch file

# 

```=
patch file < change.diff
```
* apply changes from a diff file 

#

```=
git config --global user.email "<email>"
git config --global user.name "<name>"
```
* setting up email and usr name in git
* for a person have multiple repos,`--global` sets the username and email for all repos. 
* it is posssible to set different email and username for different projects


#

```=
git init
git clone <address>
```
* setting up/copy a new repo

#

```=
ls -l
```
* the working tree is a sandbox for us to try new features.

```=
git status
```
* show the status of the working tree

#
* working tree : sandbox for play around
* staging area : records what changes needs to go to your next commit
* git repo : database to record the changes

#

```=
git config -l
```
* list all configurations

#

```=
git diff file1
```
* check the differene from working tree to repository

```=
git diff
```
* check the unstaged differences of all files from working tree to HEAD
* compare "working tree" <-> HEAD

```=
git diff --staged
```
* check the staged differences to the HEAD
* compare "staging area" <-> HEAD


#

```=
git commit -a 
```
* commit all **tracked** files
* this does not add new files to stages

#

```=
HEAD
```
* this is a pointer points to the current snapshot
* your working tree is based on this snapshot

#

```=
git log -p
```
* `p` stands for patch
* show the patch info for each commit

```=
git log --stat
```
* show a summary of change for each commit

```=
git log -2
```
* show the last 2 commits

#

```=
git show <commit_id>
```
* show the patch for a particular commit

#

```=
git add -p
```
* show all the diffs before adding to the stage area

# 

```=
git rm <file>
```
* remove the file from working tree and staging it for next commit

```=
git mv <old_file> <new_file>
```
* rename the file in working tree and stage it for next commit

#

```=
git checkout <file>
```
* restore file from the commit

#

```=
git add *
git reset HEAD <unwantted file>
```
* remove file from stages

#

```=
git commit --ammend
```
* it will overwrite previous commit
* if no changes made to staging area, we could modify the commit msg

#

```=
git revert HEAD
```
* create a new commit which overturn all changes done in the previous commit


```=
git branch
```
* list all the available branch

```=
git branch <new-name>
```
* create a new branch

```=
git checkout <branch-name>
```
* switch to a new branch

```=
git checkout -b <new-branch>
```
* create and switch to a new branch

```=
git branch -d <branch-name>
```
* delete a branch

# 

merge algorithm
1. fast forward
2. three way

#

```=
git merge <new-content-branch>
```
* merge the current branch with new-content-branch

```=
git log --oneline --graph
```
* show the log history in a graph manner, easier to understand

#

```=
git config --global credential.helper cache
```
* enable the cache service to capture the password

#
Work flow when working with Github
1. make the changes locally and commit
2. fetch the updates from server to check conflicts.
3. push to the remote repo

