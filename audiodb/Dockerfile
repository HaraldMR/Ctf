# Use the official Apache base image
FROM ubuntu

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get upgrade -y && apt-get install -y apache2

# Copy the website files to the Apache document root directory
COPY ./app/ /var/www/html/

# Set up access policies
RUN chown -R www-data:www-data /var/www/html \
    && chmod -R 555 /var/www/html

# Set the Apache server to listen on port 80
EXPOSE 80

# Start the Apache server
ENTRYPOINT ["/usr/sbin/apache2ctl", "-D", "FOREGROUND"]