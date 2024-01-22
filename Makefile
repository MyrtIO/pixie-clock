.PHONY: configure
configure:
	pio init --ide vscode

.PHONY: build
build:
	pio run -e uno

.PHONY: flash
flash:
	pio run --target upload

.PHONY: terminal
terminal:
	python tools/terminal.py
