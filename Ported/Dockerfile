FROM ubuntu:latest

# Install VSFTPD and other required packages
RUN apt-get update && apt-get install -y vsftpd

RUN mkdir /var/ftp

# Configure VSFTPD
RUN echo "listen_port=20344" >> /etc/vsftpd.conf
RUN echo "anonymous_enable=YES" >> /etc/vsftpd.conf
RUN echo "anon_root=/home/anonymous" >> /etc/vsftpd.conf
RUN echo "local_enable=YES" >> /etc/vsftpd.conf
RUN echo "write_enable=NO" >> /etc/vsftpd.conf
RUN echo "local_umask=022" >> /etc/vsftpd.conf
RUN echo "dirmessage_enable=YES" >> /etc/vsftpd.conf
RUN echo "use_localtime=YES" >> /etc/vsftpd.conf
RUN echo "xferlog_enable=YES" >> /etc/vsftpd.conf
RUN echo "connect_from_port_20=YES" >> /etc/vsftpd.conf
RUN echo "chroot_local_user=YES" >> /etc/vsftpd.conf
RUN echo "chroot_list_enable=NO" >> /etc/vsftpd.conf  # Disable chroot_list
RUN echo "secure_chroot_dir=/var/ftp" >> /etc/vsftpd.conf
RUN echo "allow_writeable_chroot=YES" >> /etc/vsftpd.conf
RUN echo "pam_service_name=vsftpd" >> /etc/vsftpd.conf



# Create a directory for anonymous files
RUN mkdir /home/anonymous
RUN chmod 755 /home/anonymous

# Add files to the anonymous directory
COPY shadow.old /home/anonymous/
COPY shadow.old.1 /home/anonymous/
COPY shadow.old.2 /home/anonymous/
COPY shadow.old.3 /home/anonymous/
COPY shadow.old.4 /home/anonymous/
COPY shadow.old.5 /home/anonymous/
COPY shadow.old.6 /home/anonymous/


# Create user
RUN useradd -m -d /home/jonas -s /bin/bash jonas
RUN echo "jonas:cyanide" | chpasswd

COPY flag /home/jonas/

# Expose the FTP port
EXPOSE 20344

# Start the VSFTPD server
CMD ["vsftpd", "/etc/vsftpd.conf"]
