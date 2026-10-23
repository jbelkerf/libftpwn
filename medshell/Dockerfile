
FROM debian:bookworm

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        gcc make libc6-dev \
        libseccomp-dev \
        libcapstone-dev \
        socat \
    && rm -rf /var/lib/apt/lists/* && \
    useradd -m -u 1000 player

RUN apt-get update && apt-get install -y strace
WORKDIR /home/player

COPY Makefile challenge.c flag.txt shellcode-raw run.sh ./

RUN make && \
    chmod +x /home/player/run.sh /home/player/challenge && \
    chown -R player:player /home/player

USER player

EXPOSE 1335

ENTRYPOINT ["socat", "-d", "-d", "TCP-LISTEN:1335,reuseaddr,fork", "EXEC:/home/player/run.sh flag.txt,stderr"]
