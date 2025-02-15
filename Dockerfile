# Folosește Ubuntu ca imagine de bază
FROM ubuntu:latest

# Setează variabile de mediu
ENV DEBIAN_FRONTEND=noninteractive

# Actualizează pachetele și instalează pachetele de bază
RUN apt-get update && \
    apt-get install -y \
    python3 \
    python3-pip \
    python3-venv \
    gcc \
    make \
    valgrind \
    git \
    curl \
    bsdmainutils \
    imagemagick \
    recordclass \
    git \
    g++ \
    && rm -rf /var/lib/apt/lists/*

# Setează directorul de lucru
WORKDIR /workspace

# Expune portul pentru aplicații (dacă e necesar)
EXPOSE 5000

# Definirea comenzii de start
CMD ["bash"]
