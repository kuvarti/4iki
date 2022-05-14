INCLUDES = -Iincludes/.

all: $(INCLUDES) hash creator

$(INCLUDES):
	mkdir -p includes
	cp getnextchain/get_next_chain.h includes/.
	cp sqlite/sqlite3.h includes/.
	cp chain.h includes/.

clean:
	rm -rf includes
	rm a.out