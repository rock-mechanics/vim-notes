# Practical Vim

# The Vim Way
### Tip 1 : Meet the Dot Command
### Tip 2 : Don't Repeat Yourself.
### Tip 3 : Take One Step Back, Then Three Steps Forward.
### Tip 4 : Act Repeat, Reverse
### Tip 5 : Find and Replace by Hand
### Tip 6 : Meet the Dot Formula

# Part 1: Modes

## Normal Mode

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

## Insert Mode

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

## Visual Mode 

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

## Command-Line Mode

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
