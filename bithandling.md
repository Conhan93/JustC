# bithandling


introduction
---
<p> Binary numbers are values represened in a base-2 system.
  There are alot of other ways to represent values like hex, or octal base system
  The most common one that we all use is the decimal system which is in base-10</p>
  
  
  <p> Values represented in bases simply means that we represent values as multiples or powers of that
  base.
  
  The number 100 in decimal(base-10) being 10^2x1 + 10^1x0 + 10^0x0 == 100
  </p>
  <p>
  Where each digit from the right to left is a step up in the power of 10, AND each digit can be
  multiplied by base-1 so for base-10 it's 0,1,2,3,4,5,6,7,8,9. ex: 10^0x6 == 6, 8^1x1 == 8.
  the other numerical system like hexadecimal, octal and binary systems work in exactly the same way.
  The idea being that the bases work as a building block to construct whatever value you're trying to represent.
  </p>
  
  <p> We're mostly going to be using the binary system which is in base-2. Which since it being base-2 only has
  2 possible values per "building block" this makes the binary system really really powerful in computing, because
  it can be used to represent LOGIC (on/true, off/false), which is why it's used for computing. </p>
  
  
Numerical System - Binary
---
<p>
  Because the binary system is expressed in base-2, there's only two values you can multiply each "building block"(power of) with.
  which is why it's so handy in representing logic in. a value or "building block" can be either on or off, true or false, 1 or 0.
</p>

<p> 
  so like 100 = 10^2x1 + 10^1x0 + 10^0x0 in the decimal system, the same value in binary is written like
  01100100 which is equal 100, each digit from right to left represents an increase in the power of 2.

  01100100 == 2^7x0 + 2^6x1 + 2^5x1 + 2^4x0 + 2^3x0 + 2^2x1 + 2^1x0 + 2^0x0 == 0 + 64 + 32 + 0 + 0 + 4 + 0 + 0
  </p>
  
  <p>
  each digit in a binary number is refered(?) to as a bit and 8 bits makes up a byte(usually)
  a byte is kinda the basic size of a memory cell(holds values, these are usually 32 or 64 bits in modern computers)
  </p>

<p>
****BESKRIVA BINÄRA OCH KOPPLA DET TILL ASCII TABELL FÖR REFERENS****
</p>

<img src="(https://miro.medium.com/max/2356/1*Ae2Vp6Z7rfhipVFX1PkLaw.gif" alt="ASCII table" width="200"/>


<p>
 Excellent tutorial for learning to calculate in Binary:[Binary Tutorial](https://medium.com/@LindaVivah/learn-how-to-read-binary-in-5-minutes-dac1feb991e)
  
</p> 

Logical Operators/Boolean Operators
---
<p> 
  Logical/Bitwise operators work just like mathematical operators, in that they tell the compiler to perform certain mathematical or logical functions.
  Look at the following operators the same way you would "+", "-", "*" signs when calculating mathematically. 
  Trying to commit them all to memory right now may seem daunting so just focus on understanding each one by one. </p>
  
  <p>
  Below we will look at the most commonly used operators and try our hand at some "boolean arithmetic". In our case this basically just means binary calculations.
  This is just for understanding what all the operators actually do behind the scenes. Just learning to use codeblocks with these types of functions is honestly
  good enough at this point. The rest will fall in to place later.
</p>
  <p>
  Before we start, note that all the operations (or calculations) will be done FROM the left operand TO the right operand. 
  For example, A + B adds the A-operand to the B-operand which results in a new third (A+B)-operand.
</p>
  
 ![](https://www.tablesgenerator.com/markdown_tables)
 
| A | B | A&B | A\|B | A^B |
|:-:|:-:|:---:|:----:|:---:|
| 0 | 0 |  0  |   0  |  0  |
| 0 | 1 |  0  |   1  |  1  |
| 1 | 1 |  1  |   1  |  0  |
| 1 | 0 |  0  |   1  |  1  |
 
 <p>
Assume A = 60 and B = 13 in binary format, they will be as follows:

A = 0011 1100

B = 0000 1101

-----------------

A&B = 0000 1100 

A|B = 0011 1101

A^B = 0011 0001

~A = 1100 0011

</p>

|  |  |  |
|-|-|-|
| & | Binary AND Operator copies a bit to the result if it exists in both operands.  | (A & B) = 12, i.e., 0000 1100 |
| \| | Binary OR Operator copies a bit if it exists in either operand. | (A \| B) = 61, i.e., 0011 1101 |
| ^ | Binary XOR Operator copies the bit if it is set in one operand but not both.  | (A ^ B) = 49, i.e., 0011 0001 |
| ~ | Binary One's Complement Operator is unary and has the effect of 'flipping' bits. | (~A ) = ~(60), i.e,. -0111101 |
| << | Binary Left Shift Operator. The left operands value is moved left by the number of bits specified by the right operand. | A << 2 = 240 i.e., 1111 0000 |
| >> | Binary Right Shift Operator. The left operands value is moved right by the number of bits specified by the right operand. | A >> 2 = 15 i.e., 0000 1111 |

<p>
  Looking closer at the operations
</p>
