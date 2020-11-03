# Bithandling

Contents
-----

- [Introduction](https://github.com/Conhan93/JustC/blob/developing/bithandling.md#introduction)
- [Signed/Unsigned Datatypes](https://github.com/Conhan93/JustC/blob/developing/bithandling.md#signedunsigned-datatypes)
- [Numerical Systems - Binary](https://github.com/Conhan93/JustC/blob/developing/bithandling.md#numerical-system---binary)
- [Logical Operators/Boolean Operators](https://github.com/Conhan93/JustC/blob/developing/bithandling.md#logical-operatorsboolean-operators)
- [Bitwise Operators](https://github.com/Conhan93/JustC/blob/developing/bithandling.md#bitwise-operators)
- [Using Bitwise Shifting to Access Bits](https://github.com/Conhan93/JustC/blob/developing/bithandling.md#using-bitwise-shifting-to-access-bits)
- [Using Bitwise Shift and Operators to modify bits](https://github.com/Conhan93/JustC/blob/developing/bithandling.md#using-bitwise-shift-and-operators-to-modify-bits)


introduction
---
<p> Binary numbers are values represened in a base-2 system.
  There are alot of other ways to represent values like hex, or octal base system
  The most common one that we all use is the decimal system which is in base-10</p>
  
  
  <p> Values represented in bases simply means that we represent values as multiples or powers of that
  base.
  
  The number 100 in decimal(base-10) being (10^2)x1 + (10^1)x0 + (10^0)x0 == 100
  </p>
  <p>
  Where each digit from the right to left is a step up in the power of 10, AND each digit can be
  multiplied by base-1 so for base-10 it's 0,1,2,3,4,5,6,7,8,9. ex: (10^0)x6 == 6, (8^1)x1 == 8.
  the other numerical system like hexadecimal, octal and binary systems work in exactly the same way.
  The idea being that the bases work as a building block to construct whatever value you're trying to represent.
  </p>
  
  <p> We're mostly going to be using the binary system which is in base-2. Which since it being base-2 only has
  2 possible values per "building block" this makes the binary system really really powerful in computing, because
  it can be used to represent LOGIC (on/true, off/false), which is why it's used for computing. </p>
  
<p>
  
  Signed/Unsigned Datatypes
  ---
  Lets start by looking at the simplest one, being 32bit integers. 
  You may recall ints in C take 4 bytes of memory (4 bytes * 8 bits = 32 bit).
  A signed integer is any digit between about -2 billion to +2 billion.
  An UNsigned integer can only be positive digits between about 0 to 4 billion.
  Note that they both share a range of about 4 billion, but are shifted on the number line.
</p>
  
<p>
  Now lets look at chars which are only 1 byte (8 bits). A signed char has the range -127 to +127 while the UNsigned is 0-256.
  The name signed comes from the fact that 1 of 8 bits holds the sign determining if the value is positive of negative.
</p>

  <p align="center">
  <img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/20200806155050/signed-and-unsigned-char-in-C.png" alt="ASCII table" height='300' width="600"/>
  </p>
  
<p>
  
  This also explains the lower max values of +-127 since a signed char only has 7 bits open to fill, compared to unsigned 8 bits. 
  Although as you can see below, the value range is again, the same, only shifted on the number line.
  
<p align="center">
  
  <img src="https://i.stack.imgur.com/0SQVh.png" alt="ASCII table" height='300' width="600"/>
  
</p>

</p>
  
  <p>
  Consider the fact that if you want to access the full ASCII-table or work with 8bit-manipulation (which we are) you will 
  need all 8 bits in that 1 byte unsigned char to do it. 
  </p>
  
Numerical System - Binary
---
<p>
  Because the binary system is expressed in base-2, there's only two values you can multiply each "building block"(power of) with.
  which is why it's so handy in representing logic in. a value or "building block" can be either on or off, true or false, 1 or 0.
</p>

<p> 
  so like 100 = (10^2)x1 + (10^1)x0 + (10^0)x0 in the decimal system, the same value in binary is written like
  01100100 which is equal 100, each digit from right to left represents an increase in the power of 2.

  01100100 == (2^7)x0 + (2^6)x1 + (2^5)x1 + (2^4)x0 + (2^3)x0 + (2^2)x1 + (2^1)x0 + (2^0)x0 == 0 + 64 + 32 + 0 + 0 + 4 + 0 + 0
  </p>
  
  <p>
  each digit in a binary number is referred to as a bit and 8 bits makes up a byte(usually)
  a byte is kinda the basic size of a memory cell(holds values, these are usually 32 or 64 bits in modern computers)
  </p>
  
  <p>
  Below is a table showing conversion between different bases and the ASCII table which is used to convert bytes
  into chars, just to show you that they're really just numbers
  </p>
<p aling="center">
  
<img src="https://miro.medium.com/max/2356/1*Ae2Vp6Z7rfhipVFX1PkLaw.gif" alt="ASCII table" height='400' width="800"/>

</p>


 Excellent tutorial for learning to calculate in Binary: [Binary Tutorial](https://medium.com/@LindaVivah/learn-how-to-read-binary-in-5-minutes-dac1feb991e)
  


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
  
  <p>
    The OR operation evaluates if to true if either operand is true. if 1 or 0 == 1 so only one needs to be true. the only
    case in which OR evaluates to false is if both operands are false or 0(<-- look an OR operation in a sentence!)
  </p>

  ![OR outcomes](http://web.cs.iastate.edu/~smkautz/cs127f16/notes/chapter09/_static/ab.PNG)
  
  <p>
    XOR or Exclusive OR means either or, so not both. we'll be using this quite alot to flip bits, since if one operands is different the outcome
    will be the opposite of that. it's a bit difficult to put into text but hopefully the truth charts make it a bit more clear.
  </p>
  
  
  ![XOR outcomes](https://iq.opengenus.org/content/images/2018/10/xor-table-5.png)
  
  <p>
    These are all the basic operations(technically XOR is a composite of the others). there are lots of other types that are made by
    combining different operations into one, like NAND(NOT AND) or NOR(NOT OR) or XOR but what's important is understanding the basic
    theory behind them.
  </p>
  
<p> 
  
Bitwise Operators
---
  
  Bitwise operators work just like mathematical operators, in that they tell the compiler to perform certain mathematical, or in our case, logical functions.
  Look at the following operators the same way you would "+", "-" "x" signs when calculating mathematically. 
  Trying to commit them all to memory right now may feel daunting so just focus on understanding each one by one. </p>
  
  <p>
  Below we will look at the most commonly used operators and try our hand at some "boolean arithmetic". In our case this basically equates to binary calculations.
  This is just for understanding what all the operators actually do behind the scenes. 
  Just learning to use copied codeblocks with these types of functions is honestly good enough at this point. 
  The rest will fall in to place later.
</p>
  <p>
  Before we start, note that all the operations (or "calculations") will be done FROM the left operand TO the right operand. 
  For example, A + B adds the A-operand to the B-operand which results in a new third (A+B)-operand.
</p>
<p>
  This first table lists completed operations so just try and use it as a reference going forward.
 
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

It's important to note that these operations are done on a bit-by-bit basis, so if you're performing an AND operations on two binary
numbers, then the first two digit in both numbers will AND:ed then the result of that operation will be first bit in the new number
and so on and so on.

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
  Looking closer at the operations {forts. följer}
</p>

Using Bitwise Shifting to Access Bits
------


<p>
  Bitwise shifting means shifting the bits a number of places to left or right depending on the direction you're shifting.
 </p>
 <p>
  the syntax for bitwise shifting in C is "a << b" where the bits in "a" are shifted by "b" positions to the left.
  
  EX:
  5 << 2 == 20  
  |0|0|0|0|0|1|0|1| << 2 == |0|0|0|1|0|1|0|0|  
  here the bits have been shifted to the left by 2 places.
  </p>
  
  <p>
    When we do low level programming we might want to store several values in a bit, by turning those bits on or off(1 or 0).  
    Bitwise shifting allows us to access the individual bits in a byte and perform operations to modify them and store information there.  
  
    Say we have a value I = 00000000 and we want to modify the fourth bit in I to store some value or setting
    We could change it by using the OR operation on I with another byte with the fourth bit set to on(1).  
    other_bit = 00010000  
    since 0 | 1 == 1 and operations are done on a per-bit base only the fourth bit on I will be switched on.  
    
    I |= other_bit == 00010000.  
    
    A more general way to get other_bit = 00010000 that doesn't involve declaring another variable  
    would be to write it using bitwise shifting to get the number that we want.  
    
    If we bitshift the one here by 4 places to left we'll get other_bit.  
    1 == 00000001  
    (1 << 4) == 00010000  
    So now if we we're to use OR from that bitwise shift operation on I we would get the same  
    result.  
    I = 00000000
    I |= (1 << 4) == 00010000  
    
    If we generalize even more we can say that that expression below can reach any bit in position n  
    and by performing logic/bool operations with it we can set, clear, test, flip any bit of the same
    size as "a".  
    
    (a << n)
    
   </p>
   
   Using Bitwise Shift and Operators to modify bits
   -----
   
   <p>
    So now that we have a really basic understanding of logical operations(hopefully!) and how to access bits.  
    Let's talk about how to change those bits and the syntax for how to do that in C
    </p>
    
    
      Setting Bits  
      Setting a bit means turning it "on" or setting it to 1. You could use a bit to store device state or  
      setting, for recording an input on the device, to start recording you'd need to turn that bit on.   
      
      Let's say that we have the bit for recording on the first bit, to start that recording we'd first  
      need to SET the first bit.  
      
      This is our device state I, with a two bits already turned on. 
      To access the first bit we use bitwise shifting as in the previous section.
      Bitshifting from to the zeroth(first place, think of it like an array index).  
      
      To be able to change the value we use OR operation. the OR operation will  
      always set the two bits it is operating on to on(1) unless they're both off  
      but since the bit we're using to access(from the bitshifting) is always 1  
      the effect is that the targeted bit will always be set to on and all  
      other bits in the target byte will remain untouched.
      
      I = 6 == 00000110  
      (1 << 0) == 00000001
      I |= (1 << 0)  == 00000110 | 00000001  
      I = 7 == 00000111
      
<p>
  Now the first bit in the device state I has been set, but to turn on whatever function is  
  responsible for that input we'd probably need to check the device states first bit and  
  see what value it has  
  </p>
    
    Testing a Bit
    
    To be able to test a bit we again need to first access the bit we want to look at
    through bitshifting and then perform a logical operation on it that gives us the
    value of that bit.
    
    The logical operation needs to return only the value of the bit we're interested in
    and the operation for that is AND.
    
    AND evaluates to true(or 1) only and if only both bits are true and since the only
    bit that's turned on in our bitshifted byte is one we're interested in(first one)
    all other bits will be cancelled(turned off) and we'll be left with the value of
    the bit we're looking for if it is on(1) otherwise we'll get 0
    
    I = 7 == 00000111
    (1 << 0) == 00000001
    I & (1 << 0) == 00000111 & 00000001 = 00000001
    I & (1 << 0) == 1
    
    Now that we have the value of the first bit we can plug it into an if statement
    and to get a simple check on wether it is on or not.
    
    if(I & (1 << 0))  {
    device.record();
    }
    
    If the bit is on, it'll have a value >= 0 and will be evaluated as true, if not
    it will be evaluated as false.(since C evaluates anything other than 0 as true)
    
    Negative values are not possible for bits
<p>
  Now that the device has been running the recording for a while a condition might have told us to finish  
  and stop recording whatever we're doing.  
  To do that we're going to once again use bitwise shifting to access the first bit  
  and then we're going to have use a logical operation on that bit again, but this time  
  to clear it, set it to 0  
    
    Clearing a Bit
    
    Clearing a bit works very much like setting a bit, once you've accessed the bit you're
    going to perform the reverse operation of setting.
    When you set a bit you're using the AND operation, we're still going to be using the
    AND operation but with a tweak.
    
    We're going to combine logical operators to perform a NAND operation(or run it through a
    NAND gate).
    That is done by using the NOT operator to reverse the bitshifted bit before we and it
    with our device state byte. the symbol for the NOT operator in C is "~".
    
    
    I = 7 == 00000111
    (1 << 0) == 00000001
    ~(1 << 0) == 11111110
    I &= ~(1 << 0) == 00000111 & 11111110 == 00000110
    I is now 00000110
    
    Now the bit is cleared so if we run the check on that bit again.
    
    if(I & (1 << 0))  {
    device.record();
    }
    
    It will be evaluated as false
    
 <p>
    The last example is bit flipping, meaning that everytime we run this operation the value of the will be changed  
    from 0 to 1 to 0 and so on. Which might be useful for say... flashing a led light when a certain type of card  
    has been scanned.  
      
    Bit Flipping
    
    To flip a bit we're going to as always, use bitshifting to access the bit we want to change and then apply
    a logical operation to it. This time we'll be using XOR(exclusive or)
    
    XOR changes the value of the byte or bit it's applied to 1 if they differ and 1 if they're the same,
    the symbol in C for XOR is "^" so if a = 0 and b = 1 then a ^= b changes a to 1 then
    if we do it again a ^= b then a = 0
    
    
    I = 7 == 00000110
    (1 << 0) == 00000001
    I ^= (1 << 0)
    I == 00000111
    If we do it again...
    I ^= (1 << 0)
    I == 00000110
    and again..
    I ^= (1 << 0)
    I == 00000111
    
    So we the last bit(bit[0]) flipping between 1 and 0 everytime we run the operation on it.
    If we run an if statement on that after everychange, and that bit is tied to say a led light.
    
    if(I & (1 << 0))  {
    device.lightOn();
    }
    else  {
    device.ledOff();
    }
    
    or even better, use the state of the bit with a "Test Bit" operation
    to set the light.
    
    device.light((I ^= (1 << 0)) & (1 << 0));
    
    Then the light will switch on and off everytime the function is called.
