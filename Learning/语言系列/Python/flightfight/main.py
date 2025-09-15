import time 

import pygame

from Map.map0 import * # 背景图片

from pygame.constants import * #可以导入pygame.constants的所有方法

from enemy.enemyplane1 import * # 敌机一号

from HeroPlane.Original1 import * #英雄飞机

from BGM.bgm import * #背景音乐

class Bomb(): #碰撞效果
   def __init__(self,screen,type): #初始化
      self.screen = screen
      if type == "enemy":
         self.mImage = [pygame.image.load("./picture/enemy1_down" + str(v) + ".png") for v in range(1,5)]
      else:
         self.mImage = [pygame.image.load("./picture/hero_blowup_n" + str(v) + ".png") for v in range(1,5)]
      self.mIndex = 0 #设置当前爆照图片索引

      self.mPobs = [0,0] #设置爆炸位置
      
      self.mVisible = False #设置爆炸是否可见
   def action(self,rect):
      self.mPobs[0] = rect.left
      self.mPobs[1] = rect.top  #设置爆炸位置
      self.mVisible = True #设置爆炸开关
   
   def draw(self):
     
      if not self.mVisible:
         return
      self.screen.blit(self.mImage[self.mIndex],(self.mPobs[0],self.mPobs[1])) #将爆炸图片贴到窗口
      self.mIndex += 1 #设置爆炸图片索引
      if self.mIndex >= len(self.mImage): #判断爆炸图片索引是否大于爆炸图片列表长度
         #如果下标已经到了最后代表爆炸结束
         #下标重置，mVisible重置
         self.mIndex = 0
         self.mVisible = False
class Manager(): #管理
   create_enemy_id = 10 #敌机计时器

   bg_size = (456,665) #背景图片大小

   game_over_id = 11 #游戏结束标识

   is_game_over = False #游戏是否结束

   over_time = 3 #重开游戏等待时间

   def __init__(self):
      pygame.init() #为什么绘制文字以后要加这个初始化？

      self.screen = pygame.display.set_mode(Manager.bg_size,0,32) #创建窗口

      # self.bg = pygame.image.load("./picture/BGP3.png") #加载背景图片
      
      self.map = GameBackground(self.screen) #背景移动方法

      self.players = pygame.sprite.Group() #创建玩家精灵组

      self.enemys = pygame.sprite.Group() #创建敌机精灵组

      self.player_bomb = Bomb(self.screen, 'player') #初始化玩家爆炸对象

      self.enemy_bomb = Bomb(self.screen, 'enemy') #初始化敌机爆炸对象

      self.sound = Gamesound() # 初始化声音播放对象

   def drawText(self,text,x,y,textHeight = 30,fontColor = (255,0,0),backgroudColor=None): #绘制文字方法

      font_obj = pygame.font.Font('./Gluten-Black.ttf',textHeight) #设置字体和大小

      text_obj = font_obj.render(text,True,fontColor,backgroudColor) #设置文字样式

      text_rect = text_obj.get_rect() #使文字成为一个矩形

      text_rect_topleft = (x,y) #设置文字坐标

      self.screen.blit(text_obj,text_rect_topleft)


      text_fmt = font_obj.render(text,1,fontColor,backgroudColor) #设置文字内容，是否抗锯齿，字体颜色，背景颜色

   def exit(self):
      print('退出')
      pygame.quit()
      exit() 

   def show_over_text(self): #复活重新开始游戏文本
      self.drawText('gameover %d' % Manager.over_time,60,Manager.bg_size[1]/2,textHeight = 50, fontColor = (255,255,254))
   
   def game_over_time(self): #游戏重开倒计时
      self.show_over_text()
      Manager.over_time -= 1 #读秒
      if Manager.over_time == 0:
         pygame.time.set_timer(Manager.game_over_id,0) 
       #重置倒计时：
         Manager.over_time = 3 
         Manager.is_game_over = False
         self.start_game() 
   def start_game(self):
      enemyPlane1.clear_bullets() #清空敌机子弹
      CommonPlane.clear_bullets() #清空玩家子弹
      
      manager = Manager() #创建管理对象
      manager.main() #调用主方法

   def new_player(self):
      player = CommonPlane(self.screen)
      self.players.add(player) #将玩家飞机添加到玩家精灵组中
   def new_enemy(self):
      enemy = enemyPlane1(self.screen)
      self.enemys.add(enemy) #将敌人飞机添加到敌人精灵组中
   def main(self):
      clock = pygame.time.Clock()

      self.sound.playBGM() # 播放音乐

      self.new_player() #创建玩家飞机
      
      pygame.time.set_timer(Manager.create_enemy_id,1000) #创建敌机,即每1000毫秒创建一个敌机
      
      while True:
         # #3将背景图片贴到窗口
         # self.screen.blit(self.bg,(0,0)) #blit是将图片贴到窗口的意思，第一个参数是图片，第二个参数是坐标
         self.map.move()  # 背景移动

         self.map.draw()  # 绘制背景
        
         self.drawText('HP:10000',0,0)
         #  #获取事件，比如按键等
         if Manager.is_game_over: #判断游戏结束后才显示文字
            self.show_over_text()

         for event in pygame.event.get():
         #判断事件类型
            if event.type == QUIT: #QUIT是退出的意思，这个事件是当点击窗口的关闭按钮的时候触发的
               self.exit()  #python退出

            elif event.type == Manager.create_enemy_id:  #创建敌机
               self.new_enemy() #创建敌人飞机
            
            elif event.type == Manager.game_over_id: #开启倒计时
               self.game_over_time()

         #调用爆炸对象 
         self.player_bomb.draw()
         self.enemy_bomb.draw()
         
         if self.players.sprites():
            isover = pygame.sprite.spritecollide(self.players.sprites()[0],enemyPlane1.enemy_bullets,True) # 玩家飞机与敌人飞机碰撞检测
            #这里用spritecollide而不用groupcollide
            if isover:
               Manager.is_game_over = True #标识游戏结束
               pygame.time.set_timer(Manager.game_over_id,1000) #开始游戏倒计时
               print('中弹了！')
               self.player_bomb.action(self.players.sprites()[0].rect)

               self.players.remove(self.players.sprites()[0]) #将玩家飞机从精灵组中删除

               self.sound.BombSound() #爆炸声音
         #碰撞检测
         iscollide = pygame.sprite.groupcollide(self.players,self.enemys,True,True)

         if iscollide:
            Manager.is_game_over = True #标识游戏结束
            pygame.time.set_timer(Manager.game_over_id,1000)

            items = list(iscollide.items())[0]
            print(items)
            x = items[0]
            y = items[1][0]

            self.player_bomb.action(x.rect) # 玩家飞机爆炸
            self.enemy_bomb.action(y.rect) # 敌人飞机爆炸
            
            self.sound.BombSound() # 播放爆炸声音
         is_enemy = pygame.sprite.groupcollide(CommonPlane.bullets,self.enemys,True,True) # 子弹与敌人飞机碰撞检测
         if is_enemy:
            items = list(is_enemy.items()) [0] 
            
            y = items[1][0]

            self.enemy_bomb.action(y.rect)

            self.sound.BombSound() 
         
         self.players.update() #更新玩家飞机子弹

         self.enemys.update() #更新敌人飞机子弹

         pygame.display.update() #刷新窗口内容
         clock.tick(50)
         # time.sleep(0.02)
if __name__ == '__main__':
   manager = Manager() 
   manager.main()

# def main():
#    """完成整个程序的控制"""
#          #1创建一个窗口
#    sound = Gamesound()
#    sound.playBGM()
#    screen = pygame.display.set_mode((456,665),0,32)
   
#    player = CommonPlane(screen)
#    enemy1 = enemyPlane1(screen) # 创建敌人飞机对象
# #2创建一个背景图片
#    while True:
#       #3将背景图片贴到窗口
#       screen.blit(bg,(0,0)) #blit是将图片贴到窗口的意思，第一个参数是图片，第二个参数是坐标
   
#       #获取事件，比如按键等
#       for event in pygame.event.get():
#          #判断事件类型
#          if event.type == QUIT: #QUIT是退出的意思，这个事件是当点击窗口的关闭按钮的时候触发的
#             pygame.quit()#执行pygame退出
#             exit()  #python退出
#       player.update()
#       enemy1.update()
#       time.sleep(0.02)
#       pygame.display.update()#4显示窗口内容
# #这串代码可以判断出是直接运行这个文件，还是被引入执行的，这样可以让程序只有在直接运行这个文件的时候才执行main函数，被引入执行的话就不执行main函数了
# if __name__ == '__main__':
#    main()