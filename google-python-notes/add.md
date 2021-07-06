#

```=
with open("file.txt","w") as f : 
	

```

#

```=
os.remove(fname)
os.rename(oldname, newname)
os.mkdir('anotherdir')
os.chdir('anotherdir')
```
* `rename` is the same as `move`

#

```=
os.path.exists(fname)
```
* it return a bool value.

#

```=
os.path.isdir('somedir')
```

#

```=
r"string"
```
* this is python's way to indicate a **raw** string

```=
import re
res = re.search(r"aza", "plaza")
```
* search the pattern from the string and return `None`.

```=
import re
>>> res = re.findall(r"cats|dogs", "I love cats and dogs")
>>> type(res)
<class 'list'>
>>> res
['cats', 'dogs']
```
* `findall` returns a list of result
* if not found, it returns an empty list.

```=
if res :
...     print("found")
... else :
...     print("not found")
...
not found

```
* empty list can be used as a `boolean` expression

```=
res = re.search(r"cats", "I love cats")
>>> print(res[0])
cats
```
* the `match` object is iteratable, the index 0 is the matched string
* the index 1 and later are refering to capture groups

```=
>>> pattern=r"\b[a-z]{5}\b"
>>> re.findall(pattern, "thisa is b fivez-haxxx shool lette"
... )
['thisa', 'fivez', 'haxxx', 'shool', 'lette']
```
* `\b` is a word boundary which includes 
	1. start of the line
	2. end of the line
	3. special characters
	4. spaces
	5. etc.

	```=

re.sub(r"(\w+), (\w+)", r"\2 \1", "Jing, Chen")
'Chen Jing'
```
* subsititute and back reference

