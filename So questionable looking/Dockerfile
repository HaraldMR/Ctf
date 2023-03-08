FROM ubuntu

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get upgrade -y && apt-get install -y apache2 mysql-server php

RUN a2enmod rewrite
# RUN sed -i 's/AllowOverride None/AllowOverride All/' /etc/apache2/apache2.conf
# RUN sed -i 's/DirectoryIndex index\.html/DirectoryIndex index\.html index\.php/g' /etc/apache2/mods-enabled/dir.conf

COPY index.html /var/www/html/
COPY login.php /var/www/html/
COPY style.css /var/www/html/
COPY flag.php /var/www/html/
# COPY .htaccess /var/www/html/
COPY init.sql /docker-entrypoint-initdb.d/

EXPOSE 80

ENV DB_HOST=localhost
ENV DB_USER=root
ENV DB_PASS=password

ENTRYPOINT ["/usr/sbin/apache2ctl", "-D", "FOREGROUND"]