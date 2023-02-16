# Spec07: Memory Management

Heap is never used.  Tr3 provides a block-oriented memory manager
for applications.

* Block sizes are 8, 16, 32,... 256k btytes.
* You configure the number of blocks for each block size.
* Configuration tool sets aside memory.
* The usual alloc/dealloc operations find the block that "just fits."

The Tr3 kernel uses it's own "quick" memory manager,
with it's own memory area,
for internal useage (and that's very sparse).
