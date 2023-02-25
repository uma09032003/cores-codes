#Probability based Intelligent TicTacToe Agent has been designed by defining basic 8 variables



#define basic variables 
user=[3,3,3,3,3,3,3,3]
system=[3,3,3,3,3,3,3,3]

#define 3 X 3 matrix for storing the moves 
matrix=[[-1,-1,-1],[-1,-1,-1],[-1,-1,-1]] 
# -1 corresponds to null cell
# 0 corresponds to the user  - 'X'
# 1 corresponds to the system - 'O’
#Concept 
# The probability of winning is inversely proportional to the number of spaces to be filled.
# The chances of winning along a side in the presence of opponent piece is 0
# If there is equal probability to win, the system focusses plays for winning
# If the probability is high for the opponent, the system defends the winning chances of the #oppenent

def ret_min_index(l):
  ret=list()
  if(max(l)==0):
    return ret
  m=min(k for k in l if k>0)
  for i in range(0,len(l)):
    if(l[i]==m):
      ret.append(i)
  return ret

def place_O(index,swin,uwin,system,user):
  user[index]=0
  if(system[index]!=0):
    system[index]=system[index]-1
    if(system[index]==0):
      swin=True
  if(index==0):   
    for i in range(0,3):
      if(matrix[i][i]==-1):
        matrix[i][i]=0
        user[i+2]=0
        user[i+5]=0
        if(system[i+2]!=0):
           system[i+2]=system[i+2]-1
           if(system[i+2]==0):
             swin=True
        if(system[i+5]!=0):
             system[i+5]=system[i+5]-1
             if(system[i+5]==0):
              swin=True
        if((i+i)==2):
          if(system[1]!=0):
            system[1]=system[1]-1
            if(system[1]==0):
              swin=True
          user[1]=0
        break
  elif(index==1):
    for i in range(0,3):
       if(matrix[i][2-i]==-1):
            matrix[i][2-i]=0
            user[i+2]=0
            user[2-i+5]=0
            if(system[i+2]!=0):
              system[i+2]=system[i+2]-1
              if(system[i+2]==0):
                swin=True
            if(system[(2-i+5)]!=0):
              system[2-i+5]=system[2-i+5]-1
              if(system[2-i+5]==0):
                swin=True
            if(i==(2-i)):
              if(system[0]!=0):
                system[0]=system[0]-1
                if(system[0]==0):
                  swin=True
              user[0]=0
            break
  elif(index>=2 and index<=4):
        for i in range(0,3):
          if(matrix[index-2][i]==-1):
            matrix[index-2][i]=0
            user[i+5]=0
            if((index-2)==i):
              user[0]=0
              if(system[0]!=0):
                system[0]=system[0]-1
                if(system[0]==0):
                  swin=True
            if((index-2+i)==2):
              user[1]=0
              if(system[1]!=0):
                system[1]=system[1]-1
                if(system[1]==0):
                  swin=True
            if(system[i+5]!=0):
              system[i+5]=system[i+5]-1
              if(system[i+5]==0):
                swin=True
            break
  elif(index>=5 and index<=7):
        for i in range(0,3):
          if(matrix[i][index-5]==-1):
            matrix[i][index-5]=0
            user[i+2]=0
            if((index-5)==i):
              user[0]=0
              if(system[0]!=0):
                system[0]=system[0]-1
                if(system[0]==0):
                  swin=True
            if((index-5+i)==2):
              user[1]=0
              if(system[1]!=0):
                system[1]=system[1]-1
                if(system[1]==0):
                  swin=True
            if(system[i+2]!=0):
              system[i+2]=system[i+2]-1
              if(system[i+2]==0):
                swin=True
            break
  return (swin,uwin,system,user) 

uwin=False
swin=False

while(not(max(user)==0 and max(system)==0) and swin==False and uwin==False):
  r,c=int(input("Enter Row : ")),int(input("Enter Column : "))

  #Accepting  the user choice to move
  matrix[r][c]=1
  if(user[r+2]!=0):
    user[r+2]=user[r+2]-1
    if(user[r+2]==0):
      uwin=True
  system[r+2]=0
  if(user[c+5]!=0):
    user[c+5]=user[c+5]-1
    if(user[c+5]==0):
      uwin=True
  system[c+5]=0
  if((r-c)==0):
     if(user[0]!=0):
       user[0]=user[0]-1
       if(user[0]==0):
         uwin=True
     system[0]=0
  if((r+c)==2): 
     if(user[1]!=0):
      user[1]=user[1]-1
      if(user[1]==0):
        uwin=True
     system[1]=0

  print("\nAfter User Move : ")
  for i in range(0,3):
      print("\n")
      for j in range(0,3):
        print(matrix[i][j],end=" ")

  #Playing from the System side analysing the Probability 
  if(swin==False and uwin==False): 
    u=ret_min_index(user)
    s=ret_min_index(system)

    if(len(u)!=0 and len(s)!=0):
      if(user[u[0]]>=system[s[0]]):    
       index=random.randint(0,len(s)-1)
       index=s[index]
       swin,uwin,system,user=place_O(index,swin,uwin,system,user)
      else:
        index=random.randint(0,len(u)-1)
        index=u[index]
        swin,uwin,system,user=place_O(index,swin,uwin,system,user)
    elif(len(u)==0):
      index=random.randint(0,len(s)-1)
      index=s[index]
      swin,uwin,system,user=place_O(index,swin,uwin,system,user)
    elif(len(s)==0):
      index=random.randint(0,len(u)-1)
      index=u[index]
      swin,uwin,system,user=place_O(index,swin,uwin,system,user)

    print("\nAfter System Move : ") 
    for i in range(0,3):
      print("\n")
      for j in range(0,3):
        print(matrix[i][j],end=" ")

if(swin==False and uwin==False):
  print("\nTie")
elif(swin):
  print("\nSystem wins")
else(uwin):
  print("\nUser wins")


