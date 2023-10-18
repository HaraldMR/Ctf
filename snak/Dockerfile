FROM ubuntu

RUN apt-get update -y && \
    apt-get install -y xinetd strace && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

RUN useradd -m snaak

COPY app /home/snaak/
COPY run.sh /
COPY xinetd /etc/xinetd.d/snaak

WORKDIR /home/snaak

RUN chown -R root:root . && \
    chmod 444 flag.txt && \
    chmod a+x snak && \
    chmod +x /run.sh

EXPOSE 1337

CMD ["/usr/sbin/xinetd", "-dontfork"]