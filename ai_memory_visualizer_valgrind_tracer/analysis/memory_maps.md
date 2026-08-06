# AI Memory Visualizer

## stack_example.c

Each recursive call creates a new stack frame.

```text
depth 3: marker = 30
depth 2: marker = 20
depth 1: marker = 10
depth 0: marker = 0
main
```

The calls enter from depth `0` to `3` and return from `3` to `0`.

`p_local` points to `local_int`:

```text
p_local ---> local_int
```

Both are local stack variables. Their lifetime ends when `dump_frame` returns.

The program does not use heap memory.

## aliasing_example.c

`make_numbers` allocates one array on the heap:

```text
a ---> [0, 11, 22, 33, 44]
```

After:

```c
b = a;
```

both pointers refer to the same array:

```text
a ---\
      ---> [0, 11, 22, 33, 44]
b ---/
```

After:

```c
free(a);
```

the array lifetime ends. Both `a` and `b` become dangling pointers.

Reading `b[2]` is an invalid read. Writing to `b[3]` is an invalid write. Both are use-after-free.

## AI Correction

AI said that matching addresses in the `"enter"` and `"exit"` calls mean the same local variable was used.

This is incorrect. The first variable ended when `dump_frame` returned. The stack later reused the same address for a new variable.
