
print("INIZIO SCRIPT")

def verDispari (num):
	if(num%2==0):
		return "PARI"
	else:
		return "DISPARI"

def doublePass(STRINGA,num):
	if(num<5):
		print(STRINGA)
	else:
		print(num)	

def liste ():
	aaa = []
	aaa.append("UNO")
	aaa.append("DUE")
	aaa.append("TRE")
	aaa.reverse()
	iter = 0
	size = aaa.count()
	for iter in range (size):
		print(aaa.pop())

def main ():
	iter = 0
	liste()
	doublePass("MINORE DI 5",4)
	for iter in range(5):
		print(verDispari(iter),"\n")


