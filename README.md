This is a multi-threaded CPU miner for BitZeny adding support `yespower` + `yescrypt`, fork of macchky's cpuminer v2.6.0.

License: GPLv2. See COPYING for details.

Git tree: https://github.com/macchky/cpuminer  

*****
# Impact

`yespower` has about `2%` to `15%` better performance than old yescrypt. `yespower 0.5` has a downward compatibility mode of `old yescrypt 0.5` and provides performance improvements for yescrypt coins such as BitZeny(ZNY) & Yenten(YTN) & Koto & WAVI.

`17%`   performance improvements on `ARM-aarch64` (Smartphone & RPi64)  
`3~10%` performance improvements on `Intel`  
`2%`    performance improvements on `AMD Ryzen`   

See more details about yespower and yescrypt:  
http://www.openwall.com/yespower/  
http://www.openwall.com/yescrypt/  

*****

# Build

### Linux (Ubuntu 16.04)

##### Intel & Ryzen
full support yespower + yescrypt
```bash
cd && \
git clone https://github.com/cryptozeny/cpuminer-mc-yespower.git && \
cd cpuminer-mc-yespower && \
sudo apt-get install build-essential libcurl4-openssl-dev && \
./build.sh
```

##### ARM-aarch64 (64bit Smartphone or RPi64) Boost `17%`
full support yespower + yescrypt
```bash
cd && \
git clone https://github.com/cryptozeny/cpuminer-mc-yespower.git && \
cd cpuminer-mc-yespower && \
sudo apt-get install build-essential libcurl4-openssl-dev && \
./build-aarch64.sh
```

##### ARM-V7L (32bit Smartphone or RPi32)
no yespower yet. please use `-a yescrypt` option until next release.
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

*****

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

*****

# 주의 注意 WARNING
본인의 지갑주소 및 올바른 포트번호를 사용하세요.  
本人の財布アドレス、および正しいポート番号を使用してください。  
Please use your own wallet address and correct port number.  

### 채굴 설명서 マイニングマニュアル Mining Manual
https://github.com/semipool/zny.semi-pool.com/blob/master/README.md

*****

# Donations

cpuminer-mc 2.6.0 by macchky@github  
ZNY donation address: `Zq83XMtc9gShkgi4bNNHWA4FDbMe8dFQmD` (macchky)

yespower 0.5 support by cryptozeny@github    
ZNY donation address: `ZyWJL5qp3qZQW85HVoT3ba2feJYsZ7aQ2v` (cryptozeny)

Happy Mining!
