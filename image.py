import Image, ImageFilter

im = Image.open('C:/Users/Administrator/Desktop/hh.png')
im2 = im.filter(ImageFilter.BLUR)
im2.save('C:/Users/Administrator/Desktop/hh1.png', 'png')
