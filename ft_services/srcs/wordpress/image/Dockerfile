# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyu <seyu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/19 13:27:56 by seyu              #+#    #+#              #
#    Updated: 2021/02/19 14:35:52 by seyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.13.1
LABEL maintainer="seyu@student.42seoul.kr"

COPY srcs/wordpress-5.6.1-ko_KR.tar.gz /tmp/seyu/wordpress-5.6.1-ko_KR.tar.gz

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
	tar -xf /tmp/seyu/wordpress-5.6.1-ko_KR.tar.gz && \
	mv ./wordpress /var/www/wordpress && \
	rm -rf /tmp/seyu

COPY srcs/wp-config.php /var/www/wordpress/wp-config.php
COPY srcs/telegraf.conf /etc/telegraf/telegraf.conf
COPY srcs/www.conf /etc/php7/php-fpm.d/www.conf
COPY srcs/nginx.conf /etc/nginx/nginx.conf
COPY srcs/wordpress.ft-services.conf /etc/nginx/sites-available/wordpress.ft-services.conf
RUN ln -s /etc/nginx/sites-available/wordpress.ft-services.conf \
			/etc/nginx/sites-enabled/wordpress.ft-services.conf

EXPOSE 5050

ENTRYPOINT	telegraf & php-fpm7 & nginx -g 'daemon off;'