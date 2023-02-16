# Spec06: System Clock Ticks

Tr3 needs a system clock tick.

Tr3 just counts ticks.  It doesn't care about duration.
Time-of-day and date are not kept by Tr3 (but one of your tasks can).

Tick periodicity, granularity, and accuracy is up to you.

Tr3's system clock tick interface is called by your application
on every tick.

Tr3's clock is a counter:

* used exclusively for time-ing out system calls
* initialized to zero at start-up
* incremented as often as called.

That's it.
