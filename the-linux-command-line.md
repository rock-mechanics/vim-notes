# What Is The Shell
* shell is a program
* it takes keyboard input and pass them to operating system.

## Terminal Emulators
a software wrapper that enable you to access the shell.

## your first keystrokes
### shell prompt
a signal indicates that the shell is ready to take input.
* `$` : user
* `#` : root user.

### command history
use arrow key to access the command line history
* most Linux stores around 500 commands.

### cursor movement
* arrow key to move left and right to make modifications

### a few words about mice and focus

#### mouse
* in x window system, when you select text, it copies into a buffer. you press middle button of the mouse to paste it.
* mouse select -> copy
* middle button -> paste

#### focus
* traditional x window behavior is focus follow mouse.
* window will take inputs but will not come to foreground unless you press left button.

## try some simple commands

```=
date
cal
df
free
```
* `df` shows free space on your drive
* `free` shows free memory

## ending a terminal session

```=
exit
```
## the console behind the curtain
several terminal sessions is run on the background which are called virtual terminals.

```=
ctrl + alt + f1 - f6
```
* access these terminal sessions

```=
alt + f1 - f7
```
* return to graphical desktop


# navigation

## understanding the file system tree
* first directory is called `root`
* Linux always have a single directory tree.
* storage devices are attached to a point on the tree

## the current working directory

```=
pwd
```

## listing the contents of a directory

```=
ls
```
* it can be used to list any directory

## changing the current working directory

### absolute pathnames
* always start with root `/`

```=
ls /usr/bin
```

### relative pathnames
* starts with `./` or `../`
* `./` means current directory, it can be omitted.
* `../` means the parent directory 

### some helpful shortcuts 

```=
cd -
```
* change to previous working directory

```=
cd ~username
```
* change to home directory of user `username`

### important facts about file names 
* `.filename` is a hidden file
* do not use space in the file name

# exploring the system
## more fun with ls

```=
ls ~ /user
```
* give multiple directories for `ls`

```=
ls -l
```
* use a long format to list the files and directories.

### options and arguments
* options starts with `-`
* long options starts with `--`
* two or more options can put together sharing the `-`

```=
ls -lt --reverse
```
* by default, this applies to current directory.
* `-l` use long format
* `-t` use the modification time to sort, list from new to old 
* `-l` and `-t` shares the same `-`
* `--reverse` reverse the order.

```=
-a
-A
```
* all content including hidden files.
* `-a` list `.` and `..`
* `-A` does not list `.` and `..`

```=
-d
```
* list the directory itself instead of its content
* `ls -d` will list the properties of current directory.

```=
-S
```
* sort result by file size.

### a longer look at long format

```=
-rw-r--r-- 1 rock-mechanics rock-mechanics   17 2月  17 00:20 new
```
1. permissions
2. number of hard links.
3. owner
4. owner group
5. file size in bytes.
6. modification time
7. file name.

## determining a file's type with file

```=
file {filename}
```
* in Linux everything is a file.

## viewing file contents with less

```=
less {filename}
```
* open a file using `less`

```=
b
space
```
* pager for `less`

```=
G
g
```
* fast pager for `less`

```=
/char
n
N
```
* search for `less`
* navigate occurrence

```=
q
```
* quit `less`

### what is text
* computer only understand numbers.
* In order to represent text, a map from number to char needs to be defined.
* Simple map is called *ASCII*

### less is more
`less` is designed to replace an old UNIX program called `more`

## a guided tour
* do not be afraid to look at files.
* there is no secret in Linux

## symbolic links
* a symbolic link is a pointer to a file link (hard link)
* it acts like the real file except it updates with the real file link.

```=
symbolic link -> hard link -> memory buffer
```

## hard links
* it can also have multiple instances pointing directly to the memory buffer of the file.

# manipulating files and directories
command line makes difficult jobs easy

```=
cp -u *.html {directory}
```
* copy all `html` file into `{directory}`
* replace the file is it is older than the current one. otherwise takes no action (update).

## wildcards
* `*` : any number of any character
* `?` : any single character
* `[...]` : anything inside the braces.
* `[!...]` : anything not inside the braces
* `[[:class:]]` : any single character belongs to the character class.

```=
[:alnum:]
[:alpha:]
[:digit:]
[:lower:]
[:upper:]
```
* some character classes.
* it expands to all characters in the class.

### character ranges
* old unix uses ranges like `[a-z]` 
* they don't always work in Linux, use character class instead.

### wildcards work in the gui too

## mkdir - create directories

```=
mkdir dir1 dir2 dir3
```
* space is not allowed unless escaped.

## cp - copy files and directories
1. two arguments
```=
cp arg1 arg2
```
* copy `arg1` into `arg2`
* if `arg1` is a directory, then you needs to specify `-r`
* if `arg2` is a filename, it will renamed to that file name.

2. more arguments
```=
cp arg1 .... argn
```
* `argn` needs to be directory
* copy all `args` into `argn`

### useful options and examples

```=
cp -r
```
* recursive copy all contents of a directory
* if omitted, directories are not copied.

```=
cp -u
```
* update.
* copy only if file is newer or not existant.

```=
cp -v
```
* display more info (verbose)

## mv - move and rename files
it is very similar to `cp`
1. two arguments

```=
mv arg1 arg2
```
* move `arg1` into `arg2`
* if `arg1` is a directory, then you needs to specify `-r`
* if `arg2` is a different filename, it will be moved and renamed to that file name.

2. more arguments
```=
mv arg1 .... argn
```
* `argn` needs to be directory
* move all `args` into `argn`

### useful options and examples

```=
mv -i 
mv -u
mv -v
```
* `-i` shows an alert when overwrite another file.
* `-u` will update the file.
* `-v` will show more information.

## rm - remove files and directories

```=
rm f1 f2 f3 ...
```
### useful options and examples

```=
rm -i
rm -r
rm -f
rm -v
```
* `-i` alert user 
* `-r` removes all contents in directory, it is required to remove directory with contents.
* `-f` ignore non-existant files
* `-v` shows more information.

### be careful with rm!
there is no undo command for remove command.
especially be careful with wildcards

```=
rm * .html
```
* remove **everything!** in the current directory
* after that, bash will complain there is no `.html` file.

## ln - create links
### hard links
hard link is the original Unix way of creating links.
it has a lot of limitations.
* must be reference the file with same disk partition.
* cannot reference directory

```=
hardlink = file // in may ways.
```
* hard links is not distinguishable with files when listing.
* you need to delete all hardlink to delete a file.

### symbolic links
symbolic does not points to actual memeory location, it contains a text pointer to a file or directory.

## let's build a playground
### creating directories

```=
cd 
mkdir playground
cd playground
mkdir dir1 dir2
```

### copying files

```=
cp /etc/passwd .
cp -v /etc/passwd .
cp -i /etc/passwd .
```

### moving and renaming files

```=
mv passwd fun
mv fun dir1
mv dir1/fun dir2
mv dir2/fun .
mv dir1 dir2
mv dir2/dir1 .
mv dir1/fun .
```

### creating hard links

```=
ln fun fun-hard
ln fun dir1/fun-hard
ln fun dir2/fun-hard
```
* at this stage, if you list the files, you will find there are **4** hard links for the file `fun` and `fun-hard`
* they are the same and not distiguishable.

```=
ls -li
```
* `-i` is `innode`, it referes to the file disk entry nodes.
* in this way, we know `fun` and `fun-hard` points to the same file.

```=
2361180 -rw-r--r-- 4 rock-mechanics rock-mechanics   19 2月  17 13:07 fun
2361180 -rw-r--r-- 4 rock-mechanics rock-mechanics   19 2月  17 13:07 fun-hard
```

### creating symbolic links

```=
ln -s {hardlink or directory} {symbolic}
```
#### absolute path vs relative path
* the link can be made relative or absolute 

```=
ln -s ../fun dir1/fun-sym
```
* in `dir1`, it references a hardlink called `fun` in its parent's directory

```=
ln -s ~/Desktop/tester/fun dir1/fun-sym
```
* it always points to the hardlink in absolute path.

### removing files and directories

```=
rm fun-hard
rm -i fun
less fun-sym // an error will pop up since the file is gone.
rm fun-sym
rm -r tester
```
### creating symlinks with the gui
* it is very similar to windows shortcuts, but it is way ahead of it.

# working with commands
## what exactly are commands
1. executable program
	* compiled binaries
	* scripts written by scripting languages
2. command built into shell
3. a shell function, small shell scripts saved into environment
4. an alias, command defined by user, built from more primitive commands

## identifying commands
### type - display a command's type

```=
type {command}
```
* which of the four types does this command belongs to 

### which - display an executable's location

```=
which {command}
```
* it works for executable program (first type)

## getting a command's documentation
### help - get help for the shell builtin

```=
help {command}
```
* `[]` denotes optional item
* `|` denotes mutually exclusive items.
* it only works for shell built-ins.

### --help - display usage information

this is implemented per command base by the program designer

```=
command --help
```

### man - display a program's manual page

* man is a formal documentation for command line programs.
* many program provides such documentation.

```=
man program
```
* man usually use the progam `less` to display the page

### apropos -display appropriate commands

```=
apropos {some keywords}
```
* search the list of manpages for the keywords.
* if you have an idea what the command is doing, but have no idea exactly what is the command, you may search for it use `apropos`

```=
man -k {some keywords}
```
* it is the same as `apropos`

### whatis - display a very brief description of a command

```=
whatis {command}
```
* it will displayed in one line.

### the most brutal man page of them all
* man page is served as references, not tutorials, so it is hard to read.

### info - display a program's info entry

```=
info {program}
```
* GNU projects provide alternative man page with hypelinks.
* it can be viewed using the `info` command

### readme and other program documentation files
* many program put their documentaion in 

```=
/usr/share/doc
```
* for file with `.gz` extension, it has been compressed.
* view it using a program called `zless`

## creating your own commands with alias

```=
command1 ; command2 ; command3
```
* call a series of commands in one line.

### workflow
1. pick a name and use `type {name}` to see whether it is used.
2. create commands using the name

### commands

```=
alias foo="cd /usr; ls; cd -"
```
* go to `usr` folder , list the content, and come back.
* its life span is the terminal session.

```=
unalias foo
```
* unlink foo with all these commands

```=
alias
```
* list all alias for the system.

## further reading
* bash reference manual

# redirection
## standard input, output and error

everything is a file.

* stdin : a file that a program reads
* stdout : a file that a program generates
* stderr : a file that a program prints some status or error messages

## redirecting standard output

```=
{command} > {filename}
```
* redirect the stdout to a file

```=
{command} >> {filename}
```
* redirect the stdout to a file
* without overwriting a file, but append to the end of file.

## redirecting standard error

```=
{command} 2> {filename}
```
* redirect the stderr to a file

### redirecting standard output and error to one file

```=
{command} > {filename} 2>&1
```
* `&` can be seen as the address of the stream 1 which is the stdout

```=
{command} &> {filename}
```
* new operator to redirect both stdout and stderr.

```=
{command} &>> {filename}
```
* new operator to redirect both stdout and stderr.
* append instead of overwrite

### disposing of unwanted output

```=
ls -l /bin/usr/ 2> /dev/null
```
* `/dev/null` accepts a input and do nothing with it.
* this command generates an error,and it is sent to the bit bucker, and will not print on screen.

## redirecting standard input
### cat -concatenate files

```=
cat file1 file2 ...
```
* it combine these files to stdout and then print them on screen by default.

```=
cat files* > file
```
* combine multiple file into one file.

```=
cat
```
* it will wait for keyboard input as stdin
* `ctrl-d` is used to finish the typing.

```=
cat > file
```
* wire the stdout to a file and call `cat`.
* it will wait for input and sends it to the file when pressed `ctrl-d`

```=
cat < file
```
* wire a file to the stdin of `cat`

## pipelines

```=
command1 | command2
```

### filters

```=
cmd1 | cmd2 | cmd3 ...
```
* command used in this way is called `filter`

```=
ls /bin /usr/bin | sort | less
```
* list two directories into a sorted file stream then use `less` to page it.

### uniq - report or omit repeated lines
* `uniq` accepts a **sorted** list, and it removes dumplicates from the list, after that it sends the filtered list to stdout
* `uniq` uses binary search to detect dumplicates, that's why it needs to take a sorted list.

```=
command | sort | uniq
```
* getting input from stdin

```=
uniq sorted-file
```
* getting input from a file 

```=
uniq -d sorted-file
```
* show only dumplicates

### wc - print line, word, and byte counts
wc count number of lines, words and bytes. it can take two kinds of arguments
1. stdin
2. file

```=
command | wc 
wc file
```

#### arguments

```=
wc -l
wc -w
wc -c
```
* by default, all lines, words , bytes count will be displayed, if controlled by argument, only certain result is displayed.


### grep - print lines matching a pattern

```=
grep {pattern} file1 file2 file3 ...
command | grep 
```
* grep run across multiple files and take out lines containing certain patterns.
* grep can take inputs from both `stdin` and `file`
* it will print the selected **lines** to stdout

#### arguments

```=
grep -i 
```
* ignore case

```=
grep -v
```
* inverse the grep

### head/tail - print first / last part of files

```=
command | head 
command | tail
head file
tail file
```
* head/tail display the first/last ten lines.
* they can take inputs from `stdin` as well as `file`
* the result is directed to `stdout`

#### arguments

```=
head -n {number}
tail -n {number}
```
* change the default behavior of displaying 10 lines. display `{number}` lines.

```=
head -f file
tail -f file
```
* monitor mode, keeping the screen updated once the file is changed.
* use `ctrl - c` to exit the monitor session.

### tee - read from stdin and output to stdout and files
`tee` takes `stdin`, direct it into two destination
* a file
* `stdout`

```=
command1 | tee file | command2
```
* takes the input from command1
* `tee` saves the output to file
* `tee` saves the output to command2

# seeing the world as the shell sees it
## expansion

```=
echo arg1 arg2 ...
```
* shell will expand the args according to certain rule before executing command
* `echo` just echo the input. which is the text **after** expansion.

### pathname expansion
```=
echo *
```
* `*` expands to all file names (**including directory names**) in the current working directory.
* multiple spaces are omitted, so the default format is not working.
* expansion result will be auto-sorted.
* `*` by default does not reveal hidden files.

```=
ls -d .*
```
* list all hidden files including the `.` and `..`
* this is usually not the ideal result for hidden files.

```=
ls .[!.]*
```
* list all files containing more then two character
* the first character is a `.`
* the second character is not a `.`
* precise way to list all the hidden files.

```=
echo ~
```
* `~` expands to the home address of current user.

```=
echo ~user
```
* `~user` expands to the home directory of the user `user`

### arithmetic expansion

```=
$((expression))
```
* this will expands to the result of the expression

```=
+ - * / % **
```
* supported computation
* the precedence of computation is same as arithmetic calculation.

### brace expansion

```=
{item1,item2,item3...}
```
* expands to all single items in the braces.
* there is no space inside the pattern.

```=
echo {01..15}
echo {001..15}
```
* there is **no space** around the `..` which defines a range
* the format (preceding zeros) will be respected.

```=
echo thisis-{A..Z}-letter
```
* brace expansion can include preamble and postscript

### parameter expansion
parameter or variables will expands to its content during parameter expansion

```=
$variable-name
```
* expands to the variable content.

```=
echo $USER
```
* expands to user variable, in my case it is `rock-mechanics`

### command expansion
command expansion takes a command, and expands to its output.

```=
$(command -option argument)
```

```=
ls -l $(which cp)
```
* `$(which cp)` expands to `/usr/bin/cp`
* `ls -l /usr/bin/cp` list in detail about the program

### history expansion
```=
history
!{line-number}
```
* show the history
* expands to the command in n-th line of the history file (search forward to the details section on history)

## quoting

* `$ ~` are special characters in arguments.
* extra space will also be omitted in arguments.
* quoting is used to prevent these special characters from expansion.

### double quotes
all special characters lose their meaning except
1. `$` will expand
2. `\` will escape
3. \` will expand
* \` is an alternative syntax for command substitution like `$(command)`
* since `$` will expand, expansion using this will continue to work, so paramter, arithmetic, command expansion all work.

```=
echo "$USER $((2+2)) $(cal)"
```
* `$USER` is parameter expansion
* `$((2+2))` is arithmetic expansion
* `$(cal)` is command expansion
* double quoted argument will be taken as a single argument.

### single quotes
**all** special characters loose their special meaning, shell takes the input as pure string without expanding it.

### escpating characters
`\` can escape one character from expanding. so we don't need to put quotes

```=
echo this is \$5.00
```

### backslash escape sequences
`\` is used to represent control codes.

```=
echo -e arguments
```
* echo the arguments, and watch for escape sequences

```=
\a
```
* alert, ring a bell

```=
\b
\n
\r
\t
```
* backspace, newline, return and tab

## summing up
it will be used more frequently, it is very important to understand how expansion works.
1. pathname expansion
2. arithmatic expansion
3. command expansion
4. brace expansion
5. history expansion

# advanced keyboard tricks
## command line editing
bash uses a library called `readline` to implement command line editing.
### cursor movement

```=
ctrl - a
ctrl - e
```
* a means ahead, move to the beginning of the line.
* e means end, move to the end of the line.

```=
ctrl - f
ctrl - b
```
* f means forward, move the cursor forward one character
* b means backward, move the cursor backward one character

```=
alt - f
alt - b
```
* forward by word
* backward by word

### modifying text

```=
alt - l
alt - u
```
* change case from cursor to the end of line.
* `-l` to lower
* `-u` to upper

```=
ctrl - d
```
* delete the character at cursor position.

```=
ctrl - t
alt - t
```
* transpose the character with the previous one
* transpose the word with the previous one.

### cutting and pasting (killing and yanking) text
in readline, cut is called kill and the content is saved in a buffer called `killing`

```=
ctrl-k
ctrl-u
```
* kill to the end of line from the cursor
* kill to the beginning of line from the cursor

```=
ctrl-y
```
* yank the text from the killing buffer.

```=
alt-d
alt-backspace
```
* word wise killing
* `alt-d` kills to the end of word from the cursor
* `alt-backspace` kills to the beginning of a word from the cursor.

### the meta key
* after unix and before pcs, there is one large computer, and everybody only have a device called `terminal` which consists of
	1. screen
	2. keyboard
* meta key is invented because the developer does not know what extra key each different keyboard may have
* in modern pc, it is mapped to the `alt` key.

## completion
* `tab` key is used to auto complete keywords and variables

```=
alt - ?
```
* inspect all possible completions

### programmable completion
* bash may include addtional rules for auto-completion
* for example option list of a command
* it is implemented using shell functions.

## using history
list of history commands is kept at a file in the home directory

```=
.bash_history
```

```=
history
```
* shows the all the history commands.

```=
!{line-number}
```
* history expansion, it will expands to the command on the n-th line of the command history.

```=
c-r
```
* start increamental search in real time
* you may type and the result will refine by itself.

# permissions
* more than one person can use the computer at the same time.
* remote users can attach a terminal to the netowrk to operate on the pc. the output will be displayed in the remote screen.
* computer needs to take care of different users, so they don't mess up with each other.

## owners, group members, and everybody else
* user can own files.
* user can create a group and grant rights to this group of people
* user can grant rights to everybody using this computer.

```=
$ ls -l /etc/shadow
-rw-r----- 1 root shadow 1287 Jan 30 02:19 /etc/shadow
```
* `root` owns this file
* `root` created a group called `shadow`

```=
id
uid=1000(rock-mechanics) gid=1000(rock-mechanics) groups=1000(rock-mechanics)
```
* check userid, groupid
* `uid` is the userid, it is created when user account created.
* `gid` is the primary group id, you are born here.
* `groups` is the groups the user may belongs to, you have lived there.

```=
/etc/passwd
```
* file contains user account information.

```=
$ sudo cat /etc/passwd | grep rock
rock-mechanics:x:1000:1000::/home/rock-mechanics:/bin/bash
```
* colon seprated values.
* `username : password : uid : gid : uid-info : home-directory : shell`
* password is `x`, means it is encrypted and stored in `/etc/shadow/` directory.

```=
/etc/group
```
* file contains group information.

```=
$ sudo cat /etc/group | grep rock
lp:x:7:rock-mechanics
sudo:x:27:rock-mechanics
users:x:100:rock-mechanics
netdev:x:109:rock-mechanics
lpadmin:x:117:rock-mechanics
scanner:x:120:rock-mechanics
sambashare:x:123:rock-mechanics
rock-mechanics:x:1000:
```
* colon separated values
* group name : password : gid : other group members
* for `rock-mechanics`, there is no other group members, only the owner.
* `rock-mechanics` user is also a member for other groups listed.

```=
/etc/shadow
```
* file containing all the passwords

```=
sudo cat /etc/shadow | grep rock
rock-mechanics:$6$og7ZuH3owR0828QA$s2yyi4T2Iu/KOUKGt.8YrzJo9AYdhqHGJjTjehrrg8Hqudc1c5DP3RPD93btoTJbDVib88.ovivUxARf/2pVJ1:18656:0:99999:7:::
```
* colon separated value
* `rock-mechanics` : user name
* `$6$og....` : hashed password
* `18656` : the day you changed your password
* `0` : min days required for you to be able to change password
* `99999` : max days then you must change the password
* `7` : number of days system will warn you before your password expire.

## reading, writing, and executing

```=
$ > test
$ ls -ld test .
drwxr-xr-x 4 rock-mechanics rock-mechanics 4096 Feb 24 17:00 .
-rw-r--r-- 1 rock-mechanics rock-mechanics    0 Feb 24 17:00 test
```
* `d` stands for directory, `-` stands for regular file, `l` stands for link
* `rwx` is `read write and exectue`
* for regular files, `rwx` is normal meaning
	* `r` is reading the content of the file.
	* `w` is writing the content of the file.
	* `x` is executing the file as a program.
* for directory
	* `x` means enter directory, it is basic for other rights
	* `r` is read the content of directory, which is `ls` the directory
	* `w` is modifiying the directory structure, including add/remove/rename files.

### `chomod` to change file's mode
#### using oct mode to change the file's mode

```=
chmod 600 foo.txt
```
* you need to specify the file modes for owner, group, and everyone else.
* `6` in binary is `110`, it is the same as `rw-`
* `0` in binary is `000`, it is the same as `---`
* the `foo.txt` now has the permisson as `rw-,---,---`


```=
$ > foo.txt
$ chmod 600 foo.txt
$ ls -l foo.txt
-rw------- 1 rock-mechanics rock-mechanics 0 Feb 24 17:22 foo.txt

```
#### using symbolic mode to change the file's mode

```=
chmod u+x foo.txt
chmod g+r foo.txt
chmod o+r foo.txt
```
* `u` stands for user/owner
* `g` stands for group 
* `o` stands for others
* `a` stands for all

```=
chmod u-x foo.txt
chmod a=r foo.txt
chmod u=rw foo.txt
chomd u+x,a+r foo.txt
```

#### `umask` set default permissions
umask mask the bits when creating a new file. it uses a number to determine what permission to mask/shadow to false

```=
original file mode -> mask -> final file mode when created
```
* the process of determine file modes for newly created files.

```=
rw-, rw-, rw-
```
* default file modes.

```=
umask
0022
```
* it shows the curren `umask` value.
* starting from second bit.
* `0` is `000`, there is no mask for the `rwx`
* `2` is `010`, which mask the `w` bit.
* new created file will have rights `rw-, r--, r--`, the `w` bit is masked by `umask`

```=
umask 0000
```
* change `umask` to `0000`, there is no mask bits on.
* newly created file will have rights `rw-, rw-, rw-`

##### `umask` : the first bit : special permissions

```=
4
```
* in binary it is `100`
* setuid
* when assigned to a program, any user run this program will wear a jacket of the user (pretend to be the user).

```=
2
```
* in binary it is `010`
* setgid
* when assigned to a program, any user run this program will wear a jacket of the group (pretend to be the group member).

```=
1
```
* in binary it is `001`
* sticky bit
* when assigned to a directory, unless you are the owner of this directory, it is not allowed to delete and rename files of this directory
* normal user can only plus the content of the folder, but not able to minus the content of the folder.


## changing identities
### become another user

```=
su -l user-name
```
* start a new shell as a different user
* `-l` means login shell, switch home directory
* `exit` will return to your normal shell.

### become the super user

```=
sudo su -
```
* it starts a new shell as root user
* home directory is changed to `/root/`
* shell prompt is changed from `$` to `#`
* return to normal shell using `exit`

```=
sudo su -c 'command in single quotes'
```
* pass the command to root shell to execute and return back.
* single quotes is to prevent expansion in the current shell.

## `sudo` execute command as another user
```=
sudo command
```
* use your own password to login
* use your own shell as root.
* can be configured what you can do from super user.

```=
/etc/sudoers
```
* the file contains all settings for users that can execute sudo

### `chown` to change the owner of a file

```=
sudo chown {ownername}:{groupname} foo.txt
```

```=
$ ls -l foo.txt
-rw-r--r-- 1 rock-mechanics rock-mechanics 0 Feb 24 17:41 foo.txt
$ sudo chown root:root 
$ ls -l foo.txt
-rw-r--r-- 1 root root 0 Feb 24 17:41 foo.txt

```

## exercising our privileges
## changing your passwords

```=
passwd
```

# processes
## how a process works
when system starts up, the kernal will 
1. start a few program itself as processes
2. start a program called `init`
3. the `init` program runs a series of scripts in `/etc/` folder, which starts all the system services.
4. each process has been assigned a unique `pid`, its memory has been recorded by the system, so 
	* it could be stopped at any given time
	* it could be resumed to its state at any time.

## viewing processes

```=
ps
```
* list all the running processes controlled by the current terminal

```=
ps x
```
* list all the running processes regardless of the control terminal

```=
ps aux
```
* list all process by all the user

### Attributes of process

```=
TTY
```
* it is short for `teletype`, refering to the controlling terminal of the process.
* an `?` in the `TTY` attribute means the process has no controlling terminal.

```=
STAT
```
* it is short for `status` which shows the status of the process
* `R` means process is running or ready to run
* `S` means sleeping
* `*s` means leading process
* `*N` means nice process (low priority)
* `*<` means high priority process
* `*l` means multi-thread process
* `*+` means foreground process

```=
%MEM
```
* memory use percentage

```=
%CPU
```
* CPU usage percentage

```=
VSZ
```
* virtual memory size

```=
RSS
```
* residual (actual) memory size

```=
START
```
* time when process started

### view process dynamically with `top`
`top` shows a bunch of infomation and most recent processes (top process)

```=
top - 07:00:44 up  1:31,  0 users,  load average: 0.97, 1.85, 2.08
Tasks:  18 total,   1 running,  17 sleeping,   0 stopped,   0 zombie
%Cpu(s):  0.8 us,  0.0 sy,  0.0 ni, 99.2 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
KiB Mem :  2000000 total,  1876104 free,    80364 used,    43532 buff/cache
KiB Swap: 41943036 total, 40752636 free,  1190400 used.  1919636 avail Mem 
```
* `top` : is the name of the program
* `07:00:44` : is the current time of the day
* `up 1:31` : system has been on for 1:31 hours
* `0 users` :  there is no users currently
* `load average` : 0.97, 1.85, 2.08` : number of process waitting for last 1, 5, 15 minutes
* `%Cpu(s): 0.8us` : 0.8% of the cpu is used by user process
* `0.0 sys` : 0% of the cpu is used by system process
* `0.0 ni` : 0% of the cpu is used by nice process
* `0.0 wa` : 0% of the cpu is used by waiting process (process waiting for io input)
* `Mem` : physical memory
* `Swap` : virtual memory

## controlling processes
### interrupting the process

```=
ctrl-c
```
* interrupt means politely ask the program to terminate
* most program can be interrupted in this manner

```=
{program-name} &
```
* start a program and put it in the background

```=
jobs
[1]+ Running xlogo &
```
* list the running processes
* `[1]` is the job number
* `Running` is the status of the process
* `xlogo &` is the name of the process

```=
fg %{job-number}
```
* bring the process to the foreground
* `%{job-number} can be omitted if there is only one job in the job control center.

```=
ctrl-z
```
* pause(stop) the process and put it in the background

```=
bg %{job-number}
```
* move a stopped process in the background

### why start a graphical program from command line
1. there may not be gui for the program (no buttons)
2. we can lauch interesting command line `options` when we lanuch graphic program from command line

## signals

```=
ctrl-c
```
* terminal send a `INT` signal to the program

```=
ctrl-z
```
* terminal send a `TSTP` (terminal stop) to the program

### why signals
program can do certain clean up work when received with some signals such as terminate

### sending other signals

```=
kill -{signal} {process-id}
kill -{signal} {job-number}
```
* sending a signal to a process

```=
kill {process-id}
kill -TERM {process-id}
```
* send a terminate signal to the process
* default behavior without specifying the options

```=
kill -INT {process-id}
```
* send a interrupt signal to the process
* different program perceive this in different way. most program will just termiate

```=
kill -KILL {process-id}
```
* kill the process immediately by the kernal
* no clean up work is possible

```=
kill -TSTP {process-id}
```
* send a terminal stop signal to the process
* same as press `ctrl-z`
* program may ignore it after recieve this signal

```=
kill -STOP {process-id}
```
* stop the process without terminating
* program must stop when receiving this signal

```=
kill -CONT {process-id}
```
* continue a stopped process

### view all the possible signals

```=
kill -l
```
### sending signal to multiple processes

```=
killall -{signal} name1 name2..
```

## more process related commands

```=
pstree
```
* show parent-child relationship for all process

```=
vmstat
vmstat -n
```
* stands for `virtual memory statistics`
* it shows the resource usage of the system
* using an option of `n`, we can see a snapshot of resource usage every `n` seconds.

# Chapter 11 : The environment
when we start a shell session, the shell maintains a body of information called the `The Environment`
the program will ususally be customized through two information
1. configration file
2. the environment

## what is stored in the environment
1. environment variable
2. shell variable (this data is placed by bash)
3. aliases
4. shell functions

### examine the environment

```=
set
```
* print both shell and environemnt variables

```=
printenv | less
```
* print environment variables.

```=
printenv {var-name}
```
* print certain values of the variable

```=
alias
```
* show the list of alias that the shell is using.

### some interesting variables

```=
EDITOR
SHELL
HOME
LANG
PAGER
PATH
PS1
TERM
TZ
USER
```
### how is the environment established
1. when the bash starts, it will read some `start up` files to establish the environment for all users
2. it will then reads some personal configration file to personalize the environment for the current user.

### login shell
login shell requires user to login to use the shell (for example, virtual shell)

```=
/etc/profile
```
* for all users

```=
~/.bash_profile
```
* for the current user.

```=
~/.bash_login
```
* back up file if `~/.bash_profile` not found

```=
~/.profile
```
* back up file if `~/.bash_login` not found

### non-login shell
non-login shell is the normal shell we use through various of terminals. we don't need a password to access the shell
* it is usually started by a login shell
* it will inherit the environment from its parents.

```=
/etc/bash.bashrc
```
* for all users

```=
~/.bashrc
```
* for the current user.

### what is in a startup file

```=
#....
```
* this is a comment

```=
if ...
   ...
fi
```
* if block

```=
PATH=$PATH:$HOME/bin
```
* change the content of the variable.
* `:$HOME/bin` will be appended to the content of the variable.
* the `PATH` variable is a colon seprated value list, so we need to append ` : something`

```=
export PATH
```
* make this path available to its child process.

## modifying the environment
### which file should we modify
the idea is to keep your personal setting in your home directory without causing problems for other users.

```=
~/.bash_profile
```
* this file is for customization for login shell

```=
~/.bashrc
```
* this file is for customization for non-login shell


### text editors
### using a text editor
### why comments are important
### activating our changes

```=
source ~/.bashrc
```

## Chapter 12 : An gentle introduction to vi
## Chapter 13 : Customizing the prompt

```=
echo $PS1
```
* check the prompt string 1 environment varible.
* this variable controls the appearance of the prompt

### prompt string content
1. escape sequence `\x`. which has special meanings.

```=
\u
\w
\h
\$
\!
\#
\a
\A
```
* `\u` is the user name
* `\w` is the current working directory
* `\h` is the host computer name
* `\$` is the prompt character, it will be displayed as normal `$`, if the user is root, it will be displayed as `#`
* `\!` is the history number of the current command
* `\#` is the number of commands you have entered during the current shell session.
* `\a` is bell ring
* `\A` is the current time in hour:min format

2. controlling characters 

```=
\[....\]
```
* controlling characters does not print, the bash will ignore these characters when calculating the length of the prompt.

* it is used for manipulate the output such as 
	1. moving the cursor
	2. change the color of the text
	3. include other non-print characters.

3. text literals
* the actual text that will be displayed in the terminal prompt.

### Adding color
* this is done using non-print controlling characters
* it should be enclosed in `\[ .. \]` to indicate they are controlling non-print controlling characters.
* the standard is developed by ANSI to cater for too many different types of terminals.

```=
\033
```
* indicate this is a color changing command

```=
[x;
```
* there are two values to be included
	1. 0 : dark color 
	2. 1 : light color
	3. 4 : underscore
	4. 5 : blinking

```=
3xm
```
* specify the color of the text 
* `0` is black group
* `1` is red group
* `2` is green group
* `3` is yellow group
* `4` is blue group
* `5` is purple group
* `6` is cyan group
* `7` is white group
* there is a special code `0m` which signify the return of previous color

```=
4xm
```
* specify the color of the background color

```=
\[\33[0;31m\]
```
* a complete compound string siginfing change the color to red.

```=
\[\33[0;41m\]
```
* a complete compound string siginfing change the background-color to red.

```=
\[\033[0m\]
```
* a complete compound string siginfin return to previous color

### moving the cursor

```=
\033[{move-command}
```
* overall format to move the cursor

### move-commands

```=
s
```
* store the current cursor position in a buffer.

```=
u
```
* resume the cursor position from the buffer

```=
K
```
* clear the cursor position to the end of the line
* this removes any characters that is printed on the screenn before.

```=
{number}A
```
* move the cursor up n line.

```=
{number}B
```
* move the cursor down n line.

```=
{number}C
```
* move the cursor forward n characters

```=
{number}D
```
* move the cursor backward n characters

```=
2J
```
* move the cursor to the upper left corner.

```=
{number1},{number2}H
```
* move the cursor to line number1 and coloumn number2

```=
1,1H
2J
```
* these two commands are equivalent

## Chapter 14 : Package Management
### what makes a linux distribution good
* package system
* vitality of the support community

### what is a package system
* a method of installing and maintaining softwares on the system.

### packaging systems families
1. debian style (.deb)
2. redhat style (.rpm)

### package files
* a compressed file that consists of the body of the progrma
* it will also comes with the meta data of the prorgram
* sometimes it comes with cofigration scripts before and after the installation of the software.

### how package files are made
* they are usually made by package maintainer
* the package maintainer will get and compile the source code, add meta data and pre and post configrations.

### repositories
* a collection of packages.
* it is common for the distribution to maintain several different repositories and include third-party repositories.

### dependencies
* some program requires program component from a shared library.
* package management tool will do the dependencies resolution to make sure all the dependencies are installed when the program is installed.

### high and low level package tools
1. low level tools
	* installing package files
	* for debian family, it usually use `dpkg`
	* for redhat family, it usually use `rpm`
2. high level tools
	* searching meta data
	* dependency resolution
	* for debian family, it usually use `apt-get` and `aptitude`
	* for redhat family, it usually use `yum`

### common package management tasks
#### finding a package in a repository

```=
apt-get update
apt-cache search {string}
```
* `apt-get update` updates the fetching lists
* `apt-cache search` search the string from the package list.

#### installing a package from a repository

```=
apt-get update
apt-get install {package-name}
```
#### download a package from the repository

```=
apt-get download {package-names}
```
* it will downloaded to the current directory
* you may provide multiple names in one go.

#### installing a package from a package file

```=
dpkg --install {package-file}
```
* this method is applied after the package file has been downloaded.
* it will search for Internet for dependencies, so most of time an Internet connection is compulsory

#### remove a package

```=
apt-get remove {package-name}
```

#### updating a package from a repository

```=
apt-get update
apt-get upgrade
```
* `apt-get update` retreive a new list of packages from the repo
* this info is stored in cache.

#### display info about an installed package

```=
apt-cache show {package-name}
```
* get the information about an installed package.
* it will read the cache, so better perform an update before make the query.

#### updating a package from a package file

```=
dpkg --install {package-file}
```

#### list installed package

```=
dpkg --list
```

#### determine if a package is installed

```=
dpkg --status {package-name}
```

#### determine other files belongs to the same packages.

```=
dpkg --search {file-name}
```

## Chapter 15 : Storage Devices
## Chapter 16 : Networking
## Chapter 17 : Searching for files
### `locate` : find the file in the easy way

```=
locate /bin/zip
```
* find all path names containing `*/bin/zip*`
* it performs a rapid database search
* the database is updated periodically.

```=
dbupdate
```
* update the database manually.
* this ensure `locate` can find the most recent files.

### `find` : find the file in the hard way.

```=
find {directory} {pattern}
```
* this lists all the files in the directory matching the pattern
* if {directory} is omitted, it defaults to the current directory
* if {pattern} is omitted, it defaults to all files

```=
find {tests or actions} {options}
```
* using `tests` to filter the path name further
* using `actions` to do action on the selected pathname(the file)
* using `option` to change the scope of the find search.

```=
{test or action} -and {test or action} -or {test or action} -not {test or action}
```
* combine `test` and `action` in the logical way.
* it executes from left to right
* we can include `\( ...\)` to change the sequence.
* if the operator omitted, if defaults to `-and`
* operators are evalued in the shortcut manner.

#### tests
1. type test
	* `-type f` : regualr file
	* `-type d` : direcotry
	* `-type l` : symbolic link
2. name test
	* case senstive : `-name {wildcards}`
	* case insenstive : `-iname {wildcards}`
3. size test
	* `-size n`
4. modification time test in minutes
	* `-cmin n` : changed in minutes including file attributes
	* `-mmin n` : modified in minutes only refer to file content.
5. modification time test in days.
	* `-ctime n` : change in days 
	* `-mtime n` : modification in content in days.
6. modification comparison with a file
	* `-cnewer {file}`
	* `-newer {file}`
7. ownership test
	* `-user {user-name}`
	* `-group {group-name}`
	* `-nouser`
	* `-nogroup`
8. permission test
	* `-perm xxxx` 
9. empty file test
	* `-empty`
10. inode number test
	* `-inum {number}`
	* `-samefile {filename}` : finds file with same inode number with selected file.
11. reverse test
	* `-not {test}`

#### actions
##### pre-defined actions
1. `-print` : print selected filepath (default if omitted)
1. `-delete` : delete selected file
1. `-ls` : perform a long list for the selected file to inspect its properties.
1. `-quit` : quit find once found the file.

##### user-defined actions

```=
-exec {command} '{}' ';'
```
* fire the command at every instance of the filepath that meets the tests.
* `'{}'` represents the current filepath that matches the tests
* `';'` indicate the end of the command.
* they are both single quoted to prevent expansion.

```=
-ok {command} '{}' ';'
```
* fire the command at every instance of the filepath that meets the tests
* ask for confirmation each time.

##### improve the efficiencies

```=
find ~ -type f -name "foo*" -exec ls -l '{}' ';'
```
* find the file, and each time a file is found, fire a `ls -l` command.
* this is not very efficient.

```=
find ~ -type f -name "foo*" -exec ls -l '{}' '+'
```
* find the file, accumulat the path. at the end, we fire the `ls -l` commands for all the paths.
* this creates a space sperated argument lists it then feeds the `ls -l` command.
* bad file names containing space will be quoted.

##### turn stdin to argument list.

```=
xargs {command}
```
* the keyboard input will become the arg list.
* use `c-d` to terminate the input.

```=
{command1} | xargs {command2}
```
* `|` turns the stdout of command1 to stdin of xargs
* xargs convert the stdin to argument list for command2
* it creates space seprated argument list.

```=
find ~ -type f -name "foo*" | xargs ls -l
```
* xargs parse the stdin using spaces, then will encouter problem if the file name contains space.
* filename containing space will be treated as two different files.

```=
find ~ -type f -name "foo*" -print0 | xargs --null ls -l
```
* print a null character at each filepath
* use null character as delimiter for the arguments.
* this will handle all the bad file names cotaining spaces.

#### options

```=
-depth
```
* process files before directory.
* this is auto applied when using `-delete` action, because otherwise delete a directory with files will fail.

```=
-maxdepth n
```
* go down the tree from directory n levels and stop search.

```=
-mindepth n
```
* go down the tree from directory n levels then start search.

```=
-mount
```
* not to search other file systems

```=
-noleaf
```
* find non-unix file systems such as MS-DOS or CD

## Chapter 18 : Archiving and Backup
### compressing files
#### what is compression
remove dedundency and optimize the data storage space. the data will be restored to its original state
* lossless compression : the recovered data is exactly the same with original
* lossy compression : the recovered data is a close approximation.
#### gzip
* lossless compression program.
* replace original with compressed version.

```=
gzip options orignal-files
```
* compressed each file to `file-name.gz`
* used the compressed file to replace original files

```=
gzip -c files
```
* compresse each file and send the compressed file lists to `stdout`
* original files are untouched.

```=
gzip -f files
```
* overwrite the `.gz` files even they are already exist.

```=
gzip -l files
```
* list statisics for each compressed file.

```=
{command} | gzip > file
```
* takes stdin. compressed stdin, and save it in a compressed file.

```=
gunzip file.gz
gunzip file
```
* uncompress a file, `.gz` can be omitted.

```=
gunzip -c file.gz ..
```
* send the uncompressed file to stdout.
* a similar program called `zcat`, which perform the same thing.

#### bzip2
* higher compression rate
* lower speed
* its usage is almost identical as `gzip`

### archiving files
#### what is archiving 
archiving is turn many files into one big file for easy storage.
#### tar
* its name is derived from `tape archive`, which helps program early days to save data on the tape.

```=
tar mode[options] files-to-archive
```
* mode comes before options.

##### mode

```=
tar c files
tar x files
tar r files
tar t files
```
* c is for create, creat the `.tar` file, it will overwrite the file if the `tar` file existed.
* x is for extract
* r is for append, it will append to `tar` file if it exists, otherwise creat a new `tar` file.
* t is for tabulate, show the content of the `.tar` file without touching the original file.

##### options

```=
f {tar-name}
```
* specify the name of the tar archive.
* tar can receive file from stdin, we just need to specify `f -`

```=
v
```
* verobse, printing more information about the process.

```=
--wildcards {pattern}
```
* using wild cards to select files to archive.

##### combined examples

```=
tar cf test.tar test1 test2 test3
```
* create a test.tar archive from the three files.

```=
tar xf test.tar
```
* extract the test.tar on the current directory.

```=
find -name 'test*' -exec tar cf test.tar '{}' '+'
```
* find all the files staring with test from current directory
* in one go, create a test.tar

```=
find -name 'test*' | tar cf tests.tar --files-from=-
```
* find gives a list of pathnames to stdin of the tar command.
* --files-from=- takes stdin as the input to tar.

```=
find -name 'test*' | tar cf - --files-from=- | gzip > tests.tgz
```
* for tar commands, the input is from stdin. output is directed to stdout.
* the archived file in stdout is captured by gzip to create a compressed file.
* it is a conversion to call it `.tgz` file.

```=
find -name 'test*' | tar czf tests.tgz --files-from=-
```
* tar have an option z. to directly create a bz file after create the tar file.

```=
find -name 'test*' | tar cjf tests.tbz --files-from=-
```
* tar have an option j. 
* use bzip2 progrm to zip the tar.

```=
ssh remote-sys 'tar cf - files' | tar xf -
```
* using ssh to archive a remote directory or files into stdout.
* the stdout will be transfer to local machine through ssh tunnel.
* on the local machine, the stdout is captured by tar to extract to files.
* in this way, we are transfering a directory from remote machine to local machine securely through the tunnel.

#### zip

```=
zip options zip-file files...
```

### synchronizing files and directories
#### use rsync over a network

## Chapter 19 : Regular Expressions
### grep
* it stands for global regular expression print (grep)
* it searches a file and output to stdout the matching lines.

```=
grep options regex files
```
* grep is capable to search multiple files

#### grep-options

```=
grep -i regex files
```
* ignore case in the regex

```=
grep -v regex files
```
* invert match, show results not match with regex.

```=
grep -c regex files
```
* count the number of matches for each file.
* there will be a number print out for each file.

```=
grep -l regex files
```
* list the file names instead of each line of the match.

```=
grep -L regex files
```
* list the file names not containing the match.

```=
grep -n regex files
```
* prefix line number of each match.

```=
grep -h regex files
```
* hide the file names for the output.

### Meta characters and literals
* Meta character has special meanings
* literals are just text.

#### Meta characters

* it is a better idea to quote the regex to prevent expansion from the shell.

```=
^
$
```
* anchors, zero in length
* start and end of the line.

```=
[...]
```
* any character inside the bracket.
* meta characters will be interpreted as literals inside bracket, except two cases
	1. ^ will invert the selection.
	2. - will expand to a range of characters.
* character will be treated as individuals instead of combination.
	* ^[ab]c will match ac and bc but not abc.

```=
{char1}-{char2}
```
* expands to all characters from char1 to char2
* this may or may not work due to different sequences of characters by the language setting
	1. Ascii order ab...AB...
	2. Dictionary order aAbB....

```=
.
```
* any single character.

```=
*
```
* quantifier
* zero of more occurrence.

```=
{m}
{m, n}
{m,}
{,n}
```
* quantifier
* exact number of times.

```=
+
```
* quantifier
* one or more occurrence.

```=
?
```
* quantifier
* zero or one occurrence. It means the object before is optional

```=
( ... )
```
* create separation from different group of regular expressions.

```=
|
```
* or 

```=
\
```
* escape meta character to literal string
* escape literal character to meta character.

### POSIX Basic and POSIC Extended 
#### POSIX basic

```=
^ $ [ ] . *
```
* meta character set.
* `grep regex files` using basic set.

#### POSIX extended

```=
( ) { } ? + | 
```
* `egrep regex files` using extended  set.
* `grep  -E regex files` using extended  set.

### Alternation
* match this or that

```=
echo foo | grep -E 'foo|bar'
echo bar | grep -E 'foo|bar'
```

### quantifiers
### Finding Ugly file names with find
* grep produce positive if the instance contains the match
* find produce positive if the instance exactly match 

```=
find . -regex '.*[^a-zA-Z0-9./_-].*'
```
* -regex is a test
* all the file in the current directory starts with `./xxxx`
* without the beginning `.*`, no match will be found.

### searching for files using `locate`

```=
locate --regex '....'
```
* it will show path names containing the match
* behaves similar to `grep`

### searching for text in less and vim
* less supports extended regular expression.
* vim supports basic regular expression.

## Chapter 20 : Text Processing
### Application of text
#### documents
* large document can be written in simple text format. 
* then a mark up can be used to convert it to the final doocument.

#### web pages
* `html` and `css` are plain text.

#### email
* email use text to transmit data

#### printer output
* a output to a printer is plain text.
* the printer receives the output and print the document
* graphics is converted to text.

#### program source code
### revisiting some old friend
#### cat

```=
cat -A file
```
* show  non-printable characters.

```=
cat -n file 
```
* labelling file with line numbers 

```=
cat -s file
```
* output file removing duplicate empty lines.
* single empty lines will be preserved

#### ms-dos text vs unix text
* ms-doc text uses two characters to end a line.
* unix text uses only one character to end a line.

#### sort 
* takes `stdin` or `file` as input
* output to `stdout`
* it can take multiple files as input

```=
sort -n file
```
* sort based on the first number string found.

```=
sort -v file
```
* reverse the sort order

```=
sort -f file
```
* ignore the case of sort.
* `export LANG=POSIX` makes the character ASCII coded. in this environment sort will perform a case-sensative sort by default, all upper case letter comes before the lower case letter so `abcABC` will be sorted as `ABCabc`

```=
sort -b file
```
* in ASCII, space comes before the letters.
* this ignore the leading spaces when sorting.

```=
sort -k{c1},{c2} file
```
* default column delimiters are spaces
* `c1` and `c2` defines a range of columns sort will use.
* it will first sort based on `c1`. for the same `c1 ` value, perform next sort
* delimiters are included in the column values.so for `a<space><space>b`. the first column is `a`, second column is `<space><space>b`

```=
sort --field-seprator={char} k=1 file
```
* define a new delimiter for columns 

```=
sort -k{c1},{c2} -k{c0}n file
```
* use multiple keys to sort.
* the first key sort alphabetically
* the second key sort as numeric string with an `n` modifier.
	1. `b` modifier : ignore leading spaces for each column when sort.
	2. `n` modifier : sort as numeric string
	3. `r` modifier : reverse the sort order.

```=
sort -k{column}.{offset}{options}
```
* `offset` will offset from the starting of column and ignore all these offseted character.
* this is usuful when dealing with time format in `mm/dd/yyyy` format.

#### uniq
* input : **sorted** stdin or **sorted** file
* output : stdout 

```=
sort file | uniq 
```
* pipe the sorted file to uniq

```=
uniq -c file
```
* count duplicates
* it will print unique lines with number of occurance in the beginning.

```=
uniq -d file
```
* show duplicates only.

```=
uniq -f n file
```
* ignore the first n fields, compare only the left.
* delimiters are spaces only.

```=
uniq -i file
```
* ignore case when compare lines.

```=
uniq -s {n} file
```
* skip the first n character when compare lines
* the file needs to sorted based on the nth character, otherwise it won't work.

```=
uniq -u file
```
* default value.
* show only unique lines.

### slicing and dicing
#### cut
* extract only a portion of a line for each lines in files
* takes files or `stdin` as input.
* output to `stdout`

```=
cut -c {n} file
cut -c {n,m} file
cut -c {n-m} file
```
* cut single character or a series of characters

```=
cut -f {n} file
cut -f {n-m} file
cut -f {n1,n2,n3...} file
```
* cut the nth field.
* `Tab` is the default delimiter.

```=
cut -f {n} -d {char}
```
* `-d` changes delimiter to `char`

#### expanding tabs
when performing character-wise cut, we may encouter problems if there is `tab` characters, in order to use character wise operation we should expand it to `space`
* `expand file | cut -c ...`

#### paste
#### join
### comparing text
#### comm
#### diff
#### patch
### editing on the fly
#### tr
#### ROT13 : the not so secret decoder ring
#### sed
#### people who like sed also like
#### aspell

