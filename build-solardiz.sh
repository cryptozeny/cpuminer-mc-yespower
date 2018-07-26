# Intel or AMD Ryzen or ARM-aarch64
make clean ; \
./autogen.sh && \
./nomacro.pl && \
./configure CFLAGS="-O2 -fomit-frame-pointer -msse2" && \
make
