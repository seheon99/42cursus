# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyu <seyu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/05 16:18:26 by seyu              #+#    #+#              #
#    Updated: 2021/02/19 14:34:58 by seyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.13.1
LABEL maintainer="seyu@student.42seoul.kr"

COPY srcs/phpMyAdmin-5.0.4-english.tar.xz /tmp/seyu/phpMyAdmin-5.0.4-english.tar.xz

RUN	apk update && apk upgrade --ignore busybox && \
	apk add \
		php7 \
		php7-fpm \
		php7-mysqli \
		php7-mbstring \
		php7-json \
		php7-session \
		nginx \
		telegraf && \
	mkdir -p /run/nginx && \
	mkdir -p /var/www && \
	mkdir -p /etc/nginx/sites-available && \
	mkdir -p /etc/nginx/sites-enabled && \
	\
	tar -xf /tmp/seyu/phpMyAdmin-5.0.4-english.tar.xz && \
	mv ./phpMyAdmin-5.0.4-english /var/www/phpmyadmin && \
	rm -rf /tmp/seyu

COPY srcs/config.inc.php /var/www/phpmyadmin/config.inc.php
COPY srcs/telegraf.conf /etc/telegraf/telegraf.conf
COPY srcs/www.conf /etc/php7/php-fpm.d/www.conf
COPY srcs/nginx.conf /etc/nginx/nginx.conf
COPY srcs/phpmyadmin.ft-services.conf /etc/nginx/sites-available/phpmyadmin.ft-services.conf
RUN	ln -s /etc/nginx/sites-available/phpmyadmin.ft-services.conf \
			/etc/nginx/sites-enabled/phpmyadmin.ft-services.conf

EXPOSE 5000

ENTRYPOINT	telegraf & php-fpm7 & nginx -g 'daemon off;'