FROM ubuntu:22.04
MAINTAINER alpha <gys1120@gmail.com>
USER root

# run은 쉘에서 명령문을 실행한다.
RUN apt-get update && apt install -y software-properties-common
RUN add-apt-repository ppa:deadsnakes/ppa
RUN apt install -y python3.7
RUN apt install -y python3.7
RUN adduser ronfic-legacy
