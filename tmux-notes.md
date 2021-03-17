# Learning The Basics
## installing tmux
## starting tmux

```=
tmux
```
* create a tmux session and attach it to the current terminal session.
* once `tmux` is exited, the terminal will be returned.

```=
exit
```
* exit tmux session as well as the attached terminal session.

### creating named session

```=
tmux -new -s {session-name}
```
* create a new session named `session-name`

## the command prefix
### why we need command prefix
* tmux creates a new layer between the terminal and the applications.
* when fire a command, we need to specify whether the command is for the layer or for the applications under the layer.

```=
ctrl-b {command}
```
* default prefix for tmux, command will be captured by the tmux layer.

```=
ctrl-b t
```
* show the time. 
* even the application running have binded to `ctrl-b`, it won't be able to receive it.

## detaching and attaching sessions
* tmux can manage multiple sessions. only one or none is attached to the terminal

### dettach session
```=
prefix-d
```
* dettach the session with the terminal. this will return the terminal.
* we can close the terminal window, and the sessions will be preserved.

### list sessions
```=
tmux ls
```

### create new session without attaching to it.
```=
tmux new -s {session-name} -d
```

### attach to existing session
```=
tmux attach
```
* reattach the current terminal to the top session.
* sessions are stacked based on created time (top session is the most recent).

```=
tmux attach -t {session-name}
```
* attach a specific session.

### kill sessions
```=
tmux kill-session -t {name}
```

## working with windows
one tmux session can contain multiple windows
### creating and naming windows

```=
prefix-c
```
* creating a new window

```=
prefix-,
```
* comma is used to rename the window to a meaningful name.

### moving between windows

```=
prefix-n
```
* next window

```=
prefix-p
```
* previous window

```=
prefix-{index}
```
* using index to show windows.
* windows are stacked from index 0

### kill window

```=
prefix-&
```
* kill the window
* if all windows are killed, the tmux session will exit.
* if all sessions are killed, the tmux layer will exit.

## working with panes
window can contain different panes.

### split window into different panes
```=
prefix-%
```
* split the window vertically

```=
prefix-"
```
* split the window horizontally.

### move around panes

```=
prefix-o
```
* cycle through the windows

```=
prefix-arrow
```
* jump from pane to pane

### move pane position

```=
prefix - ctrl - o
```
* rotate all the panes in clockwise direction

### use default pane layouts

```=
prefix-space
```
* cycle through default pane layout.

### kill panes

```=
prefix-x
```
* confirm the kill and pane will be closed.

## working with command mode
send commands directly to the tmux layer.

### enter command mode

```=
prefix-:
```

### create a new window with name
```=
:new-window -n test
```
* assign a name "test" to the window

### create a new window and run a program in it.

```=
:new-window "ping -t google.com"
```
* `ls` will be run in the new window created.
* once it finish running, the window is closed.

## what's next

```=
prefix-?
```
* show a list of default key bindings
* press `q` to return to the session.

# Configuring tmux
## introducing the `.tmux.conf` file
there are two location when `tmux` applies its configration file

```=
/etc/tmux.config
~/.tmux.conf

* system-wide configration is applied first.
* user configration is applied second.
```

### defining an easier prefix

```=
set -g prefix C-a
```
* `-g` means global, it will applies to all session we created. 

```=
line starting with # is a comment.
```

```=
unbind C-b
```
* if not unbind, new and existing key binding will both work.

### changing default delay

```=
set -s escape-time 1
```

### setting window and pane index

```=
set -g base-index 1
set -g pane-base-index 1
```

### apply config changes in runtime.
```=
:source-file ~/.tmux.conf
```

## customizing keys, commands, and user input
### creating a shortcut to reload the configuration

```=
bind r source-file ~/.tmux.conf
```
* bind command will bind the key to prefix
* to trigger command, you need to press `prefix + r`

```=
bind r source-file ~/.tmux.conf \; display "reload"
```
* `\;` is used to chain two command together.

### send prefix to other program

```=
bind C-a send-prefix
```
* in case commands for tmux layer confilict with underlaying program
* `c-a` will create a tunnel, the following key combination will be sent to the program.

### splitting panes

```=
bind | split-window -h
bind - split-window -v
```
* create more visual binding to split the windows.

### remapping movement key

```=
bind h select-pane -L
bind j select-pane -D
bind k select-pane -U
bind l select-pane -R
```
### resizing panes.

```=
bind H resize-pane -L 5
bind J resize-pane -D 5
bind K resize-pane -U 5
bind L resize-pane -R 5
```
* we can visualize the movement of the divide line now.

```=
bind -r H resize-pane -L 5
bind -r J resize-pane -D 5
bind -r K resize-pane -U 5
bind -r L resize-pane -R 5
```
* `-r` option is called repeat. 
* within a time limit you can press the prefix once, then press the defined command key a few times to repeat the process without press the prefix.

### handling the mouse.

```=
set -g mouse on
```
* mouse can select the panel
* mouse can resize the panel
* mouse can scroll the panel

```=
set -g mouse off
```
* set mouse off for better efficiency.

## visual styling
### configuring colors

```=
set -g default-terminal "screen-256color"
```
* make tmux use 256 colors by default.

```=
tput colors
```
* check in terminal about color scheme.

### Changing colors
#### change status line colors

```=
set -g status-style fg=white,bg=black
```
#### change window list colors

```=
setw -g window-status-style fg=cyan,bg=black
```
* this change the window list on the status line.

```=
setw -g window-status-current-style fg=white,bold,bg=red
```
#### changing the appearance of panes.

```=
setw -g pane-border-style fg=green,bg=black
```
* setting the border during split panes.

```=
setw -g pane-active-border-style fg=white,bg=yellow
```
* change the active window border

```=
setw -g window-style fg=colour245,bg=colour235
setw -g window-active-style fg=white,bg=black
```
### customizing the tmux command line

```=
set -g message-style fg=white,bold,bg=black
```
## customizing the status line's content
the status line consists of three components
1. left panel : shows `tmux session` by default
2. window list
3. right panel: shows hostname and time and date

### configuring status line items.

```=
set -g status-left "#S"
```
* #S is the current session name

```=
set -g status-left-length 80
set -g status-left "#[fg=green]Session : #S #[fg=yellow]#I #[fg=cyan]#P"
```
* `#[fg=color]` is an attribute to set the color for the following element
* `#S` is the current session
* `#W` is the current window index
* `#P` is the current pane index

```=
set -g status-right "%d %b %R"
```
* `%d` : day
* `%b` : month
* `%R` : time in 24 hour

### keep status line info up to date
* by default, tmux refresh the status line every 15 seconds.

```=
set -g status-interval 60
```
* change to 60 seconds.

### centering the window list

```=
set -g status justify centre
```

### identifying activity in other windows.

```=
setw -g monitor-activity on
```
* it will highlight the window name if there is an activity going on in that window.

```=
setw -g visual-activity on
```
* it tell tmux to show a message about the activity on the status line.

# Scripting Csutomized tmux Environment
## The goal
build up environment with one command, it includes
1. window layout
2. pane layout
3. running programs.

## approach
* use a seris of bash command to config our environment.
* written all thest command into a bash script file

## creating a custom setup with tmux commands

```=
tmux new -s {session-name}
```
* create a new session
```=
tmux attch -t {session-name}
```
* attach to an existing session.
* `t` stands for `target`

```=
tmux split-window -h -t {session-name}
tmux split-window -h -v {session-name}
```
* split a session window

## scripting a project configuration
### build the script

```=
touch ~/test
chmod +x ~/test
```
### create project directory

```=
mkdir ~/test_project
```
### create a new session and a named window

```=
tmux new -t dev -n editor -d
```
* create a new session called 'dev', a window named 'editor'
* Detach it, so we could run other commands

### run a command inside the window in the session.

```=
tmux sendkey -t dev 'cd ~/test_project' C-m
```
* run `cd` inside `dev` session, as there is only one window, there is no ambiguity
* `C-m` is the same as press `Enter` to execute the command.

```=
tmux sendkey -t dev 'vim' C-m
```
* run `vim` program inside the only window of session `dev`

### split a window 

```=
tmux sendkey split-window -v -t dev
```
* vertical split the window

```=
tmux sendkey split-window -v -p 10 -t dev
```
* `-p 10` makes the newly created window 10% of the total width.

### apply a pre-defined layout to a window

```=
tmux select-layout -t dev main-horizontal
```
* `main-horizontal` is a pre-defined layout which tile all window horizontally.

### targeting specific window and pane.

```=
tmux send-keys -t dev:1.2 'cd ~/test_project' C-m
```
* `dev:1.2` means `session dev`, `window 1`, `pane 2`
* this will send the command to the newly created pane.

### creating another window.

```=
tmux new-window -n console -t dev
```
* create a new window named `console`

### make the window on the top of the window stack.

```=
tmux  select-window -t dev:1
```
* `dev:1` is the first window when we created the session.

### attach the terminal to the session.

```=
tmux attach -t dev
```
* the terminal will connect to the session
* the selected window will be on top the window.

### check if session existed.

```=
tmux has-session -t dev
if [$? != 0]
then 
	...
	...
	#create the session.
	...
	...
fi
tmux attach -t dev
```
* if session existed, simply connect to it, otherwise create the session.

## using tmux configuration for setup.
### approach
1. input instruction in `.tmux.conf` file. which applies certain window setup for all instance.
2. define project scale configuration file and pass it to tmux when tmux starts up.

```=
tmux -f app.conf attach
```
* `-f` asks tmux to looks for a start up file before it is running.
* tmux will run `tmux {line by line}` in the start up file
* in the `app.conf`, you don't have to prefix every command with `tmux`.
* `attach` prevent tmux from creating a new tmux session by itself.

## managing configuration with tmuxinator
### what is tmuxinator
a program makes running setup scripts easy.
### prerequisite
1. `$Editor` system variable is set
2. `ruby` interpreter is required.

### install tmuxinator

```=
gem install tmuxinator
```

### creating a new configration file

```=
tmuxinator open dev
```
* by defualt, configuration file is saved at `~/.tmuxinator` directory
* this is the same as modifying an exisiting configuration file

### configuration format 

```=
name: dev
root; ~/dev
windows
  -editor;
    layout: main-horizontal
	panes:
	  - vi
	  -   #empty bash
  -console:
```
* configuration is in `yaml` format
* **two spaces** is used for indentation.
* it provides a nicer syntax for window manipulation.

### ouput tmuxinator configuration to a bash script

```=
tmuxinator debug dev
```
* under the hood, the tmuxinator will translate the `yaml` to `bash`
* this can be run anywhere with or without tmuxinator

### load tmuxinator configuration file

```=
tmuxinator dev
```

# Working With Text And Buffers
## scrolling through output with copy mode
* copy mode is a new layer added by tmux
* in this mode, tmux has freeze the buffer to some extent.
* user has limited options for specific tasks.
* entire buffer content is treated as text documents. so you can freely navigate/copy/paste as you like with key bindings similar to an text editor such as vi.

### enter and exit copy mode

```=
prefix-[
```
* enter copy mode

```=
enter
```
* exit copy mode.

### using vi style movement instead of the arrow key

in the `.tmux.conf` file.
```=
setw -g mode-keys vi
```
* then use `hjkl` key to move a buffer once inside copy mode.
* use vi `wb` to move through words
* use vi `f{char}` and `F{char}` to locate characters.

### move quickly through the buffer.
same as vi

```=
c-b
c-f
```
* move by pages

```=
g
G
```
* to the beginning of ending of a buffer.

### searching through the buffer
same as vi

```=
?{chars}
/{chars}
```
* search backwards and forwards

```=
n
N
```
* continue search in the same direction or backward direction.

## copying and pasting text

```=
space + {movement} + enter
```
* this will copy selected text to a register managed by tmux.

```=
prefix-]
```
* paste the selected text to the follwing position

### copying entire visible pane 

```=
:cpature-pane
```
* the visible part of the text is all copied to the register managed by tmux.

### showing and saving the buffer.

```=
tmux show-buffer
```
* this command is fired in bash.
* display the content copied to the tmux buffer.
* this direct the buffer content to `stdout`

```=
tmux show-buffer > buffer.txt
```
* save `stdout` to a file.

```=
:capture-pane;save-buffer buffer.txt
```
* this commands is fired up in the comand mode.
* cpature the current pane and save it to a file.

### using multiple paste buffers.
tmux maintain a buffer stack when perform copying.

```=
:list-buffers
```
* show the buffer stack
* most recent buffer comes on top with index 0, `prifix-]` always paste buffer 0 by default.

```=
:choose-buffer
```
* choose a selected buffer to paste.
* the buffer list is shared across **all** tmux sessions.

### remapping copy and paste keys

```=
bind Escape copy-mode¬
bind-key -T copy-mode-vi v send -X begin-selection¬
bind-key -T copy-mode-vi y send -X copy-selection¬
unbind p¬
bind p paste-buffer¬
  ```
* now everything becomes vi style.

## Working With Clipboard On Linux
integrate tmux buffers with system clipboared through a program called `xclip`
* `xclip` program is required for this to work

### install xclip

```=
sudo apt-get install xclip
```
### define key-binding to send tmux buffer to system clipboard

```=
bind C-c run "tmux save-buffer - | xclip -sel clip -i"
```
* use `prefix-C-c` to copy to system clipboard

```=
bind-key -T copy-mode-vi y send-keys -X copy-pipe-and-cancel "xclip -sel clip -i"¬
```
* when yanking text from tmux, it also yanks to the system clipboard

### define key-bindings to paste from the system clipboard
```=
bind C-v run "tmux set-buffer \"$(xclip -sel clip -o)\";
```
* use `prefix-C-v` to paste text from system clipboard.

## using MacOS Clipboard Commands

```=
pbcopy
```
* takes `stdin` and send it to system clipboard

```=
pbpaste
```
* paste from system clipboard

```=
tmux show-buffer | pbcopy
```
* send top buffer to system clipboard

```=
tmux set-buffer $(pbpaste); tmux paste-buffer
```
* set buffer from system clipboard, then paste it.

# Pair Programming With tmux
## Paring with a shared account
## Using a shared account and grouped sessions
## Quickly pairing with tmate
## Pairing with separate accounts and sockets

# Workflows
## working effectively with panes and windows
### turning a pane into a window

```=
prefix-!
```
### turning a window into a pane 

```=
:join-pane -s {session-name}:{window-index}
```
* take the window in the session and join with current window.
* this can tranfer window between sessions.

```=
:join-pane -s sess1:1 -t sess2:1
```
* `-t` specify the target window.
* specifying a target session window.

```=
:join-pane -s sess1:1.1 -t sess2:1
```
* use this technique to move panes around.


### maximizing and restoring panes

```=
prefix-z
```
* zoom in the current pane to full screen
* press again to restore its original layout.

### lanuching commands in panes

```=
tmux new -s server -d "ssh user@hostname1"
tmux split-window -v "ssh user@hostname2"
```
* `split-window` has option `-t session` to specify a session window, but assume we have only one session, one window, we can omit it.
* `ssh ...` is taken as an argument passed to tmux, once tmux creates the window or pane, it will run the command inside the pane.
* the pane will close once the program finishes running.

### opening a pane in the current directory
when a new window is created, the bash's `pwd` is set as the directory where you lanuch tmux.

```=
:split-window -v -c "#{pane_current_path}"
```
* `#{...}` expands the tmux variable, `pane_current_path` expands to the currnt directory of the running bash.

### issuing commands in many panes simutaneously
tmux has a sychornize mode which allow your typing inputs to all panes

```=
set-window-option synchronize-panes on
set-window-option synchronize-panes off
```

bind the commands to a key

```=
bind C-s set-window-option synchronize-panes
```
## managing sessions
### move between sessions.

```=
prefix-)
```
* move to next session.

```=
prefix-(
```
* move to previous session.

```=
prefix-s
```
* list all sessions.
* use `j` and `k` to navigate session.
* use `l` and `h` to expand session.

### move windows between sessions.

```=
prefix-dot
```
* move the current window to another session.
* we need to type the name of the target session.

```=
tmux move-window -s {sess1}:{win-index} -t {sess2}
```
* on command line move window from one session to another session.

### creating or attaching to existing sessions

```=
if !tmux has-session -t {session-name};
then
	....
	....
	#code to config session
	....
	....
fi
exec tumux attach -t {session-name}
```
* check the existance of the session before creating it.

## tmux and you operating system
### using a different shell

```=
set -g default-shell /bin/zsh
```
* add this to `.tmux.conf` file. tmux will use zsh as default shell.

### launching tmux by default
shell running inside tmux will have access to a variable named `$TMUX`

```=
if [[ -z "$TMUX"]];
then
	tmux new -A -s "$USER"
fi
```
* this check whether terminal is running inside tmux, if not. start a new session named after the user.

### keeping specific configuration separate
tmux configuration file may differ from Linux to Mac.

```=
touch ~/.tmux.mac.conf
```
* create a configuration specifically for mac.

```=
if-shell "uname | grep -q Darwin" "source-file ~/.tmux.mac.conf"
```
* this can be added to the master `.tmux.conf` file.
* `if-shell`runs a shell command to see whether it is successful. 
* if we are in mac, the `.tmux.conf` will also source `.tmux.mac.conf`

```=
if-shell"[-f ~/.tmux.private]" "source ~/.tmux.private"
```
* check whether the file exists, if it does. then load it.

### recording program output to a log

```=
pipe-pane -o "cat>>mylog.txt"
```
* `-o` is used for toggole.

```=
bind O pipe-pane -o "cat >>~/mylog.txt" \; display "Toggled logging to ~/mylog.txt"
```
### adding battery life to the status line.
### integrating seamlessly with vim
* vim splits are different from the tmux window splits.

## extending tmux with plugins

tmux use TPM as its plugin manager.
```=
git clone https://github.com/tmuxplugins/tpm ~/.tmux/plugins/tpm
```
* clone the repo of TPM

```=
set -g @plugin 'tmux-plugins/tpm'
set -g @plugin 'tmux-plugins/tmux-resurrect'
run '~/.tmux/plugins/tpm/tpm'
```
* config the plugin manger and run it.

```=
prefix-I
```
* check status of installation of the plugin manager

```=
prefix-C-s
```
* save the current layout and sessions.

```=
prefix-C-r
```
* restore the saved layout and session.
* it is saved in you hard disk, so it is ok to disconnect tmux after saving the session, you can easily restore it.
