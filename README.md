Intra: **alerusso**
GitHub: **alerusso42**

---

# ft_malloc

## Custom Memory Management Implementation

This project is a re-implementation of the standard dynamic memory allocation functions in C (`malloc`, `free`, `realloc`). The objective is to efficiently manage system memory through direct kernel calls (`mmap`), reducing fragmentation and optimizing performance.

### Architecture & Memory Zoning
The system organizes memory into three main categories to optimize system page usage and speed up the search for free blocks:

| Zone | Allocation Limit | Description |
| :--- | :--- | :--- |
| **TINY** | $\leq$ TINY\_MAX | Small allocations grouped in 8KB heaps. |
| **SMALL** | $\leq$ SMALL\_MAX | Medium allocations grouped in 256KB heaps. |
| **LARGE** | $>$ SMALL\_MAX | Large allocations managed via dedicated `mmap` calls. |

---

### Technical Features

#### 1. Metadata Structure
Each memory zone (`t_memzone`) and each block (`t_area`) features an aligned header (`max_align_t`) allowing fast navigation via pointer arithmetic (implemented as `t_bytelist` to minimize overhead).

* **Coalescing:** During `free` operations, adjacent free blocks are automatically merged to prevent fragmentation.
* **Splitting:** If a free block is significantly larger than the requested size, it is split to preserve memory.

#### 2. Thread Safety
Access to global `t_alloc` data structures is protected by mutexes, ensuring reliability in multi-threaded environments.

#### 3. Performance & Optimization
* **Alignment:** Native support for `alignof(max_align_t)` to guarantee safe and portable memory access.
* **Search Optimization:** Each `t_memzone` tracks its `longest_chunk` and `first_free_area` to avoid unnecessary linear scans of the entire heap.

#### 4. Debugging & Tools
The system integrates specialized logging tools:
* `show_alloc_mem()`: Detailed visualization of memory occupancy (TINY, SMALL, LARGE).
* **Hex/Bit Dump:** Internal functions for binary header dumping to analyze potential memory corruption.
* **Valgrind Integration:** Integrated with `memcheck.h` to monitor managed blocks.

---

### Internal Implementation

Block navigation logic does not utilize standard 64-bit pointers for internal `next`/`prev` links. Instead, it uses a `t_bytelist` (uint32_t) offset system, significantly reducing the metadata footprint on the total payload.

```c
typedef struct s_area 
{
    t_bytelist  next;  // Offset to the next block
    t_bytelist  prev;  // Offset to the previous block
    uint8_t     info;  // Bitmask: ALLOC, FREED, etc.
} t_area;
```

---

### TODO

This project is not finished.
Task to do before the evaluation:
1. putting in the malloc shared library only a part of my libft, not everything
2. add more test for the script performance.sh
3. add tests in multithreading contexts
4. fix ld_preload in shell.sh, that causes my malloc to segfault

### Testing
Two scripts are provided in the test/ directory to verify the allocator's stability and efficiency.

#### performance.sh

Benchmarks the allocator against the system's default malloc.
⚠️ currently, only one test has been written.

Execution: 
```bash
cd test/
chmod +x performance.sh
./performance.sh
```

#### shell.sh
Run a new shell that uses this malloc implementation.
⚠️ The shell crashes immediately. This needs debugging

Execution:
```bash
cd test/
chmod +x shell.sh
./shell.sh
```

### Usage

1. Build the Library
Compile the dynamic library by running make.

2. Integration
To use the allocator in your C projects:

Include the header: Copy malloc.h from the header/ directory into your project.

Link the library: Ensure libft_malloc.so is in your project root and compile using the following flags:

```bash
cc your_code.c -L. -lft_malloc -Wl,-rpath,. -I./path/to/header
```

Note: The -Wl,-rpath,. flag tells the linker to look for the .so file in the current directory at runtime.