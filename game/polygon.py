import pygame,sys,math
from pygame.locals import *

pygame.init()
pygame.mixer.init()

weidth,height = 1000,600

screen = pygame.display.set_mode((weidth,height),0,32)

points = [(100,100),(200,100),(300,300),(400,300)]
points1 = [(300,100),(400,100),(100,300),(200,300)]
color = (255,255,0)
color1 = (0,0,0)
count = 0
while True:
    for event in pygame.event.get():
        if event.type == QUIT :
            pygame.quit()
            sys.exit()
   
    #screen.lock()
    if count%200 >= 100:
		 pygame.draw.polygon(screen,color,points)
		 pygame.draw.polygon(screen,color1,points1)
		 #count = 0
		 pygame.display.update()
    else:
	    pygame.draw.polygon(screen,color,points1)
	    pygame.draw.polygon(screen,color1,points)
	    pygame.display.update()
    #screen.unlock()	
    count+=1
    pygame.display.update()
   
