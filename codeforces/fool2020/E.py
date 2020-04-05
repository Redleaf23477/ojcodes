from PIL import Image

im = Image.open('img.png') # Can be many different formats.
pix = im.load()
for y in range(0, 63):
    lst = [] 
    for x in range(0, 63):
        v = pix[x*15+1,y*15]
        if v == (255,255,255):
            lst.append(1)
        else:
            lst.append(0)
    print(*lst, sep=',')
#print(pix[0*15+1,0*15])
#print(pix[27*15+1,0*15])
#print(pix[0*15+1,27*15])
#print(pix[27*15+1,27*15])
