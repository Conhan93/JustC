# bithandling


introduction
---
<p> Binary numbers are values represened in a base-2 system.
  There are alot of other ways to represent values like hex, or octal base system
  The most commonly used one that we're all taught and use is the decimal system
  which is in base-10</p>
  
  
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
  it can be used to represent LOGIC, which is why it's used for computing. </p>
  
  
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
  
Logical Operators/Boolean Operators
---
<p>
  This is the more interesting part to how we're going to be using binary numbers, here we're going to be using the binary numbers as logic and perform logical operations on them
  </p>
  
  <p> 
    There are a few logical operators, AND(&), OR(|) , NOT (~) and last but not least XOR(^) XOR meaning exclusive or, it's a bit special but we'll get to
    that last one.
  </p>
  
  <p>
    Let's start with NOT, it's the easiest one.
    NOT is just a negation, if you have a binary value 1 then NOT 1 is == 0, if you have a larger value 000100 = A then NOT A(~A) == 111011
    So you just switch the bits to their opposite. If it's ON then NOT ON is OFF, it's TRUE then NOT TRUE is FALSE, if it's 1 then NOT 1 is 0.
  </p>
  
  <p>
    AND is the next one, it's a bit(hah bit!) more complicated.
    AND is more of a conditional check, like an if statement. if both arguments are true, then the operation is evaluated as true. that's it.
  </p>
  
  ![AND outcomes](http://web.cs.iastate.edu/~smkautz/cs127f16/notes/chapter09/_static/and_table.PNG)
  
