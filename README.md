![libpear banner](b1.png)

# libpear 🍐

A lightweight hash table library written in C, built from scratch. Supports
key-value pair storage with double hashing for collision resolution and
dynamic resizing.


## Table of contents

- Requirements
- Installation
- Usage
- API
- How it works
- Maintainers


## Requirements

- GCC
- Make


## Installation

1. Clone the repository:

```
git clone https://github.com/Peposg/libpear.git
cd libpear
```

2. Build the static library:

```
make build
```

This compiles `src/libpear.c` into a static library `libpear.a`.


## Usage

Include the header in your program:

```c
#include "libpear.h"
```

Compile your program against the library:

```
gcc -I src your_file.c -L. -lpear -lm -o output
```

Or use the test target with your file:

```
make test FILE=your_file.c
```


## API

```c
// Create a new hash table
pear_t* pt_new();

// Delete a hash table and free all memory
void pt_delete(pear_t* pt);

// Insert a key-value pair
void insert_p(pear_t* pt, char* key, char* value);

// Search for a value by key — returns NULL if not found
char* search_p(pear_t* pt, char* key);

// Delete a key-value pair — returns 0 on success, 1 if not found
int delete_p(pear_t* pt, char* key);

// Resize the hash table to a new capacity
pear_t* pt_resize(pear_t* pt, int new_size);
```

### Example

```c
pear_t* pt = pt_new();

insert_p(pt, "name", "alice");
insert_p(pt, "city", "london");

char* result = search_p(pt, "name");  // returns "alice"

delete_p(pt, "city");

pt_delete(pt);
```


## How it works

- Keys and values are stored as strings (`char*`)
- The table uses **double hashing** to resolve collisions, using two
  different prime numbers (151 and 163) to calculate slot indices
- The default table size is 53 (a prime number chosen for even distribution)
- The table can be manually resized with `pt_resize`


## Maintainers

- Peposg - [Peposg](https://github.com/Peposg)
