# Memory Management

Discuss:
Q: What is memory management?
Q: What were your experiences with memory management so far?

- It is "easy" to get memory management related things wrong.
  For example: Buffer overflows/overruns, buffer underflows/underruns, stack overflow/stack smashing.
  Or: Segmentation fault / Page fault.

## Historic context of terms
Intel 8086 CPU (IBM-PC) 16 Bit CPU
- registers are 16 bits
- the data bus is 16 bits
- the address bus 20 bits and an address is formed by adding an offset register to a segment base register.
(segment base register << 4) + offset register

Q: How much memory can you address with 16 bits? (Put your answer in the chat.)
A: 64 kiB (2^16 = 65536 bytes)

Q: How much memory can you address with 32 bits? (Put your answer in the chat.)
A: 4 GiB (2^32 = 4294967296 bytes)

Q: How much memory can you address with 64 bits?
A: 16 EiB (2^64 = 18446744073709551616 bytes)

What is an MMU?
A MMU is a Memory Management Unit, a hardware device that sits between the actual CPU and the bus, and performs translation between virtual addresses as seen by programs and physical addresses as seen by the hardware, providing additional functionality such as memory protection so that one process cannot illigitematly access memory of another process, and swapping, that is, using slower storage like a hard drive or SSD to extend the available RAM.
The MMUs we use are usually pMMUs, that is Paged Memory Management Units.

    virtual              physical
MMU 0x00000000 mapped to <unmapped> (and will usually never be mapped, so that access to NULL triggers a segmentation fault or page fault)
MMU 0x00010000 mapped to 0x01000000
MMU 0x00020000 mapped to <unmapped> triggers IRQ (loads to 0x01060000) update to 0x01060000

The most frequent programming mistake is to access NULL.
How is NULL defined?
```
#define  ((void) 0)
```


## Lessons
- Segmentation fault / page fault always means that we accessed a pointer and that pointer is an unmapped address.
- Modern operating systems never map address 0.
  As a consequence, accessing the NULL pointer will always lead to a segmentation fault / page fault.
- Accessing a wrong pointer will not always lead to a segmentation fault / page fault, for at least two reasons:
  - A wrong pointer might still point to legitimate data, to the wrong data, but yet data that has a mapped address.
  - The operating system might actually allocate underlying memory in larger chunks.
- Always check the return value of `malloc()`, it might be `NULL`.
- Always `free()` what you `malloc()`ed, unless in tiny programs on modern operating systems with GC.
- How to find memory and resource leaks?
  - `valgrind`
  - `strace`

## What is the consequence of forgetting to deallocate resources?
- What is the consequence of not closing files?
- What is the consequence of forgetting to call free()?

- What is a memory leak?
  Memory that's allocated but no longer used and not freed.
- Tiny memory leaks are ok, they're not good, they're bad, but they're usually acceptable, at least in desktop and server space.
  Imagine your application leaks 1MB per day, that means it leaks 200 MB in 200 days, no issue, the application is most likely going to restarted many times before that.

Assume the software is the firmware of a pacemaker. Are memory leaks ok?
Imagine the autopsy report: "Heart stopped because malloc() returned NULL."
In software where memory can be life-critical, dynamic memory allocation might even be "forbidden".
