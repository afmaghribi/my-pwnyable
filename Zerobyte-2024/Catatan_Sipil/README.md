# Catatan Sipil

by Lychnobyte

---

## Flag

```
0byteCTF{b4n9_lu_ng3h3k_l4m4_4m4t_d4h_a51c97fe26}
```

## Description
"Pencatatan sipil adalah sistem dimana pemerintah mencatat peristiwa penting warga negara dan penduduknya." -Wikipedia-

`nc <ip> 20038`

## Difficulty
Tingkat kesulitan soal: medium

## Hints
> Intentionally left empty

## Tags
Heap Overflow, Tcache Poisoing, Safe Linking

## Deployment
- Install docker engine>=19.03.12 and docker-compose>=1.26.2.
- Run the container using:
    ```
    docker-compose up --build --detach
    ```

## Notes
Pakai GLIBC 2.33 milik ubuntu (libc6_2.33-0ubuntu9_amd64)