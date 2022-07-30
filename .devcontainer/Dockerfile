FROM ubuntu
ENV DEBIAN_FRONTEND noninteractive
RUN apt-get update
RUN apt-get -y install gcc
RUN apt-get -y install g++
RUN apt-get -y install cmake
RUN apt-get -y install git
RUN apt-get -y install python3
RUN apt-get -y install wget 
RUN apt-get -y install lsb-release
RUN apt-get -y install software-properties-common
RUN apt-get --allow-downgrades -y install libc6=2.35-0ubuntu3 libc-bin=2.35-0ubuntu3
RUN bash -c "$(wget -O - https://apt.llvm.org/llvm.sh)"

# WORKDIR /opt
# RUN git clone https://github.com/llvm/llvm-project.git
# WORKDIR /opt/llvm-project
# RUN git checkout release/15.x
# RUN mkdir build
# WORKDIR /opt/llvm-project/build
# RUN cmake -DCMAKE_BUILD_TYPE=Debug "-GUnix Makefiles" ../llvm
# RUN cmake --build . -- -j 24
# RUN cmake --build . --target install -- -j 24