# Uncomment lines below if you have problems with $PATH
#SHELL := /bin/bash
#PATH := /usr/local/bin:$(PATH)

BLACK        := $(shell tput -Txterm setaf 0)
RED          := $(shell tput -Txterm setaf 1)
GREEN        := $(shell tput -Txterm setaf 2)
YELLOW       := $(shell tput -Txterm setaf 3)
LIGHTPURPLE  := $(shell tput -Txterm setaf 4)
PURPLE       := $(shell tput -Txterm setaf 5)
BLUE         := $(shell tput -Txterm setaf 6)
WHITE        := $(shell tput -Txterm setaf 7)

RESET := $(shell tput -Txterm sgr0)

TARGET_COLOR := $(BLUE)

.DEFAULT_GOAL := help

help:
	@echo "--------------------------------------------------------"
	@echo "-----------${BLACK}:: ${GREEN}PlatformIO Makefile Commands${RESET} ${BLACK}::${RESET}-----------"
	@echo "--------------------------------------------------------"
	@grep -E '^[a-zA-Z_0-9%-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "${TARGET_COLOR}%-30s${RESET} %s\n", $$1, $$2}'

run:       ## Process (build) all environments specified in “platformio.ini”
	platformio run

upload:    ## Build project and upload firmware to the all devices specified in “platformio.ini”
	platformio run --target upload

clean:     ## Clean project (delete compiled objects)
	platformio run --target clean

program:   ## Upload firmware using programmer (WARNING: Upload options like upload_port don’t work as expected with platformio run -t program)
	platformio run --target program

uploadfs:  ## Upload using filesystem
	platformio run --target uploadfs

update:    ## Check or update installed PlatformIO Core packages
	platformio update
