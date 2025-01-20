# Writeup Calculator

### Main idea
Tcache poisoning to overwrite free_hook with system

### How
Fullfill tcache bins so the next free will go to unsorted bin to get libc leak. Then overwrite next chunk fd with free_hook. Since on this challenge we cannot allocate another chunk before we freed current used chunk, we need to change prev_size and prev_in_use to fillup tcache bins. Also there is safe linking, so need to leak heap base.

### Example
1. Create 0x90 chunk 8 times, and freed 8 times
2. Got libc and heap leaks
3. Create another tcache with 2 bins
4. Overwrite fd 2nd bins chunk with `encrypted` free_hook address
5. Allocate chunks, fill with `/bin/sh` then free to get shell

### Additional Notes
Below some constraints i faced during testing the chall:
1. Sometimes can got double free() detected if not freed the chunk in right order
2. Need to fill prev_size and prev_in_use with correct value, or will be detected as corrupted chunk
3. In glibc 2.33 there is count check in tcache bins, so even we change tcache bins with free_hook but the count is 0 it wont be allocated