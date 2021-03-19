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
In progress

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
In progress

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

# Chapter 6 : Rewriting History
## Create The Red Page

```=
git checkout -b new-page
```
* `-b` creates the branch and check it out

## Create The Yellow Page
## Link And Commit The New Pages
red page and yellow page reside in a single snapshot
## Create And Commit The Green Page
## Begin Interactive Rebase

```=
git rebase -i master
```
## Undo The Generic Commit
take the `edit` command of the bad commit

```=
git reset --mixed HEAD~1
```
* move the head to the previous commit
* `--mixed` keeping the working direcotry unchanged, so it looks like the change happens on top of the HEAD
* now we have a modified `index.html` and unchanged `html` files

## Split The Generic Commit
### Remove Yellow Page
* remove the yellow page link from `index.html`
* stage the `red.html` and `index.html` and commit the change
* `yellow.html` is still untracked
### Add Back Red Page
* add back yellow page link from `index.html`
* stage the `yellow.html` and the `index.html`
* commit the change
### Continue The Rebase

```=
git rebase --continue
```
## Remove The Last Commit
### Accidently Remove The Last Commit

```=
git reset --head HEAD~1
```
* this moves the HEAD to the previous commit
* this moves the `new-content` branch pointer to the previous commit
* the `green page commit` becomes dangling

```=
git log --oneline
```
* we are currently at `new-content` branch
* the `green page` is missing from the log history

## Open The Reflog

```=
git reflog
```
* the reflog contains all the changes in chronological order

### Check Out The Missing Commit
* this move the `HEAD` to the missing commit
* the missing commit is still connected to the `new-content` branch

### Create A New Branch Name And Points To The Current Commit

```=
git checkout -b green-page
```
* a branch is a `pointer` by nature.
* this create a pointer pointing to the dangled commit
* the danglling commit is still connected to the `new-content branch`. so this will make the dangling commit visiable again.

## Filter The Log History

```=
...new-page <- commit1 <- commit2 <- commit3(green-page)
git log new-page..green-page
```
* the difference between the 2 branches in terms of commits
* this will show `commit1` `commit2` and `commit3`

```=
git log -n{number}
```
* show the last `{number}` commits 

```=
git log HEAD green-page
```
* show the difference between current `HEAD` to branch `green-page`

## Merge In The Revived Branch

```=
git checkout master
git log HEAD..green-page --stat
```
* `--stat` option shows details about changes between each commits

```=
git merge green-page
```
* merge to the fastest branch

```=
git branch -d new-page
```
* delete the branch in the middle.

## Conclusion
1. branch is a pointer
2. create a branch is the same as creating a point to the commit
3. the point will move when user do a new branch
4. parent relationship of commits will not change even the commit becomes dangling

# Chapter 7 : Remotes
## Clone The Repository(Mary)

```=
git clone {repo-to-copy} {destination-folder}
```
## Configure The Repository(Mary)

```=
git config user.name "Mary"
git config user.email mary.example@rypress.com
```
* this is a local configuration overwrite the global setting
* this setting is located `.git/config` file 

## Start Mary's Day
start a new feature branch and add in the information

```=
git checkout -b bio-page
```

## Create Mary's Bio Page(Mary) 
add the bio page info and commit the change, Now two types of branch is here

```=
HEAD -> master
origin/master, origin/HEAD
```
* `master` is the local branch
* `HEAD` is the local head position
* `origin/master is the remote branch
* `origin/HEAD is the remote head position
* the remote branch pointer is **not** updated. it is completely local unless we explicitly tell it to get the update.

## View Remote Repositories

```=
git remote -v
```
* when you clone a repository, git automatically create a remote pointer called `origin` which points to the repository being cloned

## Return To Your Home Directory
## Add Mary As A Remote

```=
git remote add mary ../git-mary
```
* `mary` is the name of the remote
* `../git-mary` is the relative address of Mary's repo

```=
code-git <---> mary-git
```
* code-git is the remote to mary-git as `origin`
* mary-git is the remote to code-git as `mary`

## Fetch Mary's Branches (You)
### Check Remote Branches

```=
git branch -r
```
* currently, we don't have mary's branch in our repo

### Fetch Remote Branches

```=
git fetch mary
```
* now we get `mary/master` branch in our repo

### Read-Only Nature of Remote Branches
* remote branches are read only
* they are for reference and copy codes
* you may/not incorporate these changes by copying the branch content on you local repository

## Checkout A Remote Branch

```=
git checkout mary/master
```
* now our `HEAD` is detached, it points to a commit ahead of our master branch`

## Find Mary's Change

```=
git log master..mary/master --stat
```
## Merge Mary's Change

```=
git checkout master
git merge mary/master
```
* this result to a fast forward merge

## Push A Dummy Branch

```=
git branch dummy
git push marry dummy
```
* this push the dummy branch to the local repo of mary's
* not a good idea.

## Push A Tag

```=
git push mary master
```
* this doesn't push the tag our master branch

```=
git push mary v2.0
```
* this will push the branch with the tag

# Chapter 8 : Centralized Workflow
## Create A Bare Repository (Remote)

```=
git init --bare centrorepo.git
```
* `--bare` option tell git not creating a working directory with checked ou t files. only create the database
* in git convention, database is defined with extension `.git`
* normally in working directory, the database in located in `.git` folder in the working directory

## Update Remotes ( Mary And You )

```=
git remote rm mary
git remote add origin ../centro-repo.git
```
* do this in the my-repo directory
* this removes the remote link and add a new one.

```=
git remote rm origin
git remote add origin ../centro-repo.git
```
* do this in the mary's directory

## Push The Master Branch ( You )

```=
git push origin master
```

## Add New Updates ( You )
* create a new branch
* modify the documents and create some documents
* commit the change

## Publish The News Item ( You )

```=
git checkout master
git merge news-items
git branch -d news-items
git push origin master
```
* this will push the master branch to the centro-repo.

## Update CSS Styles ( Mary )
* create a new branch called "css-edits"
* make modification and commit the change.
* make modification and commit the change again.

## Clean Up Before Publishing ( Mary )
* combine commits using

```=
git rebase -i master
```

* never rebase commit that has been pushed to public repository
* rebasing will erase old commits and create a new commit. this will cause a diverge with the public commits

## Publish CSS Changes ( Mary )
* if the feature is done, we should publish it to `master`
* if we decide to collabrate on this feature, we may need to publish it to a feature branch.

```=
git checkout master
git merge css-edit
git branch -d css-edit
```
* so far, our master branch contains `....a <- b`
* the centrorepo master branch contains `....a <- c`
* it will be rejected, because if the remote master branch try to match the our local branch, the commit `c` will be lost
* git push only accepts fast forward merge

## Pull In Changes ( Mary )

```=
git fetch origin
```
* fetch the latest remote branches.

```=
git log master..origin/master
git log origin/master..master
```
* both contains something the other branch does not have, so they are diverged.

```=
git rebase origin/master
```
* move the diversion point on our master branch to the tip of the remote master branch
* some of the commits will be included in our local branch
* now we are totally ahead of the remote master

```=
git push origin master
```
* now, our local master branch is one commit ahead of the remote master branch, we can push to cause a fast forward merge for the remote repository

## Pull In Changes ( Me )

```=
git fetch origin
git log master..origin/master
git log origin/master..master
```
* we can see the remote repo is one commit ahead of us.
* we just need to catch up merging the branch

```=
git merge origin/master
```

## Conclusion

* the centralized workflow ensure no one else could overwrite each other's work, which makes collaboration easy and intuitive.

# Chapter 9 : Distributed Work Flow
## Problems Of Centralized Workflow
1. everyone has access to the entire master data
2. random people can push random changes.

## A New Model
1. only you have direct access to the public repository
2. you fetch content from other developer and merge it in your local repo
3. you are responsible to push the fastest updates to the public repository

## Create A BitBucket Account
## Create A Public Repository ( You )
## Push To The Public Repository ( You )
* remove old remote
* add new remote the repository
* push

## Browse The Public Repository
## Clone The Repository ( John )

```=
git clone {https.....git} my-git-repo
```

## Add The Pink Page ( John )
* add the `pink.html` and link it in `index.html`
* commit the changes

## Publish The Pink Page ( John )

```=
git push john-public pink-page
```
* push the `pink-page branch` to johns public repository

## View John's Contribution ( Me )

```=
git remote add john http://rock-mechanics@bitbucket.org/rock-mechanics/johns-repo.git
```
* add john's **public repo** as our remote named `john`

```=
git fetch john
git branch -r
git log master..john/pink-page --stat
```
* check the different made by john

```=
git checkout john/pinkpage
```
* check john's actual modification before merge

## Integrate John's Contribution ( Me )

```=
git checkout master
git merge john/pink-page
```
## Publish John's Contribution ( Me )

```=
git push origin master
```
## Update Mary's Repository ( Mary )
* remove original remote
* add remote as `origin` for `my-git-repo` public repository
* fetch from `origin`
* the remote branch is one commit ahead of us.
* we may merge the `origin/master`, but a general solution would be `rebase` directly to the `origin/master`

```=
git rebase origin/master
```
## Update John's Repository ( John )
* John is the owner of this feature, but he should not merge directly to its master branch using `john-public repo`
* because the integrator may actually modified the commit before pushing to the public repository. Instead john should fetch content from the official public repository
* this also make john sync with the official repository

```=
git fetch origin
git rebase origin/master
```

## Conclusion
1. everyone has their own personal repository
2. everyone pull content from the **only** official repository to their working directory
3. everyone push their contribution to their personal repository
4. project integrator fetch from these repos to his working directory, modify and push them to the "official" repo
5. if the project integrator stops maintaining the repo, someone else can declare their repo as the official repo.

# Chapter 10 : Patch Workflow
## What is a patch
a patch is a set of instructions about how to change a file
## Change The Pink Page ( Mary )
1. create a new `pink-page` branch 
2. modify `pink.html`

## Create A Patch ( Mary )

```=
git format-patch master
```
* this will create patch files for all the commits in the current branch which is **ahead of master**
* `000x-{commit-message}.patch` will be created
	* `000x` is the index number starting from 1
	* `{commit-message}` helps to identify which commits the master branch compares to

## Add A Pink Block ( Mary )
* modify `pink.html`

## Create Patch Of Entire Branch ( Mary )

```=
git format-patch master
```
## Mail The Patches ( Mary )

```=
git send-email {options} {files or directories}
```
* refer to documentation for detailed configuration

## Apply The Patches ( You )
* create a new feature branch
* apply the patch

```=
git checkout -b patch-integration
git am < 0001...patch
```
* `git am` stands for `apply message`, this will create a new commit
* the multiple patch can be applied in any order as long as it does not cause a conflction

## Integrate The Patches ( You )

```=
git checkout master
git merge patch-integration
git branch -d patch-integration
git clean -f
git push origin master
```

## Update Mary's Repository ( Mary )
* mary created those patches
* but she should not merge it directory. instead she should pull it directly from the official repository
* the order may be shuffled by integrator, and other patches may be applied from other contributor

```=
git checkout master
git fetch origin
git rebase origin/master
```

```=
git branch -D pink-page
git clean -f
```

## Conclusion
1. the patch workflow requires only the integrator has a public repo
2. everyone else can work locally on their own repository
3. integrator does not need to tack everyone else's repo


# Chapter 11 : Tips And Tricks
## Archive The Repository

```=
git archive master --format=zip --output=../website-2020.zip
git archive master --format=tar --output=../website-2020.tar
```
* saves one branch so we can send it to other people
* it only contains files in the current branch
* this archive has nothing to do with git, there is no `.git` folder. so no git version information is saved in the directory.

## Bundle The Repository

```=
git bundle create ../repo.bundle master
```
* the `bundle` object contains all the version information of the git.

```=
git clone repo.bundle repo-copy -b master
```
* recover the repo from the bundle file. save the repo in `repo-copy` directory
* checkout the master branch

## Ignore A File
add `.gitignore` file to untrack certain files.
## Stash Uncommited Changes
* store untracked changes to some other places.
* run `git reset --hard` to resume working directory from last commit.
* retrieve it back when finish the emergency job.

```=
git stash
```
* remove all the changes since last commit, save it somewhere else.

```=
git stash apply
```
* bring back to these changes.

if you find yourself working on the wrong branch, then you could
* stash the change.
* switch to correct branch
* apply the stash

## Hook Into Git's Internals
### What is hooks
script will be run at certain events
### Where is hook scripts is stored

```=
.git/hooks
```
### make hooks active

```=
mv post-update.sample post-update
```
* rename the hook file

## example
make a backup whereever there is a push to the repo, update the post-update hook file

```=
#!/bin/sh
echo "Publishing master branch" >&2
rm -rf ../web-site
mkdir ../web-site
git archieve master --format=tar --output=../web-site.tar
tar -xf ../web-site.tar -C ../web-site
exit 0
```

## View Diffs Between Commits

```=
git diff HEAD~2..HEAD~1
```
* view diff between two commits.

```=
git diff
```
* view diff from staging area to working directory

```=
git  diff --cached
```
* view diff from last commit to staging area.

## Alias And Other Configurations

```=
git config --global alias.co checkout
git config --global alias.ci commit
git config --global alias.br branch
```

# Chapter 12 : Plumbing
plumbing is the low level commands to gives us a more precise representation of git's internal structure.

## Examine Commit Details

```=
git cat-file commit HEAD
```
* `tree` is the nodes under the commit
* `parent` is the node of its parent
* `author` is the one who creates the content
* `committer` is the one who pulbish the content to the branch.

### What Is A Tree
a tree object is like a directory except it does not contain any actual data, it is  a paper with addresses of all its children.

the children of a tree can be the following
* another tree can be there if it contains other directory
* actual file content

## Examine A Tree
tree is binary data.

```=
git cat-file tree ...
```
* view the binary data
* not very useful

```=
git ls-tree ...
```
* parse the tree for human readable.
* it contains a set of `blob` and other `trees`
* `blob` is the address of file
* `tree` is the address of other tree.
* `blob` are shared among commits if there is no modification on the file.

## Examine A Blob

```=
git cat-file blob ..
```
* it is simply file content.
* its meta data such as file name is stored in its parent tree together with the file address
* blobs are shared among commits if they are not modified.

## Examine A Tag

```=
git cat-file tag v2.0
```
* it contains a commit object address 
* a tag is simply a pointer to one commit

## Inspect Git's Branch Representation

```=
git cat-file -t master
```
* check the type master branch.
* a branch is simply a commit

```=
git cat-file commit master
```
* a branch is simply a pointer to a commit
* it contains
	1. tree
	2. parent
	3. author
	4. committer
	5. description of the branch.

```=
.git/refs/heads/master
```
* the content of the master branch
* it contains the address of recent commit.

```=
cat .git/HEAD
ref: refs/heads/master
```
* the HEAD is current pointing to the master branch.
* this shows our working directory is the same as the commit master.

```=
git checkout origin/master
cat .git/HEAD
d5507782edeb372cdb0f39af5d8a2425736d8e95
```
* checkout makes the HEAD detached from the master branch.
* now the HEAD file contains the checksum of a commit

## Explore The Object Database

```=
.git/objects/
```
* the gits database contains all the objects.
	* commit object
	* tree object
	* blob object
	* other objects
* the files are stored in folders
* foler-name + file-name is the file id for the object.

```=
git cat-file -t ...
```
* check the type of the object.

## Collect The Garbage

```=
git gc
```
* compress individual object file
* remove dangling commits

## Add File To The Index
* create a new `news-4.html`
* update `index.html`

### What is the Index
the index is git's term of stagging shot. it consists of the last commits which is the same as the working directory before the working directory is modified.

```=
git update-index index.html
git update-index --add news-4.html
```
* now the index is different from last commit.
* one file is updated, another file is added.

## Store The Index In The Database

```=
git write-tree
```
* this writes our index snapshot to a tree object in the object database

## Create A Commit Object
1. check the parents

```=
git log --oneline -n1
```
2. define a commit object by providing the tree and the parent

```=
git write-tree {tree-address} -p {parent-address}
```
* the commit object is created with the correct parents
* it become dangling commit

3. update HEAD
update file in `.git/heads/master` from our commit address

4. all of this is the same as running

```=
git commit -a -m"...."
```


