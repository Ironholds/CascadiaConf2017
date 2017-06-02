- Intro

-- Who the heck are you?

--- Oliver

--- They/them (image)


-- Who the heck is this for?

- C++

-- C++ is a compiled language built on top of C (which R is written in)

-- It's much closer to the metal than R, and so can be a lot faster for particular kinds of operations

-- The major differences; it's compiled and strongly typed.

- Rcpp

-- The Rcpp package provides an interface between C++ and R, letting you write code in C++ and then run it in R

-- It has a lot of 'convenience types' that look a lot like R data types (Integer Vectors, Lists, Matrices, etc etc)

-- These are great but in some ways limited, and so a lot of people find themselves using the C++ 'standard library' structures instead

-- ...and which structure you use, and how you use them, has performance implications! Important when dealing with a tool to make R *faster*

- Performance

-- Memory

-- Speed

-- Availability

-- Here's what the graphs look like and how they work


- Vectors

-- What is a vector?

--- Like an R vector

--- Single type, general purpose, best thought of as an R vector

--- Low memory footprint

--- Contiguous memory

-- Contiguous memory?

--- Everything in one block

--- Easier to read from

--- Much harder to append to

--- Allocate, don't append!

-- Allocation versus appending

--- blahblfbmgbg

- Deques

-- What is a deque?

--- *double-ended queue*

--- Higher memory footprint, but!

--- *non-contiguous*

--- Faster to append to, can append to the front as well as the back

-- Deques versus vectors

--- Reading

--- Writing

- Sets

-- What is a set?

--- Just like in maths! collecton of unique values.

--- each value is also its (unique) key

--- Ordered

--- Fast `%in%`-like lookup...for lots of values

-- Sets versus vectors

--- Lookup

--- Unique inserts

- Map

-- What is a map?

--- A set but with pairs (int, int, str, int, str, str...) of key-values

--- Ordered

--- Fast %in% lookup when you need associated values.


- Unordered map/set

-- What are they?

--- Same but uh unordered

--- Slower %in%. Faster insert!

--- C++11-only

