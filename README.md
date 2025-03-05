# Garbage_collector

Garbage_collector is a simple memory management utility implemented in C. It provides functions for managing a linked list of allocated memory blocks, allowing for easy tracking and cleanup of dynamically allocated memory.

## Files

### 1. garbage_collector.h

This header file contains the definitions of the data structures and function prototypes used in the Garbage_collector utility.

- `typedef struct s_memory`: Defines a structure for a node in the linked list, containing a pointer to allocated memory (`ptr`) and a pointer to the next node (`next`).
  
- `typedef enum e_mode`: Defines an enumeration for memory allocation operations (`FREE` for freeing memory, `MALLOC` for allocating memory).

#### Function Prototypes

- `t_memory *create_node(void *ptr)`: Creates a new node for the linked list.
  
- `t_memory *find_last(t_memory **head)`: Returns a pointer to the last node in the linked list.
  
- `void lst_add_back(t_memory **head, t_memory *new)`: Adds a new node to the end of the linked list.
  
- `void free_memory(t_memory **head)`: Clears all nodes in the linked list and frees allocated memory.
  
- `void *grb_coll(size_t size, t_mode mode)`: Custom memory allocation function that tracks allocated memory using the G_Collector.

### 2. main.c (or any other source file)

You can include and use the functions from `garbage_collector.h` in your C programs to manage memory allocation and deallocation effectively.

## Usage

To use the Garbage_collector utility in your C projects, follow these steps:

1. Include the `garbage_collector.h` header file in your source files where memory management is required:

   ```c
   #include "garbage_collector.h"
   ```

2. Use the provided functions such as `grb_coll` for memory allocation and `free_memory` for memory cleanup as needed in your code.

3. Compile your C program with the necessary flags and dependencies, including the `garbage_collector.h` header file and any source files using Garbage_collector functions.

4. Run your compiled program to observe memory allocation and cleanup using Garbage_collector.

## License

This project is licensed under the [MIT License](LICENSE).
