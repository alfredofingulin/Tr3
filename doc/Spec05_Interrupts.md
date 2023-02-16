# Spec05: Interrupts

Interrupts signal external events to the application.

Tr3 handles hardware interrupts in two ways:
implicitly and explicitly.

# Implicit Interrupts; Tr3 Isn't Aware of 'Em, But An App Is

If an interrupt

* never re-enables other interrupts
* -- and --
* never invokes a Tr3 operation

during execution
then the interrupt does not have to notify Tr3.  

## Typical Operation

Implicitly:

~~~~~
/*
   a task is running
      an interrupt fires
         the machine's state is saved on the stack of the currently running task
            the interrupt handler starts
               the interrupt handler does it's thing
            the interrupt handler completes
         the machine's state is restored from the stack of the currently running task
   the task continues.
*/
~~~~~

## Why Do This?

It's an easy way to handle brief hardware intensive interrupts,
ones that communicate little with the system.

## Consequences; Have Plenty Of Stack

When the interrupt fires, any task could be running;
the interrupt will use the task's stack.

All tasks must have enough stack
for the most stack-intensive interrupt possible.

## An Implicit Example

~~~~~
/*
   a task is running
      an interrupt fires
         the machine's state is saved on the stack of the currently running task
            an interrupt handler starts
               it does it's thing
               it doesn't do a thing with Tr3
         the machine's state is restored from the stack of the
         currently running task
   the task continues
   // Tr3 never knew it happened.
*/
~~~~~

## So, Implicit Interrupts Go Behind Tr3's Back?

Yep.

## Scheduling Implicitly

Tr3 and all other tasks "don't know the interrupt exists."
Implicit interrupts do not cause rescheduling.

Rescheduling will occur when:

* an implicit interrupt completes
* the interrupted task regains control
* the task makes a Tr3 call that causes rescheduling to occur.

# Explicit Interrupts; Tr3 Has An Interrupt Task

If an interrupt

* re-enables other interrupts
* -- or --
* invokes a Tr3 operation

during execution
then the interrupt must notify Tr3.

## Typical Operation

Explicitly:

~~~~~
/*
   a task is running
      an interrupt fires
         the machine's state is saved on the stack of the currently running task
            an interrupt handler starts
               an interrupt handler tells Tr3 that an interrupt is entered
                  Tr3 makes the interrupt part of an interrupt task with an interrupt task stack
               an interrupt handler does it's thing; enabling interrupts or invoking Tr3 operations
            an interrupt handler completes
               an interrupt handler tells Tr3 that an interrupt has left
                  Tr3 finishes the interrupt task and determines which task runs next
         the machine's state is modified  
   the task continues or a new task runs.
*/
~~~~~

## Why Do This?

This is how interrupts:

* communicate events to tasks
* pre-empt the current task and run another task
* enable other interrupts during interrupt servicing.

## Consequences; It Lets (Almost) Anything Happen

Explicit interrupts may be nested.  
Interrupts can be re-enabled.
Another interrupt can fire and another explicit interrupt entered.

No matter how deep the nesting, only one interrupt task will run.
The interrupt task handles all explicit interrupts, in any order.

The interrupt task will pre-empt all other tasks,
including Tr3, for the duration.

Tr3 will not run a new task until all nested explicit interrupts have left.

Explicit interrupts may push events, message, or streams to other tasks,
but may not have have (and cannot pend) at same.
A pend implies a possible task switch.  
A task switch won't happen within an explicit interrupt;
a task switch will happen only upon leaving the last nested explicit interrupt.

## An Explicit Example

~~~~~
/*
   task_S is high priority, but is waiting for a message
   so task_R is currently running
      interrupt_A fires
         interrupt_A notifies Tr3 of entry
         interrupt_A re-enables interrupts
         interrupt_A executes
            interrupt_B fires during interrupt_A's operation
               interrupt_B notifies Tr3 of entry
               interrupt_B re-enables interrupts
               interrupt_B executes; uses Tr3 to post a message to task_S
               interrupt_B tells Tr3 that it's leaving
         interrupt_A continues execution
         interrupt_A tells Tr3 that it's leaving
      only then does Tr3 reschedule
         Tr3 decides task_R should be pre-empted
         task_S will get to run 'cause a message has arrived
   task_S is currently running.
*/
~~~~~

## So, Explicit Interrupts Notify Tr3 On Enter-ing And Leave-ing?

Right.

## Scheduling Explicitly

Tr3 and any other tasks "know the interrupt exists."
Explicit interrupts may cause rescheduling.

Rescheduling will occur when:

* the last nested explicit interrupt completes
* the last nested interrupt leave is invoked
* Tr3 regains control and reschedules
* the interrupted task may be pre-empted and another task run.

# Configuration

Tr3 can support implicit interrupts only
or implicit and explicit interrupts together.

## Implicit Configuration

Implicit interrupts are always supported by Tr3.
Tr3 doesn't know about 'em, so Tr3 doesn't need to provide anything.
There's nothing to configure for implicit interrupts.

## Explicit Configuration

Explicit interrupts are configured into Tr3's executable.
Tr3 needs the size of the interrupt stack.

# Binding

Tr3 does not directly support implicit interrupts.  
It directly supports explicit interrupts.

## Implicit Binding

To bind an interrupt to an interrupt handler,
use whatever function your uP and toolset require.

## Explicit Binding

To bind an interrupt to a Tr3 aware interrupt handler,
Tr3 supplies a macro to handle interrupt entry and exit.
You supply:

* The interrupt's expected function name
* Your Tr3-aware handler for that interrupt.

See the example code referenced on the mainpage.
