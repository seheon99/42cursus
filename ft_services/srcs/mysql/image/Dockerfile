# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyu <seyu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/19 14:20:12 by seyu              #+#    #+#              #
#    Updated: 2021/02/21 01:48:44 by seyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.13.1
LABEL maintainer="seyu@student.42seoul.kr"

RUN apk update && apk upgrade --ignore busybox && \
	apk add \
		mysql \
		mysql-client \
		telegraf && \
	mkdir -p /run/mysqld

COPY srcs/telegraf.conf /etc/telegraf/telegraf.conf
COPY srcs/init_docker.sh ./init_docker.sh
COPY srcs/init_mysql.sh ./init_mysql.sh

EXPOSE 3306

ENTRYPOINT sh init_docker.sh