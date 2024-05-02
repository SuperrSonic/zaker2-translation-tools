# zaker2-translation-tools
Contains the code used to rebuild the script, as well as a manual for changing various things in:
Konjiki no Gash Bell!! Unare! Yuujou no Zakeru 2 / Zatch Bell! Electric Arena 2.

zatchEA2_scriptV2_0x818460.bin is an updated script that adjusts the layout of the credits sequence when using the Minish Cap-style font.
This is the ideal base to work with for other translations. With a hex editor you can go to address 0x818460 (rev 1.1) of the ROM and paste it there to update the game.

The code is here in case someone wants to build it for a different platform, do note, there is no endian detection, this tool relies on the hardware being little-endian to work correctly.


# Basic documentation

The following are notes on every little thing I found in this game.
Addresses refer to ROM addresses on the 1.0 version.


# VWF Parameters for the Main Font

These are a set of 5 bytes containing data about the character, 4th byte is the screen space it takes up.
All the 4th values need to be adjusted when changing the font.

These were found by using corruption on the data that appears before the tile data of the font.
<code>
0x82A05E = !, 0x10 FF 0D 06 07
0x82A063 = ", 0x06 00 0D 08 0B
0x82A068 = unk, 0x0B 00 0B 0D 0B
0x82A06D = unk, 0x0B 00 0B 0D 08
0x82A072 = %, 0x0E 00 0B 08 08
0x82A077 = &, 0x0E 00 0B 08 04
0x82A07C = ', 0x06 FF 0D 06 05
0x82A081 = (, 0x10 FF 0D 07 05
0x82A086 = ), 0x10 FF 0D 07 07
0x82A08B = *, 0x08 00 0B 08 00
0x82A090 = don't know
0x82A095 = ,, 0x07 FF 04 06 07
0x82A09A = -, 0x04 00 07 07 04
0x82A09F = ., 0x05 FF 03 06 08
0x82A0A4 = /, 0x0F 00 0C 08 07
0x82A0A9 = 0, 0x10 00 0D 07 05
0x82A0AE = 1, 0x10 FF 0D 07 07
0x82A0B3 = 2, 0x10 00 0D 07 07
0x82A0B8 = 3, 0x10 00 0D 07 07
0x82A0BD = 4, 0x10 00 0D 07 07
0x82A0C2 = 5, 0x10 00 0D 07 07
0x82A0C7 = 6, 0x10 00 0D 07 07
0x82A0CC = 7, 0x10 00 0D 07 07
0x82A0D1 = 8, 0x10 00 0D 07 07
0x82A0D6 = 9, 0x10 00 0D 07 04
0x82A0DB = :, 0x0D FF 0B 06 04
0x82A0E0 = ;, 0x0E FF 0B 06 07
0x82A0E5 = < (now 's), 0x0D 00 0B 07 07
0x82A0EA = =, 0x0A 00 0A 07 07
0x82A0EF = >, 0x0D 00 0B 07 07
0x82A0F4 = ?, 0x10 00 0D 07 08
0x82A0F9 = @ (now é), 0x0E 00 0B 08 07
0x82A0FE = A, 0x10 00 0D 07 07
0x82A103 = B, 0x10 00 0D 07 07
0x82A108 = C, 0x10 00 0D 07 07
0x82A10D = D, 0x10 00 0D 07 07
0x82A112 = E, 0x10 00 0D 07 07
0x82A117 = F, 0x10 00 0D 07 08
0x82A11C = G, 0x10 00 0D 08 07
0x82A121 = H, 0x10 00 0D 07 06
0x82A126 = I, 0x10 FF 0D 07 07 (this needs 4th byte as 6 imo)
0x82A12B = J, 0x10 00 0D 07 08
0x82A130 = K, 0x10 00 0D 08 07
0x82A135 = L, 0x10 00 0D 07 09
0x82A13A = M, 0x10 00 0D 09 08
0x82A13F = N, 0x10 00 0D 08 07
0x82A144 = O, 0x10 00 0D 07 07
0x82A149 = P, 0x10 00 0D 07 08
0x82A14E = Q, 0x10 00 0D 08 07
0x82A153 = R, 0x10 00 0D 07 07
0x82A158 = S, 0x10 00 0D 07 08
0x82A15D = T, 0x10 00 0D 08 07
0x82A162 = U, 0x10 00 0D 07 09
0x82A167 = V, 0x10 00 0D 09 09
0x82A16C = W, 0x10 00 0D 09 07
0x82A171 = X, 0x10 00 0D 07 08
0x82A176 = Y, 0x10 00 0D 08 07
0x82A17B = Z, 0x10 00 0D 07 0F
0x82A180 = unk
0x82A19E = a, 0x0C 00 09 08 07
0x82A1A3 = b, 0x10 00 0D 07 07
0x82A1A8 = c, 0x0C 00 09 07 07
0x82A1AD = d, 0x10 00 0D 07 07
0x82A1B2 = e, 0x0C 00 09 07 06
0x82A1B7 = f, 0x10 00 0D 06 07
0x82A1BC = g, 0x0C 00 09 07 07
0x82A1C1 = h, 0x10 00 0D 07 04
0x82A1C6 = i, 0x0C 00 09 04 07
0x82A1CB = j, 0x0D 00 0A 07 08
0x82A1D0 = k, 0x10 00 0D 08 05
0x82A1D5 = l, 0x10 00 0D 06 0A
0x82A1DA = m, 0x0B 00 08 0A 07
0x82A1DF = n, 0x0B 00 08 07 07
0x82A1E4 = o, 0x0C 00 09 07 07
0x82A1E9 = p, 0x0C 00 09 07 07
0x82A1EE = q, 0x0C 00 09 07 07
0x82A1F3 = r, 0x0C 00 09 07 07
0x82A1F8 = s, 0x0C 00 09 07 06
0x82A1FD = t, 0x0D 00 0A 06 07
0x82A202 = u, 0x0C 00 09 07 09
0x82A207 = v, 0x0C 00 09 09 09
0x82A20C = w, 0x0C 00 09 09 07
0x82A211 = x, 0x0C 00 09 07 07
0x82A216 = y, 0x0C 00 09 07 07
0x82A21B = z, 0x0C 00 09 07 10
0x82A22F = ~, 0x05 00 07 07 07
</code>

# VWF Parameters for the Zatch Collection Mode

In the case of this font, they all took the same space on screen (monospaced) but could still be adjusted further to display more characters.

Zatch Collection roman font starts at 0x82E868
<code>
0x82E42A = !, 0x08 FE 07 08 05
0x82E42F = ", 0x04 FF 07 08 0B
0x82E434 = unk, 0x0A FD 08 10 0A
0x82E439 = unk, 0x0A FD 08 10 08
0x82E43E = %, 0x08 00 07 08 08
0x82E443 = &, 0x08 00 07 08 04
0x82E448 = ', 0x04 FF 07 08 05
0x82E44D = (, 0x08 FE 07 08 05
0x82E452 = ), 0x08 FF 07 08 07
0x82E457 = *, 0x08 00 07 08 07
0x82E45C = +, 0x07 00 06 08 04
0x82E461 = ,, 0x05 FE 04 08 08
0x82E466 = -, 0x03 00 04 08 04
0x82E46B = ., 0x04 FE 03 08 08
0x82E470 = /, 0x08 00 07 08 08
0x82E475 = 0, 0x08 00 07 08 06
0x82E47A = 1, 0x08 FF 07 08 08
0x82E47F = 2, 0x08 00 07 08 08
0x82E484 = 3, 0x08 00 07 08 08
0x82E489 = 4, 0x08 00 07 08 08
0x82E48E = 5, 0x08 00 07 08 08
0x82E493 = 6, 0x08 00 07 08 08
0x82E498 = 7, 0x08 00 07 08 08
0x82E49D = 8, 0x08 00 07 08 08
0x82E4A2 = 9, 0x08 00 07 08 04
0x82E4A7 = :?, 0x08 FE 07 08 04
0x82E4AC = ;?, 0x08 FE 07 08 05
0x82E4B1 = (, 0x08 FE 07 08 07
0x82E4B6 = =, 0x05 00 05 08 05
0x82E4BB = ), 0x08 FF 07 08 08
0x82E4C0 = ?, 0x08 00 07 08 08
0x82E4C5 = @ (now é) 0x08 00 07 08 08
0x82E4CA = A, 0x08 00 07 08 08
0x82E4CF = B, 0x08 00 07 08 08
0x82E4D4 = C, 0x08 00 07 08 08
0x82E4D9 = D, 0x08 00 07 08 08
0x82E4DE = E, 0x08 00 07 08 08
0x82E4E3 = F, 0x08 00 07 08 08
0x82E4E8 = G, 0x08 00 07 08 08
0x82E4ED = H, 0x08 00 07 08 06
0x82E4F2 = I, 0x08 FF 07 08 08 //check out that FF
0x82E4F7 = J, 0x08 00 07 08 08
0x82E4FC = K, 0x08 00 07 08 08
0x82E501 = L, 0x08 00 07 08 08
0x82E506 = M, 0x08 00 07 08 08
0x82E50B = N, 0x08 00 07 08 08
0x82E510 = O, 0x08 00 07 08 08
0x82E515 = P, 0x08 00 07 08 08
0x82E51A = Q, 0x08 00 07 08 08
0x82E51F = R, 0x08 00 07 08 08
0x82E524 = S, 0x08 00 07 08 08
0x82E529 = T, 0x08 00 07 08 08
0x82E52E = U, 0x08 00 07 08 08
0x82E533 = V, 0x08 00 07 08 08
0x82E538 = W, 0x08 00 07 08 08
0x82E53D = X, 0x08 00 07 08 08
0x82E542 = Y, 0x08 00 07 08 08
0x82E547 = Z, 0x08 00 07 08 0A
0x82E54C = unk, 0x0A FD 08 10 08
0x82E551 = unk, 0x08 00 07 08 04
0x82E556 = unk, 0x08 FE 07 08 06
0x82E55B = unk, 0x04 FF 07 08 08
0x82E560 = unk, 0x03 00 02 08 05
0x82E565 = ,?, 0x04 FF 07 08 08
0x82E56A = a, 0x08 00 07 08 08
0x82E56F = b, 0x08 00 07 08 07
0x82E574 = c, 0x06 00 05 08 08
0x82E579 = d, 0x08 00 07 08 08
0x82E57E = e, 0x07 00 06 08 06
0x82E583 = f, 0x08 FF 07 08 08
0x82E588 = g, 0x08 00 07 08 08
0x82E58D = h, 0x08 00 07 08 04
0x82E592 = i, 0x08 FE 07 08 07
0x82E597 = j, 0x08 00 07 08 08
0x82E59C = k, 0x08 00 07 08 05
0x82E5A1 = l, 0x08 FF 07 08 08
0x82E5A6 = m, 0x07 00 06 08 08
0x82E5AB = n, 0x07 00 06 08 08
0x82E5B0 = o, 0x07 00 06 08 08
0x82E5B5 = p, 0x08 00 07 08 08
0x82E5BA = q, 0x08 00 07 08 06
0x82E5BF = r, 0x07 FF 06 08 08
0x82E5C4 = s, 0x07 00 06 08 06
0x82E5C9 = t, 0x08 FF 07 08 08
0x82E5CE = u, 0x07 00 06 08 08
0x82E5D3 = v, 0x07 00 06 08 08
0x82E5D8 = w, 0x07 00 06 08 08
0x82E5DD = x, 0x07 00 06 08 08
0x82E5E2 = y, 0x07 00 06 08 08
0x82E5E7 = z, 0x07 00 06 08 05
0x82E5EC = {, 0x08 FE 07 08 03
0x82E5F1 = |?, 0x08 FD 07 08 05
0x82E5F1 = }, 0x08 FD 07 08 05
</code>

# Changing Credits Position

These are some addresses for adjusting the position of credits.

The rest can be found out by continuing the pattern.
These were found by comparing the size of the character and calculating the x pos from left to right.

<code>
0x7D5280 = x pos for 'Character Voice' 1
0x7D52D4 = x pos Producers
0x7D52F0 = x pos Direction
0x7D531C = x pos Planning
0x7D5328 = x pos Assistance
0x7D5360 = x pos Graphics 2
0x7D5380 = x pos T's Music
0x7D53A0 = x pos Debugging
0x7D53BC = x pos Support Staff 1
0x7D53D0 = x pos Support Staff 2
0x7D53EC = x pos Cooperation
0x7D53FC = x pos Toei Animation
</code>

# Editing the Script

For the entirety of the project I manually edited the script in a hex editor and used my tool to calculate the pointers.

There's not much else to it, but dialogue scenes, including the ones in the minigames, are buffered in order to do a 'printing' effect.

In order for the effect to work, the game reads the string in sets of 3 bytes (because the main encoding is 3 bytes!) Since the script is now 1 byte per character, you need to manually make sure the string is divisible by 3 by padding the string with spaces 0x20.

If you don't, the game will miss the terminating 0 and continue copying data until a 0 is found... or the game crashes.

I originally wanted to add a check for this in the tool but it was never a problem to just write the string carefully.


# Overflow hack

The "Overflow Hack" is what I called the bruteforce way of displaying more lines to fit more dialogue.
Because this game has no linebreak/newline command, each string is hardcoded to the spot it belongs to.

During dialogue scenes, the 3 main lines are buffered into (IIRC) 128 bytes, what you do is write spaces (0x20) until you reach the buffer for the following line.

This produced a slight delay when displaying the new line, it wasn't the best solution.

Luckily I found the hardcoded values to control which lines display each string! And they are pretty easy to find thanks to a simple pattern.
They are 32-bit little-endian values in a list, each value represents the number of a string as it exists on the script.

For example open up the script .bin in a hex editor and find text for Rauzaruk Zatch's start dialogue:
<code>
"Kiyo"
"Inside you lies great power, Zatch!"
</code>

The first string is Kiyo's name tag, copy the offset position where the 'K' starts and reverse it to 32-bit little-endian.
0x1491 = 0x91140000 search for this value in the pointer table, now divide that offset (0x30) by 4, the result is 12 or 0xC in hex.

Do the same for string number 2 and...
<code>
0x000C = "Kiyo"
0x0152 = "Inside you lies great power, Zatch!"
</code>

Now you have a pattern! Reverse the bytes for little endian...

<code>
0C00 0000 5201 0000
</code>

This will only give you 1 search result, which is exactly what we wanted.

You'll notice how the following number is 0xCA000000 that's string 0xCA (202) which is a blank space in the game's 3-byte encoding.

If you change it with 0x52010000 you'll get "Inside you lies great power, Zatch!" to also appear on the 2nd line.
So in order you use this effectively, one has to insert a new line in the script file.

And that is what I did to avoid cutting corners on the dialogue.

Another peculiar thing about this design is that name tags were often used to save space on the script.
Sunbeam's "We've met the enemy, ponygon" used the 3rd line to point to Ponygon's tag.
That makes the layout awkward in English, especially because there's no punctuation.

This also helped shed some light on one of the unused lines: "I'll show you a real nightmare!!!"
If you follow the pattern:
<code>
"Zeno"
"I'll show you a real nightmare!!!"
"" (blank)
"" (blank)
"Dufort"
"..."
"" (blank)
"" (blank)
</code>
And that ends the table for dialogue, so it is indeed a Zeno line.
It's likely this line was supposed to be in the Extra Battle in Battle Mode because Zeno is always the bonus fight.

// All the overflow hack fixes
<code>
0xFCE494 = We've met the enemy, ponygon ! (3rd line removal)
0xFCE660 = Bari: Once and for all (2nd line added)
0xFCE6B0 = Sherry: boy of the red book (2nd line added)
0xFCE7A0 = Victoream: what even is (2nd line added)
0xFCE7D0 = Victoream... (repoint)
0xFCEA00 = Naomi, life (3rd line added)
0xFCD850 = Koko, truth (2nd line edited)
0xFCD9A0 = Naomi, supposed (2nd line added)
0xFCDB70 = Megumi concert lines (can be added)
0xFCDB88 = Tia, use pointer 967
0xFCDD90 = CatchMyHeart
0xFCDE40 = Bari Hmph! (added 3rd line)
0xFCE010 = ZofisWrith (added 2nd line)
0xFCE070 = ZenoTorment (added 2nd line)
0xFCE5C4 = PennyDestZatch (organize)
</code>

# String Pointer List for Unlocking Items

Similarly, the message you get for unlocking items is controlled like dialogue is.

0xFCBB24 = pointer list for items being unlocked

That's it, I changed all of them because it looked better to name the item on the first line instead of the 2nd. Mainly because in these spots of the game I wanted to mix the JPN font.


# Tile Map Data

Gonna be brief here because this is a pain to explain.
Essentially, GBA games use a 'map' that determines where each tile will show up on the screen, at least for sprites that appear in any of the 4 background layers.

0x8B6190 = logo map data

Using an emulator like mGBA, you can display the map data easily, and if you're lucky the game will store that data in the ROM as is, making playing around with it much easier.

Many graphics use repeating tiles to save ROM space, so for this game editing the tile maps was crucial. The title screen logo features the most complex edit.


# Password Mode

Finding the password mode key combo was pretty easy, the button inputs are stored in the ROM just like the GBA reads input.

0x7D4FD4 = Password Mode key combo, found by searching 4000 2000 1000 8000, the key values in LE 16bit format.
0x2C540 = pointer for the 13106 master code GET text.

0xFCBF78 contains the item 51 password for turning title screen red.
Example of password data storage:
0000000x0000000x0000000x0000000x
The x represents the value in the password dial.

Therefore 86300 is:
0800000006000000030000000000000000 //red title screen to unlock Vulcan 3000


# Fonts Used for Graphics

Kido's Up+B+R "SHOCK" sign is using a font called Mistral.
The top-left blue logos for modes use Milford Condensed, bold, italic, 11pt, no aa.
Arial was used for simple stuff.

Minish Cap's font served as the alternate VWF for the main font, each character was checked against the game to match the width.


# Voice Editing

There are 169+1 voiced sounds + an unused Dufort line casting Jikerdor.
Voice acting is a big feature in this game so dubbing it was pretty important to me.

The GBA is ~~cool~~ _groovy_ hardware but I doubted the developers would put something complex for rendering audio, so I assumed whatever audio format was used _had_ to be something Audacity could pick up.

So I used the import 'Raw Data' option and tried all the obvious settings:
<code>
Encoding: Signed 8-bit PCM
Byte order: Little-endian
Channels: 1
Sample Rate: 11025
</code>

Of course, I imported the entire ROM but I started slicing it chunk by chunk, until it became more manageable.

Eventually, I found the offset of the very first sound, and also a way to detect the start of a sound, as they have a unique header.

Repointing sounds doesn't allow you to use longer sounds unfortunately, so I found another way, it's tricky, though!

Pointers can be searched by looking at the sample rate s32 and going back 5 bytes.
Before each pointer is a u32 of the data size of the sound but counting starts at the u32.

How to extend length of a voice line:
- Go to the pointer address of the sound. (Find it on the list below.)
- Look at the 32-bit value that's BEFORE the pointer.
- Search for its pointer.
- Now load into the pointer that's AFTER the one you found.
- It should take you to the location of the 0x14 bytes (longer clips are 0x18 bytes) that control the length of the voices. Or, look for this value 0100 6480 to find it, 166 sounds use it.
(168 has gotta be the longest sound, ptr 3084FA08, so use that one's parameters to extend other sounds.)

Pretty messy, right? The values below are for the original voices, not the new ones. It was tiring to make a note of every repoint so I stopped.

<code>
000 = YattaDaKiyomaro! = 0xCEE274
001 = Unu! = 0xCF1C94
002 = EeeaAeh! = 0xCF3734
003 = BuriWaUmaino = 0xCF764C
004 = KiyoIntro = 0xD26708
005 = Rauzaruk = 0xD29FBC, repointed in 0xE22784 at D07BFD08 (FD7BD0)
006 = Zaker = 0xD2BE70
007 = Rashield = 0xD2CF3C
008 = Jikerdor = 0xD2E7B8
009 = Zakeruga = 0xD304FC
010 = Zagurzem = 0xD32404 (0x22C8)
011 = YarudoGash! = 0xD346E0
012 = BaoZakeruga = 0xD3703C
013 = KiyoAaaaah = 0xD3A878
014 = TiaMakazete = 0xF57F2C
015 = Eh! Heh! = 0xF5A22C
016 = Heh..! = 0xF5C0F0
017 = IkoiyoTia! = 0xD64DA8
018 = Saisu = 0xD66E7C
019 = Seoshi = 0xD680D8
020 = MaSeshield = 0xD69958
021 = Saifogeo = 0xD6C570
022 = Imayo! = 0xD6E508
023 = GigaLaSeoshi = 0xD6F384
024 = MegumiAaaaah = 0xD729A0
025 = KanchomeYattaFolgore = 0xC71930
026 = Folgore! = 0xC765B4
027 = FolgoreIntroAHaha! = 0xCD0850
028 = Poruk = 0xCD51D0
029 = Koporuk = 0xCD6544
030 = Dikaporuk = 0xCD7F68
031 = ChiChiwoMogeDa! = 0xCDA2BC
032 = FolgoreAaaaah! = 0xCDD4C0
033 = KidoEnd = 0xD1DB70
034 = shock = 0xD2173C
035 = Egh! = 0xD24178
036 = IkusoKido! = 0xD8C8F4
037 = Zegaru = 0xD8EC0C
038 = ZanenSeikai = 0xD91BC8
039 = AmZegar = 0xD8FC48
040 = RajaZerusen = 0xD964BC
041 = Zega-- = 0xD9982C
042 = U-so! = 0xD9A9F0
043 = DontgiveKido = 0xD9CCDC
044 = MikorMaZegaruga = 0xDA00F0
045 = DoctorRiddlesAaah = 0xDA3D34
046 = IkuzoLi-en! = 0xFABFC4
047 = Kuuuoooh! = 0xFAEDA4
048 = Li-enHaiyaru! = 0xD47E78
049 = wonreiYataru = 0xD4961C
050 = Rerudo = 0xD4D5C0
051 = GoBoren = 0xD4EE20
052 = GanzuBoren = 0xD51558
053 = WonreiIkoe! = 0xD54448
054 = RaoDiboren = 0xD577A0
055 = Li-enAaaaah = 0xD5B1B0
056 = MeruMeruMe! = 0xF7650C
057 = merumerume = 0xF7217C
058 = Shudoruk = 0xF3E828
059 = SighYarayarada = 0xF3A7A4
060 = RockNRoll! = 0xF42D90
061 = GoShudork = 0xF40530
062 = IkuzoUmagon! = 0xF4684C (changed ptr at 0xE22AF0 to 0xD07BFD08)
063 = Groovy! = 0xF48EE4, extender values at 0xFA8E50
064 = SunbeamAaaah = 0xF4C5E8 (44508Hz), ptr at 0xE22B08
065 = BariKahuui! = 0xC4B7F0
066 = KoredeOwari = 0xC4D508
067 = Yatearuo! = 0xC52344
068 = Zonis = 0xD09510
069 = Zorushield = 0xD0AB2C
070 = GaraZonis = 0xD0C8DC
071 = Bari! = 0xD0E574
072 = GiganoZonis = 0xD0FA38
073 = GustavAaaah = 0xD12B78
074 = PattiIntro = 0xDAA5B0
075 = PattiEnd = 0xDAE5D8
076 = PattiUltimate = 0xDB3300
077 = PattiHappi = 0xDB81DC
078 = PattiGrowl = 0xDB571C
079 = Akur = 0xF7AF04
080 = Ashield = 0xF7C4C8
081 = OrudaKuran = 0xF7DE48
082 = SouGiaku = 0xF800E8
083 = UriAaaah = 0xF82AF8
084 = WatashiVictoream = 0xF859AC
085 = Bakabaka! = 0xF8A604
086 = VnochikaraShotenni = 0xF92AF0
087 = buuurraaa! = 0xF9681C
088 = gashunk! = 0xF99F40
089 = Wagakaradabigshunk! = 0xF8F07C
090 = taisedo = 0xF9BBEC
091 = VeryMelon = 0xF9E540
092 = Uuuooh!SaikoDase = 0xFA2B10
093 = Magurga = 0xD783CC
094 = MagurYoyo = 0xD7A318
095 = Chagur = 0xD7D2C0
096 = ChagurImisdon = 0xD7EBA8
097 = MohawkAceAaaah = 0xD82A18
098 = IkoiyoAru = 0xD3D2E8
099 = YattaNeAru = 0xD40158
100 = HontoNoChi = 0xD434C4
101 = Migron = 0xC31118, ptr 0xE22490
102 = Mishield = 0xC327C4
103 = OruMigurga = 0xC34304
104 = RajaMigsen = 0xC36E6C
105 = IkuseReira = 0xC39CD8
106 = MibernaMaMigron = 0xC3C360
107 = Roll! = 0xC3FC44
108 = Fire! = 0xC40F40
109 = Connect! = 0xC42478
110 = and Harvest! = 0xC43C70
111 = Al Aaaah! = 0xC46F24
112 = BragoHmph = 0xC6BD70
113 = SherryIkinasai = 0xDEFC5C
114 = KoreDeOwari = 0xDF1154
115 = Reis = 0xDF354C
116 = Gravirei = 0xDF4B10
117 = GiganoReis = 0xDF6578
118 = IonGravirei = 0xDF90FC
119 = Ikoiyo = 0xDFC4FC
120 = BaberGravidon = 0xDFD9DC
121 = SherryAaaaah = 0xE015D8 (44508Hz)
122 = ZofisIntro = 0xFBB764
123 = KokomadeNoYoDesuNe = 0xFC0F5C
124 = Nagutteagemasho = 0xFC4DF0
125 = KokoAhoomp = 0xC78250
126 = Radom = 0xC7921C
127 = RondRadom = 0xC7A438
128 = Gigaradoshield = 0xC7C960
129 = DiogaTeoRadom = 0xC7FCF0
130 = giggle = 0xC8325C (44508Hz)
131 = ZeonIntro 0xFB4154
132 = Kiero = 0xFB9CE4
133 = Yare! = 0xFB7C58
134 = DufortEnd = 0xCA83E8
135 = Zaker2 = 0xCAADEC
136 = Rashield2 = 0xCABE74
??? = Jikerdor2 = 0xCAD3FC
137 = Zakeruga2 = 0xCAEB28
138 = Zeon... = 0xCB0314
139 = ZeoZakeruga = 0xCB1DAC
140 = DufortAaaah = 0xCB49A0 (44508Hz)
141 = NaomiEhehe = 0xD8A5DC
142 = NaomiIntro = 0xD86B20
143 = RaikuHure! = 0xDCC61C
144 = IkimasuyoIidesuka = 0xDCCD3C
145 = RaikuAaaaaah = 0xDD47B8
146 = aikuzoVULCAN! = 0xDC4DD8
147 = Yeeeeiiii! = 0xDC9298
148 = yoshaVULCAN! = 0xDD0314
149 = MEEEEEEEEH!(Dartagnan) = 0xDBBB98
150 = Suzy/Gambatte! = 0xF31088
151 = Suzy/Message = 0xF3303C
152 = Suzy/Congrats = 0xF381E4
153 = BigBoingYeah! = 0xC5CDD8
154 = RyuzuladeKiroro = 0xC94DB0
155 = DiogaRyusudon = 0xC985D8
156 = RyuzYoyo = 0xC9B650
157 = GanzuGoRyuga = 0xC9E4B8
158 = WatashiGaAitara(Joe) = 0xCC3F14
159 = Doryoo!(Wife) = 0xFA9224
160 = Kaahahaha!(Superhero) = 0xCC6A08
161 = BelgimGood = 0xC6100C
162 = Maximum = 0xC641E4
163 = BelgimFail = 0xC671D0
164 = Ready...? = 0xF53934
165 = Fight! = 0xF5518C
166 = GameOver = 0xF55F40
167 = KonjikinoGashBell = 0xCE5CBC (0x2E8A)
168 = Unare! Yuujo no Zakeru 2 = 0xCE8B58 (0x570A)
</code>

# Afterword

It's taken me several months to post this info, it's not as clean as I'd like it to be but it's something.

Did you know Raiku is voiced in this game by Jun'ichi Kanemaru? He's been Sonic's voice actor since 1998!
I didn't want to leave Raiku undubbed, so I decided to voice him myself, I thought it seemed fitting to try to mimic Jason Griffith's Sonic which is my personal favorite.
It just didn't work out, so I tried to do a 180 on it and try a Jim Carrey-sounding voice but it was terribly annoying... So I just compromised with a halfway Griffith and generic Pokémon Trainer impression.

After I finished with EA2 I wanted to take a break. I just wanted to do a simple translation and be done with it but it sort of snowballed thanks to the discovery of adjustable fonts, voice dubbing, Raze's translations, and desperately trying to port everything to the 1.1 revision.
I planned to finish way before Christmas 2023, I regrettably spent a lot of that Christmas thinking about this project. It worked out in the end because seeing this game fully in English was something truly special to me.

Once again, shoutout to Raze, whose translations and expertise helped make this project feel thoroughly finished.
