# How to use gdb

## What is gdb
GNU Debugger

## Prerequisite
program must be compiled by c compiler with `-g` option. this preserve debug information in the binary.

## Start gdb

```=
gdb
```
* lanuch gdb as a standalone program

```=
gdb <binary>
```
* load a binary at the start of the program

## In program command

These commands can be run when you start the interactive session with gdb

### Load a binary into gdb
```=
file <binary>
```
### Get a help on certain command

```=
help <command>
```
### Run the program 

```=
run
```
### Stop at a point in the program instead of running it through

```=
break <function-name>
```
* this will set a break point at one line in the program
* for example `break main`
* when you `run` the program again, the program will stop at this point

### Next line

```=
next
```
* execute next line of code. 
* this will not enter the function, it will **step over** it

### Next command ( step in )

```=
step
```
* this will execute next command
* if a function is encountered it will enter the function, so it is called **step in**

### Continue to run after break

```=
continue
```

### Print a variable when stopping at some line 

```=
print <variable>
```

### Delete a break point

```=
clear
```
### Stop whenever a variable is changed

```=
watch <variable>
```
* this is useful when you have a variable signaling the process of the program

### Check all the break points and watched variables

```=
info break
info watch
```

### Move back using function stack

```=
backtrace
bt
```
* they are the same with each other. one is abbreviated.

## composite command

```=
gdb --batch -ex run --ex bt --ex q --args ./ex3
```
* run gdb and exit with some output.
* `--batch` will combine commands into one
* `-ex <command>` is used to specify a command
* the first command is `run`, if error happens. run the second command
* the second command is `bt`, it will output the call stack backtrace if error happens.
* the third command is `q`, it will exit gdb and return to bash
* `--args <file>` is to specify the argument of gdb





