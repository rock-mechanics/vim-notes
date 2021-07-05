#!/usr/bin/env python3

with open("example.txt") as f : 
    for line in f : 
        print(line.strip().upper())

f = open('example.txt')
lines = f.readlines()
f.close()

for line in lines:
    print(line, end="")

f = open("example1.txt", "w")
count = f.write("this is some new content")
f.close()
print("{} characters are written".format(count))
