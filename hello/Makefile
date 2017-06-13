.PHONY: all clean

obj-m := hello.o

all:
	make  -C /lib/modules/4.4.0-66-generic/build  M=$(PWD) modules

clean:
	make  -C /lib/modules/4.4.0-66-generic/build M=$(PWD) clean
