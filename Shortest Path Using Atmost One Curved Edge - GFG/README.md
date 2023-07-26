# Shortest Path Using Atmost One Curved Edge
## Hard
<div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an undirected connected graph of <strong>n</strong> vertices and list of <strong>m</strong> edges in a graph and for each pair of vertices that are connected by an edge.&nbsp;</span></p>
<p><span style="font-size: 18px;">There are two edges between them, one curved edge and one straight edge i.e. the tuple <strong>(x, y, w1, w2) </strong>means that between vertices <strong>x</strong> and <strong>y</strong>, there is a straight edge with weight <strong>w1</strong> and a curved edge with weight <strong>w2</strong>. </span></p>
<p><span style="font-size: 18px;">You are given two vertices <strong>a</strong> and <strong>b</strong> and you have to go from <strong>a</strong> to <strong>b</strong> through a series of edges such that in the entire path you can use at most 1 curved edge. Your task is to find the shortest path from <strong>a</strong> to <strong>b</strong> satisfying the above condition. If there is no path from a to b, return <strong>-1</strong>.</span></p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>n = 4, m = 4
a = 2, b = 4
edges = {{1, 2, 1, 4}, {1, 3, 2, 4},
         {1, 4, 3, 1}, {2, 4, 6, 5}}
<strong>Output:
</strong>2
</span><img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/713968/Web/Other/e0873f96-11df-491f-9252-ad8911bbb26d_1685087926.png"><span style="font-size: 18px;">
<strong>Explanation:</strong>
We can follow the path 2 -&gt; 1 -&gt; 4.</span>
<span style="font-size: 18px;">This gives a distance of 1+3 = 4 if we follow
all straight paths. But we can take the curved
path  from 1 -&gt; 4, which costs 1. This
will result in a cost of 1+1 = 2</span>
</pre>
<div><span style="font-size: 18px;"><strong>Example 2:</strong></span></div>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>n = 2, m = 1
a = 1, b = 2
edges = {{1, 2, 4, 1}}
<strong>Output :</strong>
1
</span><img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/713968/Web/Other/fcf19135-c88b-48ac-8fc4-bc46efc7ca3f_1685087926.png">
<span style="font-size: 18px;"><strong>Explanation:</strong>
Take the curved path from 1 to 2 which costs 1. </span>
</pre>
<p><br><span style="font-size: 18px;"><strong>Your Task:&nbsp;&nbsp;</strong><br>You don't need to read input or print anything. Your task is to complete the function <strong>shortestPath()</strong>&nbsp;which takes 4 integers n, m, a, and b, and a list of lists named edges of size m as input and returns the cost of shortest path from a to b.</span></p>
<p><br><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O((m+n)log(n))<br><strong>Expected Auxiliary Space:</strong> O(n+m)</span></p>
<p><br><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ n,m ≤ 10<sup>5</sup><br>1 ≤ a,b ≤ n<br>weight of edges ≤ 10<sup>4</sup></span></p></div>