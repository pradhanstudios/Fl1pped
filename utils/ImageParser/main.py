from PIL import Image
import api

WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
BLUE = (0, 0, 255)
color = ()
arguments = []

img = Image.open("test.png").convert("RGB")
pixel_map = img.load()

black_pixels = api.find_all(BLACK, img)
red_pixels = api.find_all(RED, img)
blue_pixels = api.find_all(BLUE, img)

for corner in black_pixels:
    x, y = corner
    color = api.RGB_to_RGBA(pixel_map[x+1, y])
    while (x, y) not in red_pixels:
        x += 1
    while (x, y) not in blue_pixels:
        y += 1
    arguments.append((corner[0], corner[1], x, y, color[0], color[1], color[2], color[3]))

for args in arguments:
    for arg in args:
        print(arg, end=", ")
    print("\n")
    










