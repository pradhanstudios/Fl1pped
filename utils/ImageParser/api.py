from PIL import Image

# find all pixels of a certain color
def find_all(COLOR, img):
    pixel_map = img.load()
    pixels = []
    for i in range(img.size[0]):
        for j in range(img.size[1]):
            if (pixel_map[i, j] == COLOR):
                # print(f"NOT WHITE: {i}, {j}; COLOR: {pixel_map[i, j]}")
                pixels.append((i, j))

    return pixels

# convert  RGB value to RGBA
def RGB_to_RGBA(COLOR):
    newimg = Image.new("RGB", (1, 1), COLOR).convert("RGBA")
    return newimg.load()[0, 0]
