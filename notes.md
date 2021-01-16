# Vim Notes

# ZZ
saves and writes to the file.
it will also **exit** the vim editor.

# Shell and Vim
Vim is running in the shell, you may suspend Vim and do something in shell using
`:sh`
Once you finish the shell tasks, you may return to vim using
`Ctrl-D` or simply fire `exit` in the shell.

# Remap the keys.
in shell, you may type the following command.to swap the key mapping for convinience

`setxkbmap -option caps:swapescape`
* it will swap the escape keys with capslock.

# Move
* `w` : move to the **beginning** of next word. 
* `b` : move to the **beginning** of previous word.
* `0` : move to the **beginning** of the line.
* `$` : move to the **end** of the line
* when moving using `w`, all the symbols and punctuations count as a word.
* a variant of `w` is `W`, it does not count symbols and punctuations as word.

# Goto command.
it use the word `G` to denote goto.
* `G` : go to the last line of the file.
* `[number]G` : go to the number-th line.
* ```` will direct you back to your previous cursor position.
* `''` will direct you back to the beginning of your cursor line.

# Modify texts.
1. `i` : insert
1. `d` : delete and cut at the same time.
1. `c` : change
1. `a` : append
1. `y` : yank.
1. `p` : put / in other editor,it may called paste.
1. `r` : replace a single character with a single character.
1. `s` : subsititute a single character.
	* **different** from `r`, it can replace a char with multiple chars.
	* `s` can combined with motion.
1. `~` : switching capitalization of chars. from a to A
1. `x` : deleting the character on the cursor.

## Different floavors.
* `p` is pasting **after** the cursor character.
* `P` is pasting **before** the cursor character.
* `w` is moving forward one word (counting punctuations)
* `W` is moving forward one word (ignoring punctuations)
* `b` is moving backward one word (counting punctuations)
* `B` is moving backward one word (ignoring punctuations)
* `a` is appending after the character.
* `A` is appending after the the entire line.
* `c + /motion/` is change the text covered by the motion.
	* `c2w` : change 2 words
	* `c$` : change to the end of line including the cursor.
	* `c0`: change to the beginning of the line **before** the cursor.
* `C` is change the text to the end of the line including the cursor.
* `d + /motion/` is deleting the words in motion.
* `D` is deleting to the **end** of line including the cursor.
* `s` is change the char to a bunch of chars.
* `S` is change the line to a new line.
* `r` is replacing a single character with a **single character**
* `R` is replacing a serious of character one by one in strike mode.
* `x` is deleting the char on cursor
* `X` is deleting the char before cursor
* `i` is inseting text before the cursor.
* `I` is inseting text at the beginning of a line.
* `u` undos last command.
* `U` undos all changes to a line to its original state.

> Thoughts: motion after the cursor usually includes the cursor itself. but motion before the cursor usually excludes the cursor. 

## Small variations
`dw` : delete a word including space after it.
* a word of time.
* a of time.
`de` : delete to the end of a word.
* a word of time.
* a  of time.
* there is one additonal space between `a` and `of`. 

`de` : does not delete punctuations and symbols.
* a word$$! of time.
* a $$! of time.

`dE` : delete punctuations and symbols.
* a word$$! of time.
* a  of time.
> for all examples, the cursor is placed at char w intitally.

# Move by pages.
`^u` : move up half page.
`^d` : move down half page.
`^F` : move up whole page.
`^B` : move down whole page.

# Move by sentences.
* `(` : move to the beginning of previous sentences. like this one. 
* `)` : move to the beginning of next sentences. like this one. 
> sentences are seprated by puncatuations like `.`, `!` or `?`. 

# Move the current position on screen.
* `z Enter` : move the current line to the top of screen.
* `z .` : move the current line to the middle of screen.
* `z -` : move the current line to the bottom of screen. 
>> all three `z` commands move the cursor to the beginning of the line.


* `^e` : keep the cursor, move the page down one line.
* `^y` : keep the cursor, move the page up one line.

> all above commands can prefix with a number. so it will move the line number instead of current line.
> so we can achieve commands like "make line 90 to the top of the screen".

# Without changing the screen, move the cursor.
* `H` : move to the high position in screen
* `M` : move to the middle position in screen
* `L` : move to the low position in screen
> `H` and `L` can be prefixed with a number, so the cursor offset the correct position by the number.

# Search the file.
* Search from the beginning of file 
`/ [pattern]` 
* Search from the end of file 
`? [pattern]` 
> use `n` to move in the same direction. 
> use `N` to move in the opposite direction.

# Search as a motion.
* `/pattern` can be treated as a motion `to the pattern`
```=
d/while
```
* delete all the way until the word `while`.
* delete while`.
> place the cursor at `a` of `all`.

# Search within current line.
* `f [char]` : serach forward next occurance from the cursor.
* `F [char]` : search backward next occurance from the cursor.
* `;` : next one.
* `,` : previous one.
> `f` or `F` always jumps to the first letter of the ocurance.

* `t [char]` : search forward till the occurance.
* `T [char]` : search backward till the occurance.
> `t` or `T` will stop right before/after the occurance.
> `t` and `f` share same next one/ previous one commands.

# Vim argument
when firing up vim, you may specify command line argument.
* `vim + [filename]` : open the file, put the cursor to the last line. 
* `vim +n [filename]` : open the file, put the cursor to the n-th line. 
* `vim +/pattern [filename]` : open the file, put the cursor to the first occurance.
> pattern with spaces must be enquoted with ".
* `view [filename]` : the file will be opened as read only mode, where you cannot write any changes.
> `view` command can also takes some argument like `+n` or `+/pattern`

# Vim buffers
Vim opens a copy of the file into buffer. if system clashes, the lastest change you made is not written to the file, but Vim keeps a copy of the buffer. 
To view a list of buffers, in shell, you may use.
* `vim -r` 
To open a buffer, you may use 
* `vim -r [filename]`

# Deletion and restore.
Vim keeps last **9** deletion you made. there are few ways you can retrieve it.
* `"[number]p` : paste the last n-th deletion.
* You can follow it by `u` and a `.`. then the paste number will auto increased.
* `u` will revoke the pasted text.
* `.` will re-envoke the paste deletion command, but the number will be increased by 1. 

# Yank to named buffer.
yank saves the text to an special buffer which is unnamed. 
you can also yank to a **named** buffer, so it will not be overwritten easily.

* `"[a-z]y/motion/`
* there are 26 named buffer avaialble from `a` to `z`.

paste the named buffer by using.
* `"[a-z]p`

> `"[a-z]` can be combined with `d` `y` with any movement available.

## Different flavor.
if the `"[a-z]` is specifyed as `"[A-Z]`, then the named buffer will be appended instead of overwritten.
# Bookmark your position for later revisit.
During current session, if you want to mark the position of text for later visit. you may use
* `m[char]` to mark the position
* char can be any characters.

You may wish to revisit these marked places.
* ``char` : go back to exact character.
* `'char` : go back to the line of mark.
* ```` : return to previous marked character.
* `''` : return to previous marked line.

# ex editor
vim is a visual mode for ex editor. ex is a line editor underlying vim.
ex command can be fired within vim.

## ex commands
* `d` : delete line.
* `m` : move line.
* `co` : copy line.

## ex symbol
* `.` : current line.
* `$` : last line.
* `%` : for all the lines. equaivalent to `1, $`

## relative line position.
* `+` : relative forward.
* `-` : relative backward.
```=
: . , .+20 d
```
* delete next 20 lines including the current line.
* `.` can be omitted as current line is assumed.
* if a number is omitted, `1` is assumed.
```=
:-,+t0
```
* copy three lines to the begining of the files. one line before and one line after.
```=
:--,++t0
```
* copy five lines to the beginning of the files. two lines before and two lines after.

## Search the pattern as the line number.
```=
. , /pattern/ action
```
```=
. , /while/d
```
* delete from current line to the line containing while.

## Line address from arbitary line.
use `;` instead of `,` to set the base to the first line number.
* `100;+5 p` : print line 100 to line 105.
* `100,+5 p` : this equals to `100, current-line + 5 p` which may cause an error.

it can also combined with search to set the base line.
```=
:/pattern/;+5 d
```
* delete the line with pattern and the following 5 lines.
