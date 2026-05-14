# Why Dijkstra Fails with Negative Weights

Dijkstra’s algorithm doesn’t work with negative weights because it assumes that once a node has the shortest distance, it won’t change.

Example:

A → B = 2  
A → C = 5  
C → B = -4  

At first, Dijkstra picks A → B = 2 as the shortest path.

But actually, going A → C → B gives 5 + (-4) = 1, which is shorter.

The problem is that Dijkstra already “locked in” B as 2, so it doesn’t update it later.

So with negative weights, a shorter path can appear after the algorithm already made a decision, which makes the result wrong.
