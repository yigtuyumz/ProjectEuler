SRCDIR := ./srcs
OUTDIR := ./out
CC := gcc
CFLAGS := -Wall -Wextra -Werror -I. -fPIC -std=c99
LIBRARY := libProjectEuler
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OUTDIR)/%.o, $(wildcard $(SRCDIR)/*.c))
LDFLAGS := -shared

.PHONY: all clean re test

all: $(LIBRARY).so

$(LIBRARY).so: $(OBJECTS)
	$(CC) $(LDFLAGS) -o $(LIBRARY).so $^

$(OUTDIR)/%.o: $(SRCDIR)/%.c | $(OUTDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OUTDIR):
	mkdir -p $(OUTDIR)

clean:
	@rm -rf $(OUTDIR)
	@rm -f $(LIBRARY).so

re: clean all
