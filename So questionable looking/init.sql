USE mysql;

CREATE DATABASE ctf_DB;

USE ctf_DB;

CREATE TABLE users (username VARCHAR(255) PRIMARY KEY, password VARCHAR(255));

INSERT INTO users (username, password) VALUES ('admin', 'ilikepasswordsthatarelongandhardtoremember');