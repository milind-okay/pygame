import pygame,sys,math
from pygame.locals import *

pygame.init()
pygame.mixer.init()

weidth,height = 1000,600

screen = pygame.display.set_mode((weidth,height),0,32)

while True:
 for event in pygame.event.get():
  if event.type == QUIT :
   pygame.quit()
   sys.exit()
   
 pygame.display.update()
   
