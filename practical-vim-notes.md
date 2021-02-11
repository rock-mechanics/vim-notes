# Practical Vim

## Chapter 1 :  The Vim Way
### Tip 1 : Meet the Dot Command
### Tip 2 : Don't Repeat Yourself.
### Tip 3 : Take One Step Back, Then Three Steps Forward.
### Tip 4 : Act Repeat, Reverse
### Tip 5 : Find and Replace by Hand
### Tip 6 : Meet the Dot Formula

# Part 1: Modes

## Chapter 2 : Normal Mode

Normal mode is the natrual resting state for vim.
### Tip 7 : Pause Your Brush Off the Page
* Spend more time thinking, reviewing, modifing than simply inputing text to your code.
* A painter does not need to hold the brush all the time, at normal mode, he has more tools.
* Normal mode should be a natural stop for the author to think.
### Tip 8 : Chunk Your Undos
* What is a change. a change can be char, word, line. 
* between entry and exit of insert mode, it counts as an change.
* Make each "undoable chunk" corresponds to a thought.
### Tip 9 : Compose Repeatable Changes.

* in the event when two action has the same number of strokes. repeatability is also a measure.

```=
daw : delete a word and the space before it.
```
### Tip 10 : Use Counts to Do Simple Arithmetic
Both the following commands can be fixed with a number, so it will repeat `n` times.
* `ctrl-a` : increase the first number after cursor.
* `ctrl-x` : decrease the first number after cursor.
> the command will try to identify a number at the cursor position.
> if there is no number at the cursor, it will look for the first number after the cursor.
### Tip 11 : Don't Count If You Can Repeat.
* `d2w` : `d` is delete ,`2w` is a motion.
* `2dw` : `2d` is delete two times,`w` is a motion.
* `dw.` : `d` is delete, `w` is motion, `.` is repeat.
when it is hard to count, it may be easier to repeat than count. If count is a incorrect, you need to undo the entire operation and redo it, in the case of repeat, you only need to do one more repeat.

### Tip 12 : Combine And Conquer
Operators and motion can be combined to achieve greater effect.
Most of the time, operators cannot be used by itself.
#### Operators
* `d` : delete. 
* `c` : change. 
* `y` : yank. 
* `>` : shift right. 
* `<` : shift left. 
* `gu` : make it lower.
* `gU` : make it upper.
* `g~` : swap the case.

Operators can be combined with motions and text objects to achieve greater effect.

#### Motions
Motion moves your cursor to include more text from your current position.
* t{char} : from cusor to character(exlusive).
* `$` : to the end of line
* `e` : to the end of word

#### Text Object
Text object identify a pattern based on your cursor, and acts on the pattern.
* `aw` : a word
* `ap` : a paragraph
* `w` : to the end of the word

#### Special Motion : Entire line
operation on entire line is very common, thus a special rule for it.
* `dd` : delete a line.
* `cc` : change a line.
* `yy` : yank a line.
* `>>` : shift right a line.
* `<<` : shift left a line.
* `guu` : lower case a line.
* `gUU` : upper case a line.
* `g~~` : swap case for a line.

#### Operator-Pending Mode
when a `operator`is pressed, vim will enter a state that accepts only `motion` or `text-object`. before that is received,it is at a state of "Operator-Pending".
In opertor pending mode, `ESC` can resume to Normal Mode.

## Chapter 3 : Insert Mode

### Tip 13 : Make Corrections Instantly from Insert Mode
* when making edits, you may use `backspace` to delete char by char.
* you may also use `c-w` to delete a word and then re-type it.
* if the entire line is misspelled, you may use `c-u` to delete the entire line.
> try to retype words instead of delete words by character can help you identify which words you normally mistype.

### Tip 14 : Get Back to Normal Mode
A special mode is called Insert-Normal-Mode. where you need to fire a normal mode command and switch back to insert mode immediately to continue typing.

```=
<C-o> : enter insert-normal-mode, and back to inert
<C-o>zz : move the typing line to center of screen. and continue typing.
```

### Tip 15 : Paste from a Register Without Leaving Insert Mode
paste in insert mode is common. 

```=
C-r {number}
```
* number is the buffer number.

### Tip 16 : Do Back-of-the-Envelope Calculations in Place
In vim, there is a special register called expression register.
In edit mode, you may type `C-r=` to input the expression to the register.
Like typing the following sentence

```=
6 chairs, each costing 35 dollars, totally 210 dollars.
```

### Tip 17 : Insert Unusual Characters by Character Code
For any special characters, there is a vim code that can be used to enter it in edit mode.
To enter a special character, use `C-v {code}`.
* for ASCII code, the code has three digits, for example `A` = 065.
* for Unicode character, we need 65535 characters, we can use 4 digits hexadecimal code 
	* 4 digits = 16^4 = 65536 characters.
	* the 4 digits need to prefixed with a letter `u`. for example, `c-v u00bf`=`¿`.
	* unicode plane is the key word for search all the possible panel characters.

* `c-v` can also be followed with an normal key, it will input the key literally without any modification (for example tab key).

### Tip 18 : Insert Unusual Characters by Digraph
Digraph is pairs of characters used to descriptively represent special characters.

```=
c-k char1 char2
```
* digraph is meant to be descriptive.
	* ½ , it is `c-k 1 2`.
	* ÷ , it is `c-k - :`.
* digarph table can be looked up to get the key combination.

### Tip 19 : Overwrite Existing Text with Replace Mode
replace mode is changing the char one by one without changing the length of text.
It can be invoked by `R` from normal mode.
* Issues with special character, like `tab`, replace it will result in line reduction.

virtual replace mode will replace screen character one by one. not literally the real character.
It can be invoked by `gR` from normal mode.
* Tab character will be replaced with 4 or more spaces. thus line length will not shrink in the beginning.

single character version of replacement mode and virtual replacement mode is the following, normal mode will resumed once replacement is done.
* `r{char}`
* `gr{char}`

## Chapter 4 : Visual Mode 

### Tip 20 : Groke Visual Mode
Most Normal mode command can be run in visual mode, but the semantics is different.

```=
h,j,k,l
```
* expands the visual selected area.

```=
c
y
```
* change the selected text. 
* yank the selected text.

```=
viw
vaw
v{motion}
```
* `v` can be followed with a motion to select text 

```=
U
```
* `V` change selected text to uppercase.
* `v` change selected text to lowercase.

```=
>
```
* `>` indent selected text

```=
r{char}
```
* replace each character in the selection to `{char}`


### Tip 21 : Define a Visual Selection.


```=
v
```
* character visual mode.
* toggle between the normal mode.

```=
V
```
* line visual mode
* toggle between the normal mode.

```=
<c-v>
```
* block visual mode
* toggle between the normal mode.

```=
gv
```
* reselect the last selection
* it works on all three visual modes.

```=
o
```
* jump between the ends of selection

### Tip 21.5 : Repeat Character-Wise Visual Commands
In visual modes. character commands will be applied to every character.

```=
rx
```
* replace all character in the selection to `x`

### Tip 22 : Repeat Line-Wise Visual Commands
In visual modes, `.` will repeat the visual commands on the same selected text.

### Tip 23 : Prefer Operators to Visual Commands Where Possible
Visual commands normally don't work with `.` very well, it will only work on the same range (number of chars) of text, which makes it bit hard to use, if there is a normal operator alternative, we should use the normal mode alternative

```=
gU{motion}
//make text in motion upper case in normal mode
```
is usually more repeatable than

```=
v{motion}U
//perform upper case for visually selected text.
```
### Tip 24 : Edit Tablular Data with Visual-Block Mode
### Tip 25 : Chagne Columns of Text
some commands have different semantics in block visual mode.
in block visual modes, the selecion on each line is considered a *sub-selection* instead of a whole selection
operations may acts on each of them seperately.


```=
c{text}
s{text}
```
* change each sub-selection to the `{text}` 

### Tip 26 : Append After a Ragged Visual Block
block visual modes can select not only rectanglur data. It can do more and become even more useful because of its special behavior than the normal visual mode.
```
$
```
* it can extend each subselection to the end of line.
```
A
```
* append after each sub selection

## Chapter 5 : Command-Line Mode

### Tip 27 : Meet Vim's Command Line
* enter command line mode by pressing `:`
* execute the command by pressing `Enter`

### Tip 28 : Execute a Command on One or More Consecutive Lines

```=
:8
```
* go to line 8

```=
:print
:p
```
* print current line

```=
:8p
```
* go to line 8, then print it.

```=
:2,5p
```
* print line 2 to line 5 inclusive
* the cursor will stay at line 5 afterwards

```=
:.,$p
```
* print from the current line to end.
* `.` is current line. `$` denotes the end of file
* `%` denotes all lines in the file
* `'<` and `'>` denote the start and end of the selection
* `0` denotes the start of file (imaginary line 0)

```=
/pattern1/,/pattern2/p
```
* print lines from line containing pattern1 all the way to line containing pattern2

```=
/<html>/,/<\/html>/p
```
* start from line containing `<html>`
* end with line containing `</html>`, so it will operate on entire html body
* it also includes both of the html tag

```=
/<html>/+1, /<\/html>/-1p
```
* the line number can have a offset.
* the begining line number + 1
* the ending line number - 1.
* so it prints content inside the html tag without the actual html tag.

```=
.,.+1p
```
* print current line and the next line.

### Tip 29: Dumplicate or Move Line Using `:t` and `:m` Commands
`t` is named as `copy to`

```=
: from t to
: from m to 
```
* `from` and `to` is line address.
* `t` copy the `from` line, put it under `to` line
* `m` move the `from` line, put it under `to` line
* current line address sometimes can be omitted.

```=
:6t.
```
* copy line 6 and put it under the current line (omitted)

```=
:t6
```
* copy current line(omitte) and put it under line 6

```=
:t.
```
* copy current line and put it under current line.

```=
:t$
```
* copy current line and put it at the end of the file.

```=
'<,'>t0
```
* copy visually selected region to the beginning of the file.

### Tip 30 : Run Normal Mode Commands Across a Range
Combine `ex` command with normal mode allow us to loop through lines and apply commands one by one.

```=
line1,line2 normal {command}
```
* `normal` keyword shows we are going to run a normal command for each of the line.

```=
1,10 normal .
```
* repeat last nromal command for line1 to line10

```=
:% normal //
```
* comment out entire java file

```=
:% normal A;
```
* append an semicolon for all lines of a file

### Tip 31 : Repeat the Last `ex` Command

```=
@:
```
* repeat last command
* once run, the second time, we can use `@@` to achieve the same thing

### Tip 32 : Tab-Complete Your `ex` Commands
Using `tab` can auto complete your commands just like what we do in shell.

```=
<c-d>
```
* show all the auto-completion options.

```=
:colorscheme <c-d>
```
* it will show all the color scheme avaiable and `tab` can be used to switch between them.

### Tip 33 : Insert the Current Word at the Command Prompt
Vim keeps track of current cursor position and active buffer in command line mode, so you could insert it using

```=
<c-r><c-w>
```

### Tip 34 : Recall Commands from History
very similar to bash, in vim's command line, you may use 

```=
up, down
```
to loop through history commands. you may also type part of the command to look for a similar command in history.
#### Entrie history

```=
q:
```
* bring up the history window
* use <Enter> to execute the commands in the window.
* you can freely modify the command file using various of vim techniques and once completed, press enter to execute.

```=
:q
```
* exit from the command line window and goes back to your active buffer.

#### Chain two commands together to repeat
you may need to run a command after writing to vim. use `|` to chain commands together.

```=
:w | !python3 prog.py
```
* most likely you are modifying `prog.py`, you want to write it and run it.

#### Enter command line window from command line.

```=
<c-f>
```

### Tip 35: Run Commands in The Shell

```=
:!{command}
```

```=
:!ls
```
* list file in current directory
#### current file name

```=
%
```

```=
:w | !python3 %
```
* save file and use python 3 interpreter to run the current file
#### start a shell to run multiple shell commands

```=
:sh
```
* start a shell

```=
exit
```
* quit the shell and return to vim

#### suspend vim in shell and bring back vim
Since vim is actually a program running in the shell, we could suspend it temporarily using a universal shell command

```=
<c-z>
```
* suspend the vim running in shell, so you could interact with shell.

```=
$ jobs
```
* check the jobs listed in the background.

```=
$ fg
```
* bring back the suspended job.

#### using the content of a buffer for stdin and stdout

```=
:read ! {command}
```
* reroute the output of `{command}` to the buffer content.

```=
:w !{command}
```
* make the file as stdin to the command

#### filtering the contents of a buffer through an external command


```=
:{range} w !{command}
```
* pass the range of buffer to {command} as stdin
* reroute the stdout to replace the range in the buffer.

```=
:2,4 !sort -t',' -k2
```
* `-t','` tell the `sort` to delimited by `,`.
* `-k2` tells the `sort` to sort based on the second item.

#### select text to filter using `!{motion}`


```=
!G
```
* from current line to the end of file.
* then we need to type in the filter command to filter the selected text.

### Tip 36 : Run Multiple `ex` Commands as a Batch

#### Vim Scripts

a series of vim commands can be written an `.vim` file. it can then be sourced into a file at one go.
* there is no need to prefix `:` at the start of each `ex` command.

```=
global/href/join
vglobal/href/delete
%normal A: http://vimcasts.org
%normal yi"$p
%substitute/\v^[^\>]+\>\s//g
```
* above commands can be saved in `batch.vim`
#### Run scripts
* run the script using `:source batch.vim`
#### Source scripts for multiple buffers.

```=
vim *.vim
```
* open multiple files with vim as arguments buffer.

```=
:args
```
* check the opened argument buffer.

```=
:argdo source batch.vim
```
* it will source the `batch.vim` for all the argument buffer.

# Part 2 : Files

## Chapter 6 : Manage Multiple Files

### Tip 37 : Track Open Files with the Buffer List

#### Understand Distincation Between Files and Buffers

* buffer is a memory copy of a file. we are editing a buffer.
* as the buffer and file content diverges, we need to save the buffer.

```=
:write
:update
:saveas
```
#### Meet the Buffer List

```=
:ls
```
* open the buffer list.

```=
:bnext
```
* switch to next buffer in the current window.
* the current window will be replaced by the next buffer

```=
% // current buffer displayed in widow
# // alternate buffer
:b# // switch to alternate buffer
```
* this allow you to switch between two different buffers quickly in the current window.
* it can toggle quick using `<c-^>`
#### Use the Buffer List

```=
:bprev
:bnext
:bfirst
:blast
:b {number}
:b {name}
:bufdo //run ex command to all buffers
:bdelete {number1} {number2} {number2}
:N,M bdelete
```
* delete a buffer has no impact to file, it only removes the memory representation of the file, which is a copy by nature.

### Tip 38 : Group Buffers into a Collection with the Argument List
* argument list is a representation of all files that are passed to vim when vim is opened.
* argument list is not the same as buffer list.
* arg list is a feature of `vi`. 
* buffer list is a feature of `vim`.

#### Populate Argument List

```=
:args {name}
```

```=
:args *
```
* add all files in the current direcotry to argumetn list.


```=
:args **
```
* add all files in the current directory and recursively all files in the sub directory


```=
:args *.*
```
* add all files with extension to arglist.


```=
:args **/*.js
```
* add `js` file of all sub-directory to arglist


```=
:args **/*.js **/*.css
```
* add `js` and `css` files to arglist from all subdirectories.

#### using argument list


```=
:next
:prev
```
* navigate through the argument list.

### Tip 39 : Manage Hidden Files

hidden buffer is a buffer not showing up in the window.
by default, vim not allowing you to hide a buffer without saving it.

```=
set hidden
```
* disable this proection and hide buffer freely regardless of save state.
* hidden buffer will be denoted `h` in buffer list.

modified but unsaved buffer will be denoted by an `+` sign in the buffer list.modified but unsaved buffer will be denoted by an `+` sign in the buffer list.



```=
:wall
:qall
:qall! //quit all buffer without save
```


```=
:e! 
//read the file to current buffer. it will disgard all the unsaved changes
//revert to last saved version.
```

### Tip 40 : Divide Your Workspace into Split Windows


```=
:sp
```
* split windows horizontally.

```=
:sp {filename}
```
* split windows horizontally. and load a buffer.


```=
:vs
```
* split windows vertically.


```=
:vs {filename}
```
* split windows vertically. and load a buffer.


```=
:e {filename}
```
* load a buffer to current window.


```=
<c-w> h
<c-w> j
<c-w> k
<c-w> l
```
* change focus of the window.


```=
:close
```
* close the current window


```=
:only
```
* close all windows except the current one
* it will not delete the buffer.


```=
<c-w>= //make all window equal.
<c-w>_ //max the height of current window.
<c-w>| //max the width of current window.
n<c-w>_ //change to the height of window to n lines.
n<c-w>| //change to the width of window to n lines.

```
* `_` and `|` is like the adjustment bar.
* if the sell support mouse, you can also manually adjust the adjustment bar on the screen using a mouse.

### Tip 41 : Organise Your Window Layouts with Tab Pages
a tab is a collection of window layouts.


```=
:lcd 
```
* local current directory of current buffer.


```=
:lcd {path}
```
* change the local directory to `path` for the current buffer.


```=
:windo lcd {path}
```
* set the current directory for all buffers in the current window.


```=
:tabedit {filename}
```
* open a file in a new tab.


```=
<c-w>T
```
* move the current window to a new tab.


```=
:tabclose
```
* close the tab and all windows on the tab.


```=
:tabonly
```
* close all windows on the tab except for the current window.

```=
:tabn
```
* switch to next tab.

```=
:tabp
```
* switch to previous tab.

```=
:tabn {number}
```
* switch to n-th tab.

```=
:tabmove {number}
```
* change the sequence of the tab.


## Chapter 7 : Open Files and Save Them to Disk

### Tip 42 : Open a File by Its Filepath Using `:edit` 

```=
:pwd
```
* print the working directory, similar to shell.

```=
% 
```
* the full name of current buffer (including path)

```=
%:h
```
* the full path of current buffer (exluding filename)

### Tip 43 : Open a File by Its Filename Using `:find`
`path` is an set of directories vim uses to find documents using the `:find` command.

```=
:set path+=app/**
```
* add all directories under app to the path variableet 

```=
:find {part of file name} Tab
```
* open file to current buffer.

### Tip 44 : Explore the File System with netrw
`netrw` means network read and write

```=
vim {directory}
```
* open directory in vim buffer

```=
:E
```
* exlore the directory of active buffer.

```=
:Sexplore
:Vexplore
```
* explore the directory of active buffer in a split window.
### Tip 45 : Save Files to Nonexistent Directories
vim open a new buffer for new file regardless the directory existance.
vim will pop up an error if you try to write the file to an non existence directory.

```=
:!mkdir {directory}
```
* linux command to create a directory.

```=
:!mkdir -p {dir/dir/dir}
```
* create all new directories in the path.

```=
:!mkdir -p %:h
```
* create direcotry in the file name of the active buffer.

### Tip 46 : Save a File as the Super User.
in case we don't have the right to write to a file. we need to run Linux sudo command to write to the content.

```=
:w !sudo tee % >/dev/null
```
* `tee` is a linux command, takes `stdin` and saves it into a file and at the same time push it to `stdout`
* `:w !{command}` push the buffer as the `stdin`
* `%` is the current buffer name.
* `>/dev/null` is receving the `stdout` as we don't really care the output

# Part 3 : Getting Around Faster.

## Chapter 8 : Navigate Inside Files with Motion
* motion allows us to move around in a file`
* motion can be combined with operators

### Tip 47 : Keep Your Fingers on the Home Row
### Tip 48 : distinguish between real lines and display lines.
* real lines has a line nubmer.
* display lines is due to the length of line and vim auto wraps the text.

```=
g{j, k , l, h}
g0
g$
g^ // move to the first non-empty char in the display line.
```
* move around in display line.

### Tip 49 : Move Word-Wise

```=
w
b
```
* move forward to the beginning of next word.
* move backward to the beginning of previous word.

```=
e
ge
```
* `e` move to the end of next word
* `ge` move to the end of previous word

```=
ea
gea
```
* `ea` can be read as `append to the end of next word`
* `gea` can be read as `append to the end of previous word`

```=
W
B
```
* move forward to the beginning of next WORD
* move backward to the beginning of previous WORD 
* big words consists of non-letter characters 

```=
E
gE
```
* `E` move to the end of next WORD
* `gE` move to the end of previous WORD

### Tip 50 : Find by Character

```=
f{char}
```
* search a character in the current line.

```=
;
```
* continue the search

```=
,
```

* continue the search in the reverse direction

```=
t{char}
```
* can be read as `to {char}`
* search a character in the current line. stop before the character.

#### the search define a motion.
it can be used to gether with commands

```=
{commands} {motion}
```

```=
dtt
```
* delete from the current cursor to the letter t
* `tt` defines a motion

#### reverse the direction

```=
F{char}
T{char}
```

### Tip 51 : Search to Navigate

```=
/{partial words/
```

```=
n
```
* next occurance

```=
N
```
* previous occurance

#### the search define a motion too.
it can be used to gether with commands

```=
{commands} {motion}
```

```=
d/th
```
* delete from the current cursor to the char combo 'th'
* `/th` defines a motion

### Tip 52 : Trace Your Selection with Precision Text Objects
text objects is a pattern/structure of texts.

```=
i(
i[
i{
i<
```
* inside of the braces
* it does not incudes the braces iteself.

```=
a(
a[
a{
a<
```
* around of the braces
* it includes the braces and one white space either before or after the brace.

```=
it
at
```
* inside the tag
* around the tag

#### Combine text objects with commands

```=
daw
caw
yaw
di(
vi<
```
* delete a word
* change a word
* yank a word
* delete inside the ()
* visually select inside the <>

### Tip 53 : Delete Around, or Change Inside
* delete command works well with `around` motion.

```=
daw
das
dap
```
* change command works well with `in` motion

```=
ciw
ci(
cit
```
### Tip 54 : Mark Your Place and Snap Back to It

```=
m{char}
```
* mark the current position with designated letter buffer.

```=
'{char}
```
* go to the start of the marking line. 

```=
`{char}
```
* go to the marking character.

### Tip 55 : Jump Between Matching Parentheses

```=
%
```
* alternating between open and close braces.
* once it jumps, it will mark the returning position, we could return to any marked position using 

```=
``
```

## Chapter 9 : Navigate Between Files with Jump
jump allows us to move between different files.

### Tip 56 : Traverse the Jump List

* vim records the postion before and after we jump in a list called **jump list**
* each window keeps its own jump list.

```=
<c-o>
<c-i>
```
* in and out, traverse the jump list.

```=
:jumps
```
* display the whole jump list

#### What is a jump

```=
{n} G
```
* jump to n-th line.
```=
/pattern/ <enter>
?pattern/ <enter>
n 
N
```
* search forward and backward
* repeat search forward or backward.

```=
(
)
```
* jump to start of previous sentence
* jump to start of next sentence.

```=
{
}
```
* jump to start of previous paragraph
* jump to start of next paragraph.

```=
H
M
L
```
* jump the cursor on the screen

```=
'{char}
`{char}
```
* jump the cursor to the marking.

#### Observation
* jump is some unusual movement of the cursor, if the cursor's movement is within logical order, it may not considered a jump.
* if the cursor jump may cause confusion, it is normally considered a jump.

### Tip 57 ; Traverse the Change List
* vim remebers all the change in a active session and keeps it in a list called **change list**

```=
:changes
```
* open the entire change list.

```=
g,
```
* cursor position of next change

```=
g;
```
* cursor position of previous change

```=
`.
```
* go back to positon of last change.

```=
`^
```
* go back to last insertion.

```=
gi
```
* uses ``^` to find the last insersion position and enter insertion mode.

### Tip 58 : Jump to the Filename Under the Cursor

```=
gf
```
* go to the file that under the cursor.

```=
path
```
* path variable is comma seprated directories that vim will search for files using `find` and `gf`

```=
:set path?
```
* check the value of current path variable.

### Tip 59 : Snap Between Files Using Global Marks
gobal mark is recoginsed between different files

```=
m{CHAR}
```
* putting the position in the register `{CHAR}` and make it available across files. 
* the {CHAR} needs to be upper case to indicate it is global register

```=
{backquote}{CHAR}
```
* go to the position of `{CHAR}` globally.
* it will literally replace the current window with the global marked buffer.

# Part 4 : Registers

## Chapter 10 : Copy and Paste

### Tip 60 : Delete, Yank and Put with Vim's Unnamed Register

```=
x
```
* delete a under the cursor, put it in unamed register.


```=
p
```
* in normal mode, it pastes the unnamed register after the cursor.
#### Black whole register
block whole register is a register that does not return anything. we can use it to as a command of "true deletion"


```=
"_d{motion}
```
* you won't be able to yank the text once you direct the text to black whole.
* `_` is the denotion of black hole.

### Tip 61 : Grok Vim's Registers



```=
"{register}
```
* indicate the address of register


```=
"add
```
* delete the current line, put it in register a


```=
"ap
```
* puts the content of register a
#### `ex` command for regiser


```=
:d {register}
:y {register}
:p {register}
```
* all of them operate on the current line
#### `yank` special register
yank command save the content to two registers
* unamed register
* 0 register
#### unamed register

```=
""
```
* default register of `c`, `d` commands
#### append to register
```
"{CHAR}
```
* it will save to same register `char`, but instead of overwrite the register, it appends to it.
#### system clipboard register

```=
"+
```
* we can read and write to it to external applications.
#### expression register

```=
"=
```
* it will drop into command line mode, and evaluate what is inside the register.
* use `p` to paste the value into the buffer.
#### More interesting registers

```=
"%
```
* current file name

```=
"# 
```
* alternate file name

```=
".
```
* last inserted text

```=
":
```
* last ex command

```=
:/
```
* last serach pattern

### Tip 62 : Replace a Visual Selection with a Register
in visual mode, `p` replace the selecton with content in `unnamed register`
* it will also save the overwritten text into unnamed register.

### Tip 63 : Paste from a Register

```=
p
P
```
* `p` paste after the cursor, `P` paste before the cursor.
* `before character` or `before line` depends on the the content in register.

```=
<c-r>{register}
```
* puts text when in edit mode.
* it will be put before the cursor just like we typed it.
no means .

### Tip 64 : Interact with the System Clipboard
#### paste from normal mode (easy).

```=
"+p
```
#### paste from insert mode (problematic)

```=
<c-r>+
```
With `autoindent` option, vim treats paste from system clipboard as actual typing, which will incure additional indentations to the inserted text.

```=
:set paste
:set paste!
```
* `paste` option inform vim about pasting and disable relevant feature to make sure paste is as expected.
* `paste!` option resumes the vim setting.

```=
:set pastetoggle =<f5>
```
* use <f5> key to toggle the paste options.

## Chapter 11 : Macros

### Tip 65 : Record and Execute a Macro
* record a macro in register {register}

```=
q{register}
```
* quit recording the macro.

```=
q
```
* check contents of the register {register}

```=
:reg {register}
```
* run the macro in the register {register}

```=
@{register}
```
* run the last invoked macro.

```=
@@
```

### Tip 66 : Normalize, Strike, Abort
* normalize : your cursor position.
* strike : target with a motion.
* abort : when motion fails.

* if a motion fails, vim aborts the rest of the macro.

```=
1000@a
```
* we don't need to actually know how many times it will counts, we just need to know the number is large enough to fail.

### Tip 67 : Play Back with a Count
a pattern for macro can be composed as following

```=
qq{next instance}.q
```
* {next instance} can be `n` or `;` or `j` which defines a motion to move the next item.
* `.` will repeat last change.
* the pattern is scalable by prefix with a number.

```=
100@q
```
### Tip 68 : Repeat a Change on Contiguous Lines

#### Macro in series
* using `j` as the motion to next line.
* macro will stop once encouter an illegal line. (safety catch)

#### Macro in parrallel
* using visual selection to define a range.
* fire macro on each line with `normal` commands.

```=
'<,'>normal @a <enter>
```

* we don't need the motion to move the next instance, the visual selection has defined the range for us.

### Tip 69 : Append Commands to a Macro
use captical letter to append content to a register.

```=
q{REGISTER}
```
### Tip 70 : Act Upon a Collection of Files

#### first work flow (parrallel)
1. build args list
3. record macro on current file.
4. revert the changes on current files.
5. run macro on all args list.

#### commands.
* navigate through directory inside vim

```=
:cd {directory}
```

* add `rb` files to args list.

```=
:args *.rb
```

* move to the start of the args list.

```=
:first
```

* revert the change to the first file.

```=
:edit!
```

* execuate `ex` commands for all buffers in arg list.

```=
:argdo normal @a
```

* write to all buffer

```=
:argdo w
:wall
```

#### second work flow (series)
1. build args list
2. record macro on current buffer
3. append `:next` to the macro
4. run it multiple times 

### Tip 71 : Evaluate an Iterator to Number Items in a List

#### workflow
1. create a variable and intialize it
2. create a macro using the variable and increase the variable at the end of macro.
3. execute the macro on multiple lines

#### commands
* create a variable.

```=
: let i = 0
```

* check variable value.

```=
: echo i
```

* using variable in insert mode by a evaluate expression

```=
<C-r>=i
```

* increase the variable.

```=
: let i = i + 1
```

### Tip 72 : Edit the Contents of a Macro
#### work flow
1. paste the register content to the end of file at a new line.
2. edit the text in normal vim buffer.
3. yank the buffer text back to register.

#### commands

* put register on a new line.

```=
:put {register}
```

* yank content back to register

```=
"{register}dd
```

# Part 5 : Patterns
## Chapter 12 : Matching Patterns and Literals
### Tip 73 : Tune the Case Sensitivity of Search Patterns
#### global setting
* make search case insensitive

```=
:set ignorecase
```
* make search case sensitive

```=
:set noignorecase
```

#### per-search setting
* make this case insensitive

```=
\c
```
* make this case sensitive

```=
\C
```
#### smart case sensitivity

```=
:set smartcase
```
* it will override `ignorecase` setting
* if search pattern all lower case, then it is case insensitive
* if search pattern contains upper case, then it become sensitive.

### Tip 74 : Use the \v Pattern Switch for Regex Searches
`\v` stands for **very magic**. It enables all the special meanings of these special characters by default, so we don't have to escape them.
* `{n}` stands for number of times
* `(a|b)` matches a or b.
* `[...]` matches anything inside the brackets.

#### very magic exception
only **three** characters has no special meanings
1. `numbers`
1. `letters`
1. `_`

* rest of characters may not have special meaning now. but pending for assignment in the future.

#### character class
character class matches certain group of characters.
* `\x` matches hex digits characters.
* `\d` matches digits charaters.
* `\w` matches words.
* `\a` matches alphabetic characters.
* `\s` matches white space and tab.

### Tip 75 : Use the \V Literal Switch for Verbatim Searches
`\V` stands for very unmagical.
* all special characters lose the special meaning
* only `\` remain special.

### Tip 75.1 : Magical or Unmagical
* if search for patterns, `\v` is more friendly
* if search for compound words, `\V` is more friendly.

### Tip 76 : Use Parentheses to Capture Submatches
* `()` is used to create a capture group
* `\{0-9}` is used to reference the capture group both in search field and replacement field.
* `\0` is always refer to the entire match

### Tip 76.5 : Use Parenthese to Denote Groups
* group is like sets, only one of them gets matched.
* by default, the content in parenthese will be captured.

```=
/(a|b)
```
* we may tell vim not to capture the group by prefix an `%`

```=
/%(a|b)
```

### Tip 77 : Stake the Boundaries of a Word
#### word characters

```=
\w
```

#### non word characters

```=
\W
```

#### boundary of words

```=
<\w+>
```
* the `+` sign shows the word character appears one or more times.
* the boundary will exclude characters that are not inside the `<>`
* so in this case, the boundary is equivalent to the following.

```=
\W\zs\w+\ze\W
```
* `\zs` denotes the start of match
* `\ze` denotes the end of match
* we don't want to match the `\W` characters.

### Tip 78 : Stake the Boundaries of a Match
Match can be different from the pattern, we can only extract part of the pattern as the match.

```=
\zs
\ze
```
* denote the match within a pattern
* by default, the match is the entire pattern.

### Tip 79 : Escape Problem Characters

* all search field has a terminator 
* it leaves space for flags to be included in the whole expression.

```=
/
?
```
* terminator for forward search and backward search
* if your search field includes these characters, we should escape them.

```=
\
```
* it is special character even in `\V` search, it should be escaped as well.

### Tip 79.5 : Use Library Functions to Escape Characters in Search Field
#### work flow 
1. yank the search string into a register
2. bring up search field with very unmagical search
3. use `CR=` to bring up evaluation register
4. use `escape(@{register}, '{chars}') <Enter>` to evalue the expression
5. complete the search.

#### commands
* `escape` function takes two arguments, one is the register content, the other is character to be escaped.

## Chapter 13 : Search
### Tip 80 : Meet the Search Command

```=
/{pattern}
```
* forward search
* if no pattern is given, vim uses the previous pattern

```=
:set wrapscan
:set nowrapscan
```
* start from beginning once hit end.
* stop once hit boundary of document.

```=
?{pattern}
```
* backward search
* if no pattern is given, vim uses the previous pattern

```=
n
N
```
* repeat last search
* repeat last search in reversed direction.

### Tip 81 : Highlight Search Matches

```=
:set hls
```
* highlight the search in all windows.

### Tip 82 : Preview the First Match Before Execution

```=
:set incsearch
```
* Enable searching as you type, rather than waiting till you press enter.

```=
<c-r><c-w>
```
* auto complete the word for the first match in incremental search

### Tip 83 : Count the Matches from the Current Pattern
#### workflow
1. complete the search
2. use `substitute` command to count the occurance.

#### commands

```=
:%s///gn
```
* `g` denote global search through a line.
* `n` denote only count without substitute

### Tip 84 : Offset the Cursor to the End of a Search Match

```=
/{pattern}/e
```
* `e` flag place the cursor at end of the match
* by default, it always place at the start of the match.
* `n` and `N` will repeat the search with same flag.

### Tip 85 : Operate on a Complete Search Match
search matches can be different in length, or they can be nested in other words.
vim's motion may or may not be able to cover the entire match effectively.
#### possible workflow
1. complete the match
2. place cursor on the first match at the beginning of the match.
3. use search `//e` as a motion to reach the end of match, it will registered as a repeatable commands.
4. use `//` to hit the next target and place the cursor on the beginning of the next match.
5. use `.` to repeat the last command.

* the command with a motion to cover entire match requires the cursor at the beginning of the match.
* the search is refereshed by flag `e`. to hit the next target at the beginning, we need to restart the search by `//<Enter>`

### Tip 86 : Create Complex Patterns by Iterating upon Search History

```=
q/
```
* bring up command line window to show all search history.
* commands can be edited as normal vim buffers and once `Enter` is hit, the command will be executed.
* old command history will always preserved even it is changed in the editing session, new command will be apppended to the search history.
* this is a very important trick, because it allows us to iterate existing search patterns in a simple manner.

### Tip 87 : Search for the Current Visual selection
plugin called `visual star` to change the default behavior of vim
* default : in normal mode and visual mode, `*` and `#` always search for the word under the cursor.
* vim star : normal mode it search for word under cursor, in visual mode, it search for the selection.

## Chaptr 14 : Substitution

### Tip 88 : Meet the Substitute Command

```=
:{range}s/{pattern}/{replace}/{flags}
```
#### flags
* `g` : global on the line
* `c` : confirm each substitution.
* `n` : count without substitute.
* `e` : silent the error output.
* `&` : resue last flag

#### replacement character
* `\r` : enter 
* `\t` : tab
* `\\` : \
* `\{number}` : submatch content
* `\={script}` : evaluate vim script to insert 

### Tip 89 : Find and Replace Every Match in a File.
* use `%` range to denote all lines.
* use `g` flag to denote all occurances in a line.

### Tip 90 : Eyeball Each Substitution
* use `c` flag to ask for a confirmation before substitution.
* it can achieve similar effect as dot formula, which is a personal flavor to choose which.

### Tip 91 : reuse the last search pattern
* in subsititution, if search field is blank, it will use the last search pattern.
* separate search field and subsititution field can cause incomplete search history, because search history and substitute history is placed in different places.
* search history is put in search history. bring up using `q/`
* substitute history is put in ex cmd history. bring up using `q:`

#### Alternatives

```=
<c-r>/
```
* insert into the command line the register `/`, which holds the last search pattern
* the subsititute history will be full in this case.

### Tip 92 : Replace with the Contents of a Register
in substitute, the replacement field will not use the previous substitution string
#### work flow
1. yank the replacement string into a register
2. insert the value of a register into the replacement field by value or by ref.

#### commands

```=
<c-r>{register}
```
* insert the register value by value.

```=
\=@{register}
```
* `\=` is to evaluate vim script.
* `@{register}` in vim script will grab the content of a register.
* this command will update with the contents of the register, so it is by ref.

```=
:let @/ = {search pattern}
```
* populate the last search register manually.

#### work flow 
1. populate the register search
2. populate the register replace
3. use by ref to do substitution

#### commands

```=
:let @/ = "search"
:let @a = "replace"
:%s//\=@a/g
```
* all the values are by ref, so you may change the register content to use the command in different way.

### Tip 93 : Repeat the Previous Substitute Command

```=
:s
:&
```
* replay the last substitute on current line
* ignoring all the flags.
* `:&` can be short cut using `&`

```=
:&&
```
* replay the last substitution with same flags on current line
* second `&` specify the same flags as the last substitution.
* ignoring the range of last substitute.

```=
:{range}&&
```
* replay the last substitution on the current range

```=
g&
```
* run last substitution across all lines.
* `:%&&` is same as `g&`

### Tip 94 : Rearrange CSV Fields Using Submatches

```=
/\v^([^,]*),([^,]*),([^,]*)$
:%s//\3,\2,\1
```
* a very magical search
* `^` denotes the start of line.
* [^,] matches non comma character.
* `$` match the end of line.

### Tip 95 : Perform Arithmetic on the Replacement

#### workflow
1. use search pattern to identify the numeric portion
2. use vim script to add or subtract the match 
3. replace it in the substitution.

#### commands

```=
\d
```
* may appear is the search field
* match digit character same as `[0-9]`


```=
\zs
\ze
```
* may appear is the search field
* focus the match on the numeric fields.

```=
\=submatch(0)
```
* may appear in the replace field.
* vim script to capture the match as number.
* we can add or extract number from this.

### Tip 96 : Swap Two or More Words

#### workflow
1. create a dictionary in vim script, using match as key, replacement as value.
2. match both words
2. use the dictionary as replacement string, match as key.

#### commands

```=
:let swapper = {"dog":"man","man":"dog"}
```
* build a dictionary called swapper to hold two key-value pairs.

```=
/\v(<dog>|<man>)
```
* match both dog and man and capture it 

```=
:%s//\=swapper[submatch(0)]/g
```
* `\=` evaluate vim script expression
* `swapper[key]` is the syntax to access the value of a dictionary.
* `submatch(0)` is the captured match.

### Tip 97 : Find and Replace Across Multiple Files

#### workflow
1. find all matches in the project direcotry across all files.
2. all these matches will be saved in a list called `quick fix list`
3. run substitution on all list times.

#### commands

```=
:vimgrep /{pattern}/{files}
```
* `{files}` accpets string globbing where `*` match any characters, `**` match any directory
* it will open up the quick fix list

```=
:cfdo %s/{patterns}/{replacement}/g
```
* substitute all items in the quick fix list.

```=
:cfdo update
```
* save the quick fixes if it is modified
* leave it if it is unmodified.

## Chapter 15 : Global Commands
global commands is an `ex` command that allows user to run a `ex` command on lines that meets certain pattern.

### Tip 98 : Meet the Global Command

```=
:[range]g[!]/{pattern}/{cmd}
```
* `[range]` is optional, if omitted, it is default to entire file, which is all the lines `%`. 
* `[!]` is optional to specify pattern match or pattern not match, this is equivalent to `v/reg/command`
* `cmd` can be omitted, if so, vim will use default `print` command, which echos the match.

### Tip 99 : Delete Lines Containing a Pattern

### Tip 100 : Collect TODO Items in a Register 

#### workflow
1. clear the register
2. append register for each line.

#### commands

```=
q{register}q
```
* clear register by recording nothing

```=
:g/{pattern}/yank {REGISTER}
```
* use upper case register name denotes a append mode.

```=
"{register}p
```
* puts the register content somewhere else.

### Tip 101 : Alphabetize the Properties of Each Rule in a CSS File.

global commands will moves the cursor to the match literally. the `ex` command can take a range from each of this match.

```=
:{range1}g/{pattern}/{range2}{command}
```
* `range1` is the searching range of `g` command.
* `range2` is the range of each command refers to the cursor position of that match.


```=
:g/{/.+1,/}/-1 sort
```
* sort all items inside the `{}`
* `g/{/` is the global command moves the cursor to the `{` position
* `.+1` defines next line number
* `/}/-1` defines the closing line number at that match.
* `sort` will do the sorting.

```=
:g/{start}/.,/{end}command
```
* a general pattern for this approach.

```=
:sil {range}{command}
```
* by default, `ex` command will echo a message when completed a task
* `sil` silent the message in the sceario there are large number of matches.

# Part 6 : Tools
## Chapter 16 : Index and Navigate Source Code with ctags

### Tip 102 : Meet ctags

#### install ctags
```=
sudo apt-get instal exuberant-ctags
```
* install `ctags`

#### what ctags do
* it tag important keywords as file addresses.
* we can jump between these definitions if necessary.

#### create tag file

```=
ctags *.rb
```
* a file called `tag` will be created in the current directory.

#### tag files
1. tag files are simple text file about some keywords, info, patterns.
2. we can use other generator to generate similar file to be used with vim.

### Tip 103 : Configure Vim to Work with ctags

```=
:set tags?
```
* check vim's tag path.
* vim will search for tag files in the order specified by the value, once a tag file is found, vim stops looking further.

```=
:!ctags -R
```
* run ctags inside vim
* `-R` will recursively run though all sub directories

### Tip 104 : Navigate Keyword Definitions with Vim's Tag Navigation Commands
#### normal mode command

```=
<c-]>
```
* jump to the definition of the keyword under the cursor.
* in case of multiple match hits, it will jump according to priority, the current buffer has the highest priority.

```=
<c-t>
```
* go back to the place before the jump.

```=
g<c-]>
```
* igonre priority when facing dumpliates, bring up a window for selection.

```=
:tselect
```
* tag selection
* bring up the window of all matches of current keyword

```=
:tnext
```
* next tag match in the priority list.

#### `ex` commands

```=
:tag {keyword}
```
* jump to the keyword in the priority list.
* same as `<c-]>`
* use `tab` to autocomplete the keyword

```=
:tjump {keyword}
```
* ignore priority and bring up the window
* same as `g<c-]>`
* use `tab` to autocomplete the keyword

```=
:tselect
:tnext
```
* same as above.

```=
:tprev
:tfirst
:tlast
```
* navigation commands across the priority list.

## Chapter 17 : Compile Code and Navigate Errors with the Quickfix List

### what is quickfix list
* quickfix list is a list with file and line addresses we can jump to. 

### why quickfix list
* it is orignally used to track all errors generated by a compiler
* now any third party program can generate this list and interact with vim.

### Tip 105 : Compile Code Without Leaving Vim

#### workflow

1. make sure vim in current working directory
2. run `:make` to compile the code using `gcc`, it will jump to the first address in the quick fix list.
3. run `:make!` to compile the code using `gcc` without jump from the current cursor position.
4. navigate to next error address using `cnext`

### Tip 106 : Browse the Quickfix List

```=
:cnext
:cprev
:cfirst
:clast
:cc{number}
```
* navigate the quick fix list.

```=
:cnfile
:cpfile
```
* go to the first of next file
* go to the last of previous file.

```=
:copen
:cclose
```
* open quick fix window
* close quick fix window

```=
:cdo
```
* execuate command on each line of the quickfix list

```=
:cfdo
```
* execute command on each **file** in teh quickfix list.

### Tip 106.5 : Location list

#### same as quickfix list
location list is another list that holds the same type of information as quickfix list.

#### different from quickfix list
1. location list commands start with `l`, quickfix list commands start with `c`
2. quickfix list is unversal, location list is bound to current window.

### Tip 107 : Recall Results from a Previous Quickfix List

```=
:colder
:cnewer
```
* quickfix list overwrites iteself when new program using it.
* we can refer to the older list or newer list using the commands
* vim keeps last 10 quickfix list.

### Tip 108 : Customize the External Compiler

vim's `:make` commands can run any external complier program that populate a quickfix list.

#### configure what program to run for `:make`

```=
:setlocal makeprg python3\ %
```
* `makeprg` is the option to specify which program to run when we call `:make`
* `%` refer to the current file address.

#### make vim populate the quickfix list using the output of the third-party program

```=
:setglobal errorformat?
```
* check the current error format
* vim use this format to parse the output of compiler program to populate the quickfix list.

#### single command to switch compiler

```=
:compiler {program}
```
* if the compiler is supported by vim, then the `maekprg` and `errorformat` will both be configured.

## Chapter 18 : Search Project-Wide with grep, vimgrep, and Others

### Tip 109 : Call grep Without Leaving Vim
#### workflow
1. use vim's `:grep` commands as a wrapper for third party `grep` program
2. result will saved in a quickfix list for easy navigation.

#### commands

```=
:grep {pattern}
```
* case sensitive grep with default argument `n` to show the line number.

```=
:grep -i {pattern}
```
* case insentitive grep.

### Tip 110 : Customize the grep Program

#### which program to call when we run `:grep` in vim

```=
set grepprg?
```
* check the default setting of `grepprg`
* this setting specify the program to call when run `:grep`

```=
grepprg = grep -n $* /dev/null
```
* default values of the `grepprg`
* `-n` options shows the line number is default
* `$*` specify all the arguments.

#### how to populate the quickfix list.

```=
set grepformat?
```
* check the default setting of `grepformat`
* it will be used to parse the output of `grep` program to populate the quickfix list.

```=
grepformat=%f:%l:%m,%f:%l%m,%f  %l%m
```
* default value of grep format.
* `,` is used to specify different possible formats.
* `%f` is used to match the filename
* `%n` is used to match the line number
* `%m` is used to match the message

#### change default search engine to `ack-grep`

`ack-grep` is another search program that provides similar functions to `grep`

```=
code/grep/goldrush.txt
6:Waldo is studying his clipboard.
9:The penny farthing is 10 paces ahead of Waldo.
```
* an example by running `ack Waldo*`

```=
code/grep/goldrush.txt:6:Waldo is studying his clipboard.
code/grep/goldrush.txt:9:The penny farthing is 10 paces ahead of Waldo.
code/grep/department-store.txt:1:Waldo is beside the boot counter.
```
* an example by running `ack --nogroup Waldo*`
* this format is the same `grep -n Waldo*`

```=
:set grepprg=ack\ --nogroup\ $*
```
* space needs to be escapted
* it is using the same format as `grep` so there is no need to change the `grepformat` option.

#### a new flavor of ack

```=
code/grep/goldrush.txt:6:1:Waldo is studying his clipboard.
```
* an example when we run `ack --nogroup --column Waldo*`
* column number is extracted

```=
%f:%l:%c:%m
```
* a possible `grepformat` setting we can use to extract the column number to quickfix list.
* `%c` is used to extract the column number.
* now we can directly jump to the occurance of the word.

### Tip 111 : Grep with Vim's Internal Search Engine

```=
:vim[grep][!] / {pattern} /  [gj] {file}
```
* `:vim` is short for `:vimgrep`
* format of `vimgrep`, which is a built-in search engine.
* `{file}` can be used using wildcards.
* `!` inverse the grep.
* `{pattern}` can be left empty, then last search pattern will be used.

```=
:args *.txt
:vimgrep / {pattern} / ##
```
* populate the intresting file in the argument list.
* grep all the argument list.

## Chapter 19 : Dial X for Autocompletion

### Tip 112 : Meet Vims Keyword Autocompletion
#### what is keyword autocompletion
vim builds a keyword list for you when you are typing in **insert mode**.
#### trigger keyword completion

```=
<c-p>
<c-n>
```
* previous word in the list
* next word in the list.
* this use the the default keyword generation list

```=
<c-x><c-p>
<c-x><c-n>
```
* limit the word list to words in the current buffer.

