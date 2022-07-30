FROM ubuntu
ENV DEBIAN_FRONTEND noninteractive
RUN apt-get update
RUN apt-get --allow-downgrades -y install libc6=2.35-0ubuntu3 libc-bin=2.35-0ubuntu3
RUN apt-get -y install gcc
RUN apt-get -y install g++
RUN apt-get -y install cmake
RUN apt-get -y install git
RUN apt-get -y install python3
RUN apt-get -y install wget
RUN apt-get -y install lsb-release
RUN apt-get -y install software-properties-common
RUN apt-get -y install build-essential
RUN apt-get -y install zlib1g-dev
RUN apt-get -y install gdb
RUN bash -c "$(wget -O - https://apt.llvm.org/llvm.sh)"