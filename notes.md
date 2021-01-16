# ZZ
saves and writes to the file.
it will also **exit** the vim editor.

# Shell and Vim
Vim is running in the shell, you may suspend Vim using
`:sh`
Once you finish the shell tasks, you may return to vim using
`Ctrl-D` or simply fire `exit` in the shell.

# Remap the keys.
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

## Move by pages.
`^u` : move up half page.
`^d` : move down half page.
`^F` : move up whole page.
`^B` : move down whole page.

## Move the current position on screen.
* `z Enter` : move the current line to the top of screen.
* `z .` : move the current line to the middle of screen.
* `z -` : move the current line to the bottom of screen. 

> all above commands can prefix with a number. so it will move the line number instead of current line.
> so we can achieve commands like "make line 90 to the top of the screen".

## Without changing the screen, move the cursor.
* `H` : move to the high position in screen
* `M` : move to the middle position in screen
* `L` : move to the low position in screen
> `H` and `L` can be prefixed with a number, so the cursor offset the correct position by the number.

## Search the file.
* Search from the beginning of file 
`/ [pattern]` 
* Search from the end of file 
`? [pattern]` 
> use `n` to move in the same direction. 
> use `N` to move in the opposite direction.

## Search within current line.
* `f [char]` : serach forward next occurance from the cursor.
* `F [char]` : search backward next occurance from the cursor.
* `;` : next one.
* `,` : previous one.
> `f` or `F` always jumps to the first letter of the ocurance.

* `t [char]` : search forward till the occurance.
* `T [char]` : search backward till the occurance.
> `t` or `T` will stop right before/after the occurance.
> `t` and `f` share same next one/ previous one commands.
