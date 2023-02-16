# TechNote03: Memory Manager, Step By Step

Here's how to do it.

# It's Fixed At Build, Block Oriented, Up To 64 Of Each Block.

The Memory Manager sets aside a chunk of memory at build time.
Your app allocates/deallocates from it.

It's always blocks of bytes:

* 8
* 16
* 32
* 64
* 128
* 256
* 512
* 1024
* 2048
* 4096
* 8192
* 16384
* 32768
* 65256
* 131072
* 262144

You can have up to 64 of each block of bytes.

* 8 x 64 = 512 bytes
* and so on
* 262144 x 64 = Why not use Linux?

# You Alloc/Dealloc At Run-time; Just Provide The Number Of Bytes Needed 

The Memory Manager will find a block big enough to hold your data and then some.

The algorithm tries to calculate the block availabe, rather than search or fragment/compact.

Example: 

* Your app needs a 65 byte data structure.  
* 64 and 256 are config'd;
* 128 is not config'd
* You get one of the 256 blocks.

# There's A Configuration Tool; Gets Info From .h Files

That tool is a Python script named Tr3Gen.
It scans your .h files looking for keywords.

# Specify Number of Blocks: #define TR3_MMBLK_OneOfTheBlockSizes number_of_blocks

To specify 18 blocks, 64 bytes each:

~~~~~{.c}
#define TR3_MMBLK_64 18
~~~~~

# Blocks Are Additive

Suppose we have three different .h files.

A:
~~~~~{.c}
#define TR3_MMBLK_64 18
~~~~~

B:
~~~~~{.c}
#define TR3_MMBLK_64 8
#define TR3_MMBLK_256 2
~~~~~

C:
~~~~~{.c}
#define TR3_MMBLK_64 2
#define TR3_MMBLK_256 1
#define TR3_MMBLK_512 3
~~~~~

then:

* 28 blocks, 64 bytes each available
* 3 blocks, 256 bytes each available
* 3 blocks, 512 bytes each available

# Inflict Tr3Gen 

It builds a data structure file needed by Tr3.

# Build and Run Your App

Watch the stuff come out.
