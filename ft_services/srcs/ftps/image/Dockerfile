# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyu <seyu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/19 21:50:40 by seyu              #+#    #+#              #
#    Updated: 2021/02/20 01:30:36 by seyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.13.1
LABEL maintainer="seyu@student.42seoul.kr"

RUN apk update && apk upgrade --ignore busybox && \
	apk add \
		vsftpd \
		openssl \
		telegraf && \
	adduser -D seyu && \
	echo 'seyu:seyuftps' | chpasswd && \
	mkdir -p /etc/pki/tls/private && \
	mkdir -p /etc/pki/tls/certs && \
	openssl req \
		-x509 \
		-nodes \
		-days 365 \
		-newkey rsa:2048 \
		-subj '/C=KR/ST=Seoul Gangnam-gu/L=Gaepo-dong/O=Innovation Academy/OU=42 seoul/CN=seyu' \
		-keyout /etc/pki/tls/private/vsftpd.key \
		-out /etc/pki/tls/certs/vsftpd.crt
COPY srcs/vsftpd.conf /etc/vsftpd/vsftpd.conf
COPY srcs/telegraf.conf /etc/telegraf/telegraf.conf

EXPOSE 20 21 21000 21001

ENTRYPOINT telegraf & vsftpd /etc/vsftpd/vsftpd.conf && sleep 5