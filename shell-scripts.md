# bash scripting
## shebang
the program pass the file as an argument to the interpreter

```=
bash ./script
```

## test
### string test
### arithmetic test
* if the string is numbers, we can use more advance comparisons

## empty string
empty string will not be expanded

```=
var2=hello
if test $var1 = $var2
```
will be expanded to the following which will cause an error.

```=
if test = hello
```
to solve the problem. we should tell bash there is an empty shadow there.

```=
var2=hello
if test "$var1" = $var2
```

## wild card
* `*` match any character any number of occurance.
* `?` match any character that occur exactly once.
* `[...]` match any character exactly once in the bracket.
* `[!...]` match any character exactly once that is not in the bracket.
* `[x-y]` creates a range of single character match from `x` to `y`
	* `x` and `y` can be letters or numbers 
	* `[a-z]` match character `a` to `z`
	* `[0-9]` match character `0` to `9`
* predefined ranges by `POSIX` standard
	* `[:alpha:]`
	* `[:alnum:]` : alphabetic and numeric character.
	* `[:digit:]`
	* `[:lower:]`
	* `[:upper:]`
	* `[:space:]` : including spaces, tabs, and new lines.
