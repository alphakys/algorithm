FROM ubuntu:22.04
MAINTAINER alpha <gys1120@gmail.com>
USER root

# run은 쉘에서 명령문을 실행한다.
RUN apt-get update && apt install -y software-properties-common
RUN add-apt-repository ppa:deadsnakes/ppa
RUN apt install -y python3.7
RUN apt install -y python3.7
RUN adduser ronfic-legacy

1. root 계정 초기 비밀번호 설정 passwd 1004
2. sudo 설치하기 - apt install sudo
3. adduser alpha
4. usermod -aG sudo alpha
5. sudo apt install software-properties-common
6. sudo add-apt-repository ppa:deadsnakes/ppa
7. sudo apt install python3.7
8. sudo apt-get install -y python3-pip \
9-1. python3.7 pip 작동 안됨 \
  ! 해결 sudo apt install python3.7-distutils \
9-2. venv 작동 안됨
  ! 해결 sudo apt-get install python3.7-dev python3.7-venv
9. sudo apt install -y nginx
10. sudo apt install ufw

Runtime privilege and Linux capabilities
Option	Description
--cap-add	Add Linux capabilities
--cap-drop	Drop Linux capabilities
--privileged	Give extended privileges to this container
--device=[]	Allows you to run devices inside the container without the --privileged flag.
By default, Docker containers are “unprivileged” and cannot, for example, run a Docker daemon inside a Docker
By default, Docker containers are "unprivileged" and cannot, for example, run a Docker daemon inside a Docker
container. This is because by default a container is not allowed to access any devices, but a “privileged” container
container. This is because by defautl a container is not allowed to access any devices, but a "privileged" container
is given access to all devices (see the documentation on cgroups devices).
is gived access to all devices (see the documentation on cgroups devices).


# 아직 검증 안됨 !! sudo 명령어를 써도 ufw가 작동하지 않을 때!
  update-alternatives --set iptables /usr/sbin/iptables-legacy
11. sudo ufw allow Nginx Full

12. ctrl + p + q 컨테이너 종료 없이 나가기

docker commit -m "nginx install completed"