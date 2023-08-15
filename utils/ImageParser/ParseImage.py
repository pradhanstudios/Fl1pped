import cv2
import numpy as np
from PIL import Image
import api
import sys

filename = sys.argv[1]

img = cv2.imread(filename)
p_img = Image.open(filename)
pixel_map = p_img.load()
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

ret,thresh = cv2.threshold(gray,50,255,0)
contours,hierarchy = cv2.findContours(thresh, 1, 2)
# print("Number of contours detected:", len(contours))
args = []

width, height = p_img.size

for cnt in contours:
   x1,y1 = cnt[0][0]
   approx = cv2.approxPolyDP(cnt, 0.01*cv2.arcLength(cnt, True), True)
   if len(approx) == 4:
        x, y, w, h = cv2.boundingRect(cnt)
        # print(cnt)
        ratio = float(w)/h
        color = api.RGB_to_RGBA(pixel_map[x, y])
        if not (not (w > 5 and h > 5) or width in [x, y, x+w, y+h, color[0], color[1], color[2], color[3]] or height in [x, y, x+w, y+h, color[0], color[1], color[2], color[3]]):
            args.append([x, y, x+w, y+h, color[0], color[1], color[2], color[3]])
            print([w, h])
            img = cv2.drawContours(img, [cnt], -1, (0,255,0), 3)
    
        #   print(color)
        # print([w, h])

        
with open(f"{filename}_converted.txt", "w") as fh:
    for arguments in args:
        for arg in arguments:
            print(arg, end=", ")
            fh.write(f"{arg}, ")

        print("\n")
        fh.write("\n")
        

cv2.imshow("level_with_parsing", img)
cv2.waitKey(0)
cv2.destroyAllWindows()