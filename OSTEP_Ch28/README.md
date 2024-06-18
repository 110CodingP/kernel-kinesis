# Learnings
- Lock is a variable that along with lock() and unlock() functions (which take primarily the Lock as input) control which thread accesses the critical section.
- Controlling interrupts can help attain atomicity, though from security perspective it is best suited for the OS only.
- Some hardware support is necessary to build a correct lock.
- Spin Locks and Test and Set instruction



# Doubts
- In OSTEP it is mentioned that spin locks are not fair, but that is only the case when scheduling is not pre-emptive right?<br>
<span style="color:#ADFA25;">A - Yeah, always think of the scheduler as malicious</span>