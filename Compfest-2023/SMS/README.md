# SMS

by Lychnobyte

---

## Flag

```
COMPFEST15{OwO_0tsu_0tsu_g4nb4tt4n3_y0sh1_y0sh1_5dc84a11f2}
```

## Description
The program that will send messages to your loved ones 🖤

`nc <ip> <port>`

## Difficulty
Tingkat kesulitan soal: medium

## Hints
> Intentionally left empty

## Tags
One Byte Stack Overflow, Libc database, ROP, Ret2csu

## Deployment
- Install docker engine>=19.03.12 and docker-compose>=1.26.2.
- Run the container using:
    ```
    docker-compose up --build --detach
    ```

## Notes
Pakai GLIBC 2.31 milik ubuntu 22.04.06 LTS (libc6_2.31-0ubuntu9.9_amd64)