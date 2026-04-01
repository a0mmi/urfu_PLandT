reserved.txt:

```
apple
banana
cherry
```

input.txt:

```
apple banana apple cherry banana apple cherry banana cherry
```

output.txt:

```
apple 3
banana 3
cherry 3
```

---

reserved.txt:
```
hello
world
test
unused
```
input.txt:

```
hello world hello test world hello
```
output.txt:

```
hello 3
world 2
test 1
```

---

reserved.txt:

```
if
while
for
int
return
break
```

input.txt:

```
if while for int return if while if for int break return if while
```

output.txt:
```
if 4
while 3
for 2
int 2
return 2
break 1
```
-------

reserved.txt:
```
function
variable
loop
condition
pointer
reference
class
object
```
input.txt:
```
function variable loop condition pointer reference class object
function variable loop condition pointer reference class object
function variable condition pointer reference class object
function variable loop condition pointer reference class object
function variable condition pointer reference class object
function variable condition pointer reference class object
function variable loop condition reference class object
function variable loop condition reference class object
function variable loop condition reference class object
function variable loop condition reference class object
function variable loop condition reference class object
function variable loop condition reference class object
variable loop condition pointer class object
function variable loop condition pointer object
function variable loop condition pointer reference class object
function condition pointer reference class object
function variable loop condition pointer reference class
function variable loop condition pointer reference class object
function variable condition pointer reference class object
function variable condition pointer reference class object
function variable condition pointer reference class object
function variable pointer reference class object
function variable pointer reference class object
function variable pointer reference class object
function variable pointer reference class object
function variable pointer reference class object
function pointer reference class object
function loop condition reference class object
variable loop condition pointer reference class object
object
```
output.txt:
```
class 28
object 28
variable 28
function 27
reference 27
condition 23
pointer 22
loop 16
```