all:
	@echo make sure to you run as sudo
	@echo compiling ...
	@gcc configure.c -o configure;\
		echo answer to the question for creating log file;\
		./configure;\
		echo created log file;\
		echo installing ...;\
		cp configure /usr/bin;\
		echo installed ! ;\
		echo writing i3 config file ...;\
		cd /usr;\
		cd .config;\
		cd i3;\
		echo 'exec_always configure' >> ~/.config/i3/config;\
		echo config file edited ;\
		echo cleaning up ... ;\
		rm -f configure;\
		echo you are ready to go
	@echo $~
	@echo $~
	@echo if after rebooting nothing changed edit config file of i3 to make configure command called always , by the way dont delete log.txt file , if you want to change the resolution , just edit it there
