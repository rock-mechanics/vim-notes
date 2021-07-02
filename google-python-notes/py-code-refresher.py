print(type(1 + 1))
print(type(1 + 1.0))
print(type("hi" + "there"))

# what is the output of type function
print(type(type(1)))
print(type(type(type(1))))

# pass does nothing but a placeholder
def nothing():
    pass
print(type(nothing()))
# if a function did not return, python will return Nulltype

print(type(True))

i = 0
for i in range(4):
    pass
print (i)

msgs = [1, 2, 100, 20, 3333]
for msg in msgs:
    print("{:>4}".format(msg))

mydict = {"this": 6, "that": 10}
print(type(mydict))
print(type(mydict.keys()))
print(type(mydict.values()))

