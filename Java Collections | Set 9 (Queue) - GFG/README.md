# Java Collections | Set 9 (Queue)
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Implement different operations on a queue&nbsp;q&nbsp;.<br>
<br>
<strong>Input:</strong><br>
The first line of input contains an integer&nbsp;<strong>T</strong>&nbsp;denoting the no of test cases . Then T test cases follow. The first line of input contains an integer&nbsp;<strong>Q</strong>&nbsp;denoting the no of queries . Then in the next line are&nbsp;<strong>Q</strong>&nbsp;space separated queries .<br>
A query can be of&nbsp;four&nbsp;types&nbsp;<br>
1. a x (Pushes an element x at the end of the&nbsp;queue&nbsp;q&nbsp;)<br>
2. r (if queue&nbsp;is not empty&nbsp;pops the front&nbsp;element and prints it, else prints -1)<br>
3. s (prints the size of the queue)<br>
4. p (if queue&nbsp;is not empty prints the front&nbsp;element of the queue, else&nbsp;prints&nbsp;-1)<br>
<br>
<strong>Output:</strong><br>
The output for each test case will&nbsp;&nbsp;be space separated integers denoting the results of each query .&nbsp;<br>
<br>
<strong>Constraints:</strong><br>
1&lt;=T&lt;=100<br>
1&lt;=Q&lt;=100<br>
<br>
<strong>Example:</strong></span></p>

<p><span style="font-size:18px"><strong>Input</strong><br>
2<br>
5<br>
a 5 a 10 a 15 r p<br>
4<br>
a 5 r p s&nbsp;<br>
<strong>&nbsp;<br>
Output:</strong><br>
5 10&nbsp;<br>
5 -1 0&nbsp;</span></p>

<p><span style="font-size:18px"><strong>EXPLANATION:</strong></span></p>

<p><span style="font-size:18px"><strong>In test case 1:&nbsp;</strong>&nbsp;In first query 5 is added to the queue.In second query 10 is added to the queue. In third query 15 is added to the queue. In fourth query 5 is removed from the queue and printed.In last query front&nbsp;element of the queue is printed i.e. 10.</span></p>
</div>