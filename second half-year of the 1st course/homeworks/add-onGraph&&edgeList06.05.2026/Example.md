##Примеры:
Задача 1:
in:
4
1 2
3
3

out:
adjacency lists:
vertex 0 --> 1 -> 2 -> nullptr
vertex 1 --> 3 -> nullptr
vertex 2 --> 3 -> nullptr
vertex 3 --> nullptr
List of edges:
Edge 1: (0 -> 1)
Edge 2: (0 -> 2)
Edge 3: (1 -> 3)
Edge 4: (2 -> 3)

in:
5
1 2
3
3


out:
adjacency lists:
vertex 0 --> 1 -> 2 -> nullptr
vertex 1 --> 3 -> nullptr
vertex 2 --> 3 -> nullptr
vertex 3 --> nullptr
vertex 4 --> nullptr
List of edges:
Edge 1: (0 -> 1)
Edge 2: (0 -> 2)
Edge 3: (1 -> 3)
Edge 4: (2 -> 3)

in:
3
1
2
2

out:
adjacency lists:
vertex 0 --> 1 -> nullptr
vertex 1 --> 2 -> nullptr
vertex 2 --> 2 -> nullptr
List of edges:
Edge 1: (0 -> 1)
Edge 2: (1 -> 2)
Edge 3: (2 -> 2)
Задача 2:
in:
4
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
out:
Adjacency matrix:
     0  1  2  3  
 0 [ 0  1  1  0  ]
 1 [ 1  0  0  1  ]
 2 [ 1  0  0  1  ]
 3 [ 0  1  1  0  ]

Adjacency lists (after loading from matrix):
vertex 0 --> 1 -> 2 -> nullptr
vertex 1 --> 0 -> 3 -> nullptr
vertex 2 --> 0 -> 3 -> nullptr
vertex 3 --> 1 -> 2 -> nullptr

Number of isolated vertices: 0

in:
5
0 1 1 0 0
1 0 0 0 0
1 0 0 0 0
0 0 0 0 0
0 0 0 0 0
out:
Adjacency matrix:
     0  1  2  3  4  
 0 [ 0  1  1  0  0  ]
 1 [ 1  0  0  0  0  ]
 2 [ 1  0  0  0  0  ]
 3 [ 0  0  0  0  0  ]
 4 [ 0  0  0  0  0  ]

Adjacency lists (after loading from matrix):
vertex 0 --> 1 -> 2 -> nullptr
vertex 1 --> 0 -> nullptr
vertex 2 --> 0 -> nullptr
vertex 3 --> nullptr
vertex 4 --> nullptr

Number of isolated vertices: 2

in:
5
0 1 0 0 0
1 0 1 0 0
0 1 0 0 0
0 0 0 1 0
0 0 0 0 0
out:
Adjacency matrix:
     0  1  2  3  4  
 0 [ 0  1  0  0  0  ]
 1 [ 1  0  1  0  0  ]
 2 [ 0  1  0  0  0  ]
 3 [ 0  0  0  1  0  ]
 4 [ 0  0  0  0  0  ]

Adjacency lists (after loading from matrix):
vertex 0 --> 1 -> nullptr
vertex 1 --> 0 -> 2 -> nullptr
vertex 2 --> 1 -> nullptr
vertex 3 --> 3 -> nullptr
vertex 4 --> nullptr

Number of isolated vertices: 1