FROM debian:bookworm

RUN apt-get update && \
    apt-get install -y --no-install-recommends gcc file python3 gdb procps  vim make libc6-dev socat && \
    rm -rf /var/lib/apt/lists/* && \
    useradd -m -u 1000 player

WORKDIR /home/player
COPY Makefile challenge.c  secret flag.txt ./
RUN make

# flag and binary owned by 'player' — the same user that will run the binary,
# since socat execs it after USER player below. No setuid needed.
RUN chown player:player challenge secret flag.txt && \
    chmod 500 challenge && \
    chmod 400 flag.txt secret

USER player
EXPOSE 1331

ENTRYPOINT ["socat", "TCP-LISTEN:1331,reuseaddr,fork", "EXEC:/home/player/challenge,stderr"]