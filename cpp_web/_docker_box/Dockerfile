FROM ubuntu:20.04

ENV TZ=Europe/Belgrade

RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get -qq update
RUN apt-get -qq upgrade
RUN apt-get -qq install gcc g++ build-essential cmake

RUN apt-get -qq install libboost1.67-all-dev 
RUN apt-get -qq install libtcmalloc-minimal4 && ln -s /usr/lib/libtcmalloc_minimal.so.4 /usr/lib/libtcmalloc_minimal.so
