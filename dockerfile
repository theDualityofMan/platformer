# Use a lightweight Debian image with g++
FROM debian:bookworm-slim

# Install all dependencies for Raylib + build tools
RUN apt-get update && apt-get install -y \
    build-essential \
    git \
    cmake \
    pkg-config \
    xorg-dev \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    libasound2-dev \
    libxrandr-dev \
    libxi-dev \
    libxcursor-dev \
    libxinerama-dev \
    libpthread-stubs0-dev \
    libudev-dev \
    && rm -rf /var/lib/apt/lists/*

# Build Raylib from source
RUN git clone --depth=1 https://github.com/raysan5/raylib.git /raylib && \
    cd /raylib && \
    mkdir build && cd build && \
    cmake -DBUILD_EXAMPLES=OFF -DCMAKE_INSTALL_PREFIX=/usr .. && \
    make -j$(nproc) && make install

# Copy your project into the container
WORKDIR /app
COPY . /app

# Compile your Raylib game (adjust filenames as needed)
RUN g++ main.cpp unit.cpp warrior.cpp -o game \
    -I /usr/include \
    -lraylib -lm -lpthread -ldl -lGL -lrt -lX11

# Run your game
CMD ["./game"]
