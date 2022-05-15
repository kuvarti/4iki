INCLUDES = -Iincludes/.

all: $(INCLUDES) hashcreator

$(INCLUDES):
	mkdir -p includes
	cp getnextchain/get_next_chain.h includes/.
	cp sqlite/sqlite3.h includes/.
	cp chain.h includes/.

hashcreator: $(INCLUDES)
	gcc src/chain.c getnextchain/*.c $(INCLUDES) -o randomHashGenerator

clean:
	rm -rf includes
	rm -f a.out randomHashGenerator