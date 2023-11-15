FROM ubuntu

RUN apt-get update -y && \
    apt-get install -y xinetd strace libseccomp-dev build-essential && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

RUN useradd -m quest

COPY quest.c /home/quest/
COPY app /home/quest/
RUN gcc -o /home/quest/quest /home/quest/quest.c
COPY run.sh /
COPY xinetd /etc/xinetd.d/quest

WORKDIR /home/quest

RUN chown -R quest:quest . && \
    chmod 444 flag.txt && \
    chmod a+x quest && \
    chmod +x /run.sh

EXPOSE 1337

CMD ["/usr/sbin/xinetd", "-dontfork"]