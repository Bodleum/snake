targets	:= snake
EXT := .cpp
objs	:= $(patsubst %$(EXT),%.o,$(wildcard *$(EXT)))

.DEFAULT_GOAL := all

$(targets): $(objs)

CC		:= g++
CFLAGS	:= -Wall -Werror -lncurses

all: clean $(targets) rm_ints

keep_ints: clean $(targets)

deps := $(patsubst %.o,%.d,$(objs))
-include $(deps)
DEPFLAGS = -MMD -MF $(@:.o=.d)

$(targets):
	$(CC) $(CFLAGS) -o $@ $^

%.o: %$(EXT)
	$(CC) $(CFLAGS) -c $< $(DEPFLAGS)

clean:
	rm -f $(targets) $(objs) $(deps)

rm_ints:
	rm -f $(objs) $(deps)
