CC = clang
TARGET = pact

$(TARGET): $(wildcard *.c) $(wildcard */*.c)
	$(CC) -o $@ $^

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

	cp pkg /usr/bin/

uninstall:
	@if [ "$$(id -u)" -ne 0 ]; then \
		echo -e "\033[31mERROR:\033[0m Elevated priviliges are required for uninstallation. Ensure you execute make install with sudo or as the root user."; \
		exit 1; \
	fi

	rm -f /usr/bin/pkg