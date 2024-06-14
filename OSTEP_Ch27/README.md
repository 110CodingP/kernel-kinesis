# Reflection

- Learnt how to create threads and wait for them


## Queries

- OSTEP mentions using wrapper functions for malloc , pthread_create and pthread_join but gcc throws me an implicit function declaration warning when I try to use the wrappers, why?

- what do pthread_mutex_lock ,unlock and pthread_mutex_t do exactly?
- what does it even mean to initialize a lock?
- where are the codes for the c, c++ and pthreads?
- why do we need to keep the lock while signalling?
- what is the lock locking exactly?
- are the two locks on page 7 and 8 different?
- in the using simple flag example how will the lock be released if we don't use pthread_cond_wait