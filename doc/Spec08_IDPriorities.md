# Spec08: IDs and Priorities

Tr3 requires each task to have a

* unique ID number
* priority

Here are the rules.

# ID Rules

* Each task ID is unique.
* Duplicate IDs are not allowed.
* The ID refers to both the task and message queue possessed by the task.

# ID Values And Allocations

IDs are unsigned 8-bits and range 0..0xFF; but many values are reserved

  ID Value     |  Usage
---------------|-----------------------------------------------------
0              | **self** 
^              | ie my task ID, whatever it is.
^              | Doesn't really exist.
1              | **Tr3's private section.**
^              | Essentially the high priority SVC exception handler.
^              | Really an atomic access function(s).
^              | Note its priority fixed at 1.
2, 3, 4        | **Reserved by Tr3.**
5              | **Tr3's explicit interrupt task.**
^              | Essentially the kernel task.
^              | Really uses direct calls instead of message queues.
^              | Note its priority fixed at 5.
6, 7, 8        | **Reserved by Tr3.**
9              | **Tr3 kernel task.**
^              | Uses its message queue.
^              | Note its priority fixed at 9.
10, 11, 12     | **Available to application tasks.**
^              | Note the priority is fixed at 10, 11, 12 respectively.
^              | These will run with lower priority 
^              | than Tr3 kernel, interrupt, or reserved tasks
^              | and with higher priority 
^              | than Tr3 system clock tick.
13             | **Tr3's system clock tick task.**
^              | Note its priority fixed at 13.
14, 15, 16     | **Available to application tasks.**
^              | Note the priority is fixed at 14, 15, 16 respectively.
^              | These will run with lower priority 
^              | than Tr3 system clock tick,
^              | and with higher priority 
^              | than Tr3 memory management task.
17             | **Tr3's memory management task.**
^              | Note its priority is fixed at 17.
18, 19, 20     | **Reserved; hell I dunno.**
21             | **The application's initialization task.**
^              | Note its priority fixed at 21.
^              | If the application doesn't need an init task,
^              | then it may be left undefined.
22..31         | **Available to application tasks.**
^              | Note fixed priority (see below).
32...127       | **Available to application tasks.**
^              | Nominal priority can vary (see below)
128..0xFE      | Reserved for future use.
0xFF           | **unused** or empty task ID.

(BTW, the unmerged cells are due to a bug in Doxygen 1.9.1's Markdown table 
handling; I got tired of messing with it.)

# Priority Rules

* Priority values are inverse: The larger the value, the lower the priority.
* Tasks with IDs 1..31 are forced to corresponding priority value 1..31.
* Tasks with IDs 32..127 can 
  * be any priority value 31..0xFE.
  * duplicate priorities; ie two tasks may have the same priority value

# Priority Values And Allocations

Priorities are unsigned 8-bits and range 0..0xFF; but many values are reserved.

* Priority value 0 means "self" or "the default priority"
* Priority value 0xFF means "empty" or "unused".
