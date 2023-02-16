# TechNote01: Architectural Overview

Tr3 has an external view, internal task view, and a data view.

# External: APIs and a Config Tool

Several application program interfaces are provided.
A config tool is necessary.

## Tr3API

The actual task management and messaging API.
Your application uses this.

## Tr3APIEI

Explicit interrupt handling.
Binds your handlers to ARM hardware interrupts 
while hiding and handling all Tr3 interrupt handling necessities.

## Tr3APIRet

This exposes and unifies return and results formats and values.
It ensures consistant representation both internal and external.

## Tr3Gen 

The configuration tool.
Scans your source code for keywords
then builds data structures used by Tr3.

## Tr3ICfg 

Exposes configuration of internal Tr3 tasks.
Provided as an example.  

Future tuning may be necessary.

# Internal: A Private Section and Several Tasks.

Here is the partitioning.

## Tr3PrivSec 

"Private Section".  An ARM SVC exception handler.
It provides atomic services that must execute to completion.

Takes advantage of the fact that SVC is the highest priority 
exception/interrupt in an ARM system.

It briefly runs on the main stack pointer.

## Tr3ExpIntTask

Not really a task, but a gateway to Tr3KernTask services.

Co-exists with any interrupt that's running and uses 
the main stack pointer.

## Tr3KernTask

A task the does all the usual scheduling operations.
It knows internal data structures, how to use these, 
and private sections to help out.

Runs as it's own task on it's own stack (thread).

## Tr3SysClkTask

A task to manage sleeping and periodic tasks.
Runs on it's own thread.

## Tr3MemManTask

Obvious.

It atomically allocate-s/de-allocates-s memory on request, 
without annoying interrupts, kernel, or system clock.

# Data

The task management model is detailed in uDN01_TaskMgmtMdl.md .

Task control entity relationship diagram, 
really all the data packaged by the config tool,
is detailed in uDN02_TaskERD.md .

Memory management has it's own ERD: uDN03_MemManERD.md .

