# Learning the Basics
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
# this is a comment.
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

## Scripting Csutomized tmux Environment
### The goal
build up environment with one command, it includes
1. window layout
2. pane layout
3. running programs.

### approach
* use a seris of bash command to config our environment.
* written all thest command into a bash script file

### creating a custom setup with tmux commands

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

### scripting a project configuration
#### build the script

```=
touch ~/test
chmod +x ~/test
```
#### create project directory

```=
mkdir ~/test_project
```
#### create a new session and a named window

```=
tmux new -t dev -n editor -d
```
* create a new session called 'dev', a window named 'editor'
* Detach it, so we could run other commands

#### run a command inside the window in the session.

```=
tmux sendkey -t dev 'cd ~/test_project' C-m
```
* run `cd` inside `dev` session, as there is only one window, there is no ambiguity
* `C-m` is the same as press `Enter` to execute the command.

```=
tmux sendkey -t dev 'vim' C-m
```
* run `vim` program inside the only window of session `dev`

#### split a window 

```=
tmux sendkey split-window -v -t dev
```
* vertical split the window

```=
tmux sendkey split-window -v -p 10 -t dev
```
* `-p 10` makes the newly created window 10% of the total width.

#### apply a pre-defined layout to a window

```=
tmux select-layout -t dev main-horizontal
```
* `main-horizontal` is a pre-defined layout which tile all window horizontally.

#### targeting specific window and pane.

```=
tmux send-keys -t dev:1.2 'cd ~/test_project' C-m
```
* `dev:1.2` means `session dev`, `window 1`, `pane 2`
* this will send the command to the newly created pane.

#### creating another window.

```=
tmux new-window -n console -t dev
```
* create a new window named `console`

#### make the window on the top of the window stack.

```=
tmux  select-window -t dev:1
```
* `dev:1` is the first window when we created the session.

#### attach the terminal to the session.

```=
tmux attach -t dev
```
* the terminal will connect to the session
* the selected window will be on top the window.

#### check if session existed.

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

