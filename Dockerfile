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

docker cp는 container에 있는 파일을 local machine(filesystem)에 복사 할 수 있다.
docker cp container id:/home/app/app name /home/ubuntu/app
# 응용 .을 써서 디렉토리가 통째로 복사되는게 아닌 디렉토리 하위의 파일들만 복사되는지 확인해보자
docker cp container id:/home/app/app name/. /home/ubuntu/app

13. pip mysqlclient 설치 시 필요한 ubuntu packages
sudo apt install python3-dev default-libmysqlclient-dev build-essential
pip install mysqlclient

14. docker image를 통해 설치한 운영체제에 기본 에디터가 설치되어 있지 않다.
그래서 sudo apt-get install vim-gtk로 vim 설치

15. 장고를 development server를 뛰우려면 collect static과 같은 곳곳에 퍼져있는 static 파일들을 상용서버로 띄우기 전에 장고 폴더로 모아주는 명령어를
작성해줘야 상용 서버에서 static 파일들을 적절히 서빙 할 수 있다. 지금까지 나는 debug=True에서 test를 해보았기 때문에 디버그 모드에서는 static 파일들을 모아줄 필요가
없었기 때문에 이런 착오를 일으키게 된거 같다.

16. collect static 완료 그런데 admin에서 제대로 css가 안나옴
이유는 장고 서버는 웹서버(아파치 nginx와 같은 정적파일을 주요! 기능으로 다루는)의 역할을 하지 않기 때문
그럼 결론은 nginx를 연결해야 한다.!

17. nginx django 연결 완료
18. 쿠버네티스를 공부할 지 젠킨스까지 붙일지 고민됨
19. 쿠버네티스 대시보드 띄우기 및 echoserver image를 가지고 쿠버네티스 deployment까지 했음