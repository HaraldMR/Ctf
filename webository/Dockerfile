FROM php:apache

# Expose port 80 for HTTP
EXPOSE 80

# Install Git
RUN apt-get update && apt-get install -y git

# Create a non-root user for Git repository access
RUN useradd -ms /bin/bash gituser

# Copy the contents of your Git repository to the Apache document root
COPY unnamed/. /var/www/html

# Set ownership and permissions for the Git repository
RUN chmod -R 700 /var/www/html/.git

COPY 10o2r-23njy2-ekui2o1-2o1j2o1.jpg /var/www/html

# Start Apache service
CMD ["apache2-foreground"]