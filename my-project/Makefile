PROJECT = awesomesauce
BUILD_DIR = bin
SHARED_DIR = ../rtos

#TODO make use of wildcards to include c files from main project
CFILES = main.c

# These files are from rtos
CFILES += heap_1.c list.c opencm3.c port.c queue.c tasks.c

#AFILES += asm_file.s

DEVICE=stm32f446RET6

# You shouldn't have to edit anything below here.
VPATH += $(SHARED_DIR)
INCLUDES += $(patsubst %,-I%, . $(SHARED_DIR))
OPENCM3_DIR=../libopencm3

include $(OPENCM3_DIR)/mk/genlink-config.mk
include ../rules.mk
include $(OPENCM3_DIR)/mk/genlink-rules.mk
