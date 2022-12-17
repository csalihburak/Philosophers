FROM alpine:3.13

RUN	apk update && apk upgrade && apk add --no-cache \
        nginx \
        openssl

RUN mkdir /etc/nginx/ssl
RUN mkdir -p /run/nginx

RUN openssl req -x509 -nodes -days 365 -subj "/C=TR/ST=ISTANBUL/O=42 ISTANBUL, Inc./CN=scoskun" \
        -addext "subjectAltName=DNS:scoskun.42.fr" \
        -newkey rsa:2048 -keyout /etc/nginx/ssl/scoskun.42.fr.key -out /etc/nginx/ssl/scoskun.42.fr.crt;

RUN pkill -f nginx & wait $!

RUN nginx -t

EXPOSE 443
EXPOSE 9000

ENTRYPOINT ["nginx", "-g", "daemon off;"]
