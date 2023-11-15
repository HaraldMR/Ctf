FROM ubuntu:focal

RUN apt-get update -y && \
    apt-get install -y xinetd strace libseccomp-dev && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

RUN useradd -m xorcade

COPY app /home/xorcade/
COPY run.sh /
COPY xinetd /etc/xinetd.d/xorcade

WORKDIR /home/xorcade

RUN chown -R root:root . && \
    chmod 444 flag.txt && \
    chmod a+x xorcade && \
    chmod +x /run.sh

EXPOSE 1337

CMD ["/usr/sbin/xinetd", "-dontfork"]