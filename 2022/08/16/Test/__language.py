from os import path
from os import system

clear = lambda: system('cls')

def __reader(__file):
    return open(path.join(path.dirname(path.abspath(__file__)), 'lang', __file)).read().split('\n')

#lang list avail
lang_list = __reader('locate')

#read locate
english = __reader('english.txt')

#main function
def __lang_select():
    clear()
    print('Available language:')
    a=0
    for i in lang_list:
        a += 1
        print(str(a)+'. '+i) 
    lang_select = input('Please select the language by number: ')
    if lang_select == '1': return english
    #   format: 
    #   elif lang_select == '': return 
    
    else: return None



