# Intal_Library
1.	INTRODUCTION
Intal is a C Library of functions to compute addition, subtraction, multiplication, compare, exponentiation (positive exponent) and many more. An intal is a non-negative integer of arbitrary length.
Some of the general integer datatypes in C are,
•	Signed or unsigned short int (short int)
•	Signed or unsigned long int (long int)
•	Float
•	Double
•	Long double
Applications may include addition, subtraction, multiplication, comparison (which use brute force approach), binary coefficient, factorial etc can be computed using arbitrary string length.


2.	Approach

Add Function:
    It uses the brute force approach to add two intals passed as a string to the parameters. Three while loops have been used in this function in which the first one adds when both the intals are present,
next two copy the string as it is to the result array(temp used). The result is stored in the array in reverse order meaning the rightmost addition is in the lsb of the result array. Thus there's a extra static function used here to reverse the string.
The implementation was pretty simple and there were no challenges faced.

Compare Function:
    This function initially decides the result based on the length of the intals and returns the result appropriately. In case both the intals are of the same length, it compares the strings converted to number from left to right and return the result appropriately.
This function to was direct and there were no challenges faced.

Difference Function:
    This function uses the brute force method to subtract. The function initially subtracts the number from right to left and reveres the result array by using the static function defined. While subtracting there can be two major cases which arise and needs to be handled carefully. That is when intal1>intal2 and intal1<intal2. The function i have written uses if condition to check which of the two are greater and subtract appropriately. The difference between subtraction and addition is that the carry needs to be subtracted here and needs to be added in the Add function. The result needs to be reversed here also as we did in add function.
The approach very simple one case had to be carefully handled was subtraction of intals line  "25" and "25" had to return "0" and not "00".


Multiply Function:
    This function initially checks if any of the intals passed are zero and straight away returns string zero as the answer. I have used three "for" loops, the first one traverses through the first intal, second "for" loops is used to pad zeros and the third one calculated intermediates. At the end of third loop (within the first one) there's an if condition which checks if there's any carry and appends it to the temp array. At the end, all the intermediate results are added and put into a different result array and the tremp array is freed.

Pow Function:
    The function uses recursive approach which makes it's time complexity O(log n). The function calls itself repeatedly by passing n/2 again and again. When n%2 gives zero or is no more divisible by two, it calls the intal_multiply function accordingly.
Challenges faced here were if incase the  memory allocated in multiply function is even 1 less than strlen(intal1)*strlen(intal2) it gives incorrect results while calculating large values of pow.

Mod Function:
    This function initially checks the nearest power of 10 multiplied by intal2. once it gets that it repeatedly subtracts the nearest power from intal1, until intal1<nearest power of 10 of intal2 calculated and stores it in the result. This whole process is put in a while loop which repeats until strlen(intal1) reaches 0 or gets exhausted. Result is returned in the end.
There were no major challenges faced.

GCD Function:
    The problem statement asks us to return 0(even though mathematically not correct) when both the numbers passed are zeros. Otherwise the function uses recursion and returns intal2 if intal1 is zero else finds mod of the two numbers.
This function was simple hence no problems faced.

Fibonacci Function:
    I have used dynamic programming approach to solve the problem. Thus returning only the final answer as the result. No challenges faced while coding for the function.

Factorial Function:
    Solved the function using iteration and uses intal_add and intal_multiply in it. I used a temp variable which keeps getting incremented by one and gets multiplied by the result in the loop.
No challenges faced.

Bincoeff Function:
    Used the dynamic programming approach to solve the problem. “Bincoef” is an array of size n, it iteratively keeps adding the values of bincof[j] and bincof[j-1] and stores it in bincof[j] at the end it returns bincof[k].
    
Max Function:
    This function uses intal_compare and assigns the index to max_indx according to the return value.
No challenges faced.

Min Function:
    This function also uses intal_compare and assigns the index of minimum string in the array to min_indx according to the returned value from intal_compare.
No challenges faced.

Search Function:
    This function in turn uses the intal_compare and compares the key with the strings if intal_compare returns 0, meaning key is found, else continue searching. If the array is exhausted, returns -1.

Binsearch Function:
    Uses the binary sort algorithm and returns -1 if not found.
No challenges faced.

Sort Function:
    Used the merge sort algorithm to sort the given array. Which works on Divide and conquer.
An malloc(): memory corrupt error occurs if the two variables initialized are not freed after everything gets merged into original array.

Coin Row Problem:
    This function uses dynamic programming approach to solve the problem. It also additionally used the intal_compare and intal_add functions declared above. The function also uses O(n) time and O(1) extra space. I have used three pointers prev. cur and next to keep the track of the values instead of using an array which makes this code use O(1) space. Basically using the window of three approach and interested only in optimal answer and not the solution(in this case). 



  
