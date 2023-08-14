from PIL import Image
import api
# define constants
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
BLUE = (0, 0, 255)
MAGENTA = (255, 0, 255) # player 1 pos
PURPLE = (128, 0, 128) # player 2 pos
# define color and arguments for later
color = ()
arguments = []

#image stuff
img = Image.open("test.png").convert("RGB") # convert to RGB for easier use
pixel_map = img.load() # all RGB values of pixels

# get pixels

black_pixels = api.find_all(BLACK, img) # top left
blue_pixels = api.find_all(BLUE, img) # top right
red_pixels = api.find_all(RED, img) # bottom right
white_pixels = api.find_all(WHITE, img)
magenta_pixel = api.find_all(MAGENTA, img) # player 1 pos
purple_pixel = api.find_all(PURPLE, img) # player 2 pos

arguments.append((magenta_pixel[0][0], magenta_pixel[0][1])) # player 1 pos
arguments.append((purple_pixel[0][0], purple_pixel[0][1])) # player 2 pos


for corner in black_pixels:
    x, y = corner
    color = api.RGB_to_RGBA(pixel_map[x+1, y]) # get the next pixel to the right of the top left to get the color of the rectangle
    while (x, y) not in red_pixels: # top left to top right
        x += 1
    while (x, y) not in blue_pixels: # top right to bottom right
        y += 1
    # top_left.x, top_left.y, bottom_right.x, bottom_right.y {RGBA} values
    arguments.append((corner[0], corner[1], x, y, color[0], color[1], color[2], color[3]))

# print arguments
for args in arguments:
    for arg in args:
        if arg:
            print(arg, end=", ")
    print("\n")
    










