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
## summing up
## further reading

# processes
## how a process works
## viewing processes
## controlling processes
## signals
## more process related commands
## summing up
