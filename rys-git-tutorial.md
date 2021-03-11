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
* the history is the same as the stable version.
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


