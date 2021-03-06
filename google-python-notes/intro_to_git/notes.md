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
git log --oneline --graph --all
```
* show the log history in a graph manner, easier to understand
* `--all` shows the history for all branches.

#

```=
git config --global credential.helper cache
```
* enable the cache service to capture the password

#
Work flow when working with Github
1. make the changes locally and commit
2. fetch the updates from server to check conflicts.
3. git will try to merge the remote branch to your local one
4. once conflicts resolved, push to the remote repo

```=
git branch -r
```
* show **read-only** branche

```=
git remote show origin
```
* get information about the remote repo, the remote repo is named as origin

```=
git remote update
```
* fetch all the new branches of the remote repo
* create a local **read-only** image of the branch

```=
>> git remote show origin
* remote origin
	Fetch URL: git@github.com:rock-mechanics/vim-notes.git
    Push  URL: git@github.com:rock-mechanics/vim-notes.git
	HEAD branch: master
	Remote branches:
	experimental tracked
	master       tracked
	Local branch configured for 'git pull':
	master merges with remote master
	Local ref configured for 'git push':
	master pushes to master (fast-forwardable)
```
* **tracked** means when you fetch, you auto get the latest updates from remote repo
* **HEAD** refers to the current checkout branch

#

```=
git push -u origin refactor
```
* push to a new branch `refactor` to the remote repo `origin`
* this creates a new branch in the remote repo. reviewers can review the chagnes in the branch and decided whether to merge it into the master branch of the remote repo

# 

```=
git rebase master
```
* rebase the experimental branch on top of the master branch, so the history of the experimental branch can be linear.

```=
git checkout master
git merge experimental
```
* after the rebase, we can have a fast-forward merge


```=
git push --delete origin experimental
```
* remove the remote branch



