# Practical Vim

# The Vim Way
## Tip 1 : Meet the Dot Command
## Tip 2 : Don't Repeat Yourself.
## Tip 3 : Take One Step Back, Then Three Steps Forward.
## Tip 4 : Act Repeat, Reverse
## Tip 5 : Find and Replace by Hand
## Tip 6 : Meet the Dot Formula

# Part 1: Modes
Normal mode is the natrual resting state for vim.
## Tip 7 : Pause Your Brush Off the Page
* Spend more time thinking, reviewing, modifing than simply inputing text to your code.
* A painter does not need to hold the brush all the time, at normal mode, he has more tools.
* Normal mode should be a natural stop for the author to think.
## Tip 8 : Chunk Your Undos
* What is a change. a change can be char, word, line. 
* between entry and exit of insert mode, it counts as an change.
* Make each "undoable chunk" corresponds to a thought.
## Tip 9 : Compose Repeatable Changes.
* in the event when two action has the same number of strokes. repeatability is also a measure.
```=
daw : delete a word and the space before it.
```
## Tip 10 : Use Counts to Do Simple Arithmetic
Both the following commands can be fixed with a number, so it will repeat `n` times.
* `ctrl-a` : increase the first number after cursor.
* `ctrl-x` : decrease the first number after cursor.
> the command will try to identify a number at the cursor position.
> if there is no number at the cursor, it will look for the first number after the cursor.
## Tip 11 : Don't Count If You Can Repeat.
* `d2w` : `d` is delete ,`2w` is a motion.
* `2dw` : `2d` is delete two times,`w` is a motion.
* `dw.` : `d` is delete, `w` is motion, `.` is repeat.
when it is hard to count, it may be easier to repeat than count. If count is a incorrect, you need to undo the entire operation and redo it, in the case of repeat, you only need to do one more repeat.

## Tip 12 : Combine And Conquer
Operators and motion can be combined to achieve greater effect.
Most of the time, operators cannot be used by itself.
### Operators
* `d` : delete. 
* `c` : change. 
* `y` : yank. 
* `>` : shift right. 
* `<` : shift left. 
* `gu` : make it lower.
* `gU` : make it upper.
* `g~` : swap the case.

### Motions
* l : letter.
* aw : a word.
* ap : a paragraph.
* t{char} : from cusor to character(exlusive).

### Special Motion : Entire line
operation on entire line is very common, thus a special rule for it.
* `dd` : delete a line.
* `cc` : change a line.
* `yy` : yank a line.
* `>>` : shift right a line.
* `<<` : shift left a line.
* `guu` : lower case a line.
* `gUU` : upper case a line.
* `g~~` : swap case for a line.

### Operator-Pending Mode
when a `operator`is pressed, vim will enter a state that accepts only `motion`. before a `motion` is received,it is at a state of "Operator-Pending".
In opertor pending mode, `esc` can resume to Normal Mode.

## Insert Mode

### Tip 13 : Make Corrections Instantly from Insert Mode
* when making edits, you may use `backspace` to delete char by char.
* you may also use `c-w` to delete a word and then re-type it.
* if the entire line is misspelled, you may use `c-u` to delete the entire line.
> try to retype words instead of delete words by character can help you identify which words you normally mistype.

### Tip 14 : Get Back to Normal Mode
A special mode is called Insert-Normal-Mode. where you need to fire a normal mode command and switch back to insert mode **immediately** to continue typing.
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


