WARNING = -Wall -Wextra -Wpedantic
CFLAGS = -std=c99 -O0 $(WARNING)
LDFLAGS =
LDLIBS = -lm

OUTDIR = .build
OBJ = \
	  $(OUTDIR)/main.o \
	  $(OUTDIR)/token.o \
	  $(OUTDIR)/opcode.o \

NAME = aa

all: $(NAME)

run: $(NAME)
	$(OUTDIR)/$(NAME) test.asm

$(NAME): $(OBJ)
	$(CC) -o $(OUTDIR)/$@ $^ $(LDFLAGS) $(LDLIBS)

$(OUTDIR)/%.o: src/%.c
	@mkdir -p $(OUTDIR)
	$(CC) -o $@ -c $^ $(CFLAGS)

clean:
	rm -rf $(OUTDIR) core log
