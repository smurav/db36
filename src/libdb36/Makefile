PREFIX ?= $(DESTDIR)/usr
LIBDIR ?= $(PREFIX)/lib
HDRLIBS= 
HDRS=$(wildcard *.h)
SRCS=$(wildcard *.c)
OBJS=$(patsubst %.c,%.o,$(SRCS))
TARGET=libdb36.so
LIBS=-lselinux
INCLUDES=-I /usr/include/pgsql/server
CFLAGS += $(INCLUDES) -fpic -O2 -g -pipe -Wall -Wp,-D_FORTIFY_SOURCE=2 -fexceptions -fstack-protector --param=ssp-buffer-size=4 -m64 -mtune=generic
all: $(TARGET)

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CC) $(LIBS) -shared -o $@ $^

install: all
	test -d $(LIBDIR) || install -m 644 -d $(LIBDIR)
	install -m 644 $(TARGET) $(LIBDIR)

clean:
	rm *.o $(TARGET)
