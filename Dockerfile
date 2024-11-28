# syntax=docker/dockerfile:1
FROM ubuntu:24.04

RUN apt update \
    && apt upgrade -y \
    && apt install -y \
    build-essential \
    clang \
    clang-format \
    cmake \
    curl \
    git \
    llvm \
    make \
    ninja-build \
    python-is-python3 \
    python3-pip \
    wget \
    && rm -rf /var/lib/apt/lists/*

RUN \
    wget https://developer.arm.com/-/media/Files/downloads/gnu/13.3.rel1/binrel/arm-gnu-toolchain-13.3.rel1-x86_64-arm-none-eabi.tar.xz \
    && tar -vxJf arm-gnu-toolchain-13.3.rel1-x86_64-arm-none-eabi.tar.xz -C /usr/share
ENV PATH=/usr/share/arm-gnu-toolchain-13.3.rel1-x86_64-arm-none-eabi/bin:$PATH

WORKDIR /stm32g0b1
COPY . .

ENV CPM_SOURCE_CACHE=/stm32g0b1/.cpm_cache/
ENV CC="gcc"
ENV CXX="g++"

ENTRYPOINT ["./entrypoint.sh"]
