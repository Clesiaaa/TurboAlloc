<div align="center"> <image src="TA_enhanced.PNG" alt="Description"> </div>

# TurboAlloc — Enhanced Memory Allocator in C

A reimplementation of `malloc` and `free` in C, built as a learning project. Provides two allocator backends: a linked list and a binary search tree.

---

## Features

- `t_alloc` / `t_free` — linked list allocator
- `t_allocx` / `t_freex` — binary search tree allocator

---

## UpComming Features

- `t_allocrd` / `t_freerd` — AVL/Red Black tree allocator
- `t_callocK`  — Enhanced callocator in LL, BST and AVLs
- `t_reallocK`  — Enhanced reallocator in LL, BST and AVLs
- `t_deallocK`  — Enhanced deallocator in LL, BST and AVLs
---

## Project Structure

```
.
├── include/
│   ├── block.h       # block_t and node_t definitions
│   ├── talloc.h      # t_alloc / t_allocx declarations
│   └── tfree.h       # t_free / t_freex declarations
├── src/
│   ├── talloc.c      
│   └── tfree.c
└── main.c
```

---

## Build

```bash
make
```

---

## Usage

```c
#include "talloc.h"
#include "tfree.h"

int *arr = t_alloc(10 * sizeof(int));   // linked list allocator
int *arr2 = t_allocx(10 * sizeof(int)); // BST allocator

t_free(arr);
t_freex(arr2);
```

---

## How It Works

Each allocation prepends a metadata header (`block_t` or `node_t`) to the requested memory zone. The pointer returned to the user points just after this header.

On free, the header is recovered by subtracting `sizeof(block_t)` from the pointer, and `is_free` is set to `1`. On the next allocation, free blocks of sufficient size are reused without calling `sbrk`.

---

## Authors

- Robert Folga