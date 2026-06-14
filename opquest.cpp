/* it is the best question of  todays contest in which we have to 
Maximize Sum of Device Ratings
 we can put any element to any other device but only once so  we have to play only with minimum and second minimum only 
 we will greedily find smallest global  minimum and the find the sum of all second min and subtract the smallest secondminimum  valuee



 so the relation is   globalMin+sumOfAllSecondMinimum-smallestSecondMinimum

 there is a corner case in which only have 1 size so the ans of that is the sum of all the elemenys oin it
*/