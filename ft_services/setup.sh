#!/bin/bash

ECHO=/bin/echo

## USAGE
# ./setup.sh [init, clean, clear, docker, kubernetes, kuber, kube, k8s]
# init -> minikube 삭제 후 재시작 (도커 이미지 삭제)
# clean, clear -> minikube 정리 후 재시작 (도커 이미지 유지)
# docker -> 도커 이미지 최신화
# kubernetes, kuber, kube, k8s -> minikube 설정파일을 kubectl 을 통해 적용
# 매개변수가 없으면 clear, docker, kubernetes 순서로 진행
# ex) ./setup.sh kube -> 도커파일은 건들이지 않고 쿠버네티스 설정만 다시 진행
#
# ./setup.sh exec [name]
# kubectl exec -it $(kubectl get pods | grep [name] | awk '{print $1}') -- /bin/sh
# ex) ./setup.sh exec ftps --> ftps가 실행되고 있는 컨테이너 쉘에 접근

# Echo Colors
NOCOLOR=$'\033[0m'
RED=$'\033[31m'
GREEN=$'\033[32m'
ORANGE=$'\033[33m'
BLUE=$'\033[34m'
PURPLE=$'\033[35m'
CYAN=$'\033[36m'
LIGHTGRAY=$'\033[37m'
DARKGRAY=$'\033[90m'
LIGHTRED=$'\033[91m'
LIGHTGREEN=$'\033[92m'
YELLOW=$'\033[93m'
LIGHTBLUE=$'\033[94m'
LIGHTPURPLE=$'\033[95m'
LIGHTCYAN=$'\033[96m'
WHITE=$'\033[97m'

# Echo Characters
LINE_CLEAR=$'\33[2K'$'\r'
CHECK=$'\u2714'
CROSS=$'\u274C'

function show_foreward()
{
	${ECHO} "Services to install (${#SERVICE_NAME[@]}/${#SERVICE_TODO_NAME[@]})"
	for name in "${SERVICE_NAME[@]}"; do
		${ECHO} " ${GREEN}${CHECK}${NOCOLOR} $name"
	done
	if [ ${#SERVICE_NAME[@]} -ne ${#SERVICE_TODO_NAME[@]} ]; then
		${ECHO} "Services to DO NOT install ($(expr ${#SERVICE_TODO_NAME[@]} - ${#SERVICE_NAME[@]})/8)"
		for name in "${SERVICE_TODO_NAME[@]}"; do
			if [ -z $(printf '%s\n' "${SERVICE_NAME[@]}" | grep -P "^$name$") ]; then
				${ECHO} " ${RED}${CROSS}${NOCOLOR} $name"
			fi
		done
	fi
	${ECHO}
}

function initialize()
{
	${ECHO} "----------------------clear-everything----------------------"
	eval $(minikube docker-env)
	${ECHO} -n Deleting ${ORANGE}minikube${NOCOLOR}
	minikube delete >> setup.log 2>> error.log
	${ECHO} ${LINE_CLEAR}Delete ${BLUE}minikube${NOCOLOR} ${GREEN}Successfully${NOCOLOR}
	${ECHO} "----------------------clear-everything----------------------"
}

function clear_stuff()
{
	${ECHO} "-------------------------initialize-------------------------"
	kubectl config set-context --current --namespace= >> setup.log 2>> error.log
	${ECHO} -n Deleting the ${ORANGE}namespace${NOCOLOR} of kubernetes: ${ORANGE}ft-services${NOCOLOR}
	kubectl delete namespace ft-services >> setup.log 2>> error.log
	${ECHO} ${LINE_CLEAR}Delete the ${BLUE}namespace${NOCOLOR} of kubernetes ${GREEN}Successfully${NOCOLOR}: ${BLUE}ft-services${NOCOLOR}
	${ECHO} -n Deleting the ${ORANGE}namespace${NOCOLOR} of kubernetes: ${ORANGE}metallb-system${NOCOLOR}
	kubectl delete namespace metallb-system >> setup.log 2>> error.log
	${ECHO} ${LINE_CLEAR}Delete the ${BLUE}namespace${NOCOLOR} of kubernetes ${GREEN}Successfully${NOCOLOR}: ${BLUE}metallb-system${NOCOLOR}
	${ECHO} -n Deleting the ${ORANGE}PersistentVolume${NOCOLOR} of kubernetes: ${ORANGE}influxdb${NOCOLOR}
	kubectl delete -f srcs/influxdb/influxdb-volume.yaml >> setup.log 2>> error.log
	${ECHO} ${LINE_CLEAR}Delete the ${BLUE}PersistentVolume${NOCOLOR} of kubernetes ${GREEN}Successfully${NOCOLOR}: ${BLUE}influxdb${NOCOLOR}
	${ECHO} -n Deleting the ${ORANGE}PersistentVolume${NOCOLOR} of kubernetes: ${ORANGE}mysql${NOCOLOR}
	kubectl delete -f srcs/mysql/mysql-volume.yaml >> setup.log 2>> error.log
	${ECHO} ${LINE_CLEAR}Delete the ${BLUE}PersistentVolume${NOCOLOR} of kubernetes ${GREEN}Successfully${NOCOLOR}: ${BLUE}mysql${NOCOLOR}
	${ECHO} "-------------------------initialize-------------------------"
	${ECHO} ""
}

# Start minikube
function start_minikube()
{
	${ECHO} "--------------------------minikube--------------------------"
	minikube start --driver=docker
	EXIT_STATUS=$?
	if [ ${EXIT_STATUS} -ne 0 ]; then
		exit ${EXIT_STATUS}
	fi
	${ECHO} "--------------------------minikube--------------------------"
	${ECHO} ""
}

# Build docker images
function build_docker()
{
	${ECHO} -n "Building ${ORANGE}$1${NOCOLOR} image... "
	docker build -t service_$1 srcs/$1/image >> setup.log 2>> error.log
	EXIT_STATUS=$?
	if [ ${EXIT_STATUS} -eq 0 ]; then
		${ECHO} ${LINE_CLEAR}Builded ${BLUE}$1 ${NOCOLOR}image ${GREEN}Successfully${NOCOLOR}
	else
		${ECHO} ${LINE_CLEAR}${ORANGE}docker build $1${NOCOLOR} returned a non-zero code: ${RED}${EXIT_STATUS}${NOCOLOR}
		exit ${EXIT_STATUS}
	fi
	return ${EXIT_STATUS}
}
function start_docker()
{
	${ECHO} "---------------------------docker---------------------------"
	eval $(minikube docker-env)
	for name in "${SERVICE_NAME[@]}"; do
		if [ "${name}" == "metallb" ] ; then
			continue
		fi
		build_docker $name
	done
	${ECHO} "---------------------------docker---------------------------"
	${ECHO} ""
}

function apply_kube_metallb()
{
	if [ -n "$(kubectl get configmap --namespace=metallb-system | grep config)" ]; then
		kubectl delete configmap config --namespace=metallb-system >> setup.log 2>> error.log
	fi
	${ECHO} -n "Apply ${ORANGE}metallb${NOCOLOR} to minikube through kubectl... "
	MINIKUBE_IP=$(minikube ip)
	sed -i "s/MINIKUBE_IP/$MINIKUBE_IP/" srcs/metallb/metallb-configmap.yaml
	minikube addons enable metallb >> setup.log 2>> error.log
	kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)" >> setup.log 2>> error.log
	kubectl apply -f srcs/metallb/ >> setup.log 2>> error.log
	EXIT_STATUS=$?
	sed -i "s/$MINIKUBE_IP/MINIKUBE_IP/" srcs/metallb/metallb-configmap.yaml
	if [ ${EXIT_STATUS} -eq 0 ]; then
		${ECHO} ${LINE_CLEAR}${BLUE}metallb ${NOCOLOR}was ${GREEN}Successfully${NOCOLOR} applied to minikube.
	else
		${ECHO} ${LINE_CLEAR}${ORANGE}metallb ${NOCOLOR}returned a non-zero code: ${RED}${EXIT_STATUS}${NOCOLOR}
		exit ${EXIT_STATUS}
	fi
	return ${EXIT_STATUS}
}
function apply_kube()
{
	${ECHO} -n "Apply ${ORANGE}$1${NOCOLOR} to minikube through kubectl... "
	kubectl apply -f srcs/$1/ >> setup.log 2>> error.log
	EXIT_STATUS=$?
	if [ ${EXIT_STATUS} -eq 0 ]; then
		${ECHO} ${LINE_CLEAR}${BLUE}$1 ${NOCOLOR}was ${GREEN}Successfully${NOCOLOR} applied to minikube.
	else
		${ECHO} ${LINE_CLEAR}kubectl apply ${ORANGE}$1${NOCOLOR} returned a non-zero code: ${RED}${EXIT_STATUS}${NOCOLOR}
		exit ${EXIT_STATUS}
	fi
	return ${EXIT_STATUS}
}
function start_kubernetes()
{
	${ECHO} "-------------------------kubernetes-------------------------"
	${ECHO} -n "Creating namespace ${ORANGE}ft-services${NOCOLOR} on minikube through kubectl... "
	kubectl create namespace ft-services >> setup.log 2>> error.log
	kubectl config set-context --current --namespace=ft-services >> setup.log 2>> error.log
	${ECHO} ${LINE_CLEAR}Created namespace ${BLUE}ft-services ${GREEN}Successfully${NOCOLOR}

	${ECHO} -n "Creating ${ORANGE}secrets${NOCOLOR} on minikube through kubectl... "
	${ECHO} ${LINE_CLEAR}Created ${BLUE}secrets ${GREEN}Successfully${NOCOLOR}

	for name in "${SERVICE_NAME[@]}"; do
		if [ "${name}" == "metallb" ]; then
			apply_kube_metallb
		else
			apply_kube $name
		fi
	done
	${ECHO} "-------------------------kubernetes-------------------------"
	${ECHO} ""
}

# ----------------------------------
# Start of script
# ----------------------------------
SERVICE_NAME=("metallb" "grafana" "wordpress" "nginx" "phpmyadmin" "ftps" "influxdb" "mysql")
SERVICE_TODO_NAME=("metallb" "grafana" "wordpress" "nginx" "phpmyadmin" "ftps" "influxdb" "mysql")

show_foreward
rm -f setup.log error.log
if [ $# -ge 1 ]; then
	if [ "$1" == "pod" -o "$1" == "exec" ]; then
		kubectl exec -it $(kubectl get pods | grep "$2" | awk '{print $1}') -- /bin/sh
		EXIT_STATUS=$?
		exit ${EXIT_STATUS}
	fi
	for command in "$@"; do
		if [ "$command" == "clear" -o "$command" == "clean" ]; then
			clear_stuff
		elif [ "$command" == "initialize" -o "$command" == "init" ]; then
			initialize
		elif [ "$command" == "minikube" ]; then
			start_minikube
		elif [ "$command" == "kubernetes" -o "$command" == "kuber" -o "$command" == "kube" -o "$command" == "k8s" ]; then
			start_kubernetes
		elif [ "$command" == "docker" ]; then
			start_docker
		fi
	done
else
	clear_stuff
	start_minikube
	start_docker
	start_kubernetes
fi
