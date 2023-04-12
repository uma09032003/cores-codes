#Input adjacency list
#Input heuristics of each

#List for maintaing cost
#If expanded - Remove
#Else - Update the costs

n=int(input("Enter the number of nodes"))
adj=list()
heu=list()
c=[0]
for i in range(n):
  #Input row
  k=list()
  for j in range(n):
    p=int(input("Enter Weight "))
    k.append(p)
  adj.append(k)
  heu.append(int(input("Enter the heuristics of the node : ")))

#Let Node 0 be your initial node
dest=int(input("Enter your destination Node : "))
def ret_minimum(open):
  a=c[open[0]]
  index=[0]
  min_node=[open[0]]
  for i in range(1,len(open)):
    if(c[open[i]]<a):
      a=c[open[i]]
      min_node.clear()
      min_node.append(open[i])
      index.clear()
      index.append(i)
    elif(c[open[i]]==a):
      min_node.append(open[i])
      index.append(i)
  return min_node,index

#Except the initial node, every node has a parent
parent=[0]
closed=[-1]
min_node=[0]
for i in range(n-1):
	parent.append(-1)
	closed.append(-1)
	c.append(0)
open=[0]
c[0]=heu[0]
closed_node=list()
index=[0]
min_node=[0]

while(dest not in min_node):
  for j in range(len(min_node)): 
    p=min_node[j]
    closed[p]=c[p]-heu[p]
    for k in range(n):
      i=adj[p][k]
      if(i==-1):
        continue
      else:
        i=k 
      if (i in open):
        if(c[i]>(adj[p][i]+heu[i]+closed[p])):
         parent[i]=p
         c[i]=adj[p][i]+heu[i]+closed[p]
      elif(i not in closed_node):
         parent[i]=p
         c[i]=adj[p][i]+heu[i]+closed[p]
         open.append(i)
      
    closed_node.append(open.pop(index[j]))
    pp=index.pop(j)
    for i in range(len(index)):
      if(index[i]>=pp):
        index[i]=index[i]-1
  min_node,index=ret_minimum(open)
  
  print("\nOpen",open,"\nClosedNode",closed_node)
  print("\nMinNode for Next Iteration",min_node)
  print("\nEnd of an iteration . . . . .")
  print(parent)
  
 '''
 INPUT ADJACENCY MATRIX:
 -1 9 4 7 -1 -1 -1
9 -1 -1 -1 11 -1 -1
4 -1 -1 -1 17 12 -1
7 -1 -1 -1 -1 14 -1
-1 11 17 -1 -1 -1 5
-1 -1 12 14 -1 -1 9
-1 -1 -1 -1 5 9 0

Heuristics=[21, 14, 18, 18, 5, 8, 0]

OUTPUT:
Open [1, 2, 3] 
ClosedNode [0]
MinNode for Next Iteration [2]
End of an iteration . . . . .
Open [1, 3, 4, 5] 
ClosedNode [0, 2]
MinNode for Next Iteration [1]
End of an iteration . . . . .
Open [3, 4, 5] 
ClosedNode [0, 2, 1]
MinNode for Next Iteration [5]
End of an iteration . . . . .
Open [3, 4, 6] 
ClosedNode [0, 2, 1, 5]
MinNode for Next Iteration [3, 4, 6]
End of an iteration . . . . .
[0, 0, 0, 0, 1, 2, 5]
'''


