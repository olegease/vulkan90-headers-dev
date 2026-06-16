.PHONY: usage gen-ccjson instance instance-run clean 
# path
BUILDS := $(shell pwd)/build
INCLUDE := $(shell pwd)/include
SOURCE := $(shell pwd)/source
EXAMPLES := $(SOURCE)/examples
# compile commands json file
CCJSON := $(BUILDS)/compile_commands.json
# vk90
VK90_C := $(SOURCE)/vulkan90.c
VK90_O := $(BUILDS)/vulkan90.o
# examples
INSTANCE_C := $(EXAMPLES)/instance.c
INSTANCE_O := $(BUILDS)/instance.o
INSTANCE := $(BUILDS)/instance
# commands
# -- usage
usage:
	@cat Makefile.usage.txt
# -- generate compile commands json
gen-ccjson:
	@echo -e "[{" > $(CCJSON)
	@echo -e '\t"directory": "$(shell pwd)",' >> $(CCJSON)
	@echo -e '\t"command": "clang -std=c90 -Werror -Wpedantic -Wall -Wextra -I \"include\" -c -x c",' >> $(CCJSON)
	@echo -e '\t"file": "$(VK90_C)"' >> $(CCJSON)
	@echo -e '}, {' >> $(CCJSON)
	@echo -e '\t"directory": "$(shell pwd)",' >> $(CCJSON)
	@echo -e '\t"command": "clang -std=c90 -Werror -Wpedantic -Wall -Wextra -I \"include\" -c -x c",' >> $(CCJSON)
	@echo -e '\t"file": "$(INSTANCE_C)"' >> $(CCJSON)
	@echo -e "}]" >> $(CCJSON)
# -- instance
instance: $(INSTANCE)
	@echo "success"
# ---- run
instance-run: $(INSTANCE)
	@$(INSTANCE)
# -- clean
clean:
	@rm -rf $(BUILDS)
	@git restore $(BUILDS)
# recipes

$(VK90_O): $(VK90_C)
	gcc -std=c90 -Werror -Wpedantic -Wall -Wextra -I "$(INCLUDE)" -c -x c $(VK90_C) -o $(VK90_O)

$(INSTANCE_O): $(INSTANCE_C)
	gcc -std=c90 -Werror -Wpedantic -Wall -Wextra -I "$(INCLUDE)" -c -x c $(INSTANCE_C) -o $(INSTANCE_O)

$(INSTANCE): $(INSTANCE_O)
	gcc $(INSTANCE_O) -o $(INSTANCE) -lvulkan