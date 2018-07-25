# Build

### Linux (Ubuntu 16.04)

##### Intel & Ryzen & ARM-aarch64 (64bit Smartphone or RPi64)
full support yespower + yescrypt
```bash
cd && \
git clone https://github.com/cryptozeny/cpuminer-mc-yespower.git && \
cd cpuminer-mc-yespower && \
sudo apt-get install build-essential libcurl4-openssl-dev && \
./build.sh
```

##### ARM-V7L (32bit Smartphone or RPi32)
no yespower yet. use yescrypt instead.
```bash
cd && \
git clone https://github.com/cryptozeny/cpuminer-mc-yespower.git && \
cd cpuminer-mc-yespower && \
sudo apt-get install build-essential libcurl4-openssl-dev && \
./build-ARMv7l.sh
```

### MacOS
TODO:

### Windows 64-bit Cross Build on Ubuntu 16.04

Native Version
```bash
cd && \
cd cpuminer-mc-yespower && \
sudo apt-get install gcc-mingw-w64 && \
cd depend && \
sh depend-curl-7_40_0.sh && \
cd .. && \
./autogen.sh && \
LDFLAGS="-L./depend/curl-7.40.0-devel-mingw64/lib64 -static" LIBCURL="-lcurldll" CFLAGS="-O3 -msse4.1 -funroll-loops -fomit-frame-pointer" ./configure --host=x86_64-w64-mingw32 --with-libcurl=depend/curl-7.40.0-devel-mingw64 && \
make
```

Static Version
TODO:

### Windows 32-bit Cross Build on Ubuntu 16.04 (NOT TESTED!!)

Native Version
```bash
cd && \
cd cpuminer-mc-yespower && \
sudo apt-get install gcc-mingw-w64 && \
cd depend && \
sh depend-curl-7_40_0.sh && \
cd .. && \
./autogen.sh && \
LDFLAGS="-L./depend/curl-7.40.0-devel-mingw32/lib -static" LIBCURL="-lcurldll" CFLAGS="-O3 -msse4.1 -funroll-loops -fomit-frame-pointer" ./configure --host=i686-w64-mingw32 --with-libcurl=depend/curl-7.40.0-devel-mingw32 && \
make
```

Static Version
TODO:

*****

# Run

### Linux
yespower (new)
```bash
./minerd -a yespower -o stratum+tcp://zny.semi-pool.com:3333 -u ZyWJL5qp3qZQW85HVoT3ba2feJYsZ7aQ2v
```

yescrypt (old)
```bash
./minerd -a yescrypt -o stratum+tcp://zny.semi-pool.com:3333 -u ZyWJL5qp3qZQW85HVoT3ba2feJYsZ7aQ2v
```

### Windows
yespower (new)
```bash
minerd.exe -a yespower -o stratum+tcp://zny.semi-pool.com:3333 -u ZyWJL5qp3qZQW85HVoT3ba2feJYsZ7aQ2v
```

yescrypt (old)
```bash
minerd.exe -a yescrypt -o stratum+tcp://zny.semi-pool.com:3333 -u ZyWJL5qp3qZQW85HVoT3ba2feJYsZ7aQ2v
```

### MacOS
TODO:

# Benchmark

### Linux
yespower (new)
```bash
./minerd -a yespower --benchmark -q
```

yescrypt (old)
```bash
./minerd -a yescrypt --benchmark -q
```

### Windows
yespower (new)
```bash
minerd.exe -a yespower --benchmark -q
```

yescrypt (old)
```bash
minerd.exe -a yescrypt --benchmark -q
```

### MacOS
TODO:
