# Spec02: Tasks

A Tr3 task does something.  A task:

* can be pre-empted by a higher priority task;
Tr3 handles saving and restoring each task's context
* can receive pointers to messages from other tasks;
Tr3 makes the delivery
* can send pointers to messages to other tasks;
Tr3 is the messenger
* is static; once created, Tr3 will schedule or run the task until power is removed
* can have multiple instances; Tr3 can manage multiple task copies, each with its own thread.

# Template

A Tr3 task has the following template:

~~~~~{.c}
void someTaskMainFunction (void *the_task_data_p)
{
   // perform initialization
   while ( some condition is true, usually forever )
   {
      // do whatever the task does
   }
}
~~~~~

# A Task Can Do Whatever Needs Doing

'Nuff said.

# Multiple Instances: Use the_task_data_p For Whatever's Needed

Typically used for initialization data; could be used for anything.

It's often used for multiple task instances. Here's how:

* there's one task function; one piece of executable code
* the task is created multiple times, each with a unique ID and unique stack
* in consequence, each instance gets its own thread of execution
* each task instance gets a unique the_task_data_p
* each task instance gets control; the_task_data_p tells the instance where to find related info.

# Statically Created; Never Deleted

Tasks are created at system start.  Each has:

* ID
* priority
* entry point
* stack and stack size
* a message pointer queue having a maximum number of entries

The task lives forever.
It will execute until pre-empted by other tasks.

Tasks are never deleted; the only way to stop a task is to power down the system or delay it "forever."

# Round-Robin-ing And Time-Slice-ing

Tr3 will round-robin tasks of equal priority:

* given two or more tasks of equal priority
* each task ready to run
* Tr3 selects the task that's been longest on the ready list
* that task will run until it is pre-empted or relinquishes control.
