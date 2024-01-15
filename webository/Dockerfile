# Use a base image with Apache and PHP
FROM php:apache

# Expose port 443 for HTTPS
EXPOSE 443

# Install Git
RUN apt-get update && apt-get install -y git

# Create a non-root user for Git repository access
RUN useradd -ms /bin/bash gituser

# Set up Apache configuration for HTTPS
COPY ssl.conf /etc/apache2/sites-available/default-ssl.conf
RUN a2enmod ssl && a2ensite default-ssl

# Copy your Git repository to the Apache document root
COPY unnamed/* /var/www/html

# Set ownership and permissions for the Git repository
RUN chmod -R 700 /var/www/html/*

COPY 10o2r-23njy2-ekui2o1-2o1j2o1.jpg /var/www/html

# Start Apache service
CMD ["apache2-foreground"]