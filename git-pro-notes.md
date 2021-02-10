# 1. Getting Started
## What is Git?
a distributed version control system and collabration tool.

## Git versions
git thinks the entire repo as a whole. each version, he will take a snapshot of all the files in the project.

## Git characteristic
* work locally.entire repo is saved on your local pc.
* super fast
* each file is checksumed, it is stored in the database by its checksum.

## Git states
* modified
* staged
* committed

## Git directory
* project dir : a version of the project database
* git dir : database containing all versions of the project.

## Git config file
Git has three config files each goes to deeper level. deeper config file will overwrite previous config file.

```=
git config --system
```
* config file located in `/etc/gitconfig`
* all users

```=
git config --global
```
* config file located in `~/.gitconfig`
* config file for current user.

```=
git config
```
* config file in project folder `.git/config`
* config file for current project.

## Setting up identity

```=
git config --global user.name "Jing Chen"
git config --global user.email "jingchen@tutanota.com"
git config --global core.editor "vim"
```
* set up the user name and email as well as default editor
* without the value to be set, it will echo the existing value if there is any setting before.

## Check the settings

```=
git config --list
```
* list all settings in action.

## Getting help

```=
git help <topic>
git <topic> --help
man git-<topic>
```

# 2. Git Basics
## Getting a Git Repository

```=
git init
```
* initalize a direcotry using git.
* `.git` directory will be created

```=
git clone [url]
```
* getting a **full** copy from a remote git repository

## Checking Status of your file

```=
git status
```
