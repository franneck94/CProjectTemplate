install:
	sudo apt-get install gcovr lcov

install_doc:
	pip install jinja2 Pygments
	sudo apt-get install doxygen

setup:
	pip install conan

prepare:
	rm -rf build
	mkdir build
