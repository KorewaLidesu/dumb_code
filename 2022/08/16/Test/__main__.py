import os
from __language import __lang_select

clear = lambda: os.system('cls')

def __menu(__locate, __extra):
    if __locate != None:
        __max = 0
        for i in __locate:
            __max = len(i) if __max < len(i) else __max
        _space = __max + 1 + __extra if (__max % 2 != 0) else _space + __extra
        clear()
        print('<'+'='*_space+'>')
        for i in __locate:
            __space = int((_space - len(i))/2)
            print('|'+' '*__space + i + ' '*__space+'|') if len(i) % 2 == 0 else print('|'+' '*__space + i + ' '*(__space+1)+'|')
        print('<'+'='*_space+'>\n')
    else: 
        clear()
        print('Invalid input.')

__menu(__lang_select(), 10)

__selection = int(input('       Please select the function by number: '))
if __selection == 1: 