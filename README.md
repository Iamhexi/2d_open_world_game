# 2d_open_world_game
It's the 2D open world game written in C++20 using SFML library for graphics. Work in progress.

## Requirements
Software required to build the game:

- make

- cmake (version >= 3.22)

- sfml (version >= 2.6)

- gtest

## Installation
Run the following commands:
```
cmake . -B build
cd build
make
./run
```

## Todo list

- [x] Let the player change an active item with the `e` and `q` keys.
- [x] Display an active item in the main character's hand.
- [x] Add NPCs to the main scene.
- [x] Let the player start dialogues with NPCs.
- [x] Each NPCs should have an original dialogue. Dialogues should be automatically loaded from text files.
- [x] Allow the player to replay any dialogue infinite number of times.
- [ ] Add path to an individual NPC follow. Some NPCs may just stand.

## Gameplay

### Key bindings

| **Key** | **Action** |
|-------|-------|
| Enter/Return | Go to the next dialogue line during a dialogue. |
| f | Pick up an item. |
| w | Move up. |
| s | Move down. |
| a | Move left. |
| d | Move right. |
| e | Choose the next item from an inventory. |
| q | Choose the previous item from an invetory. |
| z | Start a conversation with a nearby character. |