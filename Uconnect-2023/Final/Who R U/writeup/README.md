# Who R U | Pwn

## Proof of Concept
- format string
- got overwrite strlen with system
- overwrite .fini_array to getnline, for 2nd input /bin/sh
- payload < 64
- spawn shell