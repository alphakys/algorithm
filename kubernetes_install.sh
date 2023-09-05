#!/bin/bash
echo "Enter your root password : "
read pw

echo $pw | sudo -S ufw disable
echo $pw | sudo -S swapoff -a && sudo sed -i '/swap/s/^/#/' /etc/fstab 
echo $pw | sudo -S
cat <<EOF | echo $pw | sudo -S tee /etc/modules-load.d/k8s.conf
br_netfilter
EOF

cat <<EOF | echo $pw | sudo -S tee /etc/sysctl.d/k8s.conf
net.bridge.bridge-nf-call-ip6tables = 1
net.bridge.bridge-nf-call-iptables = 1
EOF

echo $pw | sudo -S sysctl --system

echo "xsBNBGKItdQBCADWmKTNZEYWgXy73FvKFY5fRro4tGNa4Be4TZW3wZpct9Cj8EjykU7S9EPoJ3EdKpxFltHRu7QbDi6LWSNA4XxwnudQrYGxnxx6Ru1KBHFxHhLfWsvFcGMwit/znpxtIt9UzqCm2YTEW5NUnzQ4rXYqVQK2FLG4weYJ5bKwkY+ZsnRJpzxdHGJ0pBiqwkMT8bfQdJymUBown+SeuQ2HEqfjVMsIRe0dweD2PHWeWo9fTXsz1Q5abiGckyOVyoN9//DgSvLUocUcZsrWvYPaN+o8lXTO3GYFGNVsx069rxarkeCjOpiQOWrQmywXISQudcusSgmmgfsRZYW7FDBy5MQrABEBAAHNUVJhcHR1cmUgQXV0b21hdGljIFNpZ25pbmcgS2V5IChjbG91ZC1yYXB0dXJlLXNpZ25pbmcta2V5LTIwMjItMDMtMDctMDhfMDFfMDEucHViKcLAYgQTAQgAFgUCYoi11AkQtT3IDRPt7wUCGwMCGQEAAMGoCAB8QBNIIN3Q2D3aahrfkb6axd55zOwR0tnriuJRoPHoNuorOpCv9aWMMvQACNWkxsvJxEF8OUbzhSYjAR534RDigjTetjK2i2wKLz/kJjZbuF4ZXMynCm40eVm1XZqU63U9XR2RxmXppyNpMqQO9LrzGEnNJuh23icaZY6no12axymxcle/+SCmda8oDAfa0iyA2iyg/eU05buZv54MC6RB13QtS+8vOrKDGr7RYp/VYvQzYWm+ck6DvlaVX6VB51BkLl23SQknyZIJBVPm8ttU65EyrrgG1jLLHFXDUqJ/RpNKq+PCzWiyt4uy3AfXK89RczLu3uxiD0CQI0T31u/IzsBNBGKItdQBCADIMMJdRcg0Phv7+CrZz3xRE8Fbz8AN+YCLigQeH0B9lijxkjAFr+thB0IrOu7ruwNY+mvdP6dAewUur+pJaIjEe+4s8JBEFb4BxJfBBPuEbGSxbi4OPEJuwT53TMJMEs7+gIxCCmwioTggTBp6JzDsT/cdBeyWCusCQwDWpqoYCoUWJLrUQ6dOlI7s6p+iIUNIamtyBCwb4izs27HdEpX8gvO9rEdtcb7399HyO3oD4gHgcuFiuZTpvWHdn9WYwPGM6npJNG7crtLnctTR0cP9KutSPNzpySeAniHx8L9ebdD9tNPCWC+OtOcGRrcBeEznkYh1C4kzdP1ORm5upnknABEBAAHCwF8EGAEIABMFAmKItdQJELU9yA0T7e8FAhsMAABJmAgAhRPk/dFj71bU/UTXrkEkZZzE9JzUgan/ttyRrV6QbFZABByf4pYjBj+yLKw3280//JWurKox2uzEq1hdXPedRHICRuh1Fjd00otaQ+wGF3kY74zlWivB6Wp6tnL9STQ1oVYBUv7HhSHoJ5shELyedxxHxurUgFAD+pbFXIiK8cnAHfXTJMcrmPpC+YWEC/DeqIyEcNPkzRhtRSuERXcq1n+KJvMUAKMD/tezwvujzBaaSWapmdnGmtRjjL7IxUeGamVWOwLQbUr+34MwzdeJdcL8fav5LA8Uk0ulyeXdwiAK8FKQsixI+xZvz7HUs8ln4pZwGw/TpvO9cMkHogtgzQ==" | base64 -d | echo $pw | sudo -S apt-key --keyring /usr/share/keyrings/cloud.google.gpg add -

echo "deb [signed-by=/usr/share/keyrings/cloud.google.gpg] https://apt.kubernetes.io/ kubernetes-xenial main" | echo $pw | sudo -S tee /etc/apt/sources.list.d/kubernetes.list

echo $pw | sudo -S apt-get update
echo $pw | sudo -S apt-get install -y kubelet kubeadm kubectl

echo $pw | sudo -S kubeadm init --apiserver-advertise-address 192.168.56.30 --pod-network-cidr=20.96.0.0/12
echo $pw | sudo -S kubeadm token create --print-join-command > ~/join.sh

mkdir -p $HOME/.kube
echo $pw | sudo -S cp -i /etc/kubernetes/admin.conf $HOME/.kube/config
echo $pw | sudo -S chown $(id -u):$(id -g) $HOME/.kube/config

# kubectl 자동완성 기능을 사용하기 위해선 bash-completion의 설치가 필요하다(이유는 의존성을 가지고 있기 때문에) 
# 따라서 bash-completion을 먼저 설치한다.

echo $pw | sudo -S apt-get install -y bash-completion
# 위의 명령은 bash-completion의 기본 스크립트인 /usr/share/bash-completion/bash_completion 을 생성한다. 패키지 관리자에 따라, ~/.bashrc 파일에서 이 파일을 수동으로 소스(source)해야 한다.

source /usr/share/bash-completion/bash_completion

# 시스템 전체 사용자에게 적용하기 위해 bash_completion.d에 kubectl을 추가한다.
kubectl completion bash | sudo tee /etc/bash_completion.d/kubectl > /dev/null

# 두 방법 모두 동일하다. 셸을 다시 로드하면, kubectl 자동 완성 기능이 작동할 것이다. 셸의 현재 세션에서 bash 자동 완성을 활성화하려면 exec bash를 실행한다.

exec bash

# Calico 설치 / 정확하게 내용을 파악하지 못했다. 하지만 yaml 파일에 상세한 설정들이 기록되어 있는 것 같다.
kubectl create -f https://raw.githubusercontent.com/kubetm/kubetm.github.io/master/yamls/k8s-install/calico.yaml
kubectl create -f https://raw.githubusercontent.com/kubetm/kubetm.github.io/master/yamls/k8s-install/calico-custom.yaml

# 기존의 명령어를 통해 파일을 다운받았는데 내용은 redirect하는 파일이었다.
# 최종 파일
curl https://raw.githubusercontent.com/projectcalico/calico/v3.26.1/manifests/calico.yaml -O
kubectl apply -f calico.yaml

