#
# Makefile
#
# CC 				?= gcc
LVGL_DIR_NAME 	?= lvgl
LVGL_DIR 		?= .

WARNINGS		:= -Wall -Wshadow -Wundef -Wmissing-prototypes -Wno-discarded-qualifiers -Wall -Wextra -Wno-unused-function -Wno-error=strict-prototypes -Wpointer-arith \
					-fno-strict-aliasing -Wno-error=cpp -Wuninitialized -Wmaybe-uninitialized -Wno-unused-parameter -Wno-missing-field-initializers -Wtype-limits -Wsizeof-pointer-memaccess \
					-Wno-format-nonliteral -Wno-cast-qual -Wunreachable-code -Wno-switch-default -Wreturn-type -Wmultichar -Wformat-security -Wno-ignored-qualifiers -Wno-error=pedantic \
					-Wno-sign-compare -Wno-error=missing-prototypes -Wdouble-promotion -Wclobbered -Wdeprecated -Wempty-body -Wtype-limits -Wstack-usage=2048 \
					-Wno-unused-value -Wno-unused-parameter -Wno-missing-field-initializers -Wuninitialized -Wmaybe-uninitialized -Wall -Wextra -Wno-unused-parameter \
					-Wno-missing-field-initializers -Wtype-limits -Wsizeof-pointer-memaccess -Wno-format-nonliteral -Wpointer-arith -Wno-cast-qual -Wmissing-prototypes \
					-Wunreachable-code -Wno-switch-default -Wreturn-type -Wmultichar -Wno-discarded-qualifiers -Wformat-security -Wno-ignored-qualifiers -Wno-sign-compare -std=c99
CFLAGS 			?= -O3 -g0 -I$(LVGL_DIR)/ $(WARNINGS)
LDFLAGS 		?= -lm
BIN 			= lvgl_demo
BUILD_DIR 		= ./build
BUILD_OBJ_DIR 	= $(BUILD_DIR)/obj
BUILD_BIN_DIR 	= $(BUILD_DIR)/bin

prefix 			?= /usr
bindir 			?= $(prefix)/bin

#Collect the files to compile
MAINSRC = 		./main.c

include $(LVGL_DIR)/lvgl/lvgl.mk
include $(LVGL_DIR)/lv_drivers/lv_drivers.mk

# 添加源文件目录
VPATH += :$(LVGL_DIR)/ui
VPATH += :$(LVGL_DIR)/ui/components
VPATH += :$(LVGL_DIR)/ui/fonts
VPATH += :$(LVGL_DIR)/ui/images
VPATH += :$(LVGL_DIR)/ui/screens

VPATH += :$(LVGL_DIR)/app
VPATH += :$(LVGL_DIR)/app/protocol
VPATH += :$(LVGL_DIR)/app/socket
VPATH += :$(LVGL_DIR)/app/cJSON

# 添加头文件目录
CFLAGS += -I$(CURDIR)/ui
CFLAGS += -I$(CURDIR)/ui/components
CFLAGS += -I$(CURDIR)/ui/fonts
CFLAGS += -I$(CURDIR)/ui/images
CFLAGS += -I$(CURDIR)/ui/screens

CFLAGS += -I$(CURDIR)/app
CFLAGS += -I$(CURDIR)/app/protocol
CFLAGS += -I$(CURDIR)/app/socket
CFLAGS += -I$(CURDIR)/app/cJSON

# CSRCS 			+=$(LVGL_DIR)/mouse_cursor_icon.c 

UI_CSRCS += $(wildcard ui/*.c)
UI_CSRCS += $(wildcard ui/components/*.c)
UI_CSRCS += $(wildcard ui/fonts/*.c)
UI_CSRCS += $(wildcard ui/images/*.c)
UI_CSRCS += $(wildcard ui/screens/*.c)

UI_CSRCS += $(wildcard app/*.c)
UI_CSRCS += $(wildcard app/protocol/*.c)
UI_CSRCS += $(wildcard app/socket/*.c)
UI_CSRCS += $(wildcard app/cJSON/*.c)

CSRCS += $(UI_CSRCS)
UI_OBJS := $(UI_CSRCS:.c=.o)
OBJS += $(UI_OBJS)

OBJEXT 			?= .o

AOBJS 			= $(ASRCS:.S=$(OBJEXT))
COBJS 			= $(CSRCS:.c=$(OBJEXT))

MAINOBJ 		= $(MAINSRC:.c=$(OBJEXT))

SRCS 			= $(ASRCS) $(CSRCS) $(MAINSRC)
OBJS 			= $(AOBJS) $(COBJS) $(MAINOBJ)
TARGET 			= $(addprefix $(BUILD_OBJ_DIR)/, $(patsubst ./%, %, $(OBJS)))

## MAINOBJ -> OBJFILES

all: default

$(BUILD_OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC)  $(CFLAGS) -c $< -o $@
	@echo "CC $<"
    
default: $(TARGET)
	@mkdir -p $(dir $(BUILD_BIN_DIR)/)
	$(CC) -o $(BUILD_BIN_DIR)/$(BIN) $(TARGET) $(LDFLAGS) -lpthread

clean: 
	rm -rf $(BUILD_DIR)

install:
	install -d $(DESTDIR)$(bindir)
	install $(BUILD_BIN_DIR)/$(BIN) $(DESTDIR)$(bindir)

uninstall:
	$(RM) -r $(addprefix $(DESTDIR)$(bindir)/,$(BIN))
