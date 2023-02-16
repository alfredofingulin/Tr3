# ThingRendevous3; A Real-Time Multi-tasking Pre-emptive Kernel for Embedded Systems  {#mainpage}

**Current Status; Wed, 17 Feb 2023**

This is far from complete.
Want eyeballs on uDN02_TaskERD.md and uDN03_MemManERD.md and test/Expected/Tr3Ti_OutputForm.c
Next up:

* acquire toolset 
* acquire Renesas RA2A1 and Nordic nRF5340 eval boards
* start iterative development

**End Current Status**

Unique features are described in the Motivation and Technical Overviews.
Targeted to ARM Cortex M4 uPs.

Developed using ARM's GCC toolset in a Linux environment via \todo toolset TBD
(you don't have to pay for anything),
but is tool independant 
(should work with IAR or almost anybody's tools).

# Motivation

For many embedded systems, I've found:

* Linux is too much
* RTOS' with the usual semaphores, queues, and priority mechanisms
  mean re-inventing the wheel, again and again.

What I wanted:

* A pre-emptable kernel supporting pre-emptable tasks
* Tasks can run synchronously or asynchronously (block or march-ahead)
* Rendevous between tasks by sending and receiving pointers to message blocks
* A simple kernel
  * memory footprint known at build time
  * error handling simplification 
    * no dynamic task creation or deletion
* A block-oriented dynamic memory scheme
  * reduce fragmentation 
  * simplify error handling

# An Example

\todo example code needed

Anything that begins with "Tr3" is important.

# Where To Find Things

Everything is here, but you might not want it all.

## inc/ and src/ Just the Source Code (and a tool you need in tool/)

* inc/ contains the API header files.  It's all your app needs.
* src/ contains ThingRendevous3 itself.  Everything.  The code follows:
  * Barr Embedded C conventions
  * GCC convention for in-line assember (and doesn't use ARM's CMSIS)
  * Markdown for documentation
  * Doxygen for code navigation (we're old school).
* But ThingRendevous3 needs a configuration data structure.  The data
  structure is built from keywords in your source code.
  * tool/Tr3Gen.py is that tool; requires python3
  * keywords and usage described in TN02_TaskSteps.md

## doc/ All the Docs (and a word about Doxygen)

All the docs are .md files.

* Spec files contain a requirements Specifiction and description
* TN files are Technical Notes
  * intended for app writers and maintainers
  * it's mostly "What is that?" and "How do I?"
  * it's mostly tool acquisition and configuration and "How do I?..."
* uDN are Design Notes
  * if you want to look under-the-hood, here's the hood...
  * further subdivided by uP and board.

Each .md file is a Doxygen "source" file.

Try using the command line "doxygen Doxyfile" at the root.
Watch the stuff come out.
Point your browswer to html/index.html.
Isn't that nice?

## ext/ uP and Board Support Code

ext/ contains all uP- and board-specific code.
Each uP and board has it's own subdirectory.
Each subdir contains

* a re-distribution of vendor-supplied code, tweaked in ways I've found helpful
* custom code I've developed, usually start-up code and such.

## test/ Test Code

TestCases/ contain native code unit tests.

Other subdirectories contains test code peculiar
to a uP or an evaluation board.

## tool/ Scripts and Such

I found 'em helpful.  You may too.

# License

MIT, folks.  Fell free to modify and incorp into your money-maker.
But gimme some credit, dammit; somewhere, anywhere.

# Technical Overview

ThingRendevous3, aka Tr3,
is a real-time multitasking priority-based scheduling kernel
for embedded systems.

## Tasking Model

The kernel follows Hoare's Communicating Sequential Processes pattern,
tho every task is considered an independant actor.

* The task is the fundamental computational unit.
* Each task gets its own thread (that is: each task has it's own stack).
  * Need multiple threads?  Use the same task code with a different stack.
* Tasks communicate using pointers to memory aka messages

It's very similar to Ada's task type,
but entry-s/accept-s are explicitly pointers to memory containing data.

* Every task has a queue of these message pointers
  * the content is defined by the tasks sharing that data
* Only the owning task can read from (aka accept) its message queue.
  * can be read FIFO 
  * can be read by sending task priority
  * determined at build time
* Every task can write to (aka enter) every other task's message queue
* Both pre-empting and non-pre-empting calls may be used.
* All non-pre-empting calls may be made from interrupts.
* Interrupts are nest-able and re-enable-able.

## A Configuration Tool Supports The Model

A seperate tool builds data structures needed by Tr3.
tool/Tr3Gen.py is that tool; requires python3,

* scans your code for keywords
* keywords and usage described in TN02_TaskSteps.md
* builds a file, Tr3Ti.c, that's part of your app.

Tr3 uses this data structure to operate on API requests.

## The Kernel Is Its Own Task

Tr3 always operates as its own task, with its own stack.
Tr3 is interruptable.  Tr3:

* resolve IDs using direct lookup
* priority-lists to figure out who should run
* tracks task states
* worries context saves/restores.

## Interrupts Run A Copy of The Kernel

Interrupt take advantage of ARM's seperate interrupt stack pointer.
Interrupts basically run a copy of Tr3's task.

Tr3 does not repost the usual interrupts-off critical section meme.

## A Private Section Lies Beneath

Tr3 uses a private atomic section; it's just an SVC exception.
Tr3 takes advantage of SVC's high priority
to perform crucial atomic operations, even during interrupts.

* This avoids ARM exception and interrupt priority issues (you are
  responsible for prioritizing interrupts).
* It gets around ARM process priviledge conumndrums (tho everything
  is priviledged).
* Treats ARM handlers and threads transparently.

## Timed Tasks Managed By A System Clock Task

Tr3 supplies a system clock task to handle periodic operations.
The system clock task "knows" about Tr3 internals 
to make periodic operations work.

## Block Oriented Memory Management 

Tr3 does supply a block oriented memory manager.
You configure block size, number of blocks, 
and use equivelents to acquire and release blocks.

The idea is for tasks to toss-about pointers to these blocks;
the blocks communicate message data between tasks.

Tr3 does not use the applications block oriented memory management.

Tr3 does use it's own "quick" memory management system.
It's a seperate small block scheme used for Tr3 internal messages.

Tr3 never uses heap or initialized data.

# Technical Limitation: No Dynamic Task Creation

ThingRendevous3 does not support run-time (dynamic) task creation.
All tasks and resource requirements are static
and constructed at build-time.
When you build a system,
all the tasks present at build-time are all the tasks you get.

Embedded systems I've encountered  
rarely perform dynamic task creation.
You build it; you flash it; you got it.

If you need dynamic process creation,
well, that makes the case for embedding Linux, doesn't it?

# What's Different Between Tr3, and Tr2 and Tr?

* ThingRendevous3 is the ruthless application of less-is-more.
* Approach is Test Driven Development: "design for testability."
* Internal design re-worked to simplify the interface to ARM OS traps.
* Tr3 complies with the Barr C Coding Standards, and MISRA, as much as possible.
* .md files replace .txt files where possible.

# Who's Responsible For This Thing?

Alfred O Fingulin  FinguPublic@gmail.com  alfredofingulin

It's his thing, and his thing alone.

# How Do I Stop Him?

You can't.  Only The Kielbasa Kid can stop him.

-30-
