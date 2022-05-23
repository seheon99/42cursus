# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seheon <seyu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/21 01:09:37 by seheon            #+#    #+#              #
#    Updated: 2020/09/23 18:44:55 by seheon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster
LABEL maintainer="seyu@student.42seoul.kr"

ARG	DEBIAN_FRONTEND=noninteractive

# RUN to install packages
# Installed mariadb-server instead of mysql-server
RUN	apt-get update && apt-get upgrade -y && \
	apt-get install -y --no-install-recommends --no-install-suggests \
		nginx \
		openssl \
		mariadb-server \
		php-fpm \
		php-mysql \
		php-curl \
		php-gd \
		php-mbstring \
		php-xml \
		php-xmlrpc \
		php-soap \
		php-intl \
		php-zip

# COPY and RUN to generate ROOT CA, SSL
COPY srcs/rootca_openssl.conf /tmp/seyu/rootca_openssl.conf
COPY srcs/host_openssl.conf /tmp/seyu/host_openssl.conf

RUN mkdir -p /etc/pki/tls/private/ && \
	mkdir -p /etc/pki/tls/certs/ && \
	openssl genrsa \
		-out /etc/pki/tls/private/ftserver-rootca.key \
		-passout pass:passwd \
		-aes256 \
		2048 && \
	openssl req \
		-passin pass:passwd \
		-out /etc/pki/tls/certs/ftserver-rootca.csr \
		-passout pass:passwd \
		-new \
		-key /etc/pki/tls/private/ftserver-rootca.key \
		-subj '/C=KR/ST=Seoul Gangnam-gu/L=Gaepo-dong/O=Innovation Academy/OU=42 seoul/CN=seyu' && \
	openssl x509 \
		-in /etc/pki/tls/certs/ftserver-rootca.csr \
		-out /etc/pki/tls/certs/ftserver-rootca.crt \
		-days 365 \
		-set_serial 1 \
		-signkey /etc/pki/tls/private/ftserver-rootca.key \
		-passin pass:passwd \
		-req \
		-extfile /tmp/seyu/rootca_openssl.conf \
		-extensions v3_ca && \
	openssl genrsa \
		-out /etc/pki/tls/private/ftserver.local.key \
		-passout pass:passwd \
		-aes256 \
		2048 && \
	cp /etc/pki/tls/private/ftserver.local.key /etc/pki/tls/private/ftserver.local.key.enc && \
	openssl rsa \
		-in /etc/pki/tls/private/ftserver.local.key.enc \
		-passin pass:passwd \
		-out /etc/pki/tls/private/ftserver.local.key && \
	openssl req \
		-passin pass:passwd \
		-out /etc/pki/tls/certs/ftserver.local.csr \
		-passout pass:passwd \
		-new \
		-key /etc/pki/tls/private/ftserver.local.key \
		-subj '/C=KR/ST=Seoul Gangnam-gu/L=Gaepo-dong/O=Innovation Academy/OU=42 seoul/CN=seyu' && \
	openssl x509 \
		-in /etc/pki/tls/certs/ftserver.local.csr \
		-out /etc/pki/tls/certs/ftserver.local.crt \
		-days 180 \
		-passin pass:passwd \
		-req \
		-CA /etc/pki/tls/certs/ftserver-rootca.crt \
		-CAkey /etc/pki/tls/private/ftserver-rootca.key \
		-CAcreateserial \
		-extfile /tmp/seyu/host_openssl.conf \
		-extensions v3_user

# COPY and RUN to setup nginx, wordpress, phpmyadmin, mysql
COPY srcs/ft_server.sites-available /etc/nginx/sites-available/ft_server
COPY srcs/init_mysql.sql /tmp/seyu/init_mysql.sql
COPY srcs/wordpress-5.5.1.tar /tmp/seyu/wordpress.tar
COPY srcs/wp-config.php /var/www/ft_server/wordpress/wp-config.php
COPY srcs/phpMyAdmin-5.0.2-english.tar.gz /tmp/seyu/phpmyadmin.tar.gz

COPY srcs/signin.html /var/www/ft_server/signin.html
COPY srcs/signin.css /var/www/ft_server/signin.css

RUN	rm -rf /etc/nginx/sites-enabled/default && \
	ln -s /etc/nginx/sites-available/ft_server /etc/nginx/sites-enabled/ && \
	tar -xf /tmp/seyu/wordpress.tar -C /var/www/ft_server/ && \
	tar -zxf /tmp/seyu/phpmyadmin.tar.gz -C /var/www/ft_server/ && \
	mv /var/www/ft_server/phpMyAdmin* /var/www/ft_server/phpmyadmin/ && \
	service mysql start && \
	mariadb < /tmp/seyu/init_mysql.sql && \
	service mysql stop

# Remove /tmp/seyu directory
RUN	rm -rf /tmp/seyu

# EXPOSE 80 for HTTP and 443 for HTTPS
EXPOSE 80 443

# Start container with mysql, nginx, php-fpm services
CMD	service mysql start; \
	service nginx start; \
	service php7.3-fpm start; \
	bash;
