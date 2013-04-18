CC = clang++
OPT=0
CFLAGS = -Wall -Winline -Wwrite-strings -Wno-unused -O${OPT} -std=c++0x -stdlib=libc++ -I../
LDFLAGS = -stdlib=libc++
