# ed

```=
P
```
* show a prompt for input of commands
* the default prompt is `*`

```=
!command
```
* run a shell command with prefix `!`

```=
r !command
```
* read the output of a command into the buffer.

```=
number
```
* select the line to edit.


## default line position
the default line position when you first open up ed is the last line of the document

## move 

```=
{line1}m{line2}
```
* move `line1` **after** `line2`
* move to the first line can be achieved using `3m0`, which moves `line3` to `line1`

## starting up ed

```=
ed [options] [file]
```
* ed reads the file into a buffer which is different from the original file.
* if a file is specified with `!command`, the the `stdout` of the command is read into the buffer.

### options

```=
ed -h
```

## address
### current address
ed keeps the current address in a register.

### specify address

```=
a1,a2command
```
* command is executed on line range from `a1` to `a2`

```=
a1,command
```
* the second line address is omitted.
* this is the same as `a1,a1command`, which execute on `a1`

```=
a1;a2command
```
* move the line to a1, calculate the value of a2
* in line range a1 to a2, execute the command.
* a2 maybe a regular expression

```=
a1;command
```
* it is the same as `a1;a1command`

```=
;a2command
```
* this is a bit **special**
* it is the same as `.;a2command`, which starts the range from the current line.

```=
;command
```
* **special**
* apply the command from the current line to the last line.

## use regular expression to denote address of line.

```=
/regex/
```
* search forward for a line number.

```=
?regex?
```
* search backward for a line number

## copy and paste

```=
a1,a2y
```
* copy line ranges.

```=
a1x
```
* paste **after** line a1
