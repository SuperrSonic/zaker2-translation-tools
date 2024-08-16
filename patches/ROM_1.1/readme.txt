# How to know which patches to use

"ZatchElectricArena2_rev1_x.bps" is the main translation, it is a BPS file which means it must be applied to a clean/original/unmodified ROM. This format was chosen to prevent user-error, and avoid the 16 MB limit of IPS.

"ZatchElectricArena2_rev1_x.cheats" contains cheats that can be used with mGBA, they were used during the development of the translation to reach certain points of the game quickly.


# Enhancements

Enhancements are IPS patches that can be applied in any order AFTER the main BPS patch has been applied.

"ZatchEA2_DUB_rev1_x.ips" replaces Japanese voices with the English dub.

"ZatchEA2_MinishCap_font_rev1_x.ips" replaces the original font with a nicer VWF based on The Minish Cap. This patch is recommended for improving the visibility of the text and to allow translators more screen space to work with.

"ZatchEA2_ScriptUpdate_rev1_x.ips" updates the script, this patch improves the alignment of the credits when using the "MinishCap" font. Going forward, any updates will assume you have the MinishCap font applied.

"ZatchEA2_noMenuJP_rev1_x.ips" this game has a strong mix of English and Japanese, the main menu originally is in English but the selected mode is highlighted with the Japanese title, translating this wouldn't work right so it was kept as it is. This patch removes the Japanese titles so it feels more localized. Honestly, it's kinda pointless to remove it. There are other redundant Japanese texts in the game and the English dub acknowledges the series is set in Japan.

"ZatchEA2_LinkGFX_rev1_x.ips" translates the hidden link cable prompt from the Zatch Collection mode, when the collection is less than 100%, you can hold L+R to activate this prompt. This was left untranslated in the base patch because I was unaware this was in the game.

"ZatchEA2_EasyPenny_rev1_x.ips" makes the "Penny's Present" minigame easier to complete without having to mash the A and B buttons.

"ZatchEA2_EventUnlock_rev1_x.ips" the event exclusive item will not be accessible even if you use the 13106 password, this patch gives item 52 the same unlocking requirement as item 51, so the password will work on it.
