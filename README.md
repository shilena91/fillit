# fillit

<img width="202" alt="Screen Shot 2019-12-31 at 4 03 32 PM" src="https://user-images.githubusercontent.com/44005264/71623804-b279fc00-2be7-11ea-968f-360331335898.png">

My solution for Fillit project in Hive Helsinki. I did the project with Juhani Kauppi, who is my classmate in Hive.
In this project, we are given a number of tetris pieces. We call them tetrominos. We have to find a smallest square which could be created from given tetrominos. Detailed subject and requirements are in the pdf file.

## Validating input

![1_0i1ZfKxMiFWzdTsQoAGxQw](https://user-images.githubusercontent.com/44005264/71624093-81023000-2be9-11ea-825b-b07cab4ca622.png)

First of all, we need to validating input. We call a block has a neighbor if it has another block next to it. In order to validate a given piece is a tetromino or not, we count the total neighbor of given piece. A valid tetromino has either 6 or 8 neighbors in total. If the count is not 6 or 8, we discard the input immediately.

## Choosing data structure

This is hard part. We chose to represent each tetromino as a structure which has height, width and array of strings (array of characters). We put all tetrominos in a linked list to keep track of their input order.
Since each tetromino is an array of string, we decided to represent square board as array of strings as well.

## Solving algorithm

Before placing valid(obviously) tetrominos on square board, we shift all those tetrominos' positions to up left corner of each square board, so that the first block of each tetromino will have position (0,0) or (0,1) or (0,2) in a 2-dimensional array.

The solved square board's starting size will be calculate as:

    `board starting size = sqrt(number of tetrominoes * 4 blocks per tetromino)`

Putting first tetromino to up left corner of square board, then try to put next tetrominos to availabe space on the board. If the board cannot be solve, remove all tetrominos and try to put the second one to up left corner, then so on. This step is repeated until all tetrominos can be fitted in the square. We do this step by using recursion. If the tetrominos can't fit, increase the size of map by 1 and place all tetrominos again.

## Future optimization

We had some problem with variable naming and we think we will fix them in near future. Plus some allocation in our code could be unneccessary.

We spent so much time to fix memory leak, as you can see we have 1 file just for functions to free memory, we could simplize it by using function exit(). But it was nice experience to fix memory leaks ^^.
