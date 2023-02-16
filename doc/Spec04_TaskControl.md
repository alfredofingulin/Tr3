# Spec04: Task Control

A Tr3 task can control itself or other tasks only by
making itself or another task wait.
Waiting "now" or "forever" is an option (think about it).

# Controlling Itself By Waiting

A task can make itself wait:

* zero-time; the task relinquishes control temporarily to any other task ready-to-run
* non-zero-time; the task relinquishes control for a minimum amount of time to any other task ready-to-run
* max-time; the task suspends itself until told to wait zero- or non-zero by another task.

# Controlling Other Tasks By Making Them Wait

A task can make another task wait:

* zero-time; if the target task is waiting then the wait is canceled and the task made ready-to-run
* non-zero-time; the target task is forced to wait a minimum amount of time
* max-time; the target task is suspended until told to wait zero- or non-zero by another task.

# Wait Time In System Clock Ticks

The wait duration is in system clock ticks, as an unsigned 16-bit value.

* 0: relinquish or make ready
* 1..0xFFFE: the wait time in ticks
* 0xFFFF: wait indefinately.

Told you you'd get it if you thought about it.
