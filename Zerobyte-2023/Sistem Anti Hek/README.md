# Sistem Anti Hek

by Lychnobyte

---

## Flag

```
0byteCTF{l0h_b4n9_k0k_lu_ng3h3k_s1st3m_gw3jh_44b7910c8f}
```

## Description
Sistem buatan anak bangsa sudah pasti aman dan anti hek!

`nc <ip> <port>`

## Difficulty
Tingkat kesulitan soal: medium-hard

## Hints
> Intentionally left empty

## Tags
Off-by-one, Format String, use-after-free, tcache poisoning

## Deployment
- Install docker engine>=19.03.12 and docker-compose>=1.26.2.
- Run the container using:
    ```
    docker-compose up --build --detach
    ```

## Notes
Pakai GLIBC 2.31 milik ubuntu 20.04.06 LTS