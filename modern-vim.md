# Modern Vim
## Chapter 1 : Get Modern Vim

### Tip 1 : installing vim 8 

```=
vim --version
```
* get the version info and list of features enabled in this build.
* the following is mandatory feature for this book
	1. `+job`
	1. `+channel`
	1. `+timers`
	1. `+packages`

### Tip 2 : switching to neovim
### Tip 3 : enabling pythong support in neovim

## Chapter 2 : installing plugins
### Tip 4 : understanding scripts, plugins, and packages
* package is a directory contains more than one plugins
* plugin is a directory contains more than one scripts
* script is a file containing instructions for vim using `vimscripts`

#### scripts add functionalities to vim
```=
:source {script.vim}
```
* load the script into the vim session.

#### plugins make it easy to organise and share scripts

```=
:set runtimepath += {plugin directory}
```
* install the plugin is the same as adding plugin direcotory to runtimepath
* vim automatically source the scripts inside the directory during startup.

```=
:echo join(split(&runtimepath, ','), "\n")
```
* inspect the `runtimepath`

#### packages organize and load your plugins.

```=
$VIMCONFIG/pack
```
* default place to place all packages.

#### loading process
1. search for `start` directory, load it to `runtimepath`
2. source all scripts in the `runtimepath`

### Tip 5 : installing plugins to your package

#### installing your first plugin
```=
mkdir -p ~.vim/pack/bundle/start
mkdir -p ~.vim/pack/bundle/opt
```
* create the `bundle` package.
* `start` folder contains plugin loaded when startup.
* `opt` folder contains plugin optionaly loaded by user during runtime.

```=
git clone ....
```
* clone a plugin from github into the `start` folder or `opt` folder.
* after this, the plugin is installed.

```=
:helptags ALL
```
* run help tags parser for newly installed plugins
* if the parser already parsed the document, it will update it.

```=
:help {plugin-installed}
```
* view the help document for the newly installed plugin.
* this can only work if the parser has parsed the help document.

#### installing an optional plugin
* same procedure in `opt` folder, `runtimepath` is not updated during startup.

```=
:packadd {plugin-name}
```
* load the plugin during runtime.
* `helptags` needs to be run in order to view the help documentation.

#### migrating to vim packages.


### Tip 6 : managing plugins with minpac
minpac is a package manager that 
1. manipulate the `runtimepath` variable.
2. provide function to install/uninstall/update plugins

```=
mkdir ~/.vim/pack/minpac/opt
```
* create the package for minpac
* the minpac manager will be installed in `opt` folder.

```=
git clone https://github.com/k-takata/minpac.git
```
* install the minpac into the opt folder.

```=
packadd minpac
call minpac#init()
```
* load and initialize minpac.
* it can be included in vimrc file to run on startup.

#### adding and updating plugins with minpac.

```=
call minpac#add('tpope/vim-unimpaired`)
```
* clone plugin from github directly.
* by default, it will be installed in the same packages as the minpac.
* by default, it will be installed in the start folder.

```=
call minpac#add(tpope/vim-scriptease', {'type' : 'opt'})
```
* we can pass in a dictionary as second argument, specify it should be installed in the `opt` folder.

```=
:call minpac#update()
```
* update the plugins in the minpac package.
* it will also run `helptags` for us. so we can view the documentation directly.

## Chapter 3 : opening files
### Tip 7 : finding files using fuzzy path matching
### Tip 8 : finding files semantically
### Tip 9 : jumping to an alternate file

## Chapter 4 : working with the quickfix list
### Tip 10 : running a build and navigating failures
### Tip 11 : switching compilers
### Tip 12 : linting the current file
### Tip 13 : searching files with grep-alikcs
### Tip 14 : running tests and browsing failures.

## Chapter 5 : neovim's built-in terminal emulator
### Tip 15 : grokkiing terminal mode
### Tip 16 : running program in a terminal buffer
### Tip 17 : managing windows that contain terminal buffers
### Tip 18 : using normal mode commands in a terminal buffer
### Tip 19 : sending commands to a terminal buffer
### Tip 20 : applying customization to your shell in a terminal buffer
### Tip 21 : avoiding nested neovim instances
### Tip 22 : using an existing nvim instance as the prefered editor

## Chapter 6 : sessions
### Tip 23 : saving and restoring sessions
### Tip 24 : making undo persist between sessions
### Tip 25 : restarting termnal process when resuming a session

## Chapter 7 : configuring vim
### Tip 26 : using autocommands to respond to events
### Tip 27 : respecting project conventions
### Tip 28 : settng buffer-local configuration per project

## Appendix : What's next for modern vim
### A1 : integrating with the language server protocal
### A2 : what's next for vim 8
### A3 : what's next for neovim
