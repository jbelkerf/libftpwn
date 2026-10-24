FROM debian:bookworm

RUN apt-get update && \
    apt-get install -y --no-install-recommends gcc file python3 gdb procps  vim make libc6-dev socat && \
    rm -rf /var/lib/apt/lists/* && \
    useradd -m -u 1000 player

WORKDIR /home/player
COPY Makefile challenge.c   flag.txt ./
RUN make

RUN chown player:player challenge  flag.txt && \
    chmod 500 challenge && \
    chmod 400 flag.txt 

USER player
EXPOSE 1332

ENTRYPOINT ["socat", "TCP-LISTEN:1332,reuseaddr,fork", "EXEC:/home/player/challenge,stderr"]