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
${packpath}/pack
```
* default place to place all packages.

```=
:echo join(split(&packpath, ','), "\n")
```
* inspect the packpath variable.

```=
sample-pack/start/plugin_autoload_1/..
sample-pack/start/plugin_autoload_2/..
...
sample-pack/opt/plugin_optload_1/..
sample-pack/opt/plugin_optload_2/..
```
* sample folder structure for a package.

#### loading process
1. search for `{packpath}/pack/{packname}/start` directory, load it to `runtimepath`
2. source all scripts in the `runtimepath`

### Tip 5 : installing plugins to your package

#### installing your first plugin
```=
mkdir -p {packpath}/bundle/start
mkdir -p {packpath}/bundle/opt
```
* create the `bundle` package.
* `start` folder contains plugins loaded when startup.
* `opt` folder contains plugins optionaly loaded by user during runtime.

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
mkdir {packpath}/minpac/opt
```
* create the package for minpac
* it is a package containing all plugins including the `minpac` plugin itself.
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

#### removing plugins with minpac
1. remove the `packadd` statement from `vimrc` file.
2. call clean method from minpac.

```=
:call minpac#clean()
```
* the entire directory will be removed from the `{packpath}/minpac/`

#### creating commands

```=
command! Packupdate call minpac#update()
command! Packclean call minpac#clean()
```
* add these to `vimrc` file will create new `ex` command.
* customized command must start will capital letter.

#### a modern and minimal plugin manager
* minpac uses the vim's default package functions.
* it is for minimum, may not provide all functions as `Vundle`

## Chapter 3 : opening files
### Tip 7 : finding files using fuzzy path matching
#### preparation

```=
cd ~/.vim/pack/bundle/start
git clone https://github.com/junegunn/fzf
```
* install `fzf` plugin

```=
cd ~/.vim/pack/bundle/start/fzf
./install --bin
fzf --version
```
* install the fzf for bash.
* the bash program is part of the vim fzf plugin.

```=
:FZF
```
* access fzf inside vim.

#### opening files by specifying their filepath
provide a sequence of characters, fzf will find the files base on
* path matching these characters in the order specified.

#### opening files by fuzzy-matching their names

```=
<c-k>
<c-j>
```
* navigate the filtered list 

```=
<enter>
```
* open the selected fzf file in the current window.

```=
<c-x>
```
* open the selected fzf file in split window.

```=
<c-v>
```
* open the selected fzf file in vertical split window.

```=
<c-t>
```
* open the selected fzf file in a new tab.

```=
<c-c>
```
* cancel the fzf session.

#### filtering out files
It is possiblle to limit the input to fzf so we are not troubled by all the noise input like a unused folder.


```=
export FZF_DEFAULT_COMMAND='find . -type f'
```
* default setting for the search method

```=
export FZF_DEFAULT_COMMAND='git ls-files'
```
* change the behavior, so fzf only list files tracked by git.

```=
exprot FZF_DEFAULT_COMMAND='rg --files'
```
* exclude files that marked by 'gitigonre'

#### fuzzy finding other sources
1. source : the file list sent to fzf
2. sink : after filter by the user, action to the selection.

##### possiblility 1
1. source : buffer list
2. sink : open the selected buffer

##### possiblility 2
1. source : command history list
2. sink : execute the command in the current buffer.

##### fzf.vim
a standalone plugin provide these possiblities

### Tip 8 : finding files semantically
#### plugins
* `projectionist`

#### what does it do?
1. it classifies files into different categories
2. by providing part of the filepath, we can open the file in particular type in different folders quickly.

#### preparation
install projectionist from tim pope
#### exploring demo project

* in the master project directory, a confration file called `.projections.json` , this file will define the types of the file.
* the demo shows two project structures, amazingly, the same command can work with both structure.
* sematics will be
	1. open the model of comment module.
	2. open the model of adapter module.

```=
"app/models/*.js": {"type" : "model"}
```
* sample from `.projections.json`
* all the files in models folder will be classified as `model` type.
* the models folder contains model file for all modules.

```=
:Emodel comment
:Emodel adapter
```
* `E` stands for edit
* `model` is type of the file.
* `comment` is the fill for the glob.
* this command opens the file `app/models/comment.js`
* this command opens the file `app/models/adapter.js`

```=
"src/data/models/*/model.js" : {'type' : 'model'}
```
* a new `.projections.json` for the project
* each module is sperated in its own folder, each module contains its model file.
* all the commands still work.

```=
:Emodel comment
:Emodel adapter
```
* opens `src/data/models/comment/model.js`
* opens `src/data/models/adpater/model.js`

#### Navigation command variation

```=
E : edit in current buffer.
S : edit in horizontal split buffer.
V : edit in vertical split buffer.
T : edit in a new tab.
```
#### Smart tab completion
* use `tab` to autocomplete file types and path names.
* use `ctrl-d` to reveal list of possibilities

### Tip 9 : jumping to an alternate file
#### why we need this
when we need to switch between two different files, like a code and corresponding test
#### plugins
* projectionist
#### exploring the demo

```=
"app/models/*.js" : {
	'type':'model",
	'alternate':"test/unit/models/{}-test.js"
	},
"test/unit/models/*-test.js" : {
	'type' : 'modeltest',
	'alternate':"app/models/{}.js"
	}
```
* part of the `.projections.json`
* `alternate` property defines the alternate file with this file.
* `{}` matches the glob by `*`
* files are alternates to each other, 
	* {name}.js -> {name}-test.js
	* {name}-test.js -> {name}.js 
* you may flip the two files like a flip card

## Chapter 4 : working with the quickfix list
### Tip 10 : running a build and navigating failures

```=
vim-dispatch
```
* the plugin needs to be installed.
#### making vim call the compiler (a native approach)

```=
:!tsc --outDir build %
```
* `:!` calls an external command 
* `tsc --outDir build` is the type script complier used in this example.
	* `--outDir` is the option to specify the customized directory
	* `build` is the directory name you specified.
* `%` is shorthand for the current file path.

##### the problem
1. the error message disappears, so we could not identify the error easily
2. we could not interact with vim during the compilation, we need to wait until it finishes, this is called synchronous

##### capturing compiler output with :make

```=
makeprg
errorformat
```
* specify make program and the error of output from compiler.


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
