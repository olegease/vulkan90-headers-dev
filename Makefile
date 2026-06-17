.PHONY: usage gen-ccjson instance instance-run clean 
# path
BUILDS := $(shell pwd)/build
INCLUDE := $(shell pwd)/include
SOURCE := $(shell pwd)/source
EXAMPLES := $(SOURCE)/examples
# compile commands json file
CCJSON := $(BUILDS)/compile_commands.json
WARNER := -Werror -Wpedantic -Wall -Wextra
# vk90
VK90_C := $(SOURCE)/vulkan90.c
VK90_O := $(BUILDS)/vulkan90.o
# examples
# -- instance
INSTANCE_C := $(EXAMPLES)/instance.c
INSTANCE_O := $(BUILDS)/instance.o
INSTANCE := $(BUILDS)/instance
# -- physical device
PHYSDEV_C := $(EXAMPLES)/physical_device.c
PHYSDEV_O := $(BUILDS)/physical_device.o
PHYSDEV := $(BUILDS)/physdev
# commands
# -- usage
usage:
	@cat Makefile.usage.txt
# -- generate compile commands json
gen-ccjson:
	@echo -e "[{" > $(CCJSON)
	@echo -e '\t"directory": "$(shell pwd)",' >> $(CCJSON)
	@echo -e '\t"command": "clang -std=c90 $(WARNER) -I \"include\" -c -x c",' >> $(CCJSON)
	@echo -e '\t"file": "$(VK90_C)"' >> $(CCJSON)
	@echo -e '}, {' >> $(CCJSON)
	@echo -e '\t"directory": "$(shell pwd)",' >> $(CCJSON)
	@echo -e '\t"command": "clang -std=c90 $(WARNER) -I \"include\" -c -x c",' >> $(CCJSON)
	@echo -e '\t"file": "$(INSTANCE_C)"' >> $(CCJSON)
	@echo -e '}, {' >> $(CCJSON)
	@echo -e '\t"directory": "$(shell pwd)",' >> $(CCJSON)
	@echo -e '\t"command": "clang -std=c90 $(WARNER) -I \"include\" -c -x c",' >> $(CCJSON)
	@echo -e '\t"file": "$(PHYSDEV_C)"' >> $(CCJSON)
	@echo -e "}]" >> $(CCJSON)
# -- instance
instance: $(INSTANCE)
	@echo "success"
# ---- run
instance-run: $(INSTANCE)
	@$(INSTANCE)
# -- physical device
physdev: $(PHYSDEV)
	@echo "success"
# ---- run
physdev-run: $(PHYSDEV)
	@$(PHYSDEV)
# -- clean
clean:
	@rm -rf $(BUILDS)
	@git restore $(BUILDS)
# recipes

$(VK90_O): $(VK90_C)
	gcc -std=c90 $(WARNER) -I "$(INCLUDE)" -c -x c $(VK90_C) -o $(VK90_O)

$(INSTANCE_O): $(INSTANCE_C)
	gcc -std=c90 $(WARNER) -I "$(INCLUDE)" -c -x c $(INSTANCE_C) -o $(INSTANCE_O)

$(INSTANCE): $(INSTANCE_O)
	gcc $(INSTANCE_O) -o $(INSTANCE) -lvulkan

$(PHYSDEV_O): $(PHYSDEV_C)
	gcc -std=c90 $(WARNER) -I "$(INCLUDE)" -c -x c $(PHYSDEV_C) -o $(PHYSDEV_O)

$(PHYSDEV): $(PHYSDEV_O) $(VK90_O)
	gcc $(PHYSDEV_O) $(VK90_O) -o $(PHYSDEV) -lvulkan

# Apache License 2.0
# NO WARRANTY OF ANY KIND see <http://www.apache.org/licenses/LICENSE-2.0>
# SPDX-License-Identifier: Apache-2.0
# lib: `vulkan90-headers-dev` (research) C90 Conformant Vulkan Headers
# Ⓒ Copyright (c) 2026 Oleg'Ease'Kharchuk ᦒ