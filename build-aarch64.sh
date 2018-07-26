# Intel or AMD Ryzen or ARM-aarch64
make clean ; \
./autogen.sh && \
./nomacro.pl && \

# solardiz 16 hours ago  •
# I recommend -O2 -fomit-frame-pointer instead of -O3,
# although the difference is minor
# (and expected to be seen mostly on 32-bit x86 builds,
# where you'd also want to add -msse2).

./configure CFLAGS="-O2 -fomit-frame-pointer" && \
make
