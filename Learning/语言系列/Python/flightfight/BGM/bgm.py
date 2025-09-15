import pygame

class Gamesound():
    def __init__(self):
        pygame.mixer.init() #音乐模块初始化
        pygame.mixer.music.load('./BGM/周杰伦 - 龙战骑士.flac')
        pygame.mixer.music.set_volume(0.2) #声音大小
        
        self.__bomb = pygame.mixer.Sound('./BGM/man.wav') #这里bomb被私有化了，只能在类内部使用

    def playBGM(self):    
        pygame.mixer.music.play(-1) #-1表示循环播放
    def BombSound(self):
        pygame.mixer.Sound.play(self.__bomb)  #播放
        self.__bomb.set_volume(0.5) #声音大小        

        