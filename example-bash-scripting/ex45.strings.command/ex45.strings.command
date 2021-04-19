#!/usr/bin/bash

progname=$(basename $0)
how_to_use()
{
	echo $progname usage : $progname [file]
}
if test -z $1 || ! test -f $1
then
	how_to_use >&2
	exit 1
fi

echo "let's see the original file"
cat $1

# generally string command, put a file into a list of words seprated by IFS
word_lst=$(strings $1)

echo -e "\nhere is the list after process the file with string command"
for i in $word_lst
do
	# use sed to remove all the punctuation marks.
	echo $i | sed 's/[^[:alnum:]]//g'
done
