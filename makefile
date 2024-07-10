# ----------------------------
# Makefile Options
# ----------------------------

NAME = CookClik
ICON = icon.png
DESCRIPTION = "Cookie Clicker for TI84 CE"
COMPRESSED = YES
COMPRESSED_MODE = zx0
ARCHIVED = YES
PREFER_OS_CRT = YES

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
