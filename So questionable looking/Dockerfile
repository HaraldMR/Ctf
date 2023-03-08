FROM ubuntu

RUN apt-get update -y 
RUN apt-get upgrade -y 
RUN apt-get install -y apache2 
RUN apt-get install -y mysql-server 
RUN apt-get install -y php

COPY index.html /var/www/html/
COPY login.php /var/www/html/
COPY style.css /var/www/html/
COPY flag.php /var/www/html/
COPY init.sql /docker-entrypoint-initdb.d/

EXPOSE 80

ENV DB_HOST=localhost
ENV DB_USER=root
ENV DB_PASS=password

ENTRYPOINT ["/usr/sbin/apache2ctl", "-D", "FOREGROUND"]