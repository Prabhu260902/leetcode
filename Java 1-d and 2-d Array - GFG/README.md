# Java 1-d and 2-d Array
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a integer <strong>n</strong>. We have&nbsp;<strong>n*n</strong>&nbsp;values of a 2-d array,&nbsp;and&nbsp;&nbsp;<strong>n</strong> values of 1-d array. Task is to find the sum of the left&nbsp;diagonal values of the 2-d array and the max element of the 1-d array and print them with space in between.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>â€‹Input :</strong> arr[][] = {{1,2,3}, {4,5,6}, {7, 8,9}} 
        and N = 3
brr[] = {3, 6, 9}
<strong>Output :</strong> 15 9
<strong>Explanation:</strong>
1 2 3
4 5 6
7 8 9
So, this sum of left diagonal (1+ 5 + 9) = 15
The maximum element in an array brr is 9
So, will return {15, 9} as an answer.
</span></pre>

<p><br>
<span style="font-size:18px"><strong>â€‹Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input :</strong> arr[][] = {{1,2}, {1, 2}} and N = 2
brr[] = {10, 1} <strong>
Output :</strong>  3 10 </span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function <strong>array()</strong> that takes a two-dimension array <strong>(a)</strong>, another one dimension array <strong>(b),</strong>&nbsp;sizeOfArray <strong>(n)</strong>, and return the ArrayList which is having&nbsp;the sum of the diagonal elements of the array <strong>a</strong> and the maximum number of the array&nbsp;<strong>b</strong>. The driver code takes care of the printing.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N<sup>2</sup>).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1).</span></p>

<p><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints</strong><br>
1 ≤ n ≤ 100<br>
1 ≤ a[i][j], b[i] ≤ 10<sup>3</sup></span></p>
</div>