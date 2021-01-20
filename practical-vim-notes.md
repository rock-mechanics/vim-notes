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


