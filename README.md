# Programing Project - 2st Milestone
# Searching Algorithms Server 2020

[Link to project's repository](https://github.com/OrtalLankri/OurServer)

# WHAT IS IT ABOUT ?

Our project solves a problem for a client, and offers algorithms for finding a shortest path in a graph.

# HOW DOES IT WORK ?

We connect to a client who presents us with a problem.
We transfer the problem to a matching client handler, which prepares the problem to be solved.
The problem is then being searched in cache to see if the solution to the problem already exists,
if the solution is not found, the problem is being solved.
The client is presented with a solution to its problem.
In our project, we tested four different algorithms for solving the problem of finding a shortest path in a graph,
and implement the code to use the algorithm who offered the best result.


# HOW CAN I USE IT ?

In order to use our program you need to work on a linux operating System in your computer.

Create a .txt file of a squared matrix in the following format : 
line-by-line separated by commas
start point (separated by commas)
end point (separated by commas)
‘end’

Compile the code with the following line: "g++ -std=c++14 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread". 

Run the code with: "./a.out port". (where "port" is the port of client who will send the matrix to the program).

# WORKSPACE

Our project designed on a Linux operating system in C++ language.

# TEAM

NAME: Ortal Lankri
ID: 209281674

NAME: Adi Meirman
ID: 208177204
