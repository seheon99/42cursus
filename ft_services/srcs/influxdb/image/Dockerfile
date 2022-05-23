# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyu <seyu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/05 17:01:21 by seyu              #+#    #+#              #
#    Updated: 2021/02/24 04:39:14 by seyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.13.1
LABEL maintainer="seyu@student.42seoul.kr"

COPY srcs/telegraf.conf /etc/telegraf/telegraf.conf

RUN apk update && apk upgrade --ignore busybox && \
	apk add \
		influxdb \
		telegraf

EXPOSE 8086

ENTRYPOINT telegraf & influxd run -config /etc/influxdb.conf