import pygame
from main import Manager

class GameBackground():
   bg_size = (456,665)
   def __init__(self,screen):
      self.mImage1 = pygame.image.load("./picture/BGP3.png") #加载背景图片
      self.mImage2 = pygame.image.load("./picture/BGP3.png") #加载背景图片

      self.screen = screen 

      self.y1 = 0 #设置背景图片的y坐标
      self.y2 = -self.bg_size[1]

   def draw(self):
      self.screen.blit(self.mImage1,(0,self.y1)) #将背景图片贴到窗口
      self.screen.blit(self.mImage2,(0,self.y2)) #将背景图片贴到窗口
   def move(self):
      
      self.y1 += 2 #背景图片的y坐标每次加5
      self.y2 += 2 #背景图片的y坐标每次加5

      if self.y1 >= self.bg_size[1]: #如果背景图片的y坐标大于窗口的高度
         self.y1 = -self.bg_size[1] #将背景图片的y坐标重置为0

      if self.y2 >= self.bg_size[1]: #如果背景图片的y坐标大于窗口的高度
         self.y2 = -self.bg_size[1] #将背景图片的y坐标重置为0