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

- [ ] Let the player change an active item with the `e` and `q` keys.
- [ ] Display an active item in the main character's hand.
- [ ] Add NPCs to the main scene.
- [ ] Let the player start dialogues with them.

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