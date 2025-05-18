"""这个是没有设置精灵类的版本"""
import pygame

from pygame.constants import * #可以导入pygame.constants的所有方法

class CommonPlane():
   def __init__(self,screen): 
      self.com_plane = pygame.image.load("./picture/player.png") #初号机图片46*57
      self.x = 210
      self.y = 600
      self.speed = 5
      self.screen = screen    
      self.bullets = [] # 子弹列表
   def key_control(self):
         key_pressed = pygame.key.get_pressed() #key指键盘，get_pressed是按住
      
         if key_pressed[K_w] or key_pressed[K_UP]:

            self.y -= self.speed

         if key_pressed[K_a] or key_pressed[K_LEFT]:
            
            self.x -= self.speed

         if key_pressed[K_d] or key_pressed[K_RIGHT]:
            
            self.x += self.speed

         if key_pressed[K_s] or key_pressed[K_DOWN]:
           
            self.y += self.speed
         if key_pressed[K_SPACE]: 
            bullet = Bullet(self.screen,self.x,self.y) 
            self.bullets.append(bullet)
   def display(self):   
      self.screen.blit(self.com_plane,(self.x, self.y)) #飞机
      for bullet in self.bullets: 
         bullet.display()  
         bullet.move()
         
class Bullet():
   def __init__(self,screen,x,y):
      self.x = x + 21
      self.y = y - 12
      self.image = pygame.image.load("./picture/zidan2.png") #加载子弹图片  
      self.screen = screen  
      self.speed = 10
      
   def display(self):
      self.screen.blit(self.image,(self.x, self.y)) #显示子弹
   def move(self):#子弹向上移动
      self.y -= self.speed