FROM alpine:3.16


RUN apk update && apk add --no-cache mariadb mariadb-client

RUN mkdir /var/run/mysqld;

ARG DB_NAME \
    DB_PASS \
    DB_USER \
    ROOT_PASS

RUN  chmod 777 /var/run/mysqld;
RUN sed -i "s|skip-networking|# skip-networking=0|g" /etc/my.cnf.d/mariadb-server.cnf;
RUN sed -i "s|.*bind-address*=.*|bind-address=0.0.0.0|g" /etc/my.cnf.d/mariadb-server.cnf;

RUN mysql_install_db --user=mysql --datadir=/var/lib/mysql

EXPOSE 3306

COPY requirements/mariadb/conf/create_db.sh .
RUN sh create_db.sh && rm create_db.sh
USER mysql
CMD ["/usr/bin/mysqld", "--skip-log-error"]