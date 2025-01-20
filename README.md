# My Pwnable

This repository contains all pwn challenges that i created so far

## Talent Scouting Academy - Cyber Champion 2024
- event: https://www.youtube.com/watch?v=UOKl5_gqOmI

| Chall | Vuln | Tags | Diff |
| ---- | --------- | ----- | ---- |
| [Vibe Check List](TSA-2024/Vibe%20Check%20List/) | Off-by-Null | Tcache Poisoning, Safe-linking | Hard |
| [Vibe Check List v2](TSA-2024/Vibe%20Check%20List%20v2/) | Use-after-free | Tcache Poisoning, Safe-linking, FSOP, ROP, Seccomp | Hard |
| [What are we cooking, chef?](TSA-2024/What%20are%20we%20cooking%2C%20chef%3F/) | Heap OOB | House of IO, Multithread | Medium-Hard |

## ZerobyteCTF 2024
- event: https://zerobyte.id/events/0byteCTF-2024/

| Chall | Vuln | Tags | Diff |
| ---- | --------- | ----- | ---- |
| [eazy_pwn](Zerobyte-2024/eazy_pwn/) | Buffer Overflow | One Gadget, Ret2libc | Easy |
| [catatan_sipil](Zerobyte-2024/Catatan_Sipil/) | Heap Overflow | Tcache Poisoning, Safe-linking | Hard |

## Compfest 2023
- event: https://github.com/ctfcompfest/compfest15-qualification

| Chall | Vuln | Tags | Diff |
| ---- | --------- | ----- | ---- |
| [SMS](Compfest-2023/SMS/) | One Byte Stack Overflow | ROP, Ret2csu | Medium |
| [Calculator](Compfest-2023/Calculator/) | Heap OOB | Tcache Poisoning, Safe-linking | Hard |

## ZerobyteCTF 2023
- event: https://zerobyte.id/events/0byteCTF-2023/

| Chall | Vuln | Tags | Diff |
| ---- | --------- | ----- | ---- |
| [Sistem Anti Hek](Zerobyte-2023/Sistem%20Anti%20Hek/) | Format String, Off-by-one, Use-after-free | Tcache Poisoning | Medium-Hard |
| [Quiz Kebangsaan](Zerobyte-2023/Quiz%20Kebangsaan/) | Buffer Overflow | One Gadget, Ret2libc | Easy-Medium |

## Uconnect 2023
- event: https://www.youtube.com/watch?v=yvwg-oOTJnw

### Final

| Chall | Vuln | Tags | Diff |
| ---- | --------- | ----- | --- |
| [uDecide](Uconnect-2023/Final/uDecide/) | Stack OOB | Alloca, Ret2libc | Easy-Medium |
| [uMemo](Uconnect-2023/Final/uMemo/) | Use-after-free | Heap Leak | Easy |
| [uNote v2](Uconnect-2023/Final/uNote%20v2/) | Heap Overflow | Ret2libc, One Gadget | Medium |
| [uSystem v2](Uconnect-2023/Final/uSystem%20v2/) | Heap Overflow | - | Easy |
| [Who R U](Uconnect-2023/Final/Who%20R%20U/) | Format String | GOT Overwrite | Easy-Medium |

### Qual

| Chall | Vuln | Tags | Diff |
| ---- | --------- | ----- | --- |
| [uBof](Uconnect-2023/Qual/uBof/) | Stack Overflow | vsyscall | Easy |
| [uCalc](Uconnect-2023/Qual/uCalc/) | Stack Overflow | ROP, Static Binary | Easy-Medium |
| [uNote](Uconnect-2023/Qual/uNote/) | Double Free | Tcache Poisoning | Medium-Hard |
| [uStats](Uconnect-2023/Qual/uStats/) | Stack Overflow | Ret2libc | Medium |
| [uSystem](Uconnect-2023/Qual/uSystem/) | Stack Overflow | Ret2libc | Medium |


## Cyberhackathon 2022
- event: https://www.youtube.com/watch?v=_kRr9vOjxdI

### Final

| Chall | Vuln | Tags | Diff |
| ---- | --------- | ----- | --- |
| [Mr. Minimalist](Cyberhackathon-2022/Final/Mr.%20Minimalist/) | Stack Overflow | SROP, Shellcode | Medium |
| [Mr. Simple](Cyberhackathon-2022/Final/Mr.%20Simple/) | Stack Overflow | Ret2csu | Easy-Medium |
| [Short Message](Cyberhackathon-2022/Final/Short%20Message/) | Format String, Stack Overflow | Ret2win | Easy-Medium |

### Qual

| Chall | Vuln | Tags | Diff |
| ---- | --------- | ----- | --- |
| [Arsip](Cyberhackathon-2022/Qual/Arsip/) | OOB | - | Easy |
| [Game Of Throne](Cyberhackathon-2022/Qual/Game%20Of%20Throne/) | OOB | GOT Overwrite | Easy |
| [License Key](Cyberhackathon-2022/Qual/License%20Key/) | Buffer Overflow | Ret2win | Easy |
| [MD5 Generator](Cyberhackathon-2022/Qual/MD5%20Generator/) | Code Injection | - | Easy |