CC = clang
TARGET = pact
CCFLAGS = $(shell pkg-config --libs libcurl libzip)

PACT_TEMP_DIR = /var/tmp/pact
PACT_DIR = /var/pact

$(TARGET): $(wildcard *.c) $(wildcard */*.c)
	$(CC) $(CCFLAGS) -o $@ $^

.PHONY: install

install:
	@if [ ! -f $(TARGET) ]; then \
		echo -e "\033[31mERROR:\033[0m Couldn't find executable. Ensure you execute make first!"; \
		exit 1; \
	fi

	@if [ "$$(id -u)" -ne 0 ]; then \
		echo -e "\033[31mERROR:\033[0m Elevated priviliges are required for installation. Ensure you execute make install with sudo or as the root user."; \
		exit 1; \
	fi

	cp $(TARGET) /usr/bin/
	mkdir -p $(PACT_TEMP_DIR)
	mkdir -p $(PACT_DIR)

uninstall:
	@if [ "$$(id -u)" -ne 0 ]; then \
		echo -e "\033[31mERROR:\033[0m Elevated priviliges are required for uninstallation. Ensure you execute make install with sudo or as the root user."; \
		exit 1; \
	fi

	rm -f /usr/bin/$(TARGET)
	rm -rf $(PACT_DIR)
	rm -rf $(PACT_TEMP_DIR)