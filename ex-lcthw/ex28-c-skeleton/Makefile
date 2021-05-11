# opt flags can be defined by other people
CFLAGS=-g -02 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS)
LIBS=-ldl $(OPTLIBS)

# is the prefix defined ? if not, define it here.
PREFIX?=/usr/local

# get a list of source codes
SOURCES=$(wildcard src/**/*.c src/*.c)

# pattern substitute command change *.c -> *.o
# we get a list of *.o files
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

# get a list of test source code
TEST_SRC=$(wildcard tests/*_tests.c)
# pattern substitute command *.c -> *
TESTS=$(patsubst %.c,%, $(TEST_SRC))

TARGET=build/libYOUR_LIBRARY.a
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

# The target build

all : $(TARGET) $(SO_TARGET) tests
dev : CFLAGS=-g -Wall -Isrc -Wall -Wextra $(OPTFLAGS)
dev : all

$(TARGET): CFLAGS += -fPIC
$(TARGET): build $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@
$(SO_TARGET): $(TARGET) $(OBJECTS)
	clang -shared -o $@ $(OBJECTS)

build : 
	@mkdir -p build
	@mkdir -p bin

# The Unit Tests
.PHONY: tests
tests: CFLAGS += $(TARGET)
tests: $(TESTS)
	sh ./tests/runtests.sh

# The Cleaner
clean: 
	rm -rf build $(OBJECTS) $(TESTS)
	rm -f tests/tests.log
	find . -name "*.gc*" -exec rm {} \;
	rm -rf `find . -name "*.dSYM" -print`

# The Install
install : all
	install -d $(DESTDIR)/$(PREFIX)/lib/
	install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/

# The Checker
check : 
	@echo Files with potentially dangerous functions
	@egrep '[^_.>a-zA-z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)\|stpn?cpy|a?sn?printf?byte_)' $(SOURCES) || true
