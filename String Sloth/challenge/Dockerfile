FROM ubuntu

RUN apt-get update -y && \
    apt-get install -y xinetd strace libseccomp-dev build-essential && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

RUN useradd -m sloth

COPY sloth.c /home/sloth/
COPY app /home/sloth/
RUN gcc -o /home/sloth/sloth /home/sloth/sloth.c
COPY run.sh /
COPY xinetd /etc/xinetd.d/sloth

WORKDIR /home/sloth

RUN chown -R sloth:sloth . && \
    chmod 444 flag.txt && \
    chmod a+x sloth && \
    chmod +x /run.sh

EXPOSE 1337

CMD ["/usr/sbin/xinetd", "-dontfork"]