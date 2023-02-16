# Spec01: Operates Like Other Real-time Multitasking Priority-based Kernels

And that is:

* the task is the basic unit of execution
* tasks communicate by passing pointers to messages
* tasks effect communication thru the kernel
* the kernel gets an excuse to re-schedule tasks
* the highest priority task wins and executes
* the kernel handles pre-emption and context switching, and passing-along message pointers.

In addition:

* block-oriented memory management service is available
* a system clock tick task handles periodic tasks.
