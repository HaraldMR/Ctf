# Oppsett av ctfd server

## VM
ctf.login.no er tidligere satt opp i DO med en droplet 8 GB RAM 4 vCPUs
Dette har fungert for over 100 brukere. For mindre ctfer kan det holde med en mindre instans.

CTF arkitekturen trenger 2 VM-er. En for CTFd/nettsiden og en for oppgavene/docker containerne.
Dette opsettet er satt opp på ubuntu og debian baserte systemer. Det er ikke testet på andre systemer.

## Installer docker og docker-compose

https://docs.docker.com/engine/install/
Husk post installation steps for å slippe sudo for docker kommandoer.


## Clone CTFd repo

git clone https://github.com/CTFd/CTFd.git


## Sett opp ctfd

bytt ut innhopldet av docker-compose.yml med Config/docker-compose.yml

kjør følgende kommando for å generere en secret key:
```bash
head -c 64 /dev/urandom > .ctfd_secret_key
```

Kjør `docker-compose up` for å starte serveren, legg til -d når du ser at alt fungerer som det skal i oppstarten, så starter den detached.


## Sett opp firewall og nginx

```bash
sudo apt update

sudo apt install nginx ufw

sudo ufw allow 'Nginx Full'

sudo ufw allow 'OpenSSH'

sudo ufw enable
```

sett filen ctf.login.no inn i /etc/nginx/sites-available/ctf.login.no
(endre navn på domenet på filen og inni filen om du skal nå serveren fra et annet sted)

lag en symlink til sites-enabled
```bash
sudo ln -s /etc/nginx/sites-available/ctf.login.no /etc/nginx/sites-enabled/ctf.login.no
```

reload nginx
```bash
sudo nginx -s reload
```


## Sett opp https med certbot og LetsEncrypt

Husk å sette opp DNS for domenet til ip adresse.

```bash
sudo apt-get update
sudo apt-get install software-properties-common
sudo add-apt-repository universe
sudo apt-get update

sudo apt-get install certbot python3-certbot-nginx
```

```bash
sudo certbot --nginx
```


## Importer tidligere ctfd

Anbefaler å kjøre en importering med zip filen som er lagt ved i dette repoet. Den inneholder en del oppgaver og config som er satt opp for login ctf. Husk å lage en ny bruker som du gjør til admin før du sletter den originale admin brukeren. brukernavnet og passordet er "admin".

Om dette ikke fungerer kan du fortsette med oppsettet under.


## Endre tema

Temaet som er brukt i login ctf er en modifisert versjon av pixo temaet. Du kan finne temaet her: https://github.com/hmrserver/CTFd-theme-pixo/tree/67abc2b8a444206061ad6f6070b5e5e17215336b

Temaet er fint, men har noen stygge scanlines og flickering som gjør det ekkelt for skjermer med høy refresh rate. Dette kan fikses ved å endre css filen som ligger under static/main.min.css. Last ned temaet til ~/CTFd/CTFd/themes/pixo og oppdater main.min.css til filen med samme navn i dette repoet.

Du kan bytte til temaet etter at du har satt opp serveren ved å gå til admin panelet og velge temaet.
Mens du endrer tema, kan du også legge til login favicon. filen heter loginfavicon.jpg her.


## Forside

Logg inn i admin panelet og gå til pages. Lag eller endre en page med navn "index". Her kan du legge inn innholdet i index.md filen i dette repoet. Oppdater informasjonen i teksten på forsiden til å passe til formålet.

Anbefaler også å lage en egen page for regler. denne kan linkes til på forsiden. I reglene kan det for eksempel være lurt å legge et flagg til en oppgave "Welcome" som låser opp alle andre oppgaver. Dette gjør at alle blir i det minste skummer igjennom reglene før de begynner å løse oppgaver.


## Mail

For større arrangementer er det lurt å skru på email autentisering. Det krever at du legger inn en email server som ctfd kan sende mail til brukerne fra. Første ctf-en ble satt opp med følgende innstillinger:

```
Mail From Address:
noreply+ctf@login.no

Mail Server Address:
outbound-mta.it.login.no

Mail Server Port:
587

[ ] Use Mail Server Username and Password
[ ] TLS/SSL
[X] STARTTLS
```