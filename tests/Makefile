ROOT = ..

all: run

run:
	$(MAKE) -C $(ROOT) validation
	bash run_tests.sh

clean:
	rm -rf .tmp

fclean: clean
	$(MAKE) -C $(ROOT) fclean

re: fclean all

.PHONY: all run clean fclean re
