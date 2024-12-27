WARNING = -Wall -Wextra -Wpedantic
CFLAGS = -std=c99 -O0 $(WARNING)
LDFLAGS =
LDLIBS =

OUTDIR = .build
OBJ = \
	  $(OUTDIR)/main.o \
	  $(OUTDIR)/token.o \

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
	rm -rf $(OUTDIR) core
