FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    clang \
    libc++-dev \
    libc++abi-dev \
    cmake \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /

COPY . .

RUN mkdir build && cd build && \
    cmake -DCMAKE_CXX_COMPILER=clang++ .. && \
    make

CMD ["./build/power"]