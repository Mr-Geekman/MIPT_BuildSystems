FROM ubuntu:20.04

# fix problem with timezon
ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# download dependencies
RUN apt-get update && apt-get upgrade && apt-get install -y git sendmail g++ cmake doxygen pkg-config libboost-all-dev libssl-dev gnutls-dev libcurl4-openssl-dev libgsasl7-dev

# clone required repository
RUN cd ~/ && git clone https://github.com/akhtyamovpavel/PatternsCollection.git && \
    cd PatternsCollection && mkdir build && cd build && \
    cmake .. && make

# start container in compiled library
WORKDIR ~/PatternsCollection
