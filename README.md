# raycast_game
## Description:
This is a simple game in which you can walk and take screenshot😁
You can also change the map (map_configs/src_map.cub).
<img src="https://github.com/bshawnee/raycast_game/blob/main/animation.gif" width="400" height="400"/>

## settings:
You can change textures (use 64px x 64px resolution)

### Map config:
  - R = resolution
  - F = color of floor
  - C = color of sky
  - NO = north wall texture
  - SO = south wall texture
  - WE = west wall texture
  - EA = east wall texture
  - S = sprite texture
  - 1 = wall
  - 2 = sprite
  - 0 = floor
  - S(in map) = player's starting position 

### Keys:
  - WASD - move
  - left and right arrow = view angle
  
  ## How to run:
  1. make
  2. ./cub3D map_configs/src_map.cub
  (If you want to take a screenshot add the argument "--save")

## Dependencies:
- macOS
- Xquartz
- make
- gcc
