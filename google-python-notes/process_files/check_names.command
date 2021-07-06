#!/usr/bin/env python3

import os
import re

def check_parts(part, index):
    if index == 0 : 
        return True
    elif index == 1 : 
        return part in ['productdemo', 'productfocused', 'productreview', 'ugs', 'usp', 'tvc', 'others']
    elif index == 2 : 
        return part in ['kol', 'studio', 'playable', 'animation', 'dpa']
    elif index == 3 : 
        return part in ['b'+ str(i) for i in range(1,7)]
    elif index == 4 :
        return part in ['tiktokcreative', 'keydaysupport']
    else : 
        return False

# create directory if not exist
if not os.path.isdir("illegals"):
    os.mkdir("illegals")

# scan each file names
illegals = []
for fname in os.listdir():
    msg = "pass"
    if not re.match(r'.*\.mov', fname) : 
        continue

    name = os.path.splitext(fname)[0]
    parts = name.split("_")

    for index, part in enumerate(parts):
        if not check_parts(part, index):
            illegals.append(fname)
            os.rename(fname, os.path.join("illegals", fname))
            break
if not illegals : 
    print("All Pass!")
else : 
    print("Illegal file names : ")
    for f in illegals : 
        print(f)

