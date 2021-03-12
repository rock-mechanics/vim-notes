# Chapter 1 : Introduction
## A Brief History of Revision Control
### Files and Folders
### Local VCS
* use a local database to store backup files.
### Centralized VCS
* use server to store backup files.
* a big confilict problem
### Distributed VCS
* every user has the **entire** copy of the project.
* create branch without affecting the main program.
* has to manage conflicts as well.
* create creative messup with your local copy.
* faster as it is performing local changes.
## The Birth Of Git
## Installation
## Get Ready

# Chapter 2 : Basics
## Create the Example Site
## Initialize Git Repository

```=
git init
```
* a `.git` directory is created, it will save all our versions locally.

## View The Repo Status

```=
git status
```
* an `untracked file` is not kept under version control.

## Stage a Snapshot

```=
git add index.html
git status
```

* now this file is in the staging area. 
* the entire snapshot consists of only one file. `index.html`
* if we created 1000 files later. when we revert to this version. our project will come back to this one file stage.
* staging groups a series of changes together to perform one snapshot.

## Commit The Snapshot

```=
git commit 
```
* take the snapshot. now the status of the project has been recorded.
* git will **never** change a commited snapshot.

## View The Repository History

```=
git log
```
* the message contains a checksum. which allow git figure out whether the file is corrupted.

## Configure Git

```=
git config --global user.name "Jing Chen"
git config --global user.email "jingchen@tutanota.com"
```

## Creating New Html Files
* create two new htmls file.

## Stage The New Files

```=
git add orange.html blue.html
```
* if you add a file same as previous snapshot, git will not add it to the staging area.

## Commit The New Files
## Modify The Html Pages
## Stage And Commit The Snapshot
## Explore The Repository's History

```=
git log --oneline
```
* show each history with one line.

```=
git log --oneline blue.html
```
* show file history for commits releated to specific file

## Conclusion

# Undoing Changes

```=
git log --oneline
```

```=
142c113 Create blue and orange page
```
* `142c113` is part of the checksum of the file
* it serves as identifier of the file.

## View An Old Version

```=
git checkout 142c113
```
* go back to specific snapshot

## View An Older Version
## Return To Current Version

```=
git checkout master
```
## Tag A Release

```=
git tag -a v1.0 -m"Stable version of the website"
```
* `-a` is anotated tag
* we can include a version number which serve as alias to file identifier
* `-m ..` includes a message to this version as well.

## Try a Crazy Experiment
* create a new file called crazy.html

## Stage And Commit The Snapshot
## View The Stable Commit

```=
git checkout v1.0
```
* `tag` can be used as commit identifier.

```=
git checkout master
```
* return the most recent version

## Undo Commited Change

```=
git checkout master
git revert c5a5324
```
* abolish the version 
* before we do, we need to change to master branch

```=
d2a2230 (HEAD -> master) Revert "Add a crazzzzy experiment"
c5a5324 Add a crazzzzy experiment
fa7e297 (tag: v1.0) Add Navigation links
```
* a new history is added to the history list.
* the history is the same as the stable version v1.0
* `crazzzy experiment` is abolished (reverted)

## Start A Smaller Experiment
* create a new `dummy.html`
* modify the `index.html`

## Undo Uncommitted Changes
* tracked files are modified, to undo it.

```=
git reset
```
* un-stage all staged files

```=
git reset --hard
```
* remove all modified tracked files

```=
git clean -f 
```
* remove all untracked files.

# Chapter 3 Branches Part 1 
## View Existing Branches

```=
git branch
```

```=
* master
```
* master is the default branch
* `*` in front of it denotes it is the checked out branch.

## Check Out The Crazy Expriment
* `HEAD` is the internal way indicating the current checkout snapshot
* after we checkout the crazy experiment
	1. we are not on the master branch
	2. there are no branch we are actually in.


## add a new branch
In order to do some further development to this crazy experiment, we need to create a branch

```=
git branch crazy
```

## switch to the new branch

```=
git checkout crazy
```
* this is important, otherwise, our commit will ended on some **non-existant branch**

## stage and commit the rainbow
* the `git log` will only show the history our the current branch

## Rename The Rainbow

```=
git rm crazy.html
```
* telling git stop tracking `crazy.html`

```=
git add rainbow.html
```
* telling git to track `rainbow.html`

## Return To The Master Branch
## Create A CSS Branch
### Change The Branch Name If You Mistype It

```=
git checkout {branch to rename}
git branch -m new-name
```
## Add A CSS Stylesheet
1. add a new `style.css` file.
2. commit the changes

## Link The Stylesheet
1. link the stylesheet in all the htmls.
2. commit the changes.

## Return To The Master Branch Again
* The purpose of the css branch is that it experiment some new features without threatening the stability of the master branch

## Merge The CSS Branch

```=
git checkout master
git merge css
```
* it merges to the current branch
* in this case, git reuse the commit and simply moves the master head to the css head

## Delete The CSS Branch
now css and master branch points at the same location, we can freely remove the css branch
```=
git branch -d css
```
* deleting an unmerged branch will be warned by git, since it may cause loss of work

# Chapter 4 : Branches Part 2
## Continue The Crazy Experiment
* check out the crazy branch
* it is called `feature branch`, because its purpose is to target one feature

### Rules When Create A Branch
1. when there is a major addtion to the project, create a branch
2. the branch must have a descriptive name for the purpose, otherwise don't creat the branch

## Merge The CSS Updates

```=
git merge master
```
* merge the master branch to the current branch
* this is **not** a fastforward merge, git create a new commit merging the two snapshots
* this is called `3-way merge`
* git will look at three commits, the diverted commit, the css branch and the master branch to decide what final commit looks like.

```=
git log --oneline
```
* the history of master and css all show in the log history
* they are arrranged in time order regardless its branch before.

## Style The Rainbow Page
1. add style sheet to rainbow.html
2. commit directly using

```=
git -a -m"add css to rainbow.html"
```
* `-a` add all tracked modified files to the staging area and commit them all in one go.

## Link To The Rainbow Page
add a navigation link to the rainbow page in the `index.html`

## Fork An Alternative Rainbow

```=
git branch crazy-alt
git checkout crazy-alt
```
## Change The Rainbow
modify the rainbow.html

## Emergency Update

```=
git checkout master
git branch news-hotfix
git checkout news-hotfix
```
* this type of branch is called `hotfix branch`
* we create it, we apply it and then we delete it.
* create a new `news-1.html` and link it in `index.html`

## Publish The News Hotfix

```=
git checkout master
git merge news-hotfix
```

```=
git branch -d news-hotfix
```
* remove the hotfix branch

## Complete The Crazy Experiment
change the `index.html` document

## Publish The Crazy Experiment

```=
git checkout master
git merge crazy
```
* a merge conflict appears.

```=
git status
```
* check the conflict.
* `Unmerged paths` shows the conflicting file

### Check The Conflict File

```=
<<<<<<<HEAD
....
=======
....
>>>>>>>crazy
```
* the first section contains content of current branch
* the second section contains content of the crazy branch

## Resolve The Merge Conflicts
* delete the marker
* fix the content
* commit to make the 3-way merge happen

```=
git add index.html
git commit
```
* there is no need to give a `-m` message to `git commit`, because git will provide a default message for all the merge commit.

## Clean The Feature Branches

```=
git branch -d crazy
```

```=
git branch -d crazy-alt
```
* this will raise an error, as the branch is not merged

```=
git branch -D crazy
```
* this will completely scrap this branch, and the information is lost forever.

## Conclusion
The use of branch for 
1. a feature like `crazy`
2. a hot fix like `news-hotfix`
3. a long and stable branch like `master`

Point 1 and 2 created an isolated environment for the test purpose. The stable branch is never affected.

There are two types of merges
1. `fast-forward merge` result in a linear path in project history
2. `three-way merge` result in a non-linear path in project history

# Chapter 5 : Rebasing
The purpose is to creat an linear history line so we could refer to it later.
* when we have a feature branch, the parent node on the master tree is behind the master branch, this cause a divert on the master tree and we have to do a `three way merge` to merge it to master branch.
* rebasing change the parent node of the feature branch to the master branch, so we could do a `fast forward merge` to the master tree.

## Create An About Section

```=
git branch about
git checkout about
...make a new directory called about ....
...add empty file about/index.html
git add about 
git commit -m "Add empty page in about section"
```

## Add An About Page
add content to `about/index.html` and commit the change.

## Another Emergency Update!
return to master and apply the hotfix

```=
git checkout master
git branch news-hotfix
git checkout news-hotfix
...update index.html and commit
...add news-2.html page and commit again
```
## Publish News Hotfix

```=
git checkout master
git merge news-hotfix
git branch -d news-hotfix
```
## Rebase The About Branch

```=
git checkout about
git rebase master
```

## Add A Personal Bio
add `about/me.html` and commit

## Add Dummy Page For Mary
add `about/mary.html` and commit

## Link To The About Section
add `about/index.html` to the `index.html` and commit

## Clean Up The Commit History
we have a lot of commit ahead of the master branch, sometimes not all commits history are meaningful. some of them may cause troubles.`git rebase` allows us to clean some the history before rebasing

```=
git rebase -i master
```
we can 
1. combine small commits
2. change the order of commits.
3. **dangerous**, we may also delete permanently some snapshots.

Git will ask you to write an new commit message for combined commits.

## Stop To Ammend A Commit
using rebase, we can edit a snapshot before rebasing

```=
git rebase -i master
...change commit command to edit
...edit the files
git commit --amend
git rebase --continue
```
* this will modify the snapshot of one commit in your commit history

## Continue The Interactive Rebase

```=
git rebase --abort
```
* abort the rebase, and start over from scratch

## Publish The About Section
The purpose of `interactive rebasing` is to create a meaningful history and merge back to the master.

```=
git checkout master
git merge about
git branch -d about
```













