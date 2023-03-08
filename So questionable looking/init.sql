USE mysql;

CREATE DATABASE ctf_DB;

USE ctf_DB;

CREATE TABLE users (username VARCHAR(255) PRIMARY KEY, password VARCHAR(255));

INSERT INTO users (username, password) VALUES ('admin', 'ilikepasswordsthatarelongandhardtoremember');
INSERT INTO users (username, password) VALUES ('Admin', 'reallylongpassword');
INSERT INTO users (username, password) VALUES ('admin', '7hHr5Amn3KL8cCi##89');

