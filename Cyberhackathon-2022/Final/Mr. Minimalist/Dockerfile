FROM ubuntu:24.04
ENV DEBIAN_FRONTEND=noninteractive

# Challenge setup. Not important.
RUN apt-get -y update && \
    apt-get -y install xinetd && \
    apt clean all && \
    rm -rf /var/lib/apt/lists/*

RUN groupadd -g 1337 -r ctf && useradd -u 1337 -r -g ctf ctf

WORKDIR /home/ctf

RUN ldd /bin/ls /bin/cat /bin/sh | grep "=> /" | awk '{print $3}' > required_libs.txt && \
    for lib in $(cat required_libs.txt); do cp --parent "$lib" /home/ctf/ ; done && \
    cp --parent /lib64/ld-linux-x86-64.so.2 /home/ctf/ && \
    rm -fr required_libs.txt

RUN mkdir /home/ctf/dev && \
    mknod /home/ctf/dev/null c 1 3 && \
    mknod /home/ctf/dev/zero c 1 5 && \
    mknod /home/ctf/dev/random c 1 8 && \
    mknod /home/ctf/dev/urandom c 1 9 && \
    chmod 666 /home/ctf/dev/*

RUN mkdir /home/ctf/bin && \
    cp /bin/sh /home/ctf/bin && \
    cp /bin/ls /home/ctf/bin && \
    cp /bin/cat /home/ctf/bin

RUN <<EOF cat >> /etc/xinetd.d/ctf
service ctf
{
    disable = no
    socket_type = stream
    protocol    = tcp
    wait        = no
    user        = root
    type        = UNLISTED
    port        = 9999
    bind        = 0.0.0.0
    server      = /usr/sbin/chroot
    # replace helloworld to your program
    server_args = --userspec=1337:1337 /home/ctf ./chall
    banner_fail = /etc/banner_fail
    # safety options
    per_source	= 10 # the maximum instances of this service per source IP address
    rlimit_cpu	= 20 # the maximum number of CPU seconds that the service may use
    #rlimit_as  = 1024M # the Address Space resource limit for the service
    #access_times = 2:00-9:00 12:00-24:00
}
EOF

RUN echo "Blocked by ctf_xinetd" > /etc/banner_fail

RUN <<EOF cat >> /etc/start.sh
#!/bin/sh
# Add your startup script

# DO NOT DELETE
/sbin/xinetd -f /etc/xinetd.d/ctf -pidfile /run/xinetd.pid -limit 1000 -reuse;
/bin/sleep infinity;
EOF

RUN chmod 500 /etc/start.sh
RUN chmod 444 /etc/xinetd.d/ctf

COPY ./src/ /home/ctf/

RUN chown -R root:ctf /home/ctf && \
    chmod -R 750 /home/ctf && \
    chmod 555 /home/ctf/*.txt && \
    rm -f /home/ctf/chall.asm && \
    rm -f /home/ctf/Makefile

# The challenge is working on port 9999

CMD ["/etc/start.sh"]
