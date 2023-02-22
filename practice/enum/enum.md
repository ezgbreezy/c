
# C Practice: Enumeration Constants

## Lessons

## Declaring Enumeration Constants

Enumeration constants are lists of constant integer values. They essentially create a psuedonym for a constant integer value in order to make code more legible.

```c
enum colors {Red, Green, Blue}; // Creates variable of 

enum colors current_color = Red; // Creates variable of type int
```

Enumerators are assigned ascending sequential values beginning with 0 unless values are explicitly assigned. 

So in the above example, Red = 0, Green = 1, Blue = 2. 

```c
enum colors {Red = 1, Green, Blue};
```

If Red is assigned the value 1, the sequence continues from 1, so Green = 2 and Blue = 3. 

```c
enum colors {Red = 2, Green = 1, Blue};
```

Enumerators can represent the same values as other enumerators. Here Red is assigned 2 but Green is assigned 1, therefore Blue also equals 2. 

## Using Enumeration Constants

Enumeration constants are integer values and can be used arithmetically. 

```c
enum colors {Red = 2, Green = 1, Blue};


```
