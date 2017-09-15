def minion_game(string):
    # your code goes here
    #kevin gets vowel
    #stuart gets consonants

    kevin=0
    stuart=0
    n=len(string)

    for i in range(n):
    	if string[i] in ['A', 'E', 'I', 'O', 'U']:
    		kevin+=n-i
    	else:
    		stuart+=n-i
    	pass

    if kevin>stuart:
    	print("Kevin", kevin)
    elif kevin<stuart:
    	print("Stuart", stuart)
    else:
    	print("Draw")
    	pass