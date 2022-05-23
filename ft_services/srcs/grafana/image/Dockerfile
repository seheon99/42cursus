# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seyu <seyu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/12 04:20:36 by seyu              #+#    #+#              #
#    Updated: 2021/02/21 00:00:39 by seyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.13.1
LABEL maintainer="seyu@student.42seoul.kr"

COPY srcs/telegraf.conf /etc/telegraf/telegraf.conf

RUN apk update && apk upgrade --ignore busybox && \
	apk add \
		grafana \
		telegraf

COPY srcs/datasources.yaml /usr/share/grafana/conf/provisioning/datasources/datasources.yaml
COPY srcs/dashboards.yaml /usr/share/grafana/conf/provisioning/dashboards/dashboards.yaml
COPY srcs/dashboards /usr/share/grafana/public/dashboards

EXPOSE 3000

ENTRYPOINT	telegraf & grafana-server -homepath /usr/share/grafana