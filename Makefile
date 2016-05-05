data: data/input_data/generate_search_data.py data/input_data/generate_sorting_data.py
	@cd data/input_data; \
	echo "Generating search data...\n"; \
	python3 generate_search_data.py 1000 50000 1000 10; \
	echo "Generating sorting data...\n";  \
	python3 generate_sorting_data.py 1000 50000 1000 10; \
	cd ../../

cdata: c_code/sorting/main.o c_code/search/main.o data/input_data/search_data.csv data/input_data/sorting_data.csv
	@echo "Using generated input data to collect C simulation data";\
	cd c_code/sorting; \
	./main.o; \
	cd ../search; \
	./main.o; \
	cd ../../;
