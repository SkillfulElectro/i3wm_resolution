all:
	gcc configure.c -o configure;\
		./configure;\
		cp configure /usr/bin;\
		rm -f configure
	@echo make sure to add configure to run as startup app in your system
