# DesNote01: Task Management Model

Two major points to consider: The system and the tasks.

# System Level

One task is running:

* ID
* Priority
* Stack ("thread").

# Task Level

Each task has the following model.

## A Task Has An Entry Point

And tasks should:

* be reentrant 
* avoid global or static data 
* communicate with other tasks by sending and receiving messages.
* run forever.

## A Task Can Have Parameters At Start-up

Passed by reference at task start-up.
This is optional and is if not defined, will be null.

The location is specified at build-time.

The data can be filled-in at run-time by the application initialization task.

## A Task Has It's Own ID and Base Priority

Detailed in Spec08_IDPriorities.md.  Specified at build time.

## A Task Has It's Own Stack ("Thread")

'Nuff said.  Its size is specified at build-time.

## A Task Has A Message Queue

It's an in-bound queue.
The queue length is specified at build time.
It is just pointers to data; the task knows how to interperate the data.

The queue can be read:

* FIFO
* by priority of the task posting the message, highest priority first 

Both are fixed at built time.

## A Task Can Specify Whether Or Not To Reliquish Control

Done at run time.

* Send or receiving a message may or may not reliquish control.
* So can a task delay, be it self or another task.
* So can a memory management request.

## A Task Has A Context Area

Where the task registers are saved upon preemption
and restored-from upon resumption.

The area is allocated at build time.
Transfer is effected at run time.

## Aside: Multiple Task Instances

It is possible to take the same task entry point and code:

* create multiple instances using different task names; see TN02_TaskSteps.md
* differentiate task instances using task data parameter at start-up
* each run on there own unique stack.

This is intentional.  Done at build-time.

## Kernel, System Clock, and Memory Management Tasks Cooperate & Know Internals

These comprise Tr3's core.  These basically know Tr3's internals.

## The Explicit Interrupt Task Is Different; Consequences

When an interrupt occurs, the kernel:

* preempts the current task
* switches to the explicit interrupt task.

Only one instance of this task is allowed.  It:

* does not have an input message queue 
* can send messages to other tasks, but will not relinquish control
* can alloc/free memory, but will not relinquish control
* upon interrupt completion, control is relinquished.

In consequence, upon conclusion of the explicit interrupt:

* the running task may be preempted
* another task may get control.

## A Task Has A State: Running, Ready, or Waiting 

Only one task may be running at any time.
It is usually the highest priority task that has not relinquished control.

A task may be ready.  A ready task:

* has either sent a message or has received a message
* has either alloc-d or free-d memory
* is not delayed 

A task may be waiting:

* on receipt of a message 
* on a delay, either timed or forever.
* in the special case of explicit interrupt task: occurance of any interrupt


