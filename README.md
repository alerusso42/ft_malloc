Intra: **alerusso**
GitHub: **alerusso42**

⚠️ **Note:** The shared library compilation logic is currently missing; the Makefile is incomplete.
However, you can still benchmark the custom allocator's performance against the system malloc.

```bash
cd test/
chmod +x performance.sh
./performance.sh
```

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

### Usage

⚠️ **Warning:** The shared library linking is currently under development. 
Please run `performance.sh` in the `test/` directory for verification.

Compile the project via `Makefile`:
```bash
make
```

To use the library in your projects:
```c
#include "ft_malloc.h"

void *ptr = malloc(42);
// ...
free(ptr);
```