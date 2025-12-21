*This project was developped by rafa-pk in the context of research on memory-safety and C programming.*

# Introduction
Throughout my programming journey I've come to peace with how much I like C. I find its querks very interesting
and its simplicity generally quite joyfull. But when I started trying out higher-level languages such as Go or Python, 
I couldn't help myself from being amazed with how practical splices are. Its just so convenient to not have to worry about
getting metadata on things I declare and just be able to call it whenever. So it got me thinking: I like coding in C a lot, 
but these memory safety features are just so nice to use... **I'll implement them in C!**

## What are slices?
In most higher-level programming languages, slices serve either as views or containers for data, which allows the user to
automatically have access to metadata and not have to worry about memory management so much. As mentioned, they work in two ways:
- Views: These are simple slices which work as a middle-manager — they contain a pointer to the data and information about it, but
do not have any type of ownership whatsoever.
- Containers: These are the real players when it comes to memory-safety, they work as a "host" for the data (and its metadata) and 
have complete ownership over it. This means the user just needs to call them, and its utility function, and it takes care of the rest
under the hood, making coding a little more confortable.

## C implementation

### Why are slices not native in C?
C is statically-typed, does not support type-inference, is mostly compile-time based and runs on very little abstraction. It's a low-level language.

As you may know, a string is represented as an array of chars, which decays at compile-time to mere pointers to the memory-address of said array.
This means, when the program is compiled, it loses any metadata about the string, it basically sees this:
> ```
>  [ADDRESS]: [BYTE][BYTE][BYTE]...
> ```
So all available information is lost.

With strings, its generally not a big deal, as they are all NULL-terminated by default — any string length counting function solves the issue, despite being unpractical. 
However, with general arrays — wether its integer arrays, struct arrays, linked lists... — it requires much more organisation and thinking than it should, as there is no 
straight-forward way to get the end of the array or itterate through it. The solution is usually to use structs and have an index field, buts its too much of 
a hassle for the result.
Important definition: when I talk about "metadata", I am refering to the length, capacity (if dynamically allocated) and data-block size.

### How can we implement this?
The first thing to do is to create the struct itself, so I declared a struct t_slice, in which I had the following fields:
- data
- length
- capacity
- block size
After that was done, I started working on some functions. But I quickly realised that because of all the C restrictions I couldn't make a slice-like function. To give some context,
I wanted my initalization to look like this:

> t_slice var = slice(data);

But it is basically impossible to infer all fields for all data-types just from that, so I had to change my strategy.
After some research and conversations with Chat-GPT, I finally decided to settle with macros, eventhough I wanted to avoid it.
What did that change?
Well, the main issue I had before was that I couldn't compute the length of general-arrays without creating objects pointing to it, and it seemed way too much for the task. Macros are
essentially text-replacement, so they run before compilation and have access to information that is lost at compile-time, namly: data-type, array-length. This new method now allowed me
to access pre-compilation information.

So my approach changed:
I had the struct ready, but I was now going to create helper functions which the macros would substitute, instead of trying to have one function creating a slice. 
For that, I made a function to populate the struct and a function which either made a special case for strings, or handled metadata for general-arrays. Once that was done, I got my hands
dirty in the realm of macro debugging — I defined slice(data) as being a call to the second function I mentioned. I also defined its last parameter as type_flag and used *_Generic()* to
chose the right type-flag.
The macros looked something like this:
> ```
> #define type_flag(flag) _Generic((flag), char *: 'c', const char *: 'c', default: 'i')
> #define slice(data) slicer((void *)data, sizeof(data) / sizeof((data)[0]), sizeof((data)[0]), type_flag(data))
> ```

This is the base-layer of the library, it is a work in progress and for now only viewer slices are supported, but the next steps would be to implement support for containuers and all utility
functions associated with it. 

## How to use it?
This compiles to a static library called slice.a, you just need to include the "slice.h" header where the library will be needes, then there are two options:
- You can use it as a library and compile your program like this:
> make (creates library)
> cc <flags> <program> slice.a
> ./a.out
- You can link it to an existing makefile and compile your program as above within your makefile. Which would look something like this:
> ```
> $(MAKE) slice.a
> $(CC) $(FLAGS) $(OBJ) slice.a -o $(NAME)
> ```
