# Front-end and game library plan

## Aurora-inspired library

The planned Xbox 360 interface uses a cover-first grid, selected-game details, favorites, text search, category filters, and configurable sorting. It is an original interface inspired by the usability of Aurora; it will not copy proprietary assets or code.

## Storage layout proposal

- `Hdd1:\\Emulators\\OneX360\\Games\\` — user-provided homebrew/test images and game files
- `Hdd1:\\Emulators\\OneX360\\Covers\\` — cover cache
- `Hdd1:\\Emulators\\OneX360\\Saves\\` — save-state slots
- `Hdd1:\\Emulators\\OneX360\\Config\\` — settings, favorites and library metadata

Actual mount names and writable paths must be verified on the target console before implementation is called complete.

## Cover download

A network service will later support wired Ethernet and Wi-Fi through the Xbox 360 network stack. It must use a configurable metadata/artwork provider, cache images, retry safely, and never download executable game content. Network access and provider compatibility are not implemented in this checkpoint.

## Startup presentation and audio

The boot flow will support a custom splash screen and optional user-supplied audio asset. The original Xbox One startup animation and theme music are copyrighted assets; they must not be bundled without appropriate rights. A clean implementation can use original artwork/audio or assets supplied by the user with permission.

## Quality and performance

Planned profiles: Performance, Balanced and Quality, plus per-title overrides. Options will only become active when the corresponding renderer/audio features exist; no placebo toggles.