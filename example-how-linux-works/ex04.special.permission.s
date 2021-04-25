#!/usr/bin/bash

echo -e "\npasswd is a file (program) that change the password"
echo -e "\nlet's see some special files\n"

ls -l $(which passwd)

cat << _eof_

Conclusion : 
	syntax : 
		-rxs.........
	description : 
		s is a speical permission. it is called 'setuid'
		when "you" see the s in the permssion. it means you can 
		run as the author of the program so when you are running
		passwd , you don't need to acquire root privilages
		and the program can automatically acquire all the root
		privilages when it runs.

_eof_


