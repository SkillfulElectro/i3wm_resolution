# i3wm
simple commandline app to configure resolution for i3wm

install :

```shell
$ git clone https://github.com/SkillfulElectro/i3wm_resolution.git
$ cd i3wm_resolution
$ make
```
the makefile tries to append new rules to i3 config file , if it failed !
 just add :
 
```
 $ exec_always configure
``` 


make sure to add it as your startup app , or everytime you reboot

```shell
$ configure
```
