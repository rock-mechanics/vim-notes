# python refresher

#

```=
print("hello world")
```
1. parenthesis
2. quotation

```=
for i in [1,2,3,4,5] : 
	print(i)
```
1. list and for loop
2. colon at the end of the first line

```=
for i in range(5):
	print(i)
```
1. range function generate a list. 
2. the `in` syntax will iterate the list

#

```=
print(4**5)
```
1. power function

# 

```=
type(2)
```
1. get the datatype of a data
2. typical datatype are `int`, `float` and `str` `bool` and `Nonetype`

```=
print("hi" + str(30))
print(5 + 5.0) # this works
print("5" + 5) # this is an error
```
1. `str` function converts a number to a string
2. some functions will convert **some** data types implicitly, this is the implementation of the interpreter

#

```=
def func(name):
	return name
```
* function constructs.
* colon 
* return statement

# 

```=
smaller, bigger = order_number(number1, number2)
```
* function can return multiple values. those values are seprated by **,**

#

```=
print("cat"=="dog")
```
* equality in python uses `==`

#

* string is immutable

```=
while True:
	break
```
* break statement

#

```=
word = "hi, there"
for i in word:
	print (i, end=",")
for i in [word]:
	print ( i )
```
* print can receive an `end` to replace the default `newline`
* `str` is iterable letter by letter.
* `list` is iterable item by item.

# 

```=
msg = "this"
msg.upper()
msg.lower()
```

```=
msg.strip()
msg.lstrip()
msg.rstrip()
```

```=
" ".join(["this", "is", "a", "good", "day"])
```

```=
"5".isnumeric()
```

```=
msg.index("pattern")
```

```=
submsg in msg
```
* return True of False

```=
msg.endwith("pattern")
```
* return True or False

# 

```=
name = "j"
age = 5
"my name is {} and my age is {}".format(name, age)
```
* string format method convert datatype to string implicitly

```=
{variable-name : format expression}
```
* local variable name is used to disgard the order of variable input at the end of string format
* `.2f` : format a float with two decimal positions
* `>3` : allign the output within three position to the right
* if the output cannot fill 3 positions, spaces will be added to the left of the output

#

* a very basic datatype are sequences 
	* string are sequences that are immutable
	* list are sequences that are mutable
	* tuple are sequences of any type that are immutable
* sequences share some same methods

# 

```=
def func:
	return 1 , 2 , 3
type(func())
```
* the return value of a function is a tuple
* tuple can be unpacked to a range of variables

# 

```=
index, content = enumerate(list)
```
* `enumerate` function returns a tuple 

# 

```=
list = [expression(x) in sequences if condition]
```
* this is called `list comprehention`
* generate a list in one line with variable, sequence, condition


#

```=
dictionary = {"hi":10, "hello":5}
for key in dictionary : 
	print(key)
for key, value in dictionary.items() : 
	print("{} : {}".format(key, value))
```
* loop dictionary keys directly.
* loop key value tuple using `.items` methods of dictionary

```=
print(type(mydict.keys()))
print(type(mydict.values()))
```
* `<dict_keys>` are speical sequence types
* `<dict_values>` are speical sequence types

#

```=
dir("somestring")
```
* print all methods and attributes of the class

```=
__some_methods__
```
* these methods are called by some default built in functions
* len("str") is calling the __len__ function in "str" object

#

```=
help("str")
```
* show documentation for the class of the object


