FROM ubuntu:focal

RUN apt-get update -y && \
    apt-get install -y xinetd strace libseccomp-dev && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

RUN useradd -m sloth

COPY app /home/sloth/
COPY run.sh /
COPY xinetd /etc/xinetd.d/sloth

WORKDIR /home/sloth

RUN chown -R root:root . && \
    chmod 444 flag.txt && \
    chmod a+x sloth && \
    chmod +x /run.sh

EXPOSE 1337

CMD ["/usr/sbin/xinetd", "-dontfork"]