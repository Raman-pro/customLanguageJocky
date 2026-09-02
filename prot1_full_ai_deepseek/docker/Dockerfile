FROM debian:bookworm-slim

# Build + testing + analysis toolchain for the JOCKY project
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    git \
    file \
    binutils \
    python3 \
    mingw-w64 \
    valgrind \
    clamav \
    clamav-freshclam \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace
CMD ["/bin/bash"]