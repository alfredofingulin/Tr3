# Spec00: Features, Expectations, and Memory

Tr3 is a kernel for bare-machine embedded systems.
These execute from ROM, are RAM-limited, and avoid initialized data.

# Features

Less is more.

## Does Do

* Pre-emptive task scheduling
* Multiple tasks, each with it's own stack
* Interrupts.
* Intertask communications by passing pointers to data
  * the cooperating tasks are expected to know what's pointed-to

## Doesn't Do

* Kernel-level networking
* File systems
* Executable load/unload
* Memory reference fix-up.
* Networking and file systems are bolt-ons separate from Tr3.

## Does For You

Block oriented memory management.

# Expectations

Not many.

## A System Tick

One timer generating a system clock tick:

* you supply the timer interrupt handler
* your interrupt handler manages the timer hardware
* your handler calls Tr3's system clock tick function.

## You implement good ol' function main()

* performs any hardware initialization
* passes control to Tr3's start function.

## The Config Tool Resolved Some Externals

Tr3's start function expects several globals resolved at build-time.

* The globals elaborate all tasks and stacks, and their message queue lengths.
* These globals are built by a Tr-supplied tool.
  * The tool is written in Python.
  * It scans your application for keywords and data, generating a .c file to satisfy Tr3's expectations.

# Memory Usage

\todo memory example

For a simple STM32F429 Nucleo 144 board with

* three simple tasks, each with generous 1k stacks
* interrupts
* a whole lot of unused hardware drivers
* the usual C library and start up code support, including standard out using printf

memory used is:

* less than 64k FLASH
* less than 8k RAM.

Note that Tr3 never uses:

* .heap
* .data.
