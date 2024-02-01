FROM gys1025/ubuntu:base-1.1.0
USER root
RUN add-apt-repository ppa:deadsnakes/ppa
RUN apt install -y python3.7 \
		   python3.7-distutils \
                   python3-pip 
		   # python3.7-dev python3.7-venv \ # virtual env를 설치하기 위한 패키지
		   # python3-dev default-libmysqlclient-dev build-essential # pip mysqlclient를 설치하기 위한 패키지
RUN mkdir /srv/app_server		   
ENTRYPOINT ["/bin/bash"]

# python3.7 - python3.7 버전
# python3.7-distutils - python3 pip 설치를 위한 패키지
# python3-pip - pip 설치
