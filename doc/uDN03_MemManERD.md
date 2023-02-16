# DesNote03: Memory Management Entity Relationship Diagram

Or rather: a structured list.

This bounds the memory manager table.

~~~~~

configd_Num_Of_MM_Areas, CONFIGD_NUM_OF_MM_AREAS : const uint8_t
  // ...actual memory management blocks, regardless of size.

~~~~~

The memory manager area table has one entry for each configured block.
Each memory management area has:

* info block in flash 
* data block, with flash resident pointers to RAM blocks.
* control block, in RAM, denoting the state of this memory area.

The table is always full, no null entries.

~~~~~

mm_Tbl : MMTblEntry, const array [0..configd_Num_Of_MM_Areas]

  MMTblEntry
    // instance naming convention is mm_Entry_4_ONEOFTHEBLOCKSIZES

    the_Info_Blk_p : MMInfoBlk, const pointer

      MMInfoBlk
        // instance naming convention is mm_Info_Blk_4_ONEOFTHEBLOCKSIZES and is const

        the_Blk_Size : const uint32_t with value ONEOFTHEBLOCKSIZES

        the_Num_of_Blks : const uint32_t with value number_of_blocks

        the_Blks_Avail_bits : const uint64_t
          // set bit : block is not available 
          // clear bit : block is available
          // most significant clear bit offset + 1 is the the_Num_of_Blks
          // bits must be contiguous
          // ex:
          // bits 63..2 are set; these are not available.
          // bits 1, 0 are clear; two blocks are available.
          // all bits clear; 64 blocks are available.

    the_Data_Blk_p : MMDataBlk, const pointer

      MMDataBlk
        // instance naming convention is mm_Data_Blk_4_ONEOFTHEBLOCKSIZES and is const

          // A block of memory must exist.
          // Instanced as uint8_t mm_Loc_4_ONEOFTHEBLOCKSIZES[ the_Blk_Size * the_Num_of_Blks]

          begining_Loc_p : const pointer to uint8_t array element 0
            // same as &mm_Loc_4_ONEOFTHEBLOCKSIZES[0]

          ending_Loc_p : const pointer to uint8_t array element the_Blk_Size * (the_Num_of_Blks) - 1
            // do you see it?

    the_Ctrl_Blk_p : MMCtrlBlk, const pointer

      MMCtrlBlk
        // instance naming convention is mm_Ctrl_Blk_4_ONEOFTHEBLOCKSIZES

        the_Blks_Used_bits : uint64_t
          // set bit : block is allocated
          // clear bit : block is free
          // initialized to the_Blks_Avail_bits
          // rotate right until you find a zero; that's the free block.

~~~~~

Here's how memory is allocated:

* Know the memory needed in bytes.
* Index thru the mm_Tbl until memory needed <= the_Blk_Size.
* Remember the index.
* Ensure there's a free block by verifying the_Blks_Used_bits != all ones.
* Determine the free block number by rotating the_Blks_Used_bits until you find a clear bit.
* Bit 0: block 0; bit 23: block 23; and so forth.
* Set that bit.

Serve up the pointer &mm_Loc_4_ONEOFTHEBLOCKSIZES[ the_Blk_Size * free block number].

To free up memory:

* use the memory address supplied
* index thru the table
* see if the memory address falls within starting_Loc_p and ending_Loc_p
* if so, subtract starting_Loc from the given memory address
* divide by the the_Blk_Size
* gives you the number of the free'd up block 
* clear the block in the_Blks_Used_bits.

Not an ERD, but that's how it's done.

