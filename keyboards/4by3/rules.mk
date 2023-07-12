# MCU name
MCU = atmega32u4


# Bootloader selection
BOOTLOADER = caterina

EXTRAKEY_ENABLE 	= yes
NKRO_ENABLE = yes           # Enable N-Key Rollover
CONSOLE_ENABLE		= yes
COMMAND_ENABLE		= yes
MOUSEKEY_ENABLE 	= yes

#ENCODER
ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes

#reducing .hex file size
LTO_ENABLE = yes
