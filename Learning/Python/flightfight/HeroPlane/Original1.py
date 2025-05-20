"""这个是没有设置精灵类的版本"""
import pygame

from pygame.constants import * #可以导入pygame.constants的所有方法

class CommonPlane(pygame.sprite.Sprite):
   def __init__(self,screen): 
      pygame.sprite.Sprite.__init__(self) #精灵的初始化方法，必须调用

      self.com_plane = pygame.image.load("./picture/player.png") #载入初号机图片46*57
      
      self.rect = self.com_plane.get_rect() #rect就是矩形，该方法是根据图片的大小创建一个矩形
      self.rect.topleft = [210,600]#设置矩形的坐标位置，topleft是精灵类的一个属性

      
      self.speed = 5
      
      self.screen = screen    
      
      self.bullets = pygame.sprite.Group() # Group是精灵族的意思，专门来存储精灵，类似于列表
   def key_control(self):
         key_pressed = pygame.key.get_pressed() #key指键盘，get_pressed是按住
      
         if key_pressed[K_w] or key_pressed[K_UP]:

            self.rect.top -= self.speed #rect.top代表矩形的顶部坐标

         if key_pressed[K_s] or key_pressed[K_DOWN]:
           
            self.rect.bottom += self.speed

         if key_pressed[K_a] or key_pressed[K_LEFT]:
            
            self.rect.left -= self.speed

         if key_pressed[K_d] or key_pressed[K_RIGHT]:
            
            self.rect.right += self.speed

        
         if key_pressed[K_SPACE]: 
            bullet = Bullet(self.screen,self.rect.left,self.rect.top) #将矩形的左上角坐标带入 
            self.bullets.add(bullet) #这里是为了应对精灵类的add方法，将子弹添加到精灵族中
   def update(self): #方便调用
      self.key_control()
      self.display()

   def display(self):   
      self.screen.blit(self.com_plane,self.rect) #飞机

      self.bullets.update() #update是Group的一个方法，用于更新每个子弹的坐标
      self.bullets.draw(self.screen) #draw是Group的一个方法，用于将每个子弹绘制到窗口中,因此就不再需要子弹类中的display方法
         
class Bullet(pygame.sprite.Sprite):
   def __init__(self,screen,x,y):
      pygame.sprite.Sprite.__init__(self)
           
      self.image = pygame.image.load("./picture/zidan2.png") #加载子弹图片  
      
      self.rect = self.image.get_rect() #使图像成为一个矩形
      self.rect.topleft = [x+21,y-12]
      
      self.screen = screen  

      self.speed = 10
      
   def update(self):#子弹向上移动
      self.rect.top -= self.speed

      if self.rect.top < -22:
         self.kill()         # 超出界面则删除子弹对象