# -*- coding: utf-8 -*-
"""
Created on Sat Apr 10 03:07:16 2021

@author: USER
"""

import re

#1請撰寫一正規表達式以找出在 hyphen (-) 處換行的字。
p=re.compile(r'-\n+')
q=re.compile(r'o-p')

#使用 re.sub() 移除這些字的換行符號 (\n)。提示：可先import re，並用help(re.sub)閱讀線上說明文件以瞭解用法。
help(re.sub)

#移除換行符號後，如何處理並還原那些原本不含 hyphen (-) 的字，例如 'encyclo-\npedia'?(25%)
#請參考前列三個小題，將 'This is a long-\nterm encyclo-\npedia' 正確地斷字成 ['This', 'is', 'a', 'long-term', 'encyclopedia']。（25%）
a="This is a long-\nterm encyclo-\npedia"
print(a)
a=p.sub('-',a)
a=q.sub('op',a)
print(a)
