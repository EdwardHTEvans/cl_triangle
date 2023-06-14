default:
	./build.sh

test:
	./build.sh
	python ./tests/cl_triangle_test.py
