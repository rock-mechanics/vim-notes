#

```=
export PINAPPLE=yellow
```
* create a environment variable 

```=
env
```
* bash command to show all environment vairables

```=
import os
return = os.environ.get("PINAPPLE", "")
```
* use `get` method we can provide an default value if the environment variable is not present

```=
import sys
sys.argv
```
* return a list of command line arguments

```=
import sys
sys.exit(1)
```
* provide an exit code to the command line. it can be retreived using `echo $?`

```=
import subprocess
subprocess.run(["date"])
```
* the run command receives `argv`, which is a list containing the program name and arguments
* it create a subprocess and wait until the process finish and return a value.

```=
subprocess.run(["sleep", "2"])
```
* sleep the process for 2 seconds and return back to python

```=
res = subprocess.run(["ls", "not_exist"], capture_output=True)
res.return_code
res.stdout
res.stderr
```

```=
b'string'
```
* this is raw byte data without any specification how to decode them. by default, we use utf-8 decoding to turn it into a string
* different language use different decoding method to translate bytes into characters

```=
b'string'.decode()
```
* it will become a string




