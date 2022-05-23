# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyu <seyu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 22:00:40 by seyu              #+#    #+#              #
#    Updated: 2021/02/20 16:53:44 by seyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.13.1
LABEL maintainer="seyu@student.42seoul.kr"

RUN apk update && apk upgrade --ignore busybox && \
	apk add \
		nginx \
		openssl \
		telegraf && \
	mkdir -p /run/nginx && \
	mkdir -p /etc/nginx/sites-available && \
	mkdir -p /etc/nginx/sites-enabled && \
	mkdir -p /var/www/nginx.ft-services && \
	mkdir -p /etc/pki/tls/certs && \
	mkdir -p /etc/pki/tls/private && \
	\
	openssl req \
		-x509 \
		-nodes \
		-days 365 \
		-newkey rsa:2048 \
		-subj '/C=KR/ST=Seoul Gangnam-gu/L=Gaepo-dong/O=Innovation Academy/OU=42 seoul/CN=seyu' \
		-keyout /etc/pki/tls/private/nginx.ft-services.key \
		-out /etc/pki/tls/certs/nginx.ft-services.crt

COPY srcs/nginx.conf /etc/nginx/nginx.conf
COPY srcs/telegraf.conf /etc/telegraf/telegraf.conf
COPY srcs/nginx.ft-services.conf /etc/nginx/sites-available/nginx.ft-services.conf
RUN	ln -s /etc/nginx/sites-available/nginx.ft-services.conf \
			/etc/nginx/sites-enabled/nginx.ft-services.conf

EXPOSE 80 443

ENTRYPOINT telegraf & nginx -g 'daemon off;'