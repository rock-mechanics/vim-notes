# Error 

## pass a NULL pointer
```=
Person_Print(NULL);
```
* this will cause segmentation error. 
* code such as `Person->name` will try to dereference a pointer. which will cause an error if the pointer is `NULL`

## free the memeory then use it again

```=
free(andy)
printf("%s", andy->name);
```
* this may / may not crash or may print garbage values.
* the memeory is taken off the in-use list of the operationg system. but the pointer is still points to the memory.
