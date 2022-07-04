class Graph:

	def __init__(self, vertices):
		self.V = vertices 
		self.graph = []

	
	def addEdge(self, u, v, y):
		self.graph.append([u, v, y])
		
	
	def printgraph(self, dist):
		print("Vertex Distance from Source")
		for i in range(self.V):
			print("{0}\t\t{1}".format(i, dist[i]))
	
	
	def Bellman(self, src):

		
		dist = [float("Inf")] * self.V
		dist[src] = 0


		
		for _ in range(self.V - 1):
			
			for u, v, y in self.graph:
				if dist[u] != float("Inf") and dist[u] + y < dist[v]:
						dist[v] = dist[u] + y

		

		for u, v, y in self.graph:
				if dist[u] != float("Inf") and dist[u] + y < dist[v]:
						print("Graph contains negative weight cycle")
						return
						
		
		self.printgraph(dist)

g = Graph(5)
g.addEdge(0, 1, -1)
g.addEdge(0, 2, 4)
g.addEdge(1, 2, 3)
g.addEdge(1, 3, 2)
g.addEdge(1, 4, 2)
g.addEdge(3, 2, 5)
g.Bellman(0)

