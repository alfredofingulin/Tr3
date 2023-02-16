# Spec03: Task Communications

A Tr3 task can:

* have an input queue 
  * the queue can be by FIFO or highest priority of the sending task
* receive a message from it's own input queue
  * it cannot read from another task's input queue
* send a message into another task's input queue
  * the target task ID specifies the target task queue.

# Queue Characteristics

All tasks have message pointer queues.
When the task is elaborated, the message queue can have
0..64 spaces; the number of possible messages in the queue.
Messages may be dequeued, at run time.

# Messages Are Pointers To "Something"

The two tasks have to agree, a priori, on the structure and content.

# Messages Are Anonymous Unless The Sender Puts Sender's Task ID In The Message

'Nuff said.

# Ordering, FIFO Or Priority, Is Determined At Build Time

Each task has a configuration parameter for it's input queue:

* FIFO
* Priority of the sender.

It cannot be changed at run time.

# Operations

Receive retrieves a message pointer from it's own input queue.

Send enqueues a message pointer into another task's input queue.

In either case, task hand-off can be controlled:

* give up control
  * block the task until something becomes available
  * any other ready-to-run task will run
* retain control
  * do not block
  * any other higher priority task will not be run

