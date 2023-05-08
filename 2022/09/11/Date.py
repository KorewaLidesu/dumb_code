
# importing the datetime module
import datetime
import math
 
# Getting todays date and time using now() of datetime
# class
current_date = datetime.datetime.now().date()
 
# Printing the current_date as the date object itself.
print("Original date and time object:", current_date)

start_date = datetime.datetime.strptime('11/09/2022', "%d/%m/%Y").date()

truc_com = abs((start_date-current_date).days)%5 + 1
truc_nhat = abs((start_date-current_date).days)%5 + 1
truc_lop = abs((start_date-current_date).days)%5 + 1

print("Number in the list:", truc_com)
if (truc_com == 1):   print("Hien - Tuan")
elif (truc_com == 2): print("P.Anh - M.Linh")
elif (truc_com == 3): print("D.Anh - X.Truong")
elif (truc_com == 4): print("T.Linh - T.Thuy")
else: print("N.Linh - N.Anh")

if (truc_nhat == 1):   print("Hien - Tuan")
elif (truc_nhat == 2): print("P.Anh - M.Linh")
elif (truc_nhat == 3): print("D.Anh - X.Truong")
elif (truc_nhat == 4): print("T.Linh - T.Thuy")
else: print("N.Linh - N.Anh")

if (truc_lop == 1):   print("Hien - Tuan")
elif (truc_lop == 2): print("P.Anh - M.Linh")
elif (truc_lop == 3): print("D.Anh - X.Truong")
elif (truc_lop == 4): print("T.Linh - T.Thuy")
elif (truc_lop == 5): print("T.Linh - T.Thuy")
elif (truc_lop == 6): print("T.Linh - T.Thuy")
else: print("N.Linh - N.Anh")
