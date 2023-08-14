from PIL import Image
import api
# define constants
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
BLUE = (0, 0, 255)
# define color and arguments for later
color = ()
arguments = []

#image stuff
img = Image.open("test.png").convert("RGB") # convert to RGB for easier use
pixel_map = img.load() # all RGB values of pixels

# get pixels
black_pixels = api.find_all(BLACK, img) # all top left
red_pixels = api.find_all(RED, img) # all top right
blue_pixels = api.find_all(BLUE, img) # all bottom right

for corner in black_pixels:
    x, y = corner
    color = api.RGB_to_RGBA(pixel_map[x+1, y]) # get the next pixel to the right of the top left to get the color of the rectangle
    while (x, y) not in red_pixels: # top left to top right
        x += 1
    while (x, y) not in blue_pixels: # top right to bottom right
        y += 1
    arguments.append((corner[0], corner[1], x, y, color[0], color[1], color[2], color[3]))

# print arguments
for args in arguments:
    for arg in args:
        print(arg, end=", ")
    print("\n")
    










