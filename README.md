<p align="center">
  <a>
    <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/8d/42_Logo.svg/1200px-42_Logo.svg.png" alt="Logo" width="200" height="200">
  </a>

  <p align="center">
    The least amount of moves to sorting two stacks<br>
    Project push_swap of 42 school
    <br />
	</p>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Makefile-8A2BE2">
  <img src="https://img.shields.io/badge/C-4682B4">
  <img src="https://img.shields.io/badge/Shell-2E8B57">
  <img src="https://img.shields.io/badge/Gcc-00FF00">
  <img src="https://img.shields.io/badge/AppKit-2E8B57">
  
</p>

## &#x1F4CC; Index 
- [📌 Index](#-index)
- [✨ What is push\_swap?](#-what-is-push_swap)
- [🕹 Movements](#-movements)
- [🛠 Algorithm](#-algorithm)
- [💻 Usage](#-usage)
- [📖 Examples](#-examples)

## &#x2728; What is push_swap?

This project requires to sort data in a stack, using a limited set of instructions, and with the fewest possible operations. To succeed, you will sort 100 numbers with maximun 700 movements and 500 numbers in 5000.
			
## 🕹 Movements

| | |
|---|---|
|`sa`| swap the first 2 elements at the top of stack a.|
|`sb`|  swap the first 2 elements at the top of stack b.|
|`ss`| sa and sb at the same time.|
|`pa`| take the first element at the top of b and put it at the top of a. |
|`pb`| take the first element at the top of a and put it at the top of b. |
|`ra`| shift up all elements of stack a by 1. |
|`rb`| shift up all elements of stack b by 1. |
|`rr`| ra and rb at the same time. |
|`rra`| shift down all elements of stack a by 1. |
|`rrb`|shift down all elements of stack b by 1. |
|`rrr`|rra and rrb at the same time. |

## &#x1F6E0; Algorithm

Schema of logic:


<img src="https://github.com/vcereced/push_swap/assets/120835200/8eacd016-1c5c-4ab6-a111-9ebf4c27ce3d" alt="push" width="600">


<br /><br />
Visualization should be:


![Screen-Recording-2024-03-06-at-8 50 31-PM-ezgif com-resize](https://github.com/vcereced/push_swap/assets/120835200/a3e789b9-3a6f-49b6-ac31-58482bc2d87c)



## &#x1F4BB; Usage

`make` to compile.

`exe` to compile and run a example of unsorted numbers.

`make clean` remove .o files.

`make fclean` remove .o files and .a files and executable.

## &#x1F4D6; Examples

Let's create a ``example.fdf`` file with a grid of heights of the map.

```
15 12 10 9  5  4  0  0  0  0
12 10 9  5  4  0  0  0  0  0
10 9  5  4  0  0  2  0  0  0
9  5  4  0  0  2  5  2  0  0
5  4  0  0  2  5  8  5  2  0
5  4  0  0  0  2  5  2  0  0
9  5  4  0  0  0  2  0  0  0
10 9  5  4  0  0  0  0  0  0
10 10 9  5  4  0  0  0  0  0
15 12 10 9  5  4  0  0  0  0
```
Execute this command in the terminal.

```bash
make  && ./fdf ./example.fdf 
```
Output should be:

<img width="521" src="https://github.com/vcereced/fdf/assets/120835200/355e7150-8a12-4849-983e-38bcc1bdc5ea">

With bonus features.
```bash
make bonus  && ./fdf ./test_maps/42.fdf 
```
Output should be:

