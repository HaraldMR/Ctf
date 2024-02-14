# Use the official Apache base image
FROM httpd:latest

# Copy the website files to the Apache document root directory
COPY ./app/ /var/www/html/

# Set up access policies
RUN chown -R www-data:www-data /var/www/html \
    && chmod -R 555 /var/www/html

# Set the Apache server to listen on port 40007
EXPOSE 40007

# Start the Apache server
CMD ["httpd-foreground"]