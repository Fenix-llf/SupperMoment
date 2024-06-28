CC = gcc
CFLAGS = -Wall -Wextra -g
SRCDIR = src
TARGET = suppermoment
INCDIR = include
OBJDIR = build
LIBS = cjson
LIBDIR = lib
SUBDIRS = 3rd/cJSON

SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
INCLUDES := $(shell find $(INCDIR) -type d)
INCFLAGS := $(addprefix -I,$(INCLUDES))

all: $(OBJDIR) $(TARGET) $(SUBDIRS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(SUBDIRS): 
	$(MAKE) -C $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBDIR) $(addprefix -l,$(LIBS)) $@

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done
	rm -f $(OBJDIR)/*.o $(TARGET)
