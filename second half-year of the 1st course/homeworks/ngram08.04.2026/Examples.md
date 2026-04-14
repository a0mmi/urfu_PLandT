in:

```
2
He went to bed.
He went home.
```

out:

```
he -> went (frequency: 2)
to -> bed (frequency: 1)
went -> home (frequency: 1)

he went -> home (frequency: 1)
went to -> bed (frequency: 1)
```

---

in:

```
3
A a a.
A a b.
A a a.
```

out:

```
a -> a (frequency: 5)

a a -> a (frequency: 2)
```

---

in:

```
3
One two three.
One two four.
One three four.
```

out:

```
one -> two (frequency: 2)
three -> four (frequency: 1)
two -> four (frequency: 1)

one three -> four (frequency: 1)
one two -> four (frequency: 1)
```

---

in:

```
4
Red fish blue fish!
Red fish green fish.
Blue fish swim.
Fish swim well.
```

out:

```
blue -> fish (frequency: 2)
fish -> swim (frequency: 2)
green -> fish (frequency: 1)
red -> fish (frequency: 2)
swim -> well (frequency: 1)

blue fish -> swim (frequency: 1)
fish blue -> fish (frequency: 1)
fish green -> fish (frequency: 1)
fish swim -> well (frequency: 1)
red fish -> blue (frequency: 1)
```

---

in:

```
2
Time after time time.
Time after time again.
```

out:

```
after -> time (frequency: 2)
time -> after (frequency: 2)

after time -> again (frequency: 1)
time after -> time (frequency: 2)
```
