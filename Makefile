# Uncomment lines below if you have problems with $PATH
SHELL := /bin/bash
#PATH := /usr/local/bin:$(PATH)

.DEFAULT_GOAL := show-help

## Process (build) all environments specified in “platformio.ini”
run:
	platformio run

## Build project and upload firmware to all the devices specified in “platformio.ini”
upload:
	platformio run --target upload

## Clean project (delete compiled objects)
clean:
	platformio run --target clean

## Upload firmware using programmer
program:
	platformio run --target program

## Check or update installed PlatformIO Core packages
update:
	platformio update

## Open the serial monitor
serial-monitor:
	platformio device monitor

show-help:
	@echo "$$(tput bold)Available rules:$$(tput sgr0)";echo;sed -ne"/^## /{h;s/.*//;:d" -e"H;n;s/^## //;td" -e"s/:.*//;G;s/\\n## /---/;s/\\n/ /g;p;}" ${MAKEFILE_LIST}|LC_ALL='C' sort -f|awk -F --- -v n=$$(tput cols) -v i=19 -v a="$$(tput setaf 6)" -v z="$$(tput sgr0)" '{printf"%s%*s%s ",a,-i,$$1,z;m=split($$2,w," ");l=n-i;for(j=1;j<=m;j++){l-=length(w[j])+1;if(l<= 0){l=n-i-length(w[j])-1;printf"\n%*s ",-i," ";}printf"%s ",w[j];}printf"\n";}'|more $(shell test $(shell uname) == Darwin && echo '-Xr')
