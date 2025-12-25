# fcitx5-vi-escape

A fcitx5 addon for Vim users that deactivates the input method when pressing Escape outside of preedit mode.

## Description

When using fcitx5 with Vim (or Neovim), pressing Escape while the input method is active typically requires two key presses:

1. First Escape: Commits or clears the preedit text
2. Second Escape: Exits Vim's insert mode

This addon streamlines the workflow by automatically deactivating the input method when Escape (or Ctrl+[) is pressed and there is no active preedit text. The key event is passed through to Vim, allowing you to exit insert mode with a single key press.

## Features

- Deactivates IME on Escape or Ctrl+[ when no preedit is active
- Passes the key event through to the application
- Minimal and lightweight implementation

## Requirements

- fcitx5
- CMake >= 3.15
- C++20 compatible compiler

## Installation

```bash
cmake -B build -DCMAKE_INSTALL_PREFIX=/usr
cmake --build build
sudo cmake --install build
```

## How It Works

The addon watches for key events in the `PostInputMethod` phase. When an Escape or Ctrl+[ key press is detected and the event has not been consumed by the input method (indicating no preedit text), it deactivates the input method while allowing the key event to propagate to the application.

## License

See LICENSE file for details.
