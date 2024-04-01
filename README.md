# zaker2-translation-tools
Contains the code used to rebuild the script, as well as a manual for changing various things in the game.

zatchEA2_scriptV2_0x818460.bin is an updated script that adjusts the layout of the credits sequence when using the Minish Cap-style font.
This is the ideal base to work with for other translations. With a hex editor you can go to address 0x818460 (rev 1.1) of the ROM and paste it there to update the game.

The code is here in case someone wants to build it for a different platform, do note, there is no endian detection, this tool relies on the hardware being little-endian to work correctly.

Currently, only the script updating tool is available. But eventually I will post the tile-reconstructed images needed for editing the more complex graphics in the game (title screen, etc.)
For the title screen, many tiles had to be re-arranged to draw the complete Electric Arena logo, this makes editing it now a bit of a nightmare without the crystaltile files.
